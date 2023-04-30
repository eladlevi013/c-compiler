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

// Tree functions
node *makeNode(char* token);
void addNode(node **father, node *descendant);
void printtree(node* tree, int tab);
void printArgsList(node** argsList, int argCount);
void addElement(node ***, node *, int);
#define YYSTYPE struct node*

node *temp_node = NULL;

// args-list
node** argsList = NULL;
int counter_argsList = 0;

// parameter-list
node** parList = NULL;
int counter_parlist = 0;

// var-list
node** varList = NULL;
int counter_varList = 0;
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

code: functions | args{ $$ = makeNode("CODE"); addNode(&$$, $1); }

functions: function | procedure | args

function: 
    FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode($2->token));
        addNode(&func_node, $4);
        node* type_node = makeNode("TYPE");
        addNode(&type_node, $7);
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
    }

procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode($2->token));
        addNode(&func_node, $4);
        node* type_node = makeNode("RET VOID");
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
    }

// Function args parameters
args:
	arg_declare
    {
        $$ = makeNode("ARGS");
        addNode(&$$,$1);
    }
    | args SEMICOLON arg_declare
    {
        addNode(&$$,$3);
    }
	|
    {
        $$ = makeNode("ARGS NONE");
    }

arg_declare:
    ARG_ARROW args_list COLON type
    {
        addNode(&$4,$2);
        $$ = $4;
    }

args_list:
    id
    {
        $$ = makeNode("");
        addNode(&$$,$1);
    }
    | args_list COMMA id
    {
        addNode(&$$,$3);
    }

// Body
body: 
    functions body
    {
        node* body_node = makeNode("BODY");
        addNode(&body_node, $1);
        addNode(&body_node, $2);
        $$ = body_node;
    }
    | body_after_functions_declared
    {
        $$ = $1;
    }

body_after_functions_declared:
    variable_declarations 
    {

    }
	| body_after_delarations
    {
       $$ = $1;
    }

body_after_delarations: 
    statements
    {
       $$ = $1;
    }
    | body_after_delarations statements
    {
       addNode(&$$,$2);
    }

// Statements
statements: 
    assignment_statement { $$ = $1;}
    | function_call_statement { $$ = $1; }
    | if_statement { $$ = $1; }
    | if_else_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | do_while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | code_block_statement { $$ = $1; }
    | return_statement { $$ = $1; }
    ;

assignment_statement: 
    lhs ASSIGNMENT expression SEMICOLON 
    {
        node *assignment_node = makeNode("=");
        addNode(&assignment_node, $1);
        addNode(&assignment_node, $3);
        $$ = assignment_node;

    }
    | lhs ASSIGNMENT STRING_LITERAL SEMICOLON
    {
        node* assignment_node = makeNode("=");
        addNode(&assignment_node,$1);
        addNode(&assignment_node,$3);
        $$ = assignment_node; 
    }

lhs: 
    id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS
    {
        $$ = $1;
        addNode(&$$,$3); //TO CHECK!!
    }
    | id 
    {
        $$ = $1;
    }

function_call_statement: 
    lhs ASSIGNMENT id START_ROUND_BRACKETS function_parms END_ROUND_BRACKETS SEMICOLON
    {
        //ADD
    }

function_parms:
    //ADD
    expression  
    | function_parms COMMA expression


if_statement: 
    IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements
    {
        node* if_node = makeNode("IF");
        addNode(&if_node, $3);
        addNode(&if_node, $5);
        $$ = if_node;
    }

if_else_statement:
    IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements
    {
        node* if_else_node = makeNode("IF-ELSE");
        addNode(&if_else_node, $3);
        addNode(&if_else_node, $5);
        addNode(&if_else_node, $7);
        $$ = if_else_node;
    }

while_statement: 
    WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements
    {
        node* while_node = makeNode("WHILE");
        addNode(&while_node, $3);
        addNode(&while_node, $5);
        $$ = while_node;
    }

do_while_statement: 
    DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON
    {
        node* do_while_node = makeNode("DO-WHILE");
        addNode(&do_while_node, $2);
        addNode(&do_while_node, $5);
        $$ = do_while_node;
    }

for_statement:
    FOR START_ROUND_BRACKETS assignment_statement expression SEMICOLON lhs ASSIGNMENT expression END_ROUND_BRACKETS statements
    {
        //NeEd tO FIX SPEAK TO איילון 
    }

code_block_statement:
    START_CURLY_BRACKETS body_after_functions_declared END_CURLY_BRACKETS
    {
        $$ = makeNode("BLOCK");
        addNode(&$$, $2);
    }
    | START_CURLY_BRACKETS END_CURLY_BRACKETS
    {
        $$ = makeNode("BLOCK");
    }

return_statement:
    RETURN expression SEMICOLON
    {
        $$ = makeNode("RET");
        addNode(&$$, $2);
    }

