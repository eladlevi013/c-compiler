
// Part2 - 3AC
void addVar(node* node, char* var);
void freshVar(node* node);
char* freshLabel();

// void tac_gen(node* root)
// {
//     printf("tac_gen\n");
// }
void addVar(node* node, char* var){
	node->var = strdup(var);
}

void freshVar(node* node){
	char new[10];
	sprintf(new ,"t%d", var++);
	node->var = strdup(new);
}

char* freshLabel(){
	char new[10] = "";
	sprintf(new ,"L%d", label++);
	char* L = strdup(new);
	return L;
}
