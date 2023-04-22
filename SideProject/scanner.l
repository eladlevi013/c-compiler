%{
#include<string.h>
%}
%%
[a-z0-9]+ { yylval.s=strdup(yytext);
 return EXP;
 }
.|\n ;
%%
