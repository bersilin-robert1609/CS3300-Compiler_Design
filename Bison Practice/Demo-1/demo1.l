DIGIT [0-9]
NUMBER [+-]?{DIGIT}+

%%

[ \t] {}
{NUMBER} {return NUM;}
"+" {return OP;}
"-" {return OP;}
"*" {return OP;}
"/" {return OP;}
\n  {return EOL;}
. {printf("Lexer Error : %s not valid", yytext); exit(1);}

%%