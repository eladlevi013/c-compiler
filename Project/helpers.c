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

/*
    How to use the stackScopes functions for noobies,
    
    // Scope to insert
    Scope* new_scope = (Scope*)malloc(sizeof(Scope));
    new_scope->symbolTable = NULL; new_scope->nextScope = NULL;
    push_scope(&head, new_scope);

    // Creating a new symbol record
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->id = "x";
    new_symbol->type = "int";
    new_symbol->next = NULL;
    push_symbol_record_to_current_scope(new_symbol, &head);

    // Printing the contents of all symbol tables
    print_scopes(head);
*/

// Variables
Scope* head = NULL;
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
    // return if its null
    if(tree == NULL)
        return;

    
    // print token if valid
    if(strcmp(tree->token, EMPTY_STRING) != 0)//token != "";
    {
        if(print_style == PARAMETER_PRINT && printTree_helper(tree->token)==0)
        {
            printf(" %s", tree->token);
        }
        else
        {
            printTabs(tab);
            if(print_style == PARAMETER_PRINT && printTree_helper(tree->token))
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
            else if(strcmp(tree->token, "ARGS")==0 && printTree_helper(tree->nodes[0]->token) || print_style==PARAMETER_PRINT)
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
    if(strcmp(tree->token, EMPTY_STRING) != 0)
    {
        if(printTree_helper(tree->token) && print_style == PARAMETER_PRINT)
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

//PART 2
void semanticAnalysis(node* root)
{
    printf("semanticAnalysis\n");
	semanticAnalysisRecognizeScope(root, head);
    print_scopes(head);
}

void semanticAnalysisRecognizeScope(node* root, Scope* curr_scope)
{
    if(root == NULL)
    {
        return;
    }
    else if (
           !strcmp(root->token, "CODE")
        || !strcmp(root->token, "MAIN")
        || !strcmp(root->token, "FUNC")
        || !strcmp(root->token, "IF")
        || !strcmp(root->token, "IF-ELSE")
        || !strcmp(root->token, "WHILE")
        || !strcmp(root->token, "DO-WHILE")
        || !strcmp(root->token, "FOR")
        || !strcmp(root->token, "BLOCK")
    )
    {
        Scope* new_scope = (Scope*)malloc(sizeof(Scope));
        new_scope->symbolTable = NULL; new_scope->nextScope = NULL;
        push_scope(&head, new_scope);
        curr_scope = new_scope;
    }
    else
    {
        if(strcmp(root->token, "") != 0)
        {
            Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
            new_symbol->id = root->token;
            new_symbol->type = root->token;
            new_symbol->next = NULL;
            push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        }
    }
    
    // recursion of all the nodes
    for (int i = 0; i < root->count; i++) //more brother in the same level
    {
		semanticAnalysisRecognizeScope(root->nodes[i], curr_scope);
	}
}

/*
char* checkExpression(node* exp)
{
    
    if (!strcmp(exp->token,"+")||!strcmp(exp->token,"-")||!strcmp(exp->token,"*")||!strcmp(exp->token,"/")){
		char* left, *right;
        left = checkExpression(exp->nodes[0]);
        right = checkExpression(exp->nodes[1]);
		if (!strcmp(left, "NULL") || !strcmp(right,"NULL"))
        {
			return "NULL";
        }
        if (!strcmp(left,"INT") && !strcmp(right,"INT"))
        {
			return "INT";
        }
		else if (!strcmp(left,"REAL") && !strcmp(right,"REAL"))
        {
			return "REAL";
        }
		else if ((!strcmp(left,"REAL") && !strcmp(right,"INT")) || (!strcmp(left,"INT") && !strcmp(right,"REAL")))
		{
            return "REAL";
        }
		else 
        {
			printf(" Can not perform [%s] between [%s] and [%s] - [%s %s %s]\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}

}
*/


// --------------------------------------------------
//                ~ Semantic Related
// --------------------------------------------------


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
        printf("id: %s, Type: %s\n", current->id, current->type);
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