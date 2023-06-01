// Part3 - 3AC
int var = 0;
int label = 1;



void tac_gen(node* root) {
    int havePlusChild=0,recLeft=0,recRight=0;
    if (root == NULL)
        return;
    

   
    if (strcmp(root->token, "+") == 0|| strcmp(root->token, "-") == 0 ) {
        havePlusChild=1;
        
        if (root->count>0 &&(!strcmp(root->nodes[0]->token, "+") || !strcmp(root->nodes[0]->token, "-") ))
        {
            recLeft=1;
            tac_gen(root->nodes[0]);
        }

        if (root->count>1 && (!strcmp(root->nodes[1]->token, "+") || !strcmp(root->nodes[1]->token, "-")))
        {
            recRight=1;
            tac_gen(root->nodes[1]);
        }
        if(recLeft==1)
            printf("_t%d = _t%d %s %s\n",var ,var-1,root->token, root->nodes[1]->token );
        else if(recRight==1)
            printf("_t%d = %s %s _t%d\n", var, root->nodes[0]->token,root->token, var-1);
        else
            printf("_t%d = %s %s %s\n", var, root->nodes[0]->token,root->token, root->nodes[1]->token);

        var++;
    }
    

    
    if(havePlusChild==0)
    {
        for (int i = 0; i < root->count; i++)
        {
            tac_gen(root->nodes[i]);
        }
    }
  
}