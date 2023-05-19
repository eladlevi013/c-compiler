// Includes
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Symbol {
    char* id;
    char* type;
    char* data;
    struct Symbol* next;
} Symbol;

typedef struct Scope {
    Symbol* symbolTable;
    struct Scope* nextScope;
} Scope;
