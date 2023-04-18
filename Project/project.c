%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// types
int yylex(void);
int yyerror();
char *yytext;
typedef struct node
{
char *token;
struct node *left;
struct node *right;
} node;

// Functions
node *mknode(char *token, node *left, node *right);
void printtree(node *tree);
#define YYSTYPE struct node*
%}

// Tokens from lex
%token BOOL, CHAR, INT, REAL, STRING, INT_POINTER, CHAR_POINTER, REAL_POINTER, ADDRESS;
%token IF, ELSE, WHILE, DO, FOR;
%token VAR, ARG_ARROW, RETURN, NULL, VOID;
%token AND, ASSIGNMENT, EQUALS, GREATER_THAN, GREATER_EQUALS, LOWER_THAN, LOWER_EQUALS, 
        NOT, NOT_EQUALS, OR;
%token SUBSTRACT, ADD, MULTIPLY, DIVIDE;
%token TRUE, FALSE, CHAR_LITERAL, INTEGER_LITERAL, INTEGER_LITERAL_HEX, REAL_LITERAL
        ,STRING_LITERAL, IDENTIFIER;
%token COMMENT, COLON, SEMICOLON, COMMA, VERTICAL_BAR, START_CURLY_BRACKETS, END_CURLY_BRACKETS, 
        START_ROUND_BRACKETS, END_ROUND_BRACKETS, START_SQUARE_BRACKETS, END_SQUARE_BRACKETS;

%%
// Grammer
s: exp { printf("OK\n"); printtree($1); }
exp: exp PLUS exp { $$ = mknode("+",$1,$3); }
| exp MINUS exp { $$ = mknode("-",$1,$3); }
| NUM { $$ = mknode(yytext,NULL,NULL); };
%%

// Functions
void printtree(node *tree) 
{ 
    printf("%s\n", tree->token); 
    if(tree->left) 
        printtree(tree->left); 
    if(tree->right) 
        printtree(tree->right); 
}

int yyerror() 
{ 
    printf("MY ERROR\n");
    return 0; 
}

node *mknode(char *token,node *left,node *right)
{
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(sizeof(token) + 1);
    strcpy(newstr,token);
    newnode->left = left;
    newnode->right = right;
    newnode->token = newstr;
    return newnode;
}

#include "lex.yy.c"
int main()
{
    return yyparse();
}