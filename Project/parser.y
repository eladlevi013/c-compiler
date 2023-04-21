%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function declarations
int yylex(void);
int yyerror();
char *yytext;
typedef struct node
{
    char *token;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
} node;
node *makeNode(char* token, node *first, node *second, node *third, node *fourth);
void printTree(node *tree);
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

s: code { printf("THIS IS FINE. HAVE A GOOD DAY!\n"); };

code: functions { $$ = makeNode("CODE", $1, NULL, NULL, NULL); }

functions: function1 | procedure

function1: 
    FUNCTION IDENTIFIER START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS END_CURLY_BRACKETS
    {
        if (*($2) == NULL) {
            printf("muzar");
        }
        printf("%s", (*$2).token);
        $$ = makeNode("FUNCTION",
            makeNode($2->token, NULL, NULL, NULL, NULL),
            makeNode("ARGS", $4, NULL, NULL, NULL),
            makeNode("TYPE", $7, NULL, NULL, NULL),
            makeNode("BODY", $9, NULL, NULL, NULL)
        );
    }

function: 
    FUNCTION IDENTIFIER START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        $$ = makeNode("FUNCTION",
            makeNode($2->token, NULL, NULL, NULL, NULL),
            makeNode("ARGS", $4, NULL, NULL, NULL),
            makeNode("TYPE", $7, NULL, NULL, NULL),
            makeNode("BODY", $9, NULL, NULL, NULL)
        );
    }

procedure: FUNCTION IDENTIFIER START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS

// Function args parameters
args_list: single_arg  args_list_helper | single_arg | {$$=makeNode("NONE",NULL,NULL,NULL,NULL);};
args_list_helper: SEMICOLON single_arg args_list_helper | SEMICOLON single_arg
single_arg: ARG_ARROW args_parameters COLON type
args_parameters: IDENTIFIER single_parameter | IDENTIFIER
single_parameter: COMMA IDENTIFIER single_parameter | COMMA IDENTIFIER

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
type: BOOL { makeNode("BOOL",NULL,NULL,NULL,NULL); }
    | CHAR { makeNode("CHAR",NULL,NULL,NULL,NULL); }
    | INT { makeNode("INT",NULL,NULL,NULL,NULL); }
    | REAL { makeNode("REAL",NULL,NULL,NULL,NULL); }
    | CHAR_POINTER { makeNode("CHAR_POINTER",NULL,NULL,NULL,NULL); }
    | REAL_POINTER { makeNode("REAL_POINTER",NULL,NULL,NULL,NULL); }
    | INT_POINTER { makeNode("INT_POINTER",NULL,NULL,NULL,NULL); }
    ;

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

// Functions
void printTree(node *tree) 
{ 
    // printf("%s\n", tree->token); 
    // if(tree->left) 
    //     printtree(tree->left); 
    // if(tree->right) 
    //     printtree(tree->right);
}

node *makeNode(char* token, node *first, node *second, node *third, node *fourth)
{
    node* newnode = (node*)malloc(sizeof(node));
    char* newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr,token);
    newnode->first = first;
    newnode->second = second;
    newnode->third = third;
    newnode->fourth = fourth;
    newnode->token = newstr;
    return newnode;
}
