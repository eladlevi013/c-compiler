// Includes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structs
typedef struct node
{ 
    char *token;
    struct node **nodes;
    int count;
} node;
