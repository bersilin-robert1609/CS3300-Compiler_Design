DIGIT [0-9]
LETTER [A-Za-z_]
INTEGER [+-]?{DIGIT}+
DECIMAL {INTEGER}"."{DIGIT}*|[+-]?"."{DIGIT}+
REAL ({DECIMAL}|{INTEGER})[Ee]{INTEGER}
ID {LETTER}({DIGIT}|{LETTER})*

%%

{ID} {}
{REAL} {printf("REAL: %s\n", yytext);}
{DECIMAL} {printf("DECIMAL: %s\n", yytext);}
{INTEGER} {printf("INTEGER: %s\n", yytext);}
. {}
"\n"

%%
int main()
{
    yylex();
    return 0;
}