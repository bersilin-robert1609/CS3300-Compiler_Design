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

%token DEFINEEXPR0 DEFINEEXPR1 DEFINEEXPR2
%token DEFINESTMT0 DEFINESTMT1 DEFINESTMT2
%token CLASS PUBLIC STATIC MAIN RETURN EXTENDS
%token INT BOOLEAN VOID STRING
%token IF WHILE LENGTH ELSE
%token NEW THIS 
%token BTRUE BFALSE 
%token PRNTSTMT
%token OPAREN CPAREN
%token OCURLY CCURLY
%token OSQRE CSQRE
%token SCOLON
%token LAND LOR
%token NEQ LEQ EQ
%token PLUS MINUS MUL DIV
%token EXCLAM COMMA DOT
%token <id> ID 
%token <num> NUM

%type <id> Identifier

%%

goal: MacroDefinitionMultiple MainPart
    | MainPart
;

MacroDefinitionMultiple: MacroDefinition MacroDefinitionMultiple
                       | MacroDefinition
;

MacroDefinition: MacroDefStatement
               | MacroDefExpression
;

MacroDefExpression: DEFINEEXPR0 Identifier OParen CParen OParen Expression CParen {createMacroExpr0($2, $6)}
                  | DEFINEEXPR1 Identifier OParen Identifier CParen OParen Expression CParen {createMacroExpr1($2, $4, $7)}
                  | DEFINEEXPR2 Identifier OParen Identifier Comma Identifier CParen OParen Expression CParen {createMacroExpr2($2, $4, $6, $9)}
;

MacroDefStatement: DEFINESTMT0 Identifier OParen CParen OCurly StatementsList CCurly
                 | DEFINESTMT1 Identifier OParen Identifier CParen OCurly StatementsList CCurly
                 | DEFINESTMT2 Identifier OParen Identifier Comma Identifier CParen OCurly StatementsList CCurly
;

MainPart: MainClass NextPart
;

NextPart: 
        | TypeDeclaration NextPart
;

TypeDeclaration: Class Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly
               | Class Identifier Extends Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly
;

IdentifierDeclarations: 
                      | IdentifierDeclarations IdentifierDeclarationsFinal
;

IdentifierDeclarationsFinal: Type Identifier SColon
;

MethodDeclarationMultiple: 
                         | MethodDeclarationMultiple MethodDeclaration
;

MethodDeclaration:  Public Type Identifier OParen Parameters CParen OCurly
                        IdentifierDeclarations
                        StatementsList
                        Return Expression SColon
                    CCurly
                 |  Public Type Identifier OParen CParen OCurly
                        IdentifierDeclarations
                        StatementsList
                        Return Expression SColon
                    CCurly
;

Parameters: ParametersFinal
          | ParametersFinal Comma Parameters
;

ParametersFinal: Type Identifier
;

MainClass:  Class Identifier OCurly 
                Public Static Void Main OParen String OSqre CSqre Identifier CParen OCurly 
                    PrintStatement OParen Expression CParen SColon 
                CCurly
            CCurly
;

Type: Int OSqre CSqre
    | Boolean
    | Int
    | Identifier
;

StatementsList: 
              | Statement StatementsList
;

Statement: OCurly StatementsList CCurly
         | PrintStatement OParen Expression CParen SColon
         | Identifier Eq Expression SColon
         | Identifier OSqre Expression CSqre Eq Expression SColon
         | If OParen Expression CParen Statement
         | If OParen Expression CParen Statement Else Statement
         | While OParen Expression CParen Statement
         | Identifier OParen ExpressionList CParen SColon
         | Identifier OParen CParen SColon
;

ExpressionList: Expression
              | Expression Comma ExpressionList
;

Expression: PrimaryExpression Land PrimaryExpression
          | PrimaryExpression Lor PrimaryExpression
          | PrimaryExpression Neq PrimaryExpression
          | PrimaryExpression Leq PrimaryExpression
          | PrimaryExpression Plus PrimaryExpression
          | PrimaryExpression Minus PrimaryExpression
          | PrimaryExpression Mul PrimaryExpression
          | PrimaryExpression Div PrimaryExpression
          | PrimaryExpression OSqre PrimaryExpression CSqre
          | PrimaryExpression Dot Length
          | PrimaryExpression
          | PrimaryExpression Dot Identifier OParen CParen
          | PrimaryExpression Dot Identifier OParen ExpressionList CParen
          | Identifier OParen CParen
          | Identifier OParen ExpressionList CParen
;

PrimaryExpression: Number
                 | Btrue
                 | Bfalse
                 | Identifier
                 | This
                 | New Int OSqre Expression CSqre
                 | New Identifier OParen CParen
                 | Exclam Expression 
                 | OParen Expression CParen
;

Class: CLASS {printf("class ");} ;
OCurly: OCURLY {printf(" {\n");} ;
CCurly: CCURLY {printf("\n}\n");} ;
Public: PUBLIC {printf("public ");} ;
Static: STATIC {printf("static ");} ;
Void: VOID {printf("void ");} ;
Main: MAIN {printf("main ");} ;
OParen: OPAREN {printf(" ( ");} ;
CParen: CPAREN {printf(" ) ");} ;
String: STRING {printf(" String ");} ;
OSqre: OSQRE {printf(" [ ");} ;
CSqre: CSQRE {printf(" ] ");} ;
PrintStatement: PRNTSTMT {printf(" System.out.println ");} ;
SColon: SCOLON {printf(" ;\n");} ;
Dot: DOT {printf(" . ");} ;
Length: LENGTH {printf(" length ");} ;
This: THIS {printf(" this ");} ;
New: NEW {printf(" new ");} ;
Int: INT {printf(" int ");} ;
Boolean: BOOLEAN {printf(" boolean ");} ;
Exclam: EXCLAM {printf(" ! ");} ;
Return: RETURN {printf(" return ");} ;
Extends: EXTENDS {printf(" extends ");} ;
Eq: EQ {printf(" = ");} ;
If: IF {printf(" if ");} ;
While: WHILE {printf(" while ");} ;
Else: ELSE {printf(" else ");} ;
Comma: COMMA {printf(" , ");} ;
Land: LAND {printf(" && ");} ;
Lor: LOR {printf(" || ");} ;
Neq: NEQ {printf(" != ");} ;
Leq: LEQ {printf(" <= ");} ;
Plus: PLUS {printf(" + ");} ;
Minus: MINUS {printf(" - ");} ;
Mul: MUL {printf(" * ");} ;
Div: DIV {printf(" / ");} ;
Btrue: BTRUE {printf(" true ");} ;
Bfalse: BFALSE {printf(" false ");} ;

Identifier: ID {printf(" %s ", $1);} ;
Number: NUM {printf(" %d ", $1);} ;
%%

void yyerror(const char *s)
{
    printf("Parser error: Invalid Syntax");
}

int main()
{
    yyparse();
    return 0;
}

#include "lex.yy.c" 