// Part3 - 3AC
int var = 0;
int label = 1;

void tac_gen(node* root)
{    
    // if its null return
    if (root == NULL)
        return;

    // logic part
    if(!strcmp("+", root->token))
    {
        printf("_t: %s + %s\n", root->nodes[0]->token, root->nodes[1]->token);
    }

    // iterate over the childs recursively
    for (int i = 0; i < root->count; i++)
    {
        tac_gen(root->nodes[i]);
    }
}