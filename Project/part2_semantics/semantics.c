// Includes
#include "semantics_structs.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
// Part2 - Semantic Analysis
void semanticAnalysis(node* root);
void semanticAnalysisRecognizeScope(node* root, Scope* curr_scope);
void pushSymbols(node* decleration);
void pushVariablesToSymbolTable(char* type, node** vars, int size);
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

// Global Variables
Scope* head = NULL; // The head of the scopes list
Scope* currScope = NULL; // The current scope
int isError = 0; // The number of errors in the code

void semanticAnalysis(node* root)
{
    printf("Semantic Analysis:\n");
	semanticAnalysisRecognizeScope(root, head);
    print_scopes(head);

    if (isError)
    {
		printf("%d Errors found\n", isError);
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
        currScope = curr_scope;
        if(strcmp(root->token, "") != 0)
        {
            if(!strcmp(root->token, "VAR"))
            {
                pushSymbols(root);
            }
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
}

/* given node with sons, the function will insert 
    all of them to the curr scope symbol-table */
void pushSymbols(node* decleration)
{
	for(int i = 0; i<decleration->count; i++)
    {
		pushVariablesToSymbolTable(decleration->nodes[i]->token, decleration->nodes[i]->nodes[0]->nodes, decleration->nodes[i]->nodes[0]->count);
	}
}

void pushVariablesToSymbolTable(char* type, node** vars, int size)
{
    for(int i = 0; i < size; i++)
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
	push_symbol_record_to_current_scope(newSymbol, &currScope);
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
        printf("id: %s, Type: %s, data: %s\n", current->id, current->type, current->data);
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
