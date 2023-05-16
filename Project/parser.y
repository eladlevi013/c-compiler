%{
#include "helpers.c"  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Function declarations
int yylex(void);
int yyerror(char* error);

// Variables
char *yytext;
node *temp_node = NULL;
%}

// Tokens from lex
%token BOOL CHAR INT REAL STRING INT_POINTER CHAR_POINTER REAL_POINTER ADDRESS;
%token IF ELSE WHILE DO FOR FUNCTION MAIN;
%token VAR ARG_ARROW RETURN NULL_TOKEN VOID;
%token AND ASSIGNMENT EQUALS GREATER_THAN GREATER_EQUALS LOWER_THAN LOWER_EQUALS 
        NOT NOT_EQUALS OR;
%token SUBSTRACT ADD MULTIPLY DIVIDE;
%token TRUE FALSE CHAR_LITERAL INTEGER_LITERAL INTEGER_LITERAL_HEX REAL_LITERAL
        STRING_LITERAL IDENTIFIER;
%token COLON SEMICOLON COMMA VERTICAL_BAR START_CURLY_BRACKETS END_CURLY_BRACKETS 
        START_ROUND_BRACKETS END_ROUND_BRACKETS START_SQUARE_BRACKETS END_SQUARE_BRACKETS;

%right ASSIGNMENT

%left AND OR
%left EQUALS GREATER_THAN GREATER_EQUALS LOWER_THAN LOWER_EQUALS NOT_EQUALS 
%left NOT
%left SUBSTRACT ADD
%left MULTIPLY DIVIDE 
%%

//s: code { printTree($1, 0,0); };  
s: code { printTree($1, 0,0); semanticAnalysis($1); };  

code: 
    functions Main { $$ = makeNode("CODE"); addNode(&$$,$1); addNode(&$$,$2); }
    | Main {$$ = makeNode("CODE"); addNode(&$$, $1); }

functions: 
    function_procedure
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
    }
    | functions function_procedure
    {
        addNode(&$$, $2);
    }

function_procedure: function | procedure 

Main:
    FUNCTION MAIN START_ROUND_BRACKETS END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        $$ = makeNode("MAIN");
        node* body_node = makeNode("BODY");
        addNode(&body_node, $8);
        addNode(&$$, body_node);
    }

function:
    FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        $$ = makeNode("FUNC");
        addNode(&$$, makeNode($2->token));
        addNode(&$$, $4);
        node* type_node = makeNode("RET");
        addNode(&type_node, $7);
        addNode(&$$, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&$$, body_node);
    }

procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        $$ = makeNode("FUNC");
        addNode(&$$, makeNode($2->token));
        addNode(&$$, $4);
        node* type_node = makeNode("RET VOID");
        addNode(&$$, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&$$, body_node);
    }

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
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$,$1);
    }
    | args_list COMMA id
    {
        addNode(&$$,$3);
    }

// Body
body: 
    functions body_after_functions_declared
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
        addNode(&$$, $2);
    }
    | body_after_functions_declared
    {
        $$ = $1;
    }

body_after_functions_declared:
    variable_declarations body_after_delarations
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$,$1);
        addNode(&$$,$2);
    }

body_after_delarations: 
    statements
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
    }
    | body_after_delarations statements
    {
       addNode(&$$, $2);
    }
    | { $$ = makeNode(EMPTY_STRING); };

// Statements
statements:
    assignment_statement SEMICOLON { $$ = $1;}
    | functions_call_statement { $$ = $1; }
    | if_statement { $$ = $1; }
    | if_else_statement { $$ = $1; }
    | while_statement { $$ = $1; }
    | do_while_statement { $$ = $1; }
    | for_statement { $$ = $1; }
    | code_block_statement { $$ = $1; }
    | return_statement { $$ = $1; }
    ;

assignment_statement: 
    lhs ASSIGNMENT expression 
    {
        $$ = makeNode("=");
        addNode(& $$, $1);
        addNode(& $$, $3);
    }

lhs: 
    id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS
    {
        temp_node = makeNode(EMPTY_STRING); 
        addNode(&temp_node, $1); 
        node* lenght_node = makeNode("INDEX");
        addNode(&lenght_node, $3);
        addNode(&$$, lenght_node);
    }
    | id 
    {
        $$ = $1;
    }
    | MULTIPLY id
    {
        $$ = makeNode("*");
        addNode(&$$,$2);
    }

functions_call_statement: 
    id START_ROUND_BRACKETS functions_args END_ROUND_BRACKETS SEMICOLON
    {
        $$ = makeNode("FUNC-CALL");
        addNode(&$$, $1);
        addNode(&$$, $3);
    }

functions_args:
    expression 
    {
        $$ = makeNode("ARGS");
        addNode(&$$, $1);
    } 
    | functions_args COMMA expression
    {
        addNode(&$$, $3);
    }
    |
    {
        $$ = makeNode("ARGS NONE");
    }


if_statement: 
    IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements
    {
        $$ = makeNode("IF");
        addNode(&$$, $3);
        addNode(&$$, $5);
    }

if_else_statement:
    IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements
    {
        $$ = makeNode("IF-ELSE");
        addNode(&$$, $3);
        addNode(&$$, $5);
        addNode(&$$, $7);
    }

while_statement: 
    WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements
    {
        $$ = makeNode("WHILE");
        addNode(&$$, $3);
        addNode(&$$, $5);
    }

do_while_statement: 
    DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON
    {
        $$ = makeNode("DO-WHILE");
        addNode(&$$, $2);
        addNode(&$$, $5);
    }

