%%

[ \t]+"\n" {printf("\n");}
"\t" {printf("    ");}

%%

int main()
{
    yylex();
    return 0;
}