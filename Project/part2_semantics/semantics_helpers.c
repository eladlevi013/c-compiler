// Includes
#include "semantics_structs.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Part2 - Semantic Analysis
void semantic_analysis(node* root);
void semantic_analysis_recognize_scope(node* root, Scope* curr_scope);
void push_symbols(node* decleration);
void push_variables_to_symbol_table(char* type, node** vars, int size);
void push_symbol_to_symbol_table(char* id, char* type, char* data);
char* check_expression(node* exp);
int check_function_return_type(node* funcNode,char* type);
Symbol* id_exists_in_previous_scopes(char* id);
Scope* make_new_scope();
void push_scope(Scope** head, Scope* new_scope);
void pop_scope(Scope** head);
int push_symbol_record_to_current_scope(Symbol* symbol, Scope** head);
int symbol_exists_in_scope(Symbol* symbol, Scope* head);
void print_symbol_table(Scope* scope);
void print_scopes(Scope* head);

// Global Variables
Scope* head = NULL;
Scope* currScope = NULL;
int isError = 0;

// Constants
const char* RETURN_TOKEN = "RET";
const char* VOID_TOKEN = "VOID";
const char* CODE_TOKEN = "CODE";
const char* MAIN_TOKEN = "MAIN";
const char* FUNC_TOKEN = "FUNC";
const char* IF_TOKEN = "IF";
const char* IF_ELSE_TOKEN = "IF-ELSE";
const char* WHILE_TOKEN = "WHILE";
const char* DO_WHILE_TOKEN = "DO-WHILE";
const char* BOOL_TOKEN = "BOOL";
const char* BLOCK_TOKEN = "BLOCK";
const char* VAR_TOKEN = "VAR";
const char* FUNC_CALL_TOKEN = "FUNC-CALL";
const char* STRING_TOKEN = "STRING";

