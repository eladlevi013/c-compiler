#include <stddef.h>
#include <ctype.h>

// Part3 - 3AC
void addVar(node* node, char* var);
void freshVar(node* node);
char* freshLabel();
void addCode(node* node, char* code);

int var = 0;
int label = 1;

// void tac_gen(node* root)
// {
//     printf("tac_gen\n");
// }
// void addVar(node* node, char* var){
// 	node->var = strdup(var);
// }

// void freshVar(node* node){
// 	char new[10];
// 	sprintf(new ,"t%d", var++);
// 	node->var = strdup(new);
// }

// char* freshLabel(){
// 	char new[10] = "";
// 	sprintf(new ,"L%d", label++);
// 	char* L = strdup(new);
// 	return L;
// }

// void addCode(node* node, char* code){
// 	char buffer[10000] = "";
// 	if (!strcmp(node->token, "MAIN")){
// 		sprintf(buffer, "%s", "main:\n\tBeginFunc\n");
// 		node->code = strdup(buffer);
// 	}

// 	if (!strcmp(node->token, "FUNCTION")){
// 		sprintf(buffer, "%s:\n%s", node->nodes[0]->token,"\tBeginFunc\n");
// 		node->code = strdup(buffer);
// 	}

// 	if (node->count > 0){
// 		for (int i = 0; i< node->count; i++){
// 			if (strcmp(node->nodes[i]->code,"")){
// 				sprintf(buffer + strlen(buffer), "%s", node->nodes[i]->code);
// 			}
// 		}
// 	}
// 	sprintf(buffer + strlen(buffer), "%s", code);
// 	node->code = strdup(buffer);

// 	if (!strcmp(node->token, "MAIN") || !strcmp(node->token, "FUNCTION")){
// 		sprintf(buffer + strlen(buffer), "\t%s", "EndFunc\n\n");
// 		node->code = strdup(buffer);
// 	}
// }