for_statement:
    FOR START_ROUND_BRACKETS assignment_statement SEMICOLON expression SEMICOLON assignment_statement END_ROUND_BRACKETS statements
    {
        $$ = makeNode("FOR");
        addNode(&$$, $3);
        addNode(&$$, $5);
        addNode(&$$, $7);
        addNode(&$$, $9);
    }

code_block_statement:
    START_CURLY_BRACKETS body_after_functions_declared END_CURLY_BRACKETS
    {
        $$ = makeNode("BLOCK");
        addNode(&$$, $2);
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
    | CHAR_POINTER { $$ = makeNode("CHAR*"); }
    | REAL_POINTER { $$ = makeNode("REAL*"); }
    | INT_POINTER { $$ = makeNode("INT*"); }
    ;

variable_declarations:
    variable_declare
    {
        $$ = makeNode("VAR");
        addNode(&$$, $1);
    }
    | variable_declarations variable_declare
    {
        addNode(&$$, $2);
    }
    | { $$ = makeNode(EMPTY_STRING); };

variable_declare:
    VAR variable_list COLON type SEMICOLON
    {
        addNode(&$4, $2);
        $$ = $4;
    }  
    | STRING string_list SEMICOLON
    {
        node* string_node = makeNode("STRING");
        addNode(&string_node,$2);
        $$ = string_node;
    }

// Variable Delarations 
variable_list: 
    variable_list_helper
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
    }
    | variable_list COMMA variable_list_helper
    {
        addNode(&$$, $3);
    }

variable_list_helper:
    id
    {
        temp_node = makeNode(EMPTY_STRING); 
        addNode(&temp_node, $1);
    }
    | id ASSIGNMENT literal_lexemes
    {
        // Creating the ASSIGNMENT node
        $$ = makeNode("=");
        addNode(&$$, $1);
        addNode(&$$, $3);
    }

// Strings Delarations
string_list:
    string_list_helper
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
    }
    | string_list COMMA string_list_helper
    {
        addNode(&$$, $3);
    }

string_list_helper:
    id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS
    {
        temp_node = makeNode(EMPTY_STRING); 
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
    expression AND expression{ $$ = makeNode("&&"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression DIVIDE expression{ $$ = makeNode("/"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression EQUALS expression{ $$ = makeNode("=="); addNode(&$$,$1); addNode(&$$,$3); }
    | expression GREATER_THAN expression{ $$ = makeNode(">"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression GREATER_EQUALS expression{ $$ = makeNode(">="); addNode(&$$,$1); addNode(&$$,$3); }
    | expression LOWER_THAN expression{ $$ = makeNode("<"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression LOWER_EQUALS expression { $$ = makeNode("<="); addNode(&$$,$1); addNode(&$$,$3); }
    | expression SUBSTRACT expression { $$ = makeNode("-"); addNode(&$$,$1); addNode(&$$,$3); }
    | NOT expression { $$ = makeNode("!"); addNode(&$$,$2); }
    | expression NOT_EQUALS expression { $$ = makeNode("!="); addNode(&$$,$1); addNode(&$$,$3); }
    | expression OR expression { $$ = makeNode("||"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression ADD expression { $$ = makeNode("+"); addNode(&$$,$1); addNode(&$$,$3); }
    | expression MULTIPLY expression { $$ = makeNode("*"); addNode(&$$,$1); addNode(&$$,$3); }
    | SUBSTRACT expression { $$ = makeNode("-"); addNode(&$$,$2); }
    | START_ROUND_BRACKETS expression END_ROUND_BRACKETS { $$ = $2; }
    | MULTIPLY expression { $$ = makeNode("*"); addNode(&$$,$2); }
    | ADDRESS lhs { $$ = makeNode("&"); addNode(&$$,$2); }
    | VERTICAL_BAR id VERTICAL_BAR { $$ = makeNode("LENGTH OF"); addNode(&$$,$2); }
    | id START_ROUND_BRACKETS functions_args END_ROUND_BRACKETS
    {
        $$ = makeNode("FUNC-CALL");
        addNode(&$$, $1);
        addNode(&$$, $3);
    }
    | literal_lexemes { $$ = $1;}
    | lhs { $$ = $1; }
    ;

literal_lexemes:
    bool__literal { $$ = $1; }
    | CHAR_LITERAL { $$ = makeNode(yytext); $$->type = "CHAR";}
    | integer_literal { $$ = $1;}
    | REAL_LITERAL { $$ = makeNode(yytext); $$->type = "REAL"; }
    | STRING_LITERAL { $$ = makeNode(yytext); $$->type = "STRING"; }
    | NULL_TOKEN { $$ = makeNode(yytext); $$->type = "NULL"; }
    | id { $$ = $1; }
    ;

bool__literal:
    FALSE { $$ = makeNode("false"); $$->type = "BOOL"; }
    | TRUE { $$ = makeNode("true"); $$->type = "BOOL"; }
    ;

integer_literal:
    INTEGER_LITERAL { $$ = makeNode(yytext); $$->type = "INT"; }
    | INTEGER_LITERAL_HEX { $$ = makeNode(yytext); $$->type = "INT_HEX"; }
    ;

id: 
    IDENTIFIER { $$ = makeNode(yytext); $$->type = "ID";};


%%

#include "lex.yy.c"
int main()
{
    return yyparse();
}

int yyerror(char* error) 
{
    printf("%s in line:%d does not accept %s\n", error,yylineno, yytext);
    printf("your error pisher!\n");
    return 0;
}
