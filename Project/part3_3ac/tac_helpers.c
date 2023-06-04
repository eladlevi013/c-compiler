// Part3 - 3AC
int var = 0;
int label = 1;


void getBool(node* root);

void tac_gen(node* root) {
    
    //printf("%s\n",root->token);

    if (root == NULL)
        return;
    
    

    if (strcmp(root->token, "FUNC") == 0) {
        printf("%s:\n", root->nodes[0]->token);  // Print the function name
        printf("BeginFunc\n");
        tac_gen(root->nodes[3]);  // Generate TAC for the function body
        printf("EndFunc\n");
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

        printf("ifZ %s goto L%d\n", root->nodes[1]->token, end_label);  // Modify this line

        // Generate TAC for the statements in the for loop body
        tac_gen(root->nodes[3]);

        printf("L%d:\n", inc_label);

        // Generate TAC for the increment expression
        tac_gen(root->nodes[2]);

        printf("goto L%d\n", start_label);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "WHILE") == 0) {
        // Create labels for the start and end blocks
        int start_label = label++;
        int end_label = label++;

        printf("L%d:\n", start_label);

        // Generate TAC for the condition expression
        getBool(root->nodes[0]);

        printf("ifZ %s goto L%d\n", root->nodes[0]->token, end_label);  // Modify this line

        // Generate TAC for the statements in the while loop body
        tac_gen(root->nodes[1]);

        printf("goto L%d\n", start_label);
        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "DO-WHILE") == 0) {
        // Create labels for the start and end blocks
        int start_label = label++;
        int end_label = label++;

        printf("L%d:\n", start_label);

        // Generate TAC for the statements in the do-while loop body
        tac_gen(root->nodes[0]);

        printf("L%d:\n", end_label);

        // Generate TAC for the condition expression
        getBool(root->nodes[1]);

        printf("if %s goto L%d\n", root->nodes[1]->token, start_label);  // Modify this line
        printf("goto L%d\n", end_label);
    }
    else if (strcmp(root->token, "=") == 0) {
        // Handle assignment statements
        tac_gen(root->nodes[1]);
        
        if(strcmp (root->nodes[1]->token,"&") && strcmp (root->nodes[1]->token,"PTR") )
            printf("_t%d = %s\n", var, root->nodes[1]->token);
        if(strcmp (root->nodes[0]->token,"PTR") ==0)
            printf("*%s = _t%d\n ",root->nodes[0]->nodes[0]->token,var);
        else 
         printf("%s = _t%d\n", root->nodes[0]->token, var++);
        
    } else if (strcmp(root->token, "IF") == 0) {
        // Generate TAC for the condition expression
        getBool(root->nodes[0]);

        // Create labels for if and end blocks
        int if_label = label++;
        int end_label = label++;

        printf("ifZ %s goto L%d\n", root->nodes[0]->token, if_label);

        // Generate TAC for the statements in the if block
        tac_gen(root->nodes[1]);

        printf("goto L%d\n", end_label);
        printf("L%d:\n", if_label);

        printf("L%d:\n", end_label);
    }
    else if (strcmp(root->token, "IF-ELSE") == 0) {
        // Generate TAC for the condition expression
        getBool(root->nodes[0]);

        // Create labels for if, else, and end blocks
        int if_label = label++;
        int else_label = label++;
        int end_label = label++;

        printf("ifZ %s goto L%d\n", root->nodes[0]->token, if_label);

        // Generate TAC for the statements in the if block
        tac_gen(root->nodes[1]);

        printf("goto L%d\n", end_label);
        printf("L%d:\n", if_label);

        // Generate TAC for the statements in the else block
        if (root->count > 2) {
            tac_gen(root->nodes[2]);
        }

        printf("L%d:\n", end_label);
    } 
    else if (strcmp(root->token, "RET") == 0) {
        // Handle return statements
        tac_gen(root->nodes[0]);
        printf("_t%d= %s\n",var, root->nodes[0]->token);
        printf("Return _t%d\n",var++ );
    } 
    else if (strcmp(root->token, "ARRAY_ACCESS") == 0) {
        // Handle accessing array elements
        char* array_name = root->nodes[0]->token;
        char* index = root->nodes[1]->token;
        printf("%s = %s[%s]\n", root->token, array_name, index);
    }
    else if (strcmp(root->token, "PTR") == 0) {
        // Handle dereferencing a pointer        
        printf("_t%d = *%s\n",var, root->nodes[0]->token);
    }
    else if (strcmp(root->token, "&") == 0) {
        // Handle getting the address of a variable
        printf("_t%d = &%s\n", var, root->nodes[0]->token);
    }
    else if (strcmp(root->token, "+") == 0 || strcmp(root->token, "-") == 0
               || strcmp(root->token, "*") == 0 || strcmp(root->token, "/") == 0) {
        // Generate TAC for arithmetic expressions
        tac_gen(root->nodes[0]);
        tac_gen(root->nodes[1]);
        printf("_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    }
    else {
        // Generate TAC for other nodes recursively
        for (int i = 0; i < root->count; i++) {
            tac_gen(root->nodes[i]);
        }
    }
}

void getBool(node* root) {
    if (root == NULL)
        return;

    if (strcmp(root->token, "==") == 0 || strcmp(root->token, "!=") == 0 ||
        strcmp(root->token, "<") == 0 || strcmp(root->token, ">") == 0 ||
        strcmp(root->token, "<=") == 0 || strcmp(root->token, ">=") == 0) {
        // Generate TAC for comparison operators
        tac_gen(root->nodes[0]);
        tac_gen(root->nodes[1]);
        printf("_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else if (strcmp(root->token, "||") == 0 || strcmp(root->token, "&&") == 0) {
        // Generate TAC for boolean AND and OR operators
        getBool(root->nodes[0]);
        getBool(root->nodes[1]);
        printf("_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else if (strcmp(root->token, "!=") == 0) {
        // Generate TAC for boolean NOT operator
        getBool(root->nodes[0]);
        printf("_t%d = %s %s\n", var, root->token, root->nodes[0]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else {
        // Generate TAC for other nodes recursively
        for (int i = 0; i < root->count; i++) {
            getBool(root->nodes[i]);
        }
    }
}
