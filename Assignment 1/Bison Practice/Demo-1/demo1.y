%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex(void);
    void yyerror (const char *);
%}

%token NUM OP EOL

%%

goal: lines
;

lines:
     | lines expr EOL
     | lines EOL
;

expr: expr OP term
    | term

term: NUM

%%

void yyerror(const char *s)
{
    printf("Parser Error: Unexpected Syntax\n");
}

int main()
{
    yyparse();
    return 0;
}

#include "lex.yy.c"