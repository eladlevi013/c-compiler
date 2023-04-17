%%
bool { return BOOL; }
char { return CHAR; }
int { return INT; }
real { return REAL; }
string { return STRING; }
int* { return INT_POINTER; }
char* { return CHAR_POINTER; }
real* { return REAL_POINTER; }
if { return IF; }
else { return ELSE; }
while { return WHILE; }
for { return FOR; }
var { return VAR; }
arg-> { return ARG_ARROW; }
function { return FUNCTION; }
return { return RETURN; }
null { return NULL; }
void { return VOID; }
do { return DO; }
&& { return AND; }
\/ { return DIVIDE; }
\= { return ASSIGNMENT; }
\== { return EQUALS; }
\> { return GREATER_THAN; }
\>= { return GREATER_EQUALS; }
\< { return LOWER_THAN; }
\<= { return LOWER_EQUALS; }
\- { return SUBTRACT; }
\! { return NOT; }
\!= { return NOT_EQUALS; }
\|\| { return OR; }
\+ { return ADD; }
\* { return MULTIPLY; }
\& { return AMPERSAND; }
false { return FALSE; }
true { return TRUE; }
\'(.|\\n)\' { return CHAR_LITERAL; }
[-]?[0-9]+ { return INTEGER_LITERAL; }
0[x|X]([0-9A-F])+ { return INTEGER_LITERAL_HEX; }
[+|-]?([0-9]*[\.][0-9]*[e|E][+|-]?[0-9]+|[0-9]+[e|E][+|-]?[0-9]+|[0-9]*[.][0-9]+) { return REAL_LITERAL; }
\"[^"]*\" { return STRING_LITERAL; }
[a-zA-Z][a-zA-Z0-9_]* { return IDENTIFIER; }
\; { return SEMICOLON; }
\, { return COMMA; }
\| { return VERTICAL_BAR; }
\{ { return START_CURLY_BRACKETS; }
\} { return END_CURLY_BRACKETS; }
\( { return START_ROUND_BRACKETS; }
\) { return END_ROUND_BRACKETS; }
\[ { return START_SQUARE_BRACKETS; }
\] { return END_SQUARE_BRACKETS; }
\/\*(.|\n)*\*\/ { return COMMENT; }
%%
