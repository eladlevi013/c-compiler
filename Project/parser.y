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
void printArgsList(node** argsList, int argCount);
void addElement(node ***, node *, int);
void printTabs(int tabs);
int printTree_helper(char* token);
void printTree(node* tree, int tab,int print_style);
#define YYSTYPE struct node*
node *temp_node = NULL;

// Consts for printing function
const int DEFAULT_PRINT = 0;
const int ONLY_TOKEN_PRINT = 1;
const int TOKEN_WITH_PARENTHESES_PRINT = 2;
const int PARAMETER_PRINT = 3;

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
    variable_declarations body_after_delarations
    {
        $$ = makeNode("");
        addNode(&$$,$1);
        addNode(&$$,$2);
    }

body_after_delarations: 
    statements
    {
        $$ = makeNode("");
        addNode(&$$, $1);
    }
    | body_after_delarations statements
    {
       addNode(&$$, $2);
    }
    | { $$ = makeNode(""); };

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
        temp_node = makeNode(""); 
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
        $$ = makeNode("");
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
        //ADD
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

bool__literal:
    FALSE { $$ = makeNode("false");}
    | TRUE { $$ = makeNode("true");}
    ;

char_literal:
    CHAR_LITERAL { $$ = makeNode(yytext);}

integer_literal: 
    INTEGER_LITERAL { $$ = makeNode(yytext);}
    | INTEGER_LITERAL_HEX { $$ = makeNode(yytext);}
    ;

real_literal:
    REAL_LITERAL { $$ = makeNode(yytext); }

string_literal: 
    STRING_LITERAL { $$ = makeNode(yytext); }

id: 
    IDENTIFIER { $$ = makeNode(yytext);};

literal_lexemes: 
    bool__literal { $$ = $1; }
    | char_literal { $$ = $1; }
    | integer_literal { $$ = $1;}
    | real_literal { $$ = $1; }
    | string_literal { $$ = $1; }
    | id { $$ = $1; }
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
    | { $$=  makeNode(""); };

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

// Strings Delarations
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

void printTabs(int tabs)
{
    // Generating tabs
    for(int i=0; i<tabs; i++)
    {
        printf("\t");
    }
}

int printTree_helper(char* token)
{
    return (strcmp(token, "RET") == 0 || strcmp(token, "BOOL") == 0 
         || strcmp(token, "CHAR") == 0 || strcmp(token, "INT") == 0
         || strcmp(token, "REAL") == 0 || strcmp(token, "INT_POINTER") == 0
         || strcmp(token, "CHAR_POINTER") == 0 || strcmp(token, "REAL_POINTER") == 0
    );
}

void printTree(node* tree, int tab, int print_style)
 {
    // return if its null
    if(tree == NULL)
        return;

    // print token if valid
    if(strcmp(tree->token, "") != 0)//token != "";
    {
        if(print_style == PARAMETER_PRINT)
        {
            printf(" %s", tree->token);
        }
        else
        {
            printTabs(tab);
            if(printTree_helper(tree->token))
            {
                printf("(%s", tree->token);
            }
            else if(print_style == ONLY_TOKEN_PRINT)
            {
                printf("%s\n", tree->token);
            }
            else if(print_style == TOKEN_WITH_PARENTHESES_PRINT )
            {
                printf("(%s)\n", tree->token);
            }
            else
            {
                printf("(%s\n", tree->token);
            }
        }
    }

    // Iterating over node sons
    for(int i=0; i<tree->count; i++)
    {    
        // token is valid
        if(strcmp(tree->token, "") == 0)
        {
            if(print_style == PARAMETER_PRINT)
            {
                printTree(tree->nodes[i], tab+1, PARAMETER_PRINT);
            }
            else
            {
                printTree(tree->nodes[i], tab, DEFAULT_PRINT);
            }
        }
        else 
        {
            if(strcmp(tree->token, "FUNC") == 0 && i==0)
            {
                printTree(tree->nodes[i], tab + 1, ONLY_TOKEN_PRINT);
            }
            else if(strcmp(tree->token, "FUNC") == 0 && tree->nodes[i]->count == 0)//ARGS NONE
            {
                printTree(tree->nodes[i], tab + 1, TOKEN_WITH_PARENTHESES_PRINT);
            }
            else if(printTree_helper(tree->token))
            {
                printTree(tree->nodes[i], tab + 1, PARAMETER_PRINT);
            }
            else
            {
                printTree(tree->nodes[i], tab + 1, DEFAULT_PRINT);
            }
        }
    }

    // Closing paranthesis
    if(strcmp(tree->token, "") != 0)
    {
        if(printTree_helper(tree->token) && print_style != PARAMETER_PRINT)
        {
            printf(")\n");
        }
        else if(print_style == DEFAULT_PRINT)
        {
            printTabs(tab);
            printf(")\n");
        }
    }
}