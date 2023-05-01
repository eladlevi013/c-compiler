// Includes
#include "node.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

// Defines
#define DEFAULT_PRINT 0
#define ONLY_TOKEN_PRINT 1
#define TOKEN_WITH_PARENTHESES_PRINT 2
#define PARAMETER_PRINT 3
#define EMPTY_STRING ""
#define YYSTYPE struct node*

// Signatures
node *makeNode(char* token);
void addNode(node **father, node *descendant);
void printTabs(int tabs);
int printTree_helper(char* token);
void printTree(node* tree, int tab,int print_style);

// Funcs
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

void printTabs(int tabs)
{
    for(int i=0; i<tabs; i++)
    {
        printf("\t");
    }
}

int printTree_helper(char* token)
{
    return (strcmp(token, "RET") == 0 || strcmp(token, "BOOL") == 0 
         || strcmp(token, "CHAR") == 0 || strcmp(token, "INT") == 0
         || strcmp(token, "REAL") == 0 || strcmp(token, "INT*") == 0
         || strcmp(token, "CHAR*") == 0 || strcmp(token, "REAL*") == 0
    );
}

void printTree(node* tree, int tab, int print_style)
{
    int flag=0;
    // return if its null
    if(tree == NULL)
        return;

    
    // print token if valid
    if(strcmp(tree->token, EMPTY_STRING) != 0)//token != "";
    {
        if(strcmp(tree->token, "=")==0 && print_style == PARAMETER_PRINT)
        {
            printf(" %s%s%s", tree->nodes[0]->token,tree->token,tree->nodes[1]->token);
            flag=1;
        }
        else if(print_style == PARAMETER_PRINT)
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

    if(!flag)
    {
        // Iterating over node sons
        for(int i=0; i<tree->count; i++)
        {    
            // token is valid
            if(strcmp(tree->token, EMPTY_STRING) == 0)
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
    }

    // Closing paranthesis
    if(strcmp(tree->token, EMPTY_STRING) != 0)
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
