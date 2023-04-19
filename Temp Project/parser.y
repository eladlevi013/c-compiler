%{
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
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
void printtree(node *tree, int tab);
#define YYSTYPE struct node*
%}

%token NUM PLUS MINUS
%left PLUS MINUS

%%
s: exp { printf("OK\n"); printtree($1, 0); }
exp: exp PLUS exp { $$ = mknode("+",$1,$3); }
| exp MINUS exp { $$ = mknode("-",$1,$3); }
| NUM { $$ = mknode(yytext,NULL,NULL); };
%%

void printtree(node* tree, int tab) {
	int i;
	char* token = tree->token;
	
	if(tree->left)
		printtree(tree->left, tab + 1);

	if (*token) {
		for (i = 0; i < tab; i++) {
			printf("\t");
		}
		printf("(%s\n", token);
	}
	else
		tab -= 1;

	if(tree->right)
		printtree(tree->right, tab + 1);

	for (i = 0; i < tab; i++) {
		printf("\t");
	}
	if (*token)
		printf(")\n");
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