%%
bool { printf("BOOL\n"); }
char { printf("CHAR\n"); }
int { printf("INT\n"); }
real { printf("REAL\n"); }
string { printf("STRING\n"); }
int\* { printf("INT_POINTER\n"); }
char\* { printf("CHAR_POINTER\n"); }
real\* { printf("REAL_POINTER\n"); }
if { printf("IF\n"); }
else { printf("ELSE\n"); }
while { printf("WHILE\n"); }
for { printf("FOR\n"); }
var { printf("VAR\n"); }
arg-> { printf("ARG_ARROW\n"); }
function { printf("FUNCTION\n"); }
return { printf("RETURN\n"); }
null { printf("NULL_TOKEN\n"); }
void { printf("VOID\n"); }
do { printf("DO\n"); }
&& { printf("AND\n"); }
\/ { printf("DIVIDE\n"); }
\= { printf("ASSIGNMENT\n"); }
\== { printf("EQUALS\n"); }
\> { printf("GREATER_THAN\n"); }
\>= { printf("GREATER_EQUALS\n"); }
\< { printf("LOWER_THAN\n"); }
\<= { printf("LOWER_EQUALS\n"); }
\- { printf("SUBSTRACT\n"); }
\! { printf("NOT\n"); }
\!= { printf("NOT_EQUALS\n"); }
\|\| { printf("OR\n"); }
\+ { printf("ADD\n"); }
\* { printf("MULTIPLY\n"); }
\& { printf("ADDRESS\n"); }
false { printf("FALSE\n"); }
true { printf("TRUE\n"); }
\'(.|\\n)\' { printf("CHAR_LITERAL\n"); }
[1-9][0-9]*|0 {  printf("INTEGER_LITERAL\n"); }
0[x|X]([0-9A-F])+ {  printf("INTEGER_LITERAL_HEX\n"); }
[+|-]?([0-9]*[\.][0-9]*[e|E][+|-]?[0-9]+|[0-9]+[e|E][+|-]?[0-9]+|[0-9]*[.][0-9]+) {  printf("REAL_LITERAL\n"); }
\"[^"]*\" {  printf("STRING_LITERAL\n"); }
[a-zA-Z][a-zA-Z0-9_]* {  printf("IDENTIFIER\n"); }
\; { printf("SEMICOLON\n"); }
\, { printf("COMMA\n"); }
\| { printf("VERTICAL_BAR\n"); }
\{ { printf("START_CURLY_BRACKETS\n"); }
\} { printf("END_CURLY_BRACKETS\n"); }
\( { printf("START_ROUND_BRACKETS\n"); }
\) { printf("END_ROUND_BRACKETS\n"); }
\[ { printf("START_SQUARE_BRACKETS\n"); }
\] { printf("END_SQUARE_BRACKETS\n"); }
\: printf("COLON\n");

"/*"([/]*)(([*]+[^/*]+)?[^*]*)*([*]*)"*/" { printf("COMMENT\n"); }
[\n] ;
%%