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
void semanticAnalysisRecognizeScope(node* root, Scope* curr_scope);
void pushSymbols(node* decleration);
void pushNodesToSymbolTable(char* type, node** vars, int size);
void pushSymbolToTable(char* id, char* type, char* data);

void pushScope(Scope** head,node** statements,int statements_size);
Symbol* searchIdInScopes(char* id);
char* checkExpression(node* exp);
void push_scope(Scope** head, Scope* new_scope);
void pop_scope(Scope** head);
int push_symbol_record_to_current_scope(Symbol* symbol, Scope** head);
int symbol_exists_in_scope(Symbol* symbol, Scope* head);
void print_symbol_table(Scope* scope);
void print_scopes(Scope* head);

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
int isError = 0;

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
    printf("semanticAnalysis:\n");
	semanticAnalysisRecognizeScope(root, head);
    print_scopes(head);
    if (isError)
    {
		printf("%d Errors found\n",isError);
    }
	else
    {
		printTree(root, 0,0);
    }
}

void semanticAnalysisRecognizeScope(node* root, Scope* curr_scope)
{
    if(root == NULL)
    {
        return;
    }
    else if (
            !strcmp(root->token, "FUNC")
        || !strcmp(root->token, "CODE")
        || !strcmp(root->token, "MAIN")
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
        if(strcmp(root->token, "") != 0
        && root->type != NULL
        && strcmp(root->type, "ID") == 0)
        {
            Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
            new_symbol->id = root->token;
            new_symbol->type = root->token;
            new_symbol->data = NULL;
            new_symbol->next = NULL;
            push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        }
    }

    // Recursion, the functions are for this scope
    for (int i = 0; i < root->count; i++) //more brother in the same level
    {
        if(!strcmp(root->nodes[i]->token, "FUNC"))
        {
            // if its function, get the function name and put it on the curr scope
            Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
            new_symbol->id = root->nodes[i]->nodes[1]->token;
            new_symbol->type = root->nodes[i]->nodes[0]->token;
            new_symbol->next = NULL;
            push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        }
        else if(!strcmp(root->nodes[i]->token, "MAIN"))
        {
            // if its function, get the function name and put it on the curr scope
            Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
            new_symbol->id = (char*)malloc(sizeof(char) * 5);
            strcpy(new_symbol->id, "main");
            new_symbol->type = (char*)malloc(sizeof(char) * 5);
            strcpy(new_symbol->type, "void");
            new_symbol->next = NULL;
            push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        }
        semanticAnalysisRecognizeScope(root->nodes[i], curr_scope);
    }

    ///eyalon add 
    /*
    if(!strcmp(root->nodes[i]->token, "VAR"))
    {
        pushSymbols(root->nodes[i]);
    }
    */
}

void pushSymbols(node* decleration)
{
	for(int i = 0; i<decleration->count;i++)
    {
		pushNodesToSymbolTable(decleration->nodes[i]->token, decleration->nodes[i]->nodes,decleration->nodes[i]->count);
	}
}

void pushNodesToSymbolTable(char* type, node** vars, int size)
{
    for(int i = 0;i < size; i++)
    {
		if (strcmp(vars[i]->token, "="))
        {
			pushSymbolToTable(vars[i]->token, type, NULL);
        }
		else
        {
			char* exp = checkExpression(vars[i]->nodes[1]);
			if (!strcmp(type,exp))
            {
				pushSymbolToTable(vars[i]->nodes[0]->token, type, vars[i]->nodes[1]->token);
            }
            else 
            {
				isError++;
				printf("Assignment Error mismatch: can not assign %s to %s\n", exp, type);
			}	
		}
	}
}

