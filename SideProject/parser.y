%{
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int yyerror();
int yylex(void);
int i;
%}

%union {
  char *s;
  struct node *n;
};

%token<s> EXP

%{
  struct node {
    char *value;
    struct node *left;
    struct node *right;
  };
%}

%type<n> s

%%

s: EXP {
  struct node *node = (struct node*) malloc(sizeof(struct node));
  node->value = $1;
  node->left = NULL;
  node->right = NULL;
  $$ = node;
}

%%
#include"lex.yy.c"

int main()
{
  yyparse();
  return 0;
}

int yyerror()
{
  printf("MY ERROR\n");
  return 0;
}
