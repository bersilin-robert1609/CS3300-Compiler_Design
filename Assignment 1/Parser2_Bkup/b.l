
WHITESPACE [ \t\r]+
DIGIT [0-9]
INTEGER {DIGIT}+
LETTER [a-zA-Z_]
IDENTIFIER {LETTER}({LETTER}|{DIGIT})*
COMMENTS "//".*

DS0 "#defineStmt0"
DS1 "#defineStmt1"
DS2 "#defineStmt2"

DE0 "#defineExpr0"
DE1 "#defineExpr1"
DE2 "#defineExpr2"

%%

{COMMENTS} {}

{DS0} {return DEFINESTMT0;}
{DS1} {return DEFINESTMT1;}
{DS2} {return DEFINESTMT2;}

{DE0} {return DEFINEEXPR0;}
{DE1} {return DEFINEEXPR1;}
{DE2} {return DEFINEEXPR2;}

{WHITESPACE} {}

"class" {return CLASS;}
"int" {return INT;}
"boolean" {return BOOLEAN;}
"if" {return IF;}
"while" {return WHILE;}
"else" {return ELSE;}
"length" {return LENGTH;}
"new" {return NEW;}
"this" {return THIS;}
"true" {return BTRUE;}
"false" {return BFALSE;}
"System.out.println" {return PRNTSTMT;}
"public" {return PUBLIC;}
"static" {return STATIC;}
"void" {return VOID;}
"main" {return MAIN;}
"String" {return STRING;}
"return" {return RETURN;}
"extends" {return EXTENDS;}

"(" {return OPAREN;}
")" {return CPAREN;}
"{" {return OCURLY;}
"}" {return CCURLY;}
"[" {return OSQRE;}
"]" {return CSQRE;}
";" {return SCOLON;}
"&&" {return LAND;}
"||" {return LOR;}
"!=" {return NEQ;}
"<=" {return LEQ;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"!" {return EXCLAM;}
"," {return COMMA;}
"." {return DOT;}
"=" {return EQ;}

"\n" {}

{IDENTIFIER} {
    yylval.id = strdup(yytext);
    return ID;
} 
{INTEGER} {
    yylval.id = strdup(yytext);
    return NUM;
}

. {printf("Lexer Error! %d Not Valid\n", yytext[0]);}

%%
