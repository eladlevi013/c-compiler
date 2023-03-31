%%
bool { printf("BOOL"); }
char { printf("CHAR"); }
int { printf("INT"); }
real { printf("REAL"); }
string { printf("STRING"); }
int* { printf("INT_POINTER"); }
char* { printf("CHAR_POINTER"); }
real* { printf("REAL_POINTER"); }
if { printf("IF"); }
else { printf("ELSE"); }
while { printf("WHILE"); }
for { printf("FOR"); }
var { printf("VAR"); }
arg-> { printf("ARG_ARROW"); }
function { printf("FUNCTION"); }
return { printf("RETURN"); }
null { printf("NULL"); }
void { printf("VOID"); }
do { printf("DO"); }
&& { printf("AND"); }
\/ { printf("DIVIDE"); }
\= { printf("AST"); }
\== { printf("EQ"); }
\> { printf("GT"); }
\>= { printf("GE"); }
\< { printf("LT"); }
\<= { printf("LE"); }
\- { printf("SUBTRACT"); }
\! { printf("NOT"); }
\!= { printf("NE"); }
\|\| { printf("OR"); }
\+ { printf("ADD"); }
\* { printf("MULTIPLY"); }
\& { printf("AMPERSAND"); }
false { printf("FALSE"); }
true { printf("TRUE"); }
\'.\' { printf("CHAR"); }
[-]?[0-9]+ { printf("%s", yytext); }
0[x+X][0-9A-F]+ { printf("%s", yytext); }
[-]?([0-9]*[\.][0-9]+) { printf("%s", yytext); }
["][.+\n]*["] { printf("STRING"); }
\; { printf("SEMICOLON"); }
\, { printf("COMMA"); }
\| { printf("VERTICAL_BAR"); }
\{ { printf("START_CURLY_BRACKETS"); }
\} { printf("END_CURLY_BRACKETS"); }
\( { printf("START_ROUND_BRACKETS"); }
\) { printf("END_ROUND_BRACKETS"); }
\[ { printf("START_SQUARE_BRACKETS"); }
\] { printf("END_SQUARE_BRACKETS"); }
%%