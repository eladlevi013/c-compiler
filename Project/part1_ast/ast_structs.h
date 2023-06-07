// Includes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Structs
typedef struct node
{
    char *token;
    int count;
    struct node **nodes;
    char* type;
} node;
