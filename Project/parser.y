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
    struct node *left;
    struct node *right;
} node;
node *mknode(char *token, node *left, node *right);
void printtree(node *tree);
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
// Grammer
/*
s: exp { printf("OK\n"); printtree($1); }
exp: exp PLUS exp { $$ = mknode("+",$1,$3); }
| exp MINUS exp { $$ = mknode("-",$1,$3); }
| NUM { $$ = mknode(yytext,NULL,NULL); };
*/

s: code
code: functions
functions: function | procedure
function: FUNCTION IDENTIFIER START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
procedure: FUNCTION IDENTIFIER START_ROUND_BRACKETS args_list END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS

// Function args parameters
args_list: single_arg  args_list_helper | single_arg
args_list_helper: SEMICOLON single_arg args_list_helper | SEMICOLON single_arg
single_arg: ARG_ARROW args_parameters COMMA type
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
type: BOOL 
    | CHAR
    | INT 
    | REAL 
    | CHAR_POINTER 
    | REAL_POINTER
    | INT_POINTER 
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
    printf("MY ERROR\n");
    return 0; 
}

// Functions
void printtree(node *tree) 
{ 
    printf("%s\n", tree->token); 
    if(tree->left) 
        printtree(tree->left); 
    if(tree->right) 
        printtree(tree->right); 
}

node *mknode(char *token,node *left,node *right)
{
    node *newnode = (node*)malloc(sizeof(node));
    // char *newstr = (char*)malloc(sizeof(token) + 1);
    // strcpy(newstr,token);
    // newnode->left = left;
    // newnode->right = right;
    // newnode->token = newstr;
    return newnode;
}
