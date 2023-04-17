%{
    #include<stdio.h>
    #include<string.h>
    int yylex();
    int yyerror();
%}
%token BOOL, CHAR, INT, REAL, STRING, INT_POINTER, CHAR_POINTER,
    REAL_POINTER, IF, ELSE, WHILE, FOR, VAR, ARG_ARROW, FUNCTION, 
    RETURN, NULL, VOID, DO, AND, DIVIDE, ASSIGNMENT, EQUALS, GREATER_THAN, 
    GRATER_EQUALS, LOWER_THAN, LOWER_EQUALS, SUBTRACT, NOT,
    NOT_EQUALS, OR, ADD, MULTIPLY, AMPERSAND, FALSE, TRUE, 
    CHAR, INTEGER_LITERAL, INTEGER_LITERAL_HEX, REAL_LITERAL, CHAR_LITERAL, STRING, 
    IDENTIFIER, SEMICOLON, COMMA, VERTICAL_BAR, START_CURLY_BRACKETS, 
    END_CURLY_BRACKETS, START_ROUND_BRACKETS, END_ROUND_BRACKETS, 
    START_SQUARE_BRACKETS, END_SQUARE_BRACKETS, COMMENT
%%

s: statement s | statement
statement: ifGrammer | FOR | WHILE | RETURN | COMMENT
operator: AND | DIVIDE | ASSIGNMENT | EQUALS | GREATER_THAN | GREATER_EQUALS | LOWER_EQUALS 
        | LOWER_THAN | SUBTRACT | NOT | NOT_EQUALS | OR | ADD | MULTIPLY | AMPERSAND
expression: expression operator expression | operator expression | value
literal_lexemes: bool_literal, char_literal, integer_literal, real_literal, string_literal
value: literal_lexemes | IDENTIFIER'
ifGrammer: IF expression | IF expression ELSE statement
forGrammer: FOR (;CONDITION;) BODY
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