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

code: functions { $$ = makeNode("CODE"); addNode(&$$, $1); }

functions: function | procedure | statements

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
	args_list
    {
        node* temp = makeNode("ARGS");
        temp->nodes = argsList;
        temp->count = counter_argsList;
        $$ = temp;
        argsList = NULL;
        counter_argsList=0;
    }
	|
    {
        node* temp = makeNode("NO ARGS");
    }

args_list:
    ARG_ARROW parameters_list COLON type
    {
        $4->nodes = parList;
        $4->count = counter_parlist;
        addElement(&argsList, $4, counter_argsList);
        counter_argsList++;
        
        // Resetting
        parList = NULL;
        counter_parlist = 0;
    }
    | args_list SEMICOLON ARG_ARROW parameters_list COLON type
    {
        $6->nodes = parList;
        $6->count = counter_parlist;
        addElement(&argsList, $6, counter_argsList);
        counter_argsList++;

        // Resetting
        parList = NULL;
        counter_parlist = 0;
    }

parameters_list:
    id
    {
        addElement(&parList, $1, counter_parlist);
        counter_parlist++;
    }
    | parameters_list COMMA id
    {
        addElement(&parList, $3, counter_parlist);
        counter_parlist++;
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

// Statements
statements:
    assignment_statement { $$ = $1; printf("ASDASDASD"); } 
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
    lhs ASSIGNMENT IDENTIFIER START_ROUND_BRACKETS function_call_statement1

function_call_statement1: 
    expression function_call_statement2 
    | function_call_statement2

function_call_statement2: 
    COMMA function_call_statement1
    | END_ROUND_BRACKETS SEMICOLON

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
        node* temp = makeNode("RET");
        addNode(&temp, $2);
        $$ = temp;
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
    | CHAR_LITERAL { $$ = $1; }
    | integer_literal { $$ = $1; }
    | REAL_LITERAL { $$ = $1; }
    | STRING_LITERAL { $$ = $1; }
    | id { $$ = $1;}
    ;

variable_declarations: 
    variable_declare
    {
        node* temp = makeNode("VAR");
        temp->nodes = argsList;
        temp->count = counter_argsList;
        $$ = temp;
        argsList = NULL;
        counter_argsList=0;
    }
    | variable_declarations variable_declare
    {
        $$->nodes = argsList;
        $$->count = counter_argsList;
        argsList = NULL;
        counter_argsList=0;
    }

variable_declare:
    VAR variable_list COLON type SEMICOLON
    {
        $3->nodes = varList;
        $3->count = counter_varList;
        addElement(&argsList, $3, counter_argsList);
        counter_argsList++;
        
        // Resetting
        varList = NULL;
        counter_varList = 0;
    }
    | STRING variable_list SEMICOLON
    {
        // node* temp = makeNode("STRING");
        // temp->nodes = argsList;
        // temp->count = counter_argsList;
        // $$ = temp;
        // argsList = NULL;
        // counter_argsList=0;
    }

// Variable Delarations    
variable_list:
    id
    {
        addElement(&varList, $1, counter_varList);
        counter_varList++;
    }
    | id ASSIGNMENT literal_lexemes
    {
        //to check!
        addElement(&varList, $3, counter_varList);
        counter_varList++;
    }
    | variable_list COMMA variable_list
    {
        
    }

// String Delarations 
string_list:
    id START_SQUARE_BRACKETS integer_literal END_SQUARE_BRACKETS  
    | id START_SQUARE_BRACKETS integer_literal END_SQUARE_BRACKETS EQUALS literal_lexemes 
    | string_list COMMA string_list

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
    |   literal_lexemes { $$ = $1; }
          
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
