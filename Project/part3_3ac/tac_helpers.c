#include "../tokers.h"

// Part3 - 3AC
int var = 0;
int label = 1;

int flag=0;

void get_bool(node* root);
void short_circuit_evaluation(node* root, int if_label, int end_label, int flag);

void tac_gen(node* root)
{
    int avoid_rec = 0;

    if (root == NULL)
    {
        return;
    }

    if (strcmp(root->token, FUNC_TOKEN) == 0)
    {
        avoid_rec = 1;
        printf("%s:\n", root->nodes[0]->token);  // Print the function name
        printf("\tBeginFunc\n");
        tac_gen(root->nodes[3]);  // Generate TAC for the function body
        printf("\tEndFunc\n");
    }
    else if(strcmp(root->token, FOR_TOKEN) == 0)
    {
        avoid_rec = 1;
        int end_label = label++;
        int inc_label = label++;
        int start_label = label++;

        tac_gen(root->nodes[0]);
        printf("L%d:\n", start_label++);

        if(strcmp(root->nodes[1]->token, OR_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,inc_label,2);
        }
        else if(strcmp(root->nodes[1]->token, AND_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,end_label,0);
        }
        else
        {
            get_bool(root->nodes[1]);
            printf("\tifZ _t%d goto L%d\n", var-1, end_label);
        }
        
        tac_gen(root->nodes[2]);
        printf("L%d:\n", inc_label);

        tac_gen(root->nodes[3]);
        printf("\tgoto L%d\n", start_label-1);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, WHILE_TOKEN) == 0)
    {
        avoid_rec=1;
        int end_label = label++;
        int start_label = label++;

        printf("L%d:\n", start_label++);
        // Generate TAC for the condition expression
        if(strcmp(root->nodes[0]->token, OR_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,end_label,2);
        }
        else if(strcmp(root->nodes[0]->token, AND_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,end_label,0);
        }
        else
        {
            get_bool(root->nodes[0]);
            printf("\tifZ _t%d goto L%d\n", var-1, end_label);
        }

        tac_gen(root->nodes[1]);
        printf("\tgoto L%d\n", start_label-1);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, DO_WHILE_TOKEN) == 0)
    {
        avoid_rec=1;
        int end_label = label++;
        int start_label = label++;

        printf("L%d:\n", start_label++);
        tac_gen(root->nodes[0]);

        // Generate TAC for the condition expression
        if(strcmp(root->nodes[1]->token, OR_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,end_label,1);
        }
        else if(strcmp(root->nodes[1]->token, AND_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,start_label,end_label,0);
        }
        else
        {
            get_bool(root->nodes[1]);
            printf("\tifZ _t%d goto L%d\n", var-1, end_label); 
        }

        printf("\tgoto L%d\n", start_label-1);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "=") == 0)
    {
        avoid_rec = 1;
        if(root->nodes[1]->count>0 && strcmp (root->nodes[1]->nodes[0]->token, INDEX_TOKEN) ==0)
        {
            int saveVar = -1;
            if(root->nodes[0]->count>0 && strcmp (root->nodes[0]->token,PTR_TOKEN)==0)
            {
                saveVar = var;
                printf("\t_t%d = &%s\n", var, root->nodes[0]->nodes[0]->token);
                var++;
            }
            printf("\t_t%d = &%s\n", var, root->nodes[1]->token);
            tac_gen(root->nodes[1]);
            if(saveVar==-1)
            {
                printf("\t%s = *_t%d\n", root->nodes[0]->token,var++ );
            }
            else
            {
                printf("\t*_t%d = *_t%d\n", saveVar,var++);
            }
        }
        else if(root->nodes[0]->count>0 && strcmp(root->nodes[0]->nodes[0]->token,INDEX_TOKEN) ==0)
        {
            printf("\t_t%d = &%s\n", var, root->nodes[0]->token);
            tac_gen(root->nodes[0]);
            if(root->nodes[1]->count>0 && strcmp (root->nodes[1]->token,PTR_TOKEN)==0)
            {
                int saveVar = var++;
                tac_gen(root->nodes[1]->nodes[0]);
                if(root->nodes[1]->nodes[0]->count==0)
                {
                    printf("\t*_t%d = *%s\n", var-1, root->nodes[1]->nodes[0]->token);
                }
                else
                {
                    printf("\t*_t%d = *_t%d\n", saveVar,var-1);
                }
            }
            else
            {
                printf("\t*_t%d = %s\n", var,root->nodes[1]->token );
            }
        }
        else
        {
            int flag=0;
            tac_gen(root->nodes[1]);
            if(strcmp (root->nodes[1]->token,ADDRESS_OPERATOR_TOKEN) && strcmp (root->nodes[1]->token, PTR_TOKEN) && strcmp (root->nodes[1]->token, FUNC_CALL_TOKEN) && strcmp (root->nodes[1]->token,LENGTH_OF_TOKEN) && root->nodes[1]->count<2)
            {
               printf("\t_t%d = %s\n", var, root->nodes[1]->token);
            }
            if(strcmp (root->nodes[1]->token,FUNC_CALL_TOKEN)==0 
            || strcmp (root->nodes[1]->token,LENGTH_OF_TOKEN) ==0 
            || strcmp (root->nodes[1]->token,PTR_TOKEN)==0
            || root->nodes[1]->count>=2
            || strcmp (root->nodes[1]->token,ADDRESS_OPERATOR_TOKEN) ==0)
            {
                if(strcmp(root->nodes[1]->token, PTR_TOKEN)==0 && root->nodes[1]->nodes[0]->count>0)
                {
                    flag = 1;
                    printf("\t%s = *_t%d\n", root->nodes[0]->token, var-1);
                }
                else
                {
                    var-=1;
                }
            }
            if(strcmp(root->nodes[0]->token, PTR_TOKEN)==0)
            {
                flag = 1;
                printf("\t*%s = _t%d\n",root->nodes[0]->nodes[0]->token,var++);
            }
            if(!flag)
            {
                printf("\t%s = _t%d\n", root->nodes[0]->token, var++);
            }
        }
    }
    else if (strcmp(root->token, IF_TOKEN) == 0)
    {
        avoid_rec=1;
        int end_label = label++;
        int if_label = label++;

        if(strcmp(root->nodes[0]->token, OR_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,if_label,end_label,1);
        }
        else if(strcmp(root->nodes[0]->token, AND_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,if_label,end_label,0);
        }
        else
        {
            get_bool(root->nodes[0]);
            printf("\tif _t%d goto L%d\n", var-1, if_label);
            printf("\tgoto L%d\n", end_label);
            printf("L%d:\n", if_label);
        }

        tac_gen(root->nodes[1]);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, IF_ELSE_TOKEN) == 0)
    {
        avoid_rec=1;
        int end_label = label++;
        int else_label = label++;
        int if_label = label++;

        if(strcmp(root->nodes[0]->token, OR_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,if_label,else_label,1);
        }
        else if(strcmp(root->nodes[0]->token, AND_OPERATOR_TOKEN) == 0)
        {
            short_circuit_evaluation(root,if_label,else_label,0);
        }
        else
        {
            get_bool(root->nodes[0]);
            printf("\tif _t%d goto L%d\n", var-1, if_label);
            printf("\tgoto L%d\n", else_label);
            printf("L%d:\n", if_label);
        }

        tac_gen(root->nodes[1]);
        printf("\tgoto L%d\n", end_label);
        printf("L%d:\n", else_label);

        if (root->count > 2)
        {
            tac_gen(root->nodes[2]);
        }

        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, RETURN_TOKEN) == 0)
    {
        if(root->nodes[0]->count>0)
        {
            avoid_rec = 1;
            tac_gen(root->nodes[0]);
            printf("\tReturn _t%d\n",var-1);
        }
        else
        {
            printf("\tReturn %s\n",root->nodes[0]->token);
        }
    }
    else if (strcmp(root->token, LENGTH_TOKEN) == 0)
    {
        printf("\t_t%d -> sizeof(%s)\n",var++,root->nodes[0]->token);
    }
    else if (strcmp(root->token, INDEX_TOKEN) == 0)
    {
        // Handle accessing array elements
        if(root->nodes[0]->count>0)
        {
            avoid_rec=1;
            int saveVar = var++;
            tac_gen(root->nodes[0]);
            printf("\t_t%d = _t%d + _t%d\n",var,var-1,saveVar);
        }
        else
        {
            printf("\t_t%d = _t%d + %s\n",var+1,var,root->nodes[0]->token);
            var++;
        }
    }
    else if (strcmp(root->token, PTR_TOKEN) == 0)
    {
        // Handle dereferencing a pointer
        // Handle accessing array elements.
        if(root->nodes[0]->count>0)
        {
            avoid_rec = 1;
            tac_gen(root->nodes[0]);
        }
        else
        {
            printf("\t_t%d = *%s\n",var++, root->nodes[0]->token);
        }
    }
    else if (strcmp(root->token, ADDRESS_OPERATOR_TOKEN) == 0)
    {
        // Handle getting the address of a variable
        printf("\t_t%d = &%s\n", var, root->nodes[0]->token);
        if(root->nodes[0]->count>0)
        {
            avoid_rec = 1;
            tac_gen(root->nodes[0]);
        }
        var++;
    }
    else if (strcmp(root->token, LENGTH_OF_TOKEN) == 0)
    {
        // Handle getting the address of a variable
        printf("\t_t%d = LENGTH OF (%s) \n", var++, root->nodes[0]->token);
    }
    else if (strcmp(root->token, "+") == 0
            || strcmp(root->token, "-") == 0
            || strcmp(root->token, "*") == 0
            || strcmp(root->token, "/") == 0)
    {
        int flag=0;
        avoid_rec=1;
        for(int i=0;i<root->count;i++)
        {
            if(strcmp(root->nodes[i]->token, PTR_TOKEN)==0 || strcmp(root->nodes[i]->token, LENGTH_OF_TOKEN)==0 || strcmp(root->nodes[i]->token, ADDRESS_OPERATOR_TOKEN)==0 ||  strcmp(root->nodes[i]->token, FUNC_CALL_TOKEN)==0)
            {
                flag=1;
            }
        }
        if(flag==1)
        {
            // Generate TAC for arithmetic expressions
            tac_gen(root->nodes[0]);
            tac_gen(root->nodes[1]);
            if(root->nodes[1]->count>0 && root->nodes[0]->count>0)
            {
                printf("\t_t%d = _t%d %s _t%d\n", var, var-2, root->token,var-1);
            }
            else if(root->nodes[1]->count>0)
            {
                printf("\t_t%d = %s %s _t%d\n", var, root->nodes[0]->token, root->token, var-1);
            }
            else if(root->nodes[0]->count>0)
            {
                printf("\t_t%d = _t%d %s %s\n", var, var-1, root->token,root->nodes[1]->token);
            }
            var++;
        }
        else
        {
            // Generate TAC for arithmetic expressions
            tac_gen(root->nodes[0]);
            int saveVar = var;
            tac_gen(root->nodes[1]);  
            if (strcmp(root->nodes[0]->token, "+") == 0
            || strcmp(root->nodes[0]->token, "-") == 0
            || strcmp(root->nodes[0]->token, "*") == 0
            || strcmp(root->nodes[0]->token, "/") == 0)
            {
                if (strcmp(root->nodes[1]->token, "+") == 0
                || strcmp(root->nodes[1]->token, "-") == 0
                || strcmp(root->nodes[1]->token, "*") == 0
                || strcmp(root->nodes[1]->token, "/") == 0)
                {
                    printf("\t_t%d = _t%d %s _t%d\n", var, saveVar-1, root->token, var-1);
                }
                else
                {
                    printf("\t_t%d = _t%d %s %s\n", var, var-1, root->token, root->nodes[1]->token);
                }
            }
            else
            {
                printf("\t_t%d = %s %s %s\n", var,  root->nodes[0]->token, root->token, root->nodes[1]->token);
            }
            var++;
        }
    }
    else if (strcmp(root->token, VAR_TOKEN) == 0)
    {
        avoid_rec = 1;

        for(int i=0;i<root->count;i++){
            if(strcmp(root->nodes[i]->token, STRING_TOKEN)==0)
            {
                if(strcmp(root->nodes[i]->nodes[0]->nodes[0]->token,"=")==0)
                {
                    printf("\t_t%d = &%s\n",var,root->nodes[i]->nodes[0]->nodes[0]->nodes[0]->token);
                    tac_gen(root->nodes[i]->nodes[0]->nodes[0]->nodes[0]->nodes[0]);
                    printf("\t*_t%d = %s\n",var-1,root->nodes[i]->nodes[0]->nodes[0]->nodes[1]->token);
                }
                else
                {
                    printf("\t_t%d = &%s\n",var,root->nodes[i]->nodes[0]->nodes[0]->token);
                    tac_gen(root->nodes[i]->nodes[0]->nodes[0]->nodes[0]);
                }
            }
            else
            {
                tac_gen(root->nodes[i]);
            }
        }
    }
    if (strcmp(root->token, FUNC_CALL_TOKEN) == 0)
    {
        int sum=0;
        // Generate TAC for arguments
        for (int i = 0; i < root->nodes[1]->count; i++)
        {
            printf("\t_t%d = %s\n",var,root->nodes[1]->nodes[i]->token);
            printf("\tPushParam _t%d\n", var++);
            if(strcmp(root->nodes[1]->nodes[i]->type,INT_TOKEN)==0)
            {
                sum+=4;
            }
            else if(strcmp(root->nodes[1]->nodes[i]->type,REAL_TOKEN)==0)
            {
                sum+=8;
            }
            else if(strcmp(root->nodes[1]->nodes[i]->type,CHAR_TOKEN)==0)
            {    
                sum+=1;
            }
        }
        printf("\t_t%d = LCall %s\n",var++,root->nodes[0]->token);
        printf("\tPopParams %d\n",sum);
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

void get_bool(node* root)
{
    if (root == NULL)
    {
        return;
    }

    if (strcmp(root->token, EQUALS_OPERATOR_TOKEN) == 0 || strcmp(root->token, NOT_EQUAL_OPERATOR_TOKEN) == 0 ||
        strcmp(root->token, LESS_THAN_OPERATOR_TOKEN) == 0 || strcmp(root->token, GREATER_THAN_OPERATOR_TOKEN) == 0 ||
        strcmp(root->token, LESS_THAN_OR_EQUAL_OPERATOR_TOKEN) == 0 || strcmp(root->token, GREATER_THAN_OR_EQUAL_OPERATOR_TOKEN) == 0)
    {
        // Generate TAC for comparison operators
        int flag=0;
        if(root->nodes[0]->count>0 && strcmp (root->nodes[0]->nodes[0]->token, INDEX_TOKEN) ==0)
        {
            printf("\t_t%d = &%s\n", var, root->nodes[0]->token);
            flag=1;
        }
        tac_gen(root->nodes[0]);
        int saveVar = var;
        if(root->nodes[1]->count>0 && strcmp (root->nodes[1]->nodes[0]->token, INDEX_TOKEN) ==0)
        {
            if(flag)
            {
                saveVar = var++;
            }
            printf("\t_t%d = &%s\n", var, root->nodes[1]->token);
        }
        tac_gen(root->nodes[1]);
        if(root->nodes[1]->count>0 && root->nodes[0]->count>0)
        {
            printf("\t_t%d = _t%d %s _t%d\n", var, saveVar-1, root->token,var-1);
        }
        else if(root->nodes[1]->count>0)
        {
            printf("\t_t%d = %s %s _t%d\n", var, root->nodes[0]->token, root->token, var-1);
        }
        else if(root->nodes[0]->count>0)
        {
            printf("\t_t%d = _t%d %s %s\n", var, var-1, root->token,root->nodes[1]->token);
        }
        else
        {
            printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        }
        var++;
    }
    else if (strcmp(root->token, OR_OPERATOR_TOKEN) == 0 )
    {
        // Generate TAC for boolean AND and OR operators
        get_bool(root->nodes[0]);
        get_bool(root->nodes[1]);
        printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        var++;
    }
    else if( strcmp(root->token, AND_OPERATOR_TOKEN) == 0)
    {
        // Generate TAC for boolean AND and OR operators
        get_bool(root->nodes[0]);
        get_bool(root->nodes[1]);
        printf("\t_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        var++;
    }
    else if (strcmp(root->token, NOT_EQUAL_OPERATOR_TOKEN) == 0)
    {
        // Generate TAC for boolean NOT operator
        get_bool(root->nodes[0]);
        printf("\t_t%d = %s %s\n", var, root->token, root->nodes[0]->token);
        var++;
    }
    else
    {
        // Generate TAC for other nodes recursively
        for (int i = 0; i < root->count; i++)
        {
            get_bool(root->nodes[i]);
        }
    }
}

void short_circuit_evaluation(node* root,int if_label,int end_label,int flag)
{
    for(int i=0;i<root->count;i++)
    {
        if(strcmp(root->nodes[i]->token, OR_OPERATOR_TOKEN) == 0)
        {
            int temp_flag = 0;
            for(int j=0;j<root->nodes[i]->count && !temp_flag;j++)
            {
                if(strcmp(root->nodes[i]->nodes[j]->token, AND_OPERATOR_TOKEN) == 0)
                {
                    short_circuit_evaluation(root->nodes[i],if_label+1,end_label+1,flag);
                    temp_flag = 1;
                }
                else if(strcmp(root->nodes[i]->nodes[j]->token, OR_OPERATOR_TOKEN) == 0)
                {
                    short_circuit_evaluation(root->nodes[i],if_label+1,end_label,1);
                    temp_flag = 1;
                }
            }
            for(int j=0;j<root->nodes[i]->count;j++)
            {
                get_bool(root->nodes[i]->nodes[j]);

                if(flag==2)
                {
                    printf("\tif _t%d goto L%d\n", var-1, end_label+root->nodes[i]->count);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", end_label-1);
                    }
                }
                else if(flag==1)
                {
                    printf("\tif _t%d goto L%d\n", var-1, if_label);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", end_label);
                    }
                }
                else
                {
                    printf("\tif _t%d goto L%d\n", var-1, end_label);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", if_label);
                    }
                }
            }
            printf("L%d:\n", if_label);
            if_label+=1;
        }
        if(strcmp(root->nodes[i]->token, AND_OPERATOR_TOKEN) == 0)
        {
            int temp_flag = 0;
            for(int j=0;j<root->nodes[i]->count && !temp_flag;j++)
            {
                if(strcmp(root->nodes[i]->nodes[j]->token, AND_OPERATOR_TOKEN) == 0)
                {
                    short_circuit_evaluation(root->nodes[i],if_label+1,end_label,flag);
                    temp_flag = 1;
                }
                else if(strcmp(root->nodes[i]->nodes[j]->token, OR_OPERATOR_TOKEN) == 0)
                {
                    short_circuit_evaluation(root->nodes[i],if_label+1,end_label,1);
                    temp_flag = 1;
                }
            }
            for(int j=0;j<root->nodes[i]->count;j++)
            {
                get_bool(root->nodes[i]->nodes[j]);

                if(flag==2)
                {
                    printf("\tifZ _t%d goto L%d\n", var-1, if_label);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", end_label+1);
                    }
                }
                else if(flag==1)
                {
                    printf("\tifZ _t%d goto L%d\n", var-1, if_label);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", end_label);
                    }
                }
                else
                {
                    printf("\tifZ _t%d goto L%d\n", var-1, end_label);
                    if(j+1==(root->nodes[i]->count))
                    {
                        printf("\tgoto L%d\n", if_label);
                    }
                }
            }
            printf("L%d:\n", if_label);
            if_label+=1;
        }
    }
}