%{
    #define MAX_BUF 200

    char* macros[8];
    char* replacements[8];
    int i = 0;
    void create_macro(char* macro_definition)
    {
        //printf("called for %s", macro_definition);
        int j=0;
        while(macro_definition[j] != ' ') j++;
        while(macro_definition[j] == ' ') j++;

        macros[i] = (char*)malloc(MAX_BUF);
        int k = 0;
        while(macro_definition[j] != ' ')
        {
            macros[i][k] = macro_definition[j];
            j++; k++;
        }
        macros[i][k+1] = 0;

        while(macro_definition[j] == ' ') j++;

        replacements[i] = (char*)malloc(MAX_BUF);
        k = 0;
        while(macro_definition[j] != '\n')
        {
            replacements[i][k] = macro_definition[j];
            j++; k++;
        }
        replacements[i][k+1] = 0;
        i++;
    }

    char* print_replacement(char* macro_name)
    {
        //printf("Called for %s", macro_name);
        int j = 0;
        while(j<i)
        {
            if(strcmp(macro_name, macros[j]) == 0) return replacements[j]; // 0 if equal
            j++;
        }
        return macro_name;
    }

    void print_macros()
    {
        printf("\n");
        int j = 0;
        while(j<i)
        {
            printf("Macro is %s", macros[j]);
            printf(" Replacement is %s\n", replacements[j]);
            j++;
        }
        return;
    }
%}

DIGIT [0-9]
LETTER [a-zA-Z]
MACRONAME {LETTER}({LETTER}|{DIGIT})*
WHITESPACE [ ]+
MACRO "#define"{WHITESPACE}{MACRONAME}{WHITESPACE}.*"\n"

%%

{MACRO} {create_macro(yytext); /*print_macros();*/}
{MACRONAME} {printf("%s", print_replacement(yytext));}

%%
int main()
{
    yylex();
    return 0;
}