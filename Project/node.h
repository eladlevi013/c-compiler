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

typedef struct Symbol {
    char* id;
    char* type;
    struct Symbol* next;
} Symbol;

typedef struct Scope {
    Symbol* symbolTable;
    struct Scope* nextScope;
} Scope;

//rename from node!!!
