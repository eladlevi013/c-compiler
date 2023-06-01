// Part3 - 3AC
int var = 0;
int label = 1;

void tac_gen(node* root) {
    if (root == NULL)
        return;

    if (strcmp(root->token, "FUNCTION") == 0) {
        printf("%s:\n", root->nodes[0]->token);  // Print the function name
        printf("BeginFunc\n");
        tac_gen(root->nodes[1]);  // Generate TAC for the function body
        printf("EndFunc\n");
    } 
    else if (strcmp(root->token, "=") == 0) {
        // Handle assignment statements
        tac_gen(root->nodes[1]);
        printf("_t%d = %s\n", var, root->nodes[1]->token);
        printf("%s = _t%d\n", root->nodes[0]->token, var++);
    } 
    else if (strcmp(root->token, "IF") == 0 || strcmp(root->token, "IF-ELSE") == 0) {
        // Generate TAC for the condition expression
        getBool(root->nodes[0]);

        // Create labels for if, else, and end blocks
        int if_label = label++;
        int else_label = label++;
        int end_label = label++;

        printf("if %s goto L%d\n", root->nodes[0]->token, if_label);  // Modify this line

        printf("goto L%d\n", else_label);
        printf("L%d:\n", if_label);

        // Generate TAC for the statements in the if block
        tac_gen(root->nodes[1]);
        printf("goto L%d\n", end_label);

        printf("L%d:\n", else_label);

        // Generate TAC for the statements in the else block, if it exists
        if (strcmp(root->token, "IF-ELSE") == 0 && root->count > 2) {
            tac_gen(root->nodes[2]);
        }

        printf("L%d:\n", end_label);
    } 
    else if (strcmp(root->token, "RETURN") == 0) {
        // Handle return statements
        tac_gen(root->nodes[0]);
        printf("Return %s\n", root->nodes[0]->token);
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
    else if (strcmp(root->token, "AND") == 0 || strcmp(root->token, "OR") == 0) {
        // Generate TAC for boolean AND and OR operators
        getBool(root->nodes[0]);
        getBool(root->nodes[1]);
        printf("_t%d = %s %s %s\n", var, root->nodes[0]->token, root->token, root->nodes[1]->token);
        strcpy(root->token, "_t");
        sprintf(root->token + 2, "%d", var++);
    } 
    else if (strcmp(root->token, "NOT") == 0) {
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
