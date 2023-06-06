// Part3 - 3AC
int var = 0;
int label = 1;

void getBool(node* root);
void short_circuit_evaluation(node* root,int if_label,int end_label);

void tac_gen(node* root) 
{
    //printf("%s\n",root->token);
    int avoid_rec = 0;

    if (root == NULL)
    {
        return;
    }
    

    if (strcmp(root->token, "FUNC") == 0) 
    {
        avoid_rec = 1;
        printf("%s:\n", root->nodes[0]->token);  // Print the function name
        printf("\tBeginFunc\n");
        tac_gen(root->nodes[3]);  // Generate TAC for the function body
        printf("\tEndFunc\n");
    } 
    else if(strcmp(root->token, "FOR") == 0)
    {
        tac_gen(root->nodes[0]);
        // Create labels for the start, end, and increment blocks
        int start_label = label++;
        int end_label = label++;
        int inc_label = label++;

        printf("L%d:\n", start_label);
        // Generate TAC for the condition expression
        getBool(root->nodes[1]);
        printf("\tifZ %s goto L%d\n", root->nodes[1]->token, end_label);  // Modify this line
        // Generate TAC for the statements in the for loop body
        tac_gen(root->nodes[3]);
        printf("L%d:\n", inc_label);
        // Generate TAC for the increment expression
        tac_gen(root->nodes[2]);
        printf("\tgoto L%d\n", start_label);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "WHILE") == 0)
    {
        // Create labels for the start and end blocks
        int start_label = label++;
        int end_label = label++;

        printf("L%d:\n", start_label);
        // Generate TAC for the condition expression
        getBool(root->nodes[0]);
        printf("\tifZ %s goto L%d\n", root->nodes[0]->token, end_label);  // Modify this line
        // Generate TAC for the statements in the while loop body
        tac_gen(root->nodes[1]);
        printf("\tgoto L%d\n", start_label);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "DO-WHILE") == 0) 
    {
        // Create labels for the start and end blocks
        int start_label = label++;
        int end_label = label++;

        printf("L%d:\n", start_label);
        // Generate TAC for the statements in the do-while loop body
        tac_gen(root->nodes[0]);
        printf("L%d:\n", end_label);
        // Generate TAC for the condition expression
        getBool(root->nodes[1]);
        printf("\tif %s goto L%d\n", root->nodes[1]->token, start_label);  // Modify this line
        printf("\tgoto L%d\n", end_label);
    }
    else if (strcmp(root->token, "=") == 0)
    {
        if(root->nodes[1]->count>0 && strcmp (root->nodes[1]->nodes[0]->token,"INDEX") ==0)
        {
            printf("\t_t%d = &%s\n", var, root->nodes[1]->token);
            tac_gen(root->nodes[1]);
            printf("\t%s = _t%d\n", root->nodes[0]->token,var );
        }
        else if(root->nodes[0]->count>0 && strcmp(root->nodes[0]->nodes[0]->token,"INDEX") ==0)
        {   
            printf("\t_t%d = &%s\n", var, root->nodes[0]->token);
            tac_gen(root->nodes[0]);
            printf("\t*_t%d = %s\n", var,root->nodes[1]->token );
        }
        else
        { 
            // Handle assignment statements
            tac_gen(root->nodes[1]);
                
            if(strcmp (root->nodes[1]->token,"&") && strcmp (root->nodes[1]->token,"PTR"))
            {
                printf("\t_t%d = %s\n", var, root->nodes[1]->token);
            }
            if (strcmp(root->nodes[0]->token,"PTR")==0)
            {
                printf("\t*%s = _t%d\n ",root->nodes[0]->nodes[0]->token,var);
            }
            printf("\t%s = _t%d\n", root->nodes[0]->token, var++);
        }
    } 
    else if (strcmp(root->token, "IF") == 0) 
    {     
        avoid_rec=1;
        int end_label = label++;
        int if_label = label++;
        if(strcmp(root->nodes[0]->token, "||") == 0)
        {
            short_circuit_evaluation(root,if_label,end_label);
        }
        else if(strcmp(root->nodes[0]->token, "&&") == 0)
        {
             short_circuit_evaluation(root,if_label,end_label);
        }        
        else
        {
            getBool(root->nodes[0]);
            // Create labels for if and end blocks
            printf("\tif %s goto L%d\n", root->nodes[0]->token, if_label);
            // Generate TAC for the statements in the if block
            printf("\tgoto L%d\n", end_label);
            printf("L%d:\n", if_label);
        }
        tac_gen(root->nodes[1]);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "IF-ELSE") == 0) 
    {
        avoid_rec=1;
        int end_label = label++;
        int else_label = label++;
        int if_label = label++;
        if(strcmp(root->nodes[0]->token, "||") == 0)
        {
            short_circuit_evaluation(root,if_label,else_label);
        }
        else if(strcmp(root->nodes[0]->token, "&&") == 0)
        {
             short_circuit_evaluation(root,if_label,else_label);
        }        
        else
        {
            getBool(root->nodes[0]);
            // Create labels for if and end blocks
            printf("\tif %s goto L%d\n", root->nodes[0]->token, if_label);
            // Generate TAC for the statements in the if block
            printf("\tgoto L%d\n", else_label);
            printf("L%d:\n", if_label);
        }
        tac_gen(root->nodes[1]);
        printf("\tgoto L%d\n", end_label);
        printf("L%d:\n", else_label);
        // Generate TAC for the statements in the else block
        if (root->count > 2)
        {
            tac_gen(root->nodes[2]);
        }
        printf("L%d:\n", end_label);        
    } 
    else if (strcmp(root->token, "RET") == 0)
    {
        // Handle return statements
        tac_gen(root->nodes[0]);
        printf("\t_t%d= %s\n",var, root->nodes[0]->token);
        printf("\tReturn _t%d\n",var++ );
    }  
    else if (strcmp(root->token, "LENGTH") == 0)
    {
        printf("\t_t%d -> sizeof(%s)\n",var++,root->nodes[0]->token);
    }        
    else if (strcmp(root->token, "INDEX") == 0) 
    {
        // Handle accessing array elements
        printf("\t_t%d = _t%d + %s\n",++var,var,root->nodes[0]->token);
        //char* index = root->nodes[1]->token;
    }
    else if (strcmp(root->token, "PTR") == 0)
    {
        // Handle dereferencing a pointer        
        printf("\t_t%d = *%s\n",var++, root->nodes[0]->token);
    }
    else if (strcmp(root->token, "&") == 0) 
    {
        // Handle getting the address of a variable
        printf("\t_t%d = &%s\n", var, root->nodes[0]->token);
    }
    else if (strcmp(root->token, "+") == 0 || strcmp(root->token, "-") == 0
               || strcmp(root->token, "*") == 0 || strcmp(root->token, "/") == 0) 
    {
        int flag=0;
        for(int i=0;i<root->count;i++)
        {
            if(strcmp(root->nodes[i]->token,"PTR")==0)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            // Generate TAC for arithmetic expressions
            tac_gen(root->nodes[0]);
            tac_gen(root->nodes[1]);
            printf("\t_t%d = %s %s _t%d\n", var, root->nodes[0]->token, root->token, var-1);
            strcpy(root->token, "_t");
            sprintf(root->token + 2, "%d", var++);
        }
        else
        {
            // Generate TAC for arithmetic expressions
            tac_gen(root->nodes[0]);
            tac_gen(root->nodes[1]);
            printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
            strcpy(root->token, "_t");
            sprintf(root->token + 2, "%d", var++);
        }
    }
    else if (strcmp(root->token, "VAR") == 0)
    {    
        avoid_rec = 1;
        for(int i=0;i<root->count;i++){
            
            if(strcmp(root->nodes[i]->token,"STRING")==0)
            {
                  printf("\t_t%d = &%s\n",var,root->nodes[i]->nodes[0]->nodes[0]->token);
                  tac_gen(root->nodes[i]->nodes[0]->nodes[0]->nodes[0]);
            }
            else
           {
                tac_gen(root->nodes[i]);
           }
        }
    }
    if (strcmp(root->token, "FUNC-CALL") == 0) 
    {
        // Generate TAC for function call
        char* func_name = root->nodes[0]->token;
        
        // Generate TAC for arguments
        for (int i = 0; i < root->nodes[1]->count; i++)
        {
            tac_gen(root->nodes[1]->nodes[i]);
            printf("\tPushParam _t%d\n", var);
        }
    }
    else 
    {
        if(!avoid_rec)
        {
            // Generate TAC for other nodes recursively
            for (int i = 0; i < root->count; i++)
            {  
                tac_gen(root->nodes[i]);
            }
        }
    }
}

