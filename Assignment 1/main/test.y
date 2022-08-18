%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <stdarg.h>

    int yylex(void);
    void yyerror(const char *);

    typedef struct Node {
        char *data;
        struct Node *next;
    }Node;

    Node* returnNode(char* data)
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    typedef struct LinkedList {
        Node *head;
        Node *tail;
    }LL;

    LL* returnLL(char* data)
    {
        LL* temp = (LL*)malloc(sizeof(LL));
        temp->head = returnNode(data);
        temp->tail = temp->head;
        return temp;
    }
%}

%union {
    int num;
    char* id;
    LL* llPtr;
}

%token <llPtr> DEFINEEXPR0 DEFINEEXPR1 DEFINEEXPR2
%token <llPtr> DEFINESTMT0 DEFINESTMT1 DEFINESTMT2
%token <llPtr> CLASS PUBLIC STATIC MAIN RETURN EXTENDS
%token <llPtr> INT BOOLEAN VOID STRING LENGTH
%token <llPtr> IF WHILE ELSE
%token <llPtr> NEW THIS 
%token <llPtr> BTRUE BFALSE 
%token <llPtr> PRNTSTMT
%token <llPtr> OPAREN CPAREN
%token <llPtr> OCURLY CCURLY
%token <llPtr> OSQRE CSQRE
%token <llPtr> SCOLON
%token <llPtr> LAND LOR
%token <llPtr> NEQ LEQ EQ
%token <llPtr> PLUS MINUS MUL DIV
%token <llPtr> EXCLAM COMMA DOT
%token <llPtr> ID 
%token <llPtr> NUM

%type <llPtr> Identifier, Class, Public, Static, Main, Return, Extends, Int, Boolean, Void, String, Bfalse, Btrue, New, This, Length
%type <llPtr> If, Else, While, PrintStatement, OParen, CParen, OCurly, CCurly, OSqre, CSqre
%type <llPtr> SColon, Land, Lor, Neq, Leq, Eq, Plus, Minus, Mul, Div, Exclam, Comma, Dot
%type <llPtr> goal, Expression, Statement, StatementsList, MacroDefinition, MacroDefExpression, MacroDefStatement, MainClass, MainPart
%type <llPtr> MacroDefinitionMultiple, NextPart, TypeDeclaration, IdentifierDeclarations, IdentifierDeclarationsFinal, MethodDeclaration, MethodDeclarationMultiple
%type <llPtr> Parameters, ParametersFinal, Type, ExpressionList, PrimaryExpression, Number

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

MacroDefExpression: DEFINEEXPR0 Identifier OParen CParen OParen Expression CParen
                  | DEFINEEXPR1 Identifier OParen Identifier CParen OParen Expression CParen 
                  | DEFINEEXPR2 Identifier OParen Identifier Comma Identifier CParen OParen Expression CParen 
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

Class: CLASS                {printf("\nclass "); LL* temp = returnLL("class"); $$ = temp;} ;
OCurly: OCURLY              {printf(" {\n"); LL* temp = returnLL("{"); $$ = temp;} ;
CCurly: CCURLY              {printf("\n}\n"); LL* temp = returnLL("}"); $$ = temp;} ;
Public: PUBLIC              {printf("public "); LL* temp = returnLL("public"); $$ = temp;} ;
Static: STATIC              {printf("static "); LL* temp = returnLL("static"); $$ = temp;} ;
Void: VOID                  {printf("void "); LL* temp = returnLL("void"); $$ = temp;} ;
Main: MAIN                  {printf("main "); LL* temp = returnLL("main"); $$ = temp;} ;
OParen: OPAREN              {printf(" ("); LL* temp = returnLL("("); $$ = temp;} ;
CParen: CPAREN              {printf(") "); LL* temp = returnLL(")"); $$ = temp;} ;
String: STRING              {printf("String "); LL* temp = returnLL("String"); $$ = temp;} ;
OSqre: OSQRE                {printf(" ["); LL* temp = returnLL("["); $$ = temp;} ;
CSqre: CSQRE                {printf("] "); LL* temp = returnLL("]"); $$ = temp;} ;
PrintStatement: PRNTSTMT    {printf("System.out.println"); LL* temp = returnLL("System.out.println"); $$ = temp;} ;
SColon: SCOLON              {printf(";\n"); LL* temp = returnLL(";"); $$ = temp;} ;
Dot: DOT                    {printf("."); LL* temp = returnLL("."); $$ = temp;} ;
Length: LENGTH              {printf("length"); LL* temp = returnLL("length"); $$ = temp;} ;
This: THIS                  {printf("this"); LL* temp = returnLL("this"); $$ = temp;} ;
New: NEW                    {printf("new "); LL* temp = returnLL("new"); $$ = temp;} ;
Int: INT                    {printf("int "); LL* temp = returnLL("int"); $$ = temp;} ;
Boolean: BOOLEAN            {printf("boolean "); LL* temp = returnLL("boolean"); $$ = temp;} ;
Exclam: EXCLAM              {printf("!"); LL* temp = returnLL("!"); $$ = temp;} ;
Return: RETURN              {printf("return "); LL* temp = returnLL("return"); $$ = temp;} ;
Extends: EXTENDS            {printf("extends "); LL* temp = returnLL("extends"); $$ = temp;} ;
Eq: EQ                      {printf(" = "); LL* temp = returnLL("="); $$ = temp;} ;
If: IF                      {printf("if "); LL* temp = returnLL("if"); $$ = temp;} ;
Else: ELSE                  {printf("else "); LL* temp = returnLL("else"); $$ = temp;} ;
While: WHILE                {printf("while "); LL* temp = returnLL("while"); $$ = temp;} ;
Comma: COMMA                {printf(","); LL* temp = returnLL(","); $$ = temp;} ;
Land: LAND                  {printf(" && "); LL* temp = returnLL("&&"); $$ = temp;} ;
Lor: LOR                    {printf(" || "); LL* temp = returnLL("||"); $$ = temp;} ;
Neq: NEQ                    {printf(" != "); LL* temp = returnLL("!="); $$ = temp;} ;
Leq: LEQ                    {printf(" <= "); LL* temp = returnLL("<="); $$ = temp;} ;
Plus: PLUS                  {printf(" + "); LL* temp = returnLL("+"); $$ = temp;} ;
Minus: MINUS                {printf(" - "); LL* temp = returnLL("-"); $$ = temp;} ;
Mul: MUL                    {printf(" * "); LL* temp = returnLL("*"); $$ = temp;} ;
Div: DIV                    {printf(" / "); LL* temp = returnLL("/"); $$ = temp;} ;
Btrue: BTRUE                {printf("true"); LL* temp = returnLL("true"); $$ = temp;} ;
Bfalse: BFALSE              {printf("false"); LL* temp = returnLL("false"); $$ = temp;} ;

Identifier: ID              {printf(" %s ", $1); LL* temp = returnLL($1); $$ = temp;} ;
Number: NUM                 {printf(" %s ", $1); LL* temp = returnLL($1); $$ = temp;} ;
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