// Types
type: 
    BOOL { $$ = makeNode("BOOL"); }
    | CHAR { $$ = makeNode("CHAR"); }
    | INT { $$ = makeNode("INT"); }
    | REAL { $$ = makeNode("REAL"); }
    | CHAR_POINTER { $$ = makeNode("CHAR_POINTER"); }
    | REAL_POINTER { $$ = makeNode("REAL_POINTER"); }
    | INT_POINTER { $$ = makeNode("INT_POINTER"); }
    ;

id: 
    IDENTIFIER {
        $$ = makeNode(yytext);
    };

integer_literal: 
    INTEGER_LITERAL { $$ = makeNode("INT");}
    | INTEGER_LITERAL_HEX { $$ = makeNode("INT");}
    ;
               
bool__literal:
    FALSE { $$ = makeNode("FALSE");}
    | TRUE { $$ = makeNode("TRUE");}
    ;
             
literal_lexemes: 
    bool__literal { $$ = $1; }
    | CHAR_LITERAL { $$ = makeNode("CHAR");}
    | integer_literal { $$ = $1;}
    | REAL_LITERAL { $$ = makeNode("REAL"); }
    | STRING_LITERAL { $$ = makeNode("STRING"); }
    | id { $$ = $1; }
    ;

variable_declarations:
    variable_declare
    {
        $$ = makeNode("variable_declarations");
        addNode(&$$, $1);
    }
    | variable_declarations variable_declare
    {
        addNode(&$$, $2);
    }

variable_declare:
    var_declare
    | string_declare

var_declare:
    VAR variable_list COLON type SEMICOLON
    {
        addNode(&$4, $2);
        $$ = $4;
    }

// Variable Delarations    
variable_list: 
    variable_list_helper
    {
        $$ = makeNode("");
        addNode(&$$, $1);
    }
    | variable_list COMMA variable_list_helper
    {
        addNode(&$$, $3);
    }

variable_list_helper:
    id
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, $1);
    }
    | id ASSIGNMENT literal_lexemes
    {
        // Creating the ASSIGNMENT node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, $1);
        addNode(&temp_assinment_node, $3);
        $$ = temp_assinment_node;
    }

string_declare:
    STRING string_list SEMICOLON
    {
        node* string_node = makeNode("STRING");
        addNode(&string_node,$2);
        $$ = string_node;
    }
  
string_list:
    string_list_helper
    {
        $$ = makeNode("");
        addNode(&$$, $1);
    }
    | string_list COMMA string_list_helper
    {
        addNode(&$$, $3);
    }

string_list_helper:
    id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, $1); 
        node* lenght_node = makeNode("LENGTH");
        addNode(&lenght_node, $3);
        addNode(&$$, lenght_node);
    }
    | id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS ASSIGNMENT literal_lexemes 
    {
        // Creating the ASSIGNMENT node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, $1);
        node* lenght_node = makeNode("LENGTH");
        addNode(&lenght_node, $3);
        addNode(&$$, lenght_node);
        addNode(&temp_assinment_node, $6);
        $$ = temp_assinment_node;
    }


expression: 
    operator expression
    {
        node* operator_node = makeNode($1->token); 
        addNode(&operator_node,$2);
        $$ = operator_node;
    } 
    | expression operator expression
    {
        node* operator_node = makeNode($2->token); 
        addNode(&operator_node,$1);
        addNode(&operator_node,$3);
        $$ = operator_node;
    }
    |   literal_lexemes { $$ = $1;}
          
operator: 
    AND { $$ = makeNode("&&"); }
    | DIVIDE { $$ = makeNode("/"); }
    | EQUALS { $$ = makeNode("=="); }
    | GREATER_THAN { $$ = makeNode(">"); }
    | GREATER_EQUALS { $$ = makeNode(">="); }
    | LOWER_THAN { $$ = makeNode("<"); }
    | LOWER_EQUALS { $$ = makeNode("<="); }
    | SUBSTRACT { $$ = makeNode("-"); }
    | NOT { $$ = makeNode("!"); }
    | NOT_EQUALS { $$ = makeNode("!="); }
    | OR { $$ = makeNode("||"); }
    | ADD { $$ = makeNode("+"); }
    | MULTIPLY { $$ = makeNode("*"); }
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

void printArgsList(node** argsList, int argCount) {
    if (argCount == 0) {
        printf("No arguments\n");
        return;
    }
    printf("Arguments:\n");
    for (int i = 0; i < argCount; i++) {
        printf("arg%d: %s\n", i+1, argsList[i]->token);
    }
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

void addElement(node ***list, node *element, int size) {
    *list = (node**) realloc(*list, (size+1) * sizeof(node*));
    (*list)[size] = element;
}

void printtree(node* tree, int tab) {
    int i;
    char* token = tree->token;

    if (*token) {
        for (i = 0; i < tab-1; i++) {
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
