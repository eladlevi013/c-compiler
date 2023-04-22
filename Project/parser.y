%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

// Function declarations
int yylex(void);
int yyerror();
char *yytext;
typedef struct node
{
    char *token;
    struct node **nodes;
    int count;
} node;
node *makeNode(char* token);
void addNode(node **father, node *descendant);
void printtree(node* tree, int tab);
#define YYSTYPE struct node*
%}

// Tokens from lex
%token BOOL CHAR INT REAL STRING INT_POINTER CHAR_POINTER REAL_POINTER ADDRESS;
%token IF ELSE WHILE DO FOR FUNCTION ;
%token VAR ARG_ARROW RETURN NULL_TOKEN VOID;
%token AND ASSIGNMENT EQUALS GREATER_THAN GREATER_EQUALS LOWER_THAN LOWER_EQUALS 
        NOT NOT_EQUALS OR;
%token SUBSTRACT ADD MULTIPLY DIVIDE;
%token TRUE FALSE CHAR_LITERAL INTEGER_LITERAL INTEGER_LITERAL_HEX REAL_LITERAL
        STRING_LITERAL IDENTIFIER;
%token COMMENT COLON SEMICOLON COMMA VERTICAL_BAR START_CURLY_BRACKETS END_CURLY_BRACKETS 
        START_ROUND_BRACKETS END_ROUND_BRACKETS START_SQUARE_BRACKETS END_SQUARE_BRACKETS;
%%

s: code { printtree($1, 0); };  

code: functions { $$ = makeNode("CODE"); addNode(&$$, $1); }

functions: function | procedure | args_list

function: 
    FUNCTION id START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode($2->token));
        node* args_node = makeNode("ARGS");
        addNode(&args_node, $4);
        addNode(&func_node, args_node);
        node* type_node = makeNode("TYPE");
        addNode(&type_node, $7);
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
    }

procedure: FUNCTION id START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode($2->token));
        node* args_node = makeNode("ARGS");
        addNode(&args_node, $4);
        addNode(&func_node, args_node);
        node* type_node = makeNode("TYPE VOID");
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
    }

// Function args parameters
args_list:
    single_arg args_list_helper
    {
        node *args_root = makeNode("ARGS");
        addNode(&args_root, $1);
        addNode(&args_root, $2);
        $$ = args_root;
    }
    | single_arg 
    {
        node *args_root = makeNode("ARGS");
        addNode(&args_root, $1);
        $$ = args_root;
    }
    |
    {
        $$ = makeNode("ARGS NONE");
    };

single_arg: ARG_ARROW args_parameters COLON type
{
    node* args_root = makeNode($4->token);
    addNode(&args_root, $2);
    $$ = args_root;
}

args_list_helper: SEMICOLON single_arg args_list_helper
{
    node* args_root = $2;
    addNode(&args_root, $3);
    $$ = args_root;
}
| SEMICOLON single_arg 
{
    $$ = $2;
}

args_parameters: 
id single_parameter
{
    $$ = makeNode($1->token);
}
| id
{
    $$ = makeNode($1->token);
}

single_parameter: 
COMMA id single_parameter
{
    $$ = makeNode($2->token);
}
| COMMA id
{
    $$ = makeNode($2->token);
}

// Body
body: functions body | body_after_functions_declared
body_after_functions_declared: statements | variable_declarations

// Statements
statements: assignment_statement 
          | function_call_statement 
          | if_statement
          | if_else_statement 
          | while_statement
          | do_while_statement 
          | for_statement 
          | code_block_statement
          | return_statement
          ;

assignment_statement: lhs ASSIGNMENT expression SEMICOLON 
| lhs ASSIGNMENT STRING_LITERAL SEMICOLON

lhs: IDENTIFIER '[' expression ']' | IDENTIFIER

function_call_statement: lhs ASSIGNMENT IDENTIFIER START_ROUND_BRACKETS function_call_statement1

function_call_statement1: expression function_call_statement2 | function_call_statement2

function_call_statement2: COMMA function_call_statement1 | END_ROUND_BRACKETS SEMICOLON

if_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements

if_else_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements

while_statement: WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements

do_while_statement: DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON

for_statement: FOR START_ROUND_BRACKETS assignment_statement expression SEMICOLON lhs ASSIGNMENT expression END_ROUND_BRACKETS statements

code_block_statement: START_CURLY_BRACKETS code_block_statement1

code_block_statement1: variable_declarations code_block_statement1 | code_block_statement2

code_block_statement2: statements code_block_statement2 | code_block_statement3

code_block_statement3: END_CURLY_BRACKETS

return_statement: RETURN expression SEMICOLON

// Types
type: BOOL { $$ = makeNode("BOOL"); }
    | CHAR { $$ = makeNode("CHAR"); }
    | INT { $$ = makeNode("INT"); }
    | REAL { $$ = makeNode("REAL"); }
    | CHAR_POINTER { $$ = makeNode("CHAR_POINTER"); }
    | REAL_POINTER { $$ = makeNode("REAL_POINTER"); }
    | INT_POINTER { $$ = makeNode("INT_POINTER"); }
    ;

id: IDENTIFIER {
    $$ = makeNode(yytext);
};

integer_literal: INTEGER_LITERAL 
               | INTEGER_LITERAL_HEX
               ;
               
bool__literal: FALSE 
             | TRUE
             ;
             
literal_lexemes: bool__literal
               | CHAR_LITERAL
               | integer_literal 
               | REAL_LITERAL 
               | STRING_LITERAL 
               | IDENTIFIER
               ;

// Variable Delarations
variable_declarations: VAR variable_list
variable_list: IDENTIFIER variable_helper | IDENTIFIER EQUALS literal_lexemes variable_helper
variable_helper: COMMA variable_list | COLON type SEMICOLON

// String Delarations
string: STRING string1
string1: IDENTIFIER START_SQUARE_BRACKETS integer_literal END_SQUARE_BRACKETS string2 
        | IDENTIFIER START_SQUARE_BRACKETS integer_literal END_SQUARE_BRACKETS EQUALS literal_lexemes string2
string2: COMMA string1 
| SEMICOLON

expression: expression operator expression
          | operator expression 
          | literal_lexemes
          ;
          
operator: AND
        | DIVIDE
        | EQUALS
        | GREATER_THAN 
        | GREATER_EQUALS
        | LOWER_THAN
        | LOWER_EQUALS
        | SUBSTRACT
        | NOT
        | NOT_EQUALS
        | OR
        | ADD 
        | MULTIPLY
        ;
%%
#include "lex.yy.c"
int main()
{
    return yyparse();
}

int yyerror() 
{ 
    printf("YOUR ERROR pisher!\n");
    return 0; 
}

node *makeNode(char *token)
{
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->token = newstr;
    newnode->count = 0;
    newnode->nodes = NULL;
    return newnode;
}

void addNode(node **father, node *descendant)
{
    (*father)->nodes = (node**) realloc((*father)->nodes, ((*father)->count + 1) * sizeof(node*));
    (*father)->nodes[(*father)->count++] = descendant;
}

void printtree(node* tree, int tab) {
	int i;
	char* token = tree->token;

	if (*token) {
		for (i = 0; i < tab; i++) {
			printf("\t");
		}
		printf("(%s\n", token);
	}
	else
		tab -= 1;
	if (tree->nodes) {
		for (int j = 0; j < tree->count; j++) {
			printtree(tree->nodes[j], tab + 1);
		}
	}
	for (i = 0; i < tab; i++) {
		printf("\t");
	}
	if (*token)
		printf(")\n");
}