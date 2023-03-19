%%
// keywords lexemes
"bool" { return BOOL; }
"char" { return CHAR; }
"int" { return INT; }
"real" { return REAL; }
"string" { return STRING; }
"int*" { return INT_POINTER; }
"char*" { return CHAR_POINTER; }
"real*" { return REAL_POINTER; }
"if" { return IF; }
"else" { return ELSE; }
"while" { return WHILE; }
"for" { return FOR; }
"var" { return VAR; }
"arg->" { return ARG_ARROW; }
"function" { return FUNCTION; }
"return" { return RETURN; }
"null" { return NULL; }
"void" { return VOID; }
"do" { return DO; }

// operator lexemes
"&&" { return AND; }
"/" { return DIVIDE; }
"=" { return AST; }
"==" { return EQ; }
">" { return GT; }
">=" { return GE; }
"<" { return LT; }
"<=" { return LE; }
"-" { return SUBTRACT; }
"!" { return NOT; }
"!=" { return NE; }
"||" { return OR; }
"+" { return ADD; }
"*" { return MULTIPLY; }
"&" { return AMPERSAND; }

// literal lexemes
"false" { return FALSE; }
"true" { return TRUE; }
['][.+\n]['] { return CHAR; }
[-]?[0-9]+ { return INTEGER_LITERAL; }
0[x+X][0-9A-F]+ { return INTEGER_LITERAL; }
[-]?([0-9]*[\.][0-9]+) { return REALS_LITERAL; }
["][.+\n]*["] { return STRING; }

// literal lexemes
\; { return SEMICOLON;}
\, { return COMMA; }
\| { return VETICAL_BAR; }
\{ { return START_CURLY_BRACKETS; }
\} { return END_CURLY_BRACKETS; }
\( { return START_ROUND_BRACKETS; }
\) { return END_ROUND_BRACKETS; }
\[ { return START_SQUARE_BRACKETS; }
\] { return END_SQUARE_BRACKETS; }
%%
