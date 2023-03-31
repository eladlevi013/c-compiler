%{
    #include<stdio.h>
    #include<string.h>
    int yylex();
    int yyerror();
%}
%token BOOL, CHAR, INT, REAL, STRING, INT_POINTER, CHAR_POINTER,
    REAL_POINTER, IF, ELSE, WHILE, FOR, VAR, ARG_ARROW, FUNCTION, 
    RETURN, NULL, VOID, DO, AND, DIVIDE, AST, EQ, GT, GE, LT, LE, 
    SUBTRACT, NOT, NE, OR, ADD, MULTIPLY, AMPERSAND, FALSE, TRUE, 
    CHAR, INTEGER_LITERAL, INTEGER_LITERAL_HEX, REAL_LITERAL, STRING, 
    IDENTIFIER, SEMICOLON, COMMA, VERTICAL_BAR, START_CURLY_BRACKETS, 
    END_CURLY_BRACKETS, START_ROUND_BRACKETS, END_ROUND_BRACKETS, 
    START_SQUARE_BRACKETS, END_SQUARE_BRACKETS, COMMENT

%%
s: ....
%%

#include "lex.yy.c"
int main()
{
 return yyparse();
}

int yyerror()
{
 printf ("Syntax error\n");
 return 0;
}