void semantic_analysis(node* root)
{
    printf("Semantic Analysis:\n");
	semantic_analysis_recognize_scope(root, head);
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

void semantic_analysis_recognize_scope(node* root, Scope* curr_scope)
{
    if(root == NULL)
    {
        return;
    }
    else if(!strcmp(root->token, CODE_TOKEN))
    {
        curr_scope = make_new_scope();
    }
    else if(!strcmp(root->token, MAIN_TOKEN))
    {
        Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
        new_symbol->id = (char*)malloc(sizeof(char) * 5);
        strcpy(new_symbol->id, "main");
        new_symbol->type = (char*)malloc(sizeof(char) * 5);
        strcpy(new_symbol->type, MAIN_TOKEN);
        new_symbol->data = (char*)malloc(sizeof(char) * 5);
        strcpy(new_symbol->data, VOID_TOKEN);
        new_symbol->next = NULL;
        push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        curr_scope = make_new_scope();
    }`
    else if(!strcmp(root->token, FUNC_TOKEN))
    {
        Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
        new_symbol->id = root->nodes[0]->token;
        new_symbol->type = FUNC_TOKEN;
        if(root->nodes[2]->count == 0)
        {
            new_symbol->data = VOID_TOKEN;
        }
        else
        {
            new_symbol->data = root->nodes[2]->nodes[0]->token;
        }
        new_symbol->next = NULL;
        if(strcmp(new_symbol->data, STRING_TOKEN) == 0)
        {
            isError++;
            printf("Function [%s] cannot return type STRING\n", new_symbol->id);
        }
        else
        {
            int ans = check_function_return_type(root->nodes[3], new_symbol->data);
            printf("\n%d\n",ans);
            if (!strcmp(new_symbol->data, VOID_TOKEN) && ans == 1)
            {
                isError++;
                printf ("Void function (%s) cannot return value\n",new_symbol->id);
            }
            else if(strcmp(new_symbol->data, VOID_TOKEN) && ans == 0)
            {
                isError++;
                printf ("Function (%s) return invalid value\n" ,new_symbol->id);
            }
        }

        push_symbol_record_to_current_scope(new_symbol, &curr_scope);
        curr_scope = make_new_scope();
        currScope = curr_scope;

        // add params of the function to the new scope:
        push_symbols(root->nodes[1]);
    }
    else if(!strcmp(root->token, IF_TOKEN) || !strcmp(root->token, IF_ELSE_TOKEN) 
      || !strcmp(root->token, WHILE_TOKEN) || !strcmp(root->token, DO_WHILE_TOKEN))
    {
        char* exp = check_expression(root->nodes[0]);
        if(strcmp(BOOL_TOKEN, exp))
        {
            isError++;
            if(!strcmp(root->token, IF_TOKEN))
            {
                printf("IF-condition must return type BOOL\n");
            }
            else if(!strcmp(root->token, IF_ELSE_TOKEN))
            {
                printf("IF-ELSE-condition must return type BOOL\n");
            }
            else if(!strcmp(root->token, WHILE_TOKEN))
            {
                printf("WHILE-condition must return type BOOL\n");
            }
            else if(!strcmp(root->token, DO_WHILE_TOKEN))
            {
                printf("DO-WHILE-condition must return type BOOL\n");
            }
        }
    }
    else if(!strcmp(root->token, BLOCK_TOKEN))
    {
        curr_scope = make_new_scope();
    }
    else
    {
        currScope = curr_scope;
        if(strcmp(root->token, "") != 0)
        {
            if(!strcmp(root->token, VAR_TOKEN))
            {
                push_symbols(root);
            }
            if(strcmp(root->token, FUNC_CALL_TOKEN))
            {
                
            }
        }
    }

    // iterating over the children of the current node
    for (int i = 0; i < root->count; i++)
    {
        semantic_analysis_recognize_scope(root->nodes[i], curr_scope);
    }
}

/* by given root of VAR, we'll iterate over it while calling the push_varaibles_to_symbol_table 
    that takes care of inserting all variables under data_type for example a,b,c:int; */
void push_symbols(node* decleration)
{
	for(int i = 0; i<decleration->count; i++)
    {
		push_variables_to_symbol_table(decleration->nodes[i]->token,
                                        decleration->nodes[i]->nodes[0]->nodes,
                                        decleration->nodes[i]->nodes[0]->count);
	}
}

/* inserting variables to symbol table(usually sons of VAR/DATA_TYPE) */
void push_variables_to_symbol_table(char* type, node** vars, int size)
{
    for(int i = 0; i < size; i++)
    {
		if (strcmp(vars[i]->token, "="))
        {
			push_symbol_to_symbol_table(vars[i]->token, type, NULL);
        }
		else
        {
			char* exp = check_expression(vars[i]->nodes[1]);
			if (!strcmp(type,exp))
            {
				push_symbol_to_symbol_table(vars[i]->nodes[0]->token, type, vars[i]->nodes[1]->token);
            }
            else 
            {
				isError++;
				printf("Assignment Error mismatch: can not assign %s to %s\n", exp, type);
			}	
		}
	}
}

char* check_expression(node* exp)
{
    if (exp->type != NULL && !strcmp(exp->type, "ID"))
    {
        Symbol* node = id_exists_in_previous_scopes(exp->token);
        //find the id in scope => like scope search and get the id recognize
		if(node != NULL)
        {
			if(!strcmp(node->type, "STRING") && exp->count > 0)
            {
				char* indexType = check_expression(exp->nodes[0]->nodes[0]);
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
        left = check_expression(exp->nodes[0]);
        right = check_expression(exp->nodes[1]);
		if (!strcmp(left, "NULL") || !strcmp(right,"NULL"))
        {
			return "NULL";
        }
        if (!strcmp(left,"INT") && !strcmp(right,"INT"))
        {
			return "INT";
        }
		else if ((!strcmp(left,"REAL") && !strcmp(right,"REAL"))
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
			printf("Can't perform [%s] between [%s] and [%s] - (%s %s %s)\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,"&&")||!strcmp(exp->token,"||"))
    {
        char* left, *right;
        left = check_expression(exp->nodes[0]);
        right = check_expression(exp->nodes[1]);
        if(!strcmp(left,"BOOL") && !strcmp(right,"BOOL"))
        {
            return "BOOL";
        }
        else 
        {
            isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - (%s %s %s)\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,">")||!strcmp(exp->token,"<")||!strcmp(exp->token,">=")||!strcmp(exp->token,"<="))
    {
        char* left, *right;
        left = check_expression(exp->nodes[0]);
        right = check_expression(exp->nodes[1]);
        if((!strcmp(left,"INT") && !strcmp(right,"INT")) || (!strcmp(left,"REAL") && !strcmp(right,"REAL")))
        {
            return "BOOL";
        }
		else
        {
			isError+=1;
			printf("Can't perform [%s] between [%s] and [%s] - (%s %s %s)\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if(!strcmp(exp->token,"==")||!strcmp(exp->token,"!="))
    {
        char* left, *right;
        left = check_expression(exp->nodes[0]);
        right = check_expression(exp->nodes[1]);
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
			printf("Can't perform [%s] between [%s] and [%s] - (%s %s %s)\n", exp->token, left, right,exp->nodes[0]->token, exp->token, exp->nodes[1]->token);
		}
	}
    else if (!strcmp(exp->token,"LENGTH OF"))
    {
		char* expression;
        expression = check_expression(exp->nodes[0]);
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
        expression = check_expression(exp->nodes[0]);
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
        expression = check_expression(exp->nodes[0]);
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
        expression = check_expression(exp->nodes[0]);
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

/* checking whether function return type, matching its return statement
    while returning 1 if its valid, and 0 otherwise */
int check_function_return_type(node* funcNode, char* type)
{
    if (!strcmp(funcNode->token, RETURN_TOKEN))
    {
        // IF VOID AND HAVE RETURN STATMENTS
        if(!strcmp(type, VOID_TOKEN))
        {
            return 1;
        }

        char* exp = check_expression(funcNode->nodes[0]);
        if (strcmp(exp, type) == 0)
        {
            return 1;
        }
    }
    
    // Flag to track if a matching return statement is found
    int found = 0;
    for (int i = 0; i < funcNode->count && !found; i++)
    {
        found = check_function_return_type(funcNode->nodes[i], type);
    }

    return found;
}

/* making new scope while inserting to scopes_list */
Scope* make_new_scope()
{
    Scope* new_scope = (Scope*)malloc(sizeof(Scope));
    new_scope->symbolTable = NULL; 
    new_scope->nextScope = NULL;
    push_scope(&head, new_scope);
    return new_scope;
}

/* inserting given scope to start of list */
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

/* removing last inserted scope */
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

/* checks whether symbol exists in given scope */
int symbol_exists_in_scope(Symbol* symbol, Scope* head) {
    if (head == NULL 
        || head->symbolTable == NULL) {
        return 0;
    }

    Symbol* current_symbol = head->symbolTable;
    while (current_symbol != NULL) {
        // Symbol found in scope
        if (strcmp(current_symbol->id, symbol->id) == 0) {
            return 1;
        }
        current_symbol = current_symbol->next;
    }

    // Symbol not found in scope
    return 0;
}

/* searcing for identifier */
Symbol* id_exists_in_previous_scopes(char* id)
{
    Scope* current_scope = head;
    while (current_scope != NULL) {
        Symbol* current_symbol = current_scope->symbolTable;
        while (current_symbol != NULL) {
            if (strcmp(current_symbol->id, id) == 0) {
                return current_symbol;
            }
            current_symbol = current_symbol->next;
        }
        current_scope = current_scope->nextScope;
    }

    return NULL;
}

/* pushing symbols to current scope symbol-table */
int push_symbol_record_to_current_scope(Symbol* symbol, Scope** head) {
    if (*head == NULL) {
        printf("No scope exists\n");
        return 0;
    }

    // detecting re-declaration of identifier
    if (symbol_exists_in_scope(symbol, *head) == 1) {
        // throw error whether it is a function or a variable
        if(!strcmp("FUNC", symbol->type))
        {
            printf("Re-declartion of function (%s)\n", symbol->id);
            isError++;
        }
        else
        {
            printf("Re-declartion of variable (%s)\n", symbol->id);
            isError++;
        }

        return 0;
    }

    /* while knowing its not already declared pushing symbol
        to the symbol table of the current scope */
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

/*  */
void push_symbol_to_symbol_table(char* id, char* type, char* data)
{
	Symbol* newSymbol = (Symbol*) malloc(sizeof(Symbol));
	newSymbol->id = (char*)(malloc (strlen(id) + 1));
	strncpy(newSymbol->id, id, strlen(id)+1);
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

/* Printing symbol table of given scope */
void print_symbol_table(Scope* scope)
{
    Symbol* current = scope->symbolTable;
    while (current != NULL) {
        printf("Id: %s, Type: %s, Data: %s\n", current->id, current->type, current->data);
        current = current->next;
    }
}

/* Printing scopes and symbol table */
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
