%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex(void);
    void yyerror(const char *);
%}

%union {
    int num;
    char* id;
}

%token <num> NUM
%token <id> ADD SUB MUL DIV
%token EOL

%%

goal: lines
;

lines: 
     | lines expr EOL {printf("\n");}
     | lines EOL      {printf("\n");}
;

expr: expr ADD factor {printf("+ ");}
    | expr SUB factor {printf("- ");}
    | factor
;

factor: factor MUL term {printf("* ");}
      | factor DIV term {printf("/ ");}
      | term

term: NUM {printf("%d ", yylval.num);}

%%
void yyerror(const char * s)
{
    printf("Parser Error, Invalid Syntax");
}

int main()
{
    yyparse();
    return 0;
}

#include "lex.yy.c"