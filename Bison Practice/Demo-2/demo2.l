DIGIT [0-9]
NUMBER [+-]?{DIGIT}+

%%

[ \t] {}
{NUMBER} {
    yylval.num = atoi(yytext);
    return NUM;
}
"+" {
    yylval.id = strdup(yytext);
    return ADD;
}
"-" {
    yylval.id = strdup(yytext);
    return SUB;
}
"*" {
    yylval.id = strdup(yytext);
    return MUL;
}
"/" {
    yylval.id = strdup(yytext);
    return DIV;
}
\n {return EOL;}
. {printf("Lexer Error: %s not valid", yytext); exit(0);}
%%
