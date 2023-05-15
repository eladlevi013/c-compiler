// Includes
#include "node.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Defines
#define DEFAULT_PRINT 0
#define ONLY_TOKEN_PRINT 1
#define TOKEN_WITH_PARENTHESES_PRINT 2
#define PARAMETER_PRINT 3
#define EMPTY_STRING ""
#define YYSTYPE struct node*

// Function declarations
//PART1
node *makeNode(char* token);
void addNode(node **father, node *descendant);
void printTabs(int tabs);
int printTree_helper(char* token);
void printTree(node* tree, int tab,int print_style);

//PART2
void semanticAnalysis(node* root);
Scope* head = NULL;

/*
    How to use the stackScopes functions for noobies,
    
    // Scope to insert
    Scope* new_scope = (Scope*)malloc(sizeof(Scope));
    new_scope->symbolTable = NULL; new_scope->nextScope = NULL;
    push_scope(&head, new_scope);

    // Creating a new symbol record
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = "x";
    new_symbol->type = "int";
    new_symbol->next = NULL;
    push_symbol_record_to_current_scope(new_symbol, &head);

    // Printing the contents of all symbol tables
    print_scopes(head);
*/

// Variables
int GlobalScope = 0;

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
    return (strcmp(token, "BOOL") == 0 
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

void semanticAnalysis(node* root)
{
    printf("semanticAnalysis\n");
	
}

void semanticAnalysisRecognizeScope(node* root,int depth_level)
{
    if(root == NULL)
    {
        return;
    }
    else if (!strcmp(root->token, "CODE"))
    {
        pushNewScope();
        depth_level++;
    }
    else if(!strcmp(root->token, "MAIN"))
    {
        pushNewScope();
    }
    else if(!strcmp(root->token,"FUNC"))
    {
        pushNewScope();
    }
    else if (!strcmp(root->token, "IF"))
    {
        pushNewScope();
    }
        else if(!strcmp(root->token,"IF-ELSE"))
    {
        pushNewScope();
    }
    else if (!strcmp(root->token, "WHILE"))
    {
        pushNewScope();
    }
    else if(!strcmp(root->token, "DO-WHILE"))
    {
        pushNewScope();
    }
	else if (!strcmp(root->token, "FOR"))
    {
        pushNewScope();
    }
    else if (!strcmp(root->token, "BLOCK"))
    {
        pushNewScope();
	}
    for (int i = 0; i < root->count; i++)//more brother in the same level
    {
		semanticAnalysisRecognizeScope(root->nodes[i], depth_level);
	}
}

pushNewScope()
{

    makeSymbolTable()
}

makeSymbolTable(node** statements, int size)
{
    for (int i = 0;i < size;i++)
    {
        if(!strcmp(statements[i]->token, "VAR"))
        {
			pushToSymbolTable();
		}
        else if (!strcmp(statements[i]->token, "FUNC"))
        {
			pushToSymbolTable();
        }
        else if (!strcmp(statements[i]->token, "FUNC-CALL"))
        {
		}
        else if(else if(!strcmp(statements[i]->token, "=")))
        {

        }
    }
}

// --------------------------------------------------
//                ~ Semantic Related
// --------------------------------------------------
typedef struct Symbol {
    char* name;
    char* type;
    struct Symbol* next;
} Symbol;

typedef struct Scope {
    Symbol* symbolTable;
    struct Scope* nextScope;
} Scope;

void push_scope(Scope** head, Scope* new_scope)
{
    new_scope->nextScope = *head;
    *head = new_scope;
}

void pop_scope(Scope** head)
{
    if (*head == NULL)
    {
        printf("No scope exists\n");
        return;
    }
    else
    {
        Scope* temp = *head;
        *head = (*head)->nextScope;
        free(temp);
        return;
    }
}

void push_symbol_record_to_current_scope(Symbol* symbol, Scope** head)
{
    if (*head == NULL)
    {
        printf("No scope exists\n");
        return;
    }
    else
    {
        if ((*head)->symbolTable == NULL)
        {
            (*head)->symbolTable = symbol;
            return;
        }
        else
        {
            Symbol* current_symbol = (*head)->symbolTable;
            while (current_symbol->next != NULL) {
                current_symbol = current_symbol->next;
            }
            current_symbol->next = symbol;
            return;
        }
    }
}

void print_symbol_table(Scope* scope)
{
    Symbol* current = scope->symbolTable;
    while (current != NULL) {
        printf("Name: %s, Type: %s\n", current->name, current->type);
        current = current->next;
    }
}

void print_scopes(Scope* head)
{
    Scope* current_scope = head;
    int counter = 1;
    while (current_scope != NULL) {
        printf("Scope %d:\n", counter);
        print_symbol_table(current_scope);
        current_scope = current_scope->nextScope;
        counter++;
    }
}