void getBool(node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (strcmp(root->token, "==") == 0 || strcmp(root->token, "!=") == 0 ||
        strcmp(root->token, "<") == 0 || strcmp(root->token, ">") == 0 ||
        strcmp(root->token, "<=") == 0 || strcmp(root->token, ">=") == 0) 
    {
        // Generate TAC for comparison operators
        tac_gen(root->nodes[0]);
        tac_gen(root->nodes[1]);
        printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else if (strcmp(root->token, "||") == 0 ) 
    {
        // Generate TAC for boolean AND and OR operators
        getBool(root->nodes[0]);
        getBool(root->nodes[1]);
        printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else if( strcmp(root->token, "&&") == 0)
    {
        // Generate TAC for boolean AND and OR operators
        getBool(root->nodes[0]);
        getBool(root->nodes[1]);
        printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    }
    else if (strcmp(root->token, "!=") == 0) 
    {
        // Generate TAC for boolean NOT operator
        getBool(root->nodes[0]);
        printf("\t_t%d = %s %s\n", var, root->token, root->nodes[0]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else 
    {
        // Generate TAC for other nodes recursively
        for (int i = 0; i < root->count; i++) 
        {
            getBool(root->nodes[i]);
        }
    }
}

void short_circuit_evaluation(node* root,int if_label,int end_label)
{  
    for(int i=0;i<root->nodes[0]->count;i++)
    {
        if(strcmp(root->nodes[i]->token, "||") == 0)
        {
            if(strcmp(root->nodes[i]->nodes[0]->token, "&&") == 0)
            {
                short_circuit_evaluation(root->nodes[i],if_label+1,end_label);
            }
            for(int j=0;j<root->nodes[i]->count;j++)
            {   
                getBool(root->nodes[i]->nodes[j]);

                printf("\tif _t%d goto L%d\n", var-1, if_label);
                if(j+1==(root->nodes[i]->count))
                {
                    printf("\tgoto L%d\n", end_label);
                }                
            }
            printf("L%d:\n", if_label);
        }
        if(strcmp(root->nodes[i]->token, "&&") == 0)
        {
            if(strcmp(root->nodes[i]->nodes[0]->token, "||") == 0)
            {
                short_circuit_evaluation(root->nodes[i],if_label+1,end_label);
            }
            for(int j=0;j<root->nodes[i]->count;j++)
            {   
                getBool(root->nodes[i]->nodes[j]);

                printf("\tifZ _t%d goto L%d\n", var-1, end_label);
                if(j+1==(root->nodes[i]->count))
                {
                    printf("\tgoto L%d\n", if_label);
                }
            }
            printf("L%d:\n", if_label);
        }
        if_label+=1;
    }
}