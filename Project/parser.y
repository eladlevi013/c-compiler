%{
#include "helpers.c"  
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

// Function declarations
int yylex(void);
int yyerror(char* error);

// Variables
char *yytext;
node *temp_node = NULL;
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

%right ASSIGNMENT NOT SEMICOLON

%left AND OR
%left EQUAL GREATER_THAN GREATER_EQUALS LOWER_THAN LOWER_EQUALS NOT_EQUALS 
%left SUBSTRACT ADD
%left MULTIPLY DIVIDE 
%%

s: code { printTree($1, 0,0); };  

code: functions { $$ = $1; }

function_procedure: function | procedure 

functions: 
    function_procedure
    {
        $$ = makeNode("CODE");
        addNode(&$$, $1);
    }
    | functions function_procedure
    {
        addNode(&$$, $2);
    }

function:
    FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNC");
        addNode(&func_node, makeNode($2->token));
        addNode(&func_node, $4);
        node* type_node = makeNode("RET");
        addNode(&type_node, $7);
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
    }

procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS
    {
        node* func_node = makeNode("FUNC");
        addNode(&func_node, makeNode($2->token));
        addNode(&func_node, $4);
        node* type_node = makeNode("RET VOID");
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, $9);
        addNode(&func_node, body_node);
        $$ = func_node;
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
    lhs ASSIGNMENT expression 
    {
        node *assignment_node = makeNode("=");
        addNode(&assignment_node, $1);
        addNode(&assignment_node, $3);
        $$ = assignment_node;

    }
    | lhs ASSIGNMENT STRING_LITERAL
    {
        node* assignment_node = makeNode("=");
        addNode(&assignment_node,$1);
        addNode(&assignment_node,makeNode("STRING"));
        $$ = assignment_node; 
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

function_call_statement: 
    lhs ASSIGNMENT id START_ROUND_BRACKETS function_parms END_ROUND_BRACKETS SEMICOLON
    {
        node* function_call_node = makeNode("FUNC-CALL");
        addNode(&function_call_node, $1);
        addNode(&function_call_node, makeNode($2->token));
        node* args_node = makeNode("ARGS");
        addNode(&args_node, $5);
        addNode(&function_call_node, args_node);
        $$ = function_call_node;
    }
    | lhs ASSIGNMENT id START_ROUND_BRACKETS END_ROUND_BRACKETS SEMICOLON
    {
        node* function_call_node = makeNode("FUNC-CALL");
        addNode(&function_call_node, $1);
        addNode(&function_call_node, makeNode($2->token));
        node* args_node = makeNode("ARGS NONE");
        addNode(&function_call_node, args_node);
        $$ = function_call_node;
    }

function_parms:
    expression 
    {
        $$ = makeNode(EMPTY_STRING);
        addNode(&$$, $1);
    } 
    | function_parms COMMA expression
    {
        addNode(&$$, $3);
    }


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
    FOR START_ROUND_BRACKETS assignment_statement SEMICOLON expression SEMICOLON assignment_statement END_ROUND_BRACKETS statements
    {
        node* for_node = makeNode("FOR");
        addNode(&for_node, $3);
        addNode(&for_node, $5);
        addNode(&for_node, $7);
        addNode(&for_node, $9);
        $$ = for_node;
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
    | { $$=  makeNode(EMPTY_STRING); };

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
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, $1);
        addNode(&temp_assinment_node, $3);
        $$ = temp_assinment_node;
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
    | START_ROUND_BRACKETS expression END_ROUND_BRACKETS { $$ = $2; }
    | ADDRESS lhs { $$ = makeNode("&"); addNode(&$$,$2); }
    | literal_lexemes { $$ = $1;}
    ;

literal_lexemes: 
    bool__literal { $$ = $1; }
    | CHAR_LITERAL { $$ = makeNode(yytext);}
    | integer_literal { $$ = $1;}
    | REAL_LITERAL { $$ = makeNode(yytext); }
    | STRING_LITERAL { $$ = makeNode(yytext); }
    | NULL_TOKEN { $$ = makeNode(yytext); }
    | id { $$ = $1; }
    ;

bool__literal:
    FALSE { $$ = makeNode("false");}
    | TRUE { $$ = makeNode("true");}
    ;

integer_literal: 
    INTEGER_LITERAL { $$ = makeNode(yytext);}
    | INTEGER_LITERAL_HEX { $$ = makeNode(yytext);}
    ;

id: 
    IDENTIFIER { $$ = makeNode(yytext);};


%%

#include "lex.yy.c"
int main()
{
    return yyparse();
}

int yyerror(char* error) 
{
    //fprintf(stderr, "%s at line:%d\nParser does not expect %s\n", error, yylineno+1,yytext);
   printf("YOUR ERROR pisher!\n");
   return 0; 
}
