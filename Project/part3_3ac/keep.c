void getExpression(node* root)
{
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

void ass(node* root) {
    if (root == NULL)
        return;
    
    // Generate TAC for the current node
    if (strcmp(root->token, "ASSIGNMENT") == 0) {
        printf("%s = %s\n", root->nodes[0]->token, root->nodes[1]->token);
    }
    
    // Recursively generate TAC for child nodes
    for (int i = 0; i < root->count; i++) {
        ass(root->nodes[i]);
    }
}