void pushSymbolToTable(char* id, char* type, char* data)
{
	Symbol* newSymbol = (Symbol*) malloc(sizeof(Symbol));
	newSymbol->id = (char*)(malloc (sizeof(id) + 1));
	strncpy(newSymbol->id, id, sizeof(id)+1);
	if (data != NULL) 
    {
		newSymbol->data = (char*)(malloc (sizeof(data) + 1));
		strncpy(newSymbol->data, data, sizeof(data)+1);
	}
	else
    {
		newSymbol->data = NULL;
    }
    newSymbol->type = (char*)(malloc (sizeof(type) + 1));
	strncpy(newSymbol->type, type, sizeof(type)+1);
	push_symbol_record_to_current_scope(newSymbol, &head);
}

char* checkExpression(node* exp)
{
    if (exp->type != NULL && !strcmp(exp->type, "ID"))
    {
        Symbol* node = searchIdInScopes(exp->token);
        //find the id in scope => like scope search and get the id recognize
		if(node != NULL)
        {
			if(!strcmp(node->type, "STRING") && exp->count > 0)
            {
				char* indexType = checkExpression(exp->nodes[0]->nodes[0]);
				if(strcmp("INT", indexType))
                {
					isError++;
					printf("Size of string must be type INT not %s\n", indexType);
					return "NULL";
				}
			    return "CHAR";
			}
			return node->type;
		}
        else
        {
			isError++;
			printf("Undeclared variable [%s]\n", exp->token);
            return "undefined";
		}
	}
    else if (exp->type != NULL && !strcmp(exp->type, "NULL"))
    {
        return "NULL";
    }
	else if (exp->type != NULL)
    {
        return exp->type;
    }
    if (!strcmp(exp->token,"+")||!strcmp(exp->token,"-")||!strcmp(exp->token,"*")||!strcmp(exp->token,"/"))
    {
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
		else if (!strcmp(left,"REAL") && !strcmp(right,"REAL") 
                || (!strcmp(left,"REAL") && !strcmp(right,"INT")) 
                || (!strcmp(left,"INT") && !strcmp(right,"REAL")))
        {
			return "REAL";
        }
        else if (((!strcmp(left,"INT*") && !strcmp(right,"INT")) || (!strcmp(left,"INT") && !strcmp(right,"INT*"))) && strcmp(exp->token,"*") && strcmp(exp->token,"/"))
        {
			return "INT*";
        }
		else if (((!strcmp(left,"CHAR*") && !strcmp(right,"INT")) || (!strcmp(left,"INT") && !strcmp(right,"CHAR*"))) && strcmp(exp->token,"*") && strcmp(exp->token,"/"))
        {
			return "CHAR*";
        }
		else if (((!strcmp(left,"REAL*") && !strcmp(right,"INT")) || (!strcmp(left,"INT") && !strcmp(right,"REAL*"))) && strcmp(exp->token,"*") && strcmp(exp->token,"/"))
        {
			return "REAL*";
        }
		else 
        {
            isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - [%s %s %s]\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,"&&")||!strcmp(exp->token,"||"))
    {
        char* left, *right;
        left = checkExpression(exp->nodes[0]);
        right = checkExpression(exp->nodes[1]);
        if(!strcmp(left,"BOOL") && !strcmp(right,"BOOL"))
        {
            return "BOOL";
        }
        else 
        {
            isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - [%s %s %s]\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,">")||!strcmp(exp->token,"<")||!strcmp(exp->token,">=")||!strcmp(exp->token,"<="))
    {
        char* left, *right;
        left = checkExpression(exp->nodes[0]);
        right = checkExpression(exp->nodes[1]);
        if((!strcmp(left,"INT") && !strcmp(right,"INT")) || (!strcmp(left,"REAL") && !strcmp(right,"REAL")))
        {
            return "BOOL";
        }
		else
        {
			isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - [%s %s %s]\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,"==")||!strcmp(exp->token,"!="))
    {
        char* left, *right;
        left = checkExpression(exp->nodes[0]);
        right = checkExpression(exp->nodes[1]);
        if(!strcmp(left,"INT")&&!strcmp(right,"INT"))
        {
            return "BOOL";
        }
        else if(!strcmp(left,"BOOL")&&!strcmp(right,"BOOL"))
        {
            return "BOOL";
        }   
        else if(!strcmp(left,"CHAR")&&!strcmp(right,"CHAR"))
        {
            return "BOOL";  
        }
        else if(!strcmp(left,"REAL")&&!strcmp(right,"REAL"))
        {
            return "BOOL";
        }
        else if(!strcmp(left,"INT*")&&!strcmp(right,"INT*"))
        {
            return "BOOL";
        }
        else if(!strcmp(left,"CHAR*")&&!strcmp(right,"CHAR*"))
		{
        	return "BOOL";
        }
        else if(!strcmp(left,"REAL*")&&!strcmp(right,"REAL*"))
		{
            return "BOOL";
		}
        else
        {
            isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - [%s %s %s]\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if (!strcmp(exp->token,"LENGTH OF"))
    {
		char* expression;
        expression = checkExpression(exp->nodes[0]);
		if(!strcmp(expression,"STRING"))
        {
            return "INT";
        }
		else{
			isError++;
			printf("Can't perform || on [%s] - [|%s|]\n",  expression,exp->nodes[0]->token);
		}
	}
    else if(!strcmp(exp->token,"NOT"))
    {
        char* expression;
        expression = checkExpression(exp->nodes[0]);
        if(!strcmp(expression,"BOOL"))
        {
            return "BOOL";
        }
		else
        {
			isError++;
			printf("Can't perform ! on [%s] - [!%s]\n", expression,exp->nodes[0]->token);
		}
	}
    else if (!strcmp(exp->token,"&"))
    {
		char* expression;
        expression = checkExpression(exp->nodes[0]);
		if(!strcmp(expression,"INT"))
        {
            return "INT*";
        }
		else if(!strcmp(expression,"CHAR"))
        {
            return "CHAR*";
        }
		else if(!strcmp(expression,"REAL"))
        {
            return "REAL*";
        }//ADDDDDD STRING[INDEX]
		else
        {
			isError++;
			printf("Can't perform & on [%s] - [&%s]\n",  expression,exp->nodes[0]->token);
		}
    }
	else if(!strcmp(exp->token,"*"))//PTR
    {
        char* expression;
        expression = checkExpression(exp->nodes[0]);
        if(!strcmp(expression,"INT*"))
        {
            return "INT";
        }
		else if(!strcmp(expression,"CHAR*"))
        {
            return "CHAR";
        }
		else if(!strcmp(expression,"REAL*"))
        {
            return "REAL";
        }
		else
        {
			isError++;
			printf("[%s] is not pointer\n",expression);
		}
	}
}


// -------------------------------------------------- //
//                ~ Semantic Related                  //
// -------------------------------------------------- //

void pushScope(Scope** head,node** statements,int statements_size)
{
    
}

Symbol* searchIdInScopes(char* id)
{
    return NULL;
}

void push_scope(Scope** head, Scope* new_scope)
{
    if(*head == NULL)
    {
        *head = new_scope;
        return;
    }
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

int symbol_exists_in_scope(Symbol* symbol, Scope* head) {
    if (head == NULL || head->symbolTable == NULL) {
        return 0;  // No scope or symbol table is empty, so symbol doesn't exist
    }

    Symbol* current_symbol = head->symbolTable;
    while (current_symbol != NULL) {
        if (strcmp(current_symbol->id,symbol->id)==0  ) {
            return 1;  // Symbol found in the scope's symbol table
        }
        current_symbol = current_symbol->next;
    }

    return 0;  // Symbol not found in the scope's symbol table
}

int push_symbol_record_to_current_scope(Symbol* symbol, Scope** head) {
    if (*head == NULL) {
        printf("No scope exists\n");
        return 0;
    }

    if (symbol_exists_in_scope(symbol, *head)==1) {
        
        return 0;
    }

    if ((*head)->symbolTable == NULL) {
        (*head)->symbolTable = symbol;
        return 0;
    } else {
        Symbol* current_symbol = (*head)->symbolTable;
        while (current_symbol->next != NULL) {
            current_symbol = current_symbol->next;
        }
        current_symbol->next = symbol;
        return 1;
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