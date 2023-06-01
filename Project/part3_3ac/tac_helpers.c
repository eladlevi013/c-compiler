// Part3 - 3AC
int var = 0;
int label = 1;

void tac_gen(node* root) {
    if (root == NULL)
        return;
   
    if (strcmp(root->token, "+") == 0 || strcmp(root->token, "-") == 0 
        || strcmp(root->token, "*") == 0 || strcmp(root->token, "/") == 0) {
        tac_gen(root->nodes[0]);
        tac_gen(root->nodes[1]);
        printf("_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    }

    for (int i = 0; i < root->count; i++) {
        tac_gen(root->nodes[i]);
    }
}