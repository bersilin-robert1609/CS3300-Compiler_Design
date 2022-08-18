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
		fprintf(stderr, "returnLL called %s\n", data);
        LL* temp = (LL*)malloc(sizeof(LL));
        temp->head = returnNode(data);
        temp->tail = temp->head;
        return temp;
    }

    void attach_lists(LL* list1, LL* list2)
    {
		fprintf(stderr, "attach_lists called\n");
        if(list2 != NULL && list1 != NULL) list1->tail->next = list2->head;
		else return;
        list1->tail = list2->tail;
    }

	void printLL(LL* list)
	{
		fprintf(stderr, "\n\nprintLL called\n");
		Node* temp = list->head;
		while(temp != NULL)
		{
			printf("%s", temp->data);
			temp = temp->next;
		}
	}
%}

%union {
    int num;
    char* id;
    LL* llPtr;
}

%token <id> DEFINEEXPR0 DEFINEEXPR1 DEFINEEXPR2 
%token <id> DEFINESTMT0 DEFINESTMT1 DEFINESTMT2 
%token <id> CLASS PUBLIC STATIC MAIN RETURN EXTENDS
%token <id> INT BOOLEAN VOID STRING LENGTH
%token <id> IF WHILE ELSE
%token <id> NEW THIS 
%token <id> BTRUE BFALSE 
%token <id> PRNTSTMT
%token <id> OPAREN CPAREN
%token <id> OCURLY CCURLY
%token <id> OSQRE CSQRE
%token <id> SCOLON
%token <id> LAND LOR
%token <id> NEQ LEQ EQ
%token <id> PLUS MINUS MUL DIV
%token <id> EXCLAM COMMA DOT
%token <id> ID 
%token <id> NUM

%type <llPtr> Identifier Class Public Static Main Return Extends Int Boolean Void String Bfalse Btrue New This Length
%type <llPtr> If Else While PrintStatement OParen CParen OCurly CCurly OSqre CSqre
%type <llPtr> SColon Land Lor Neq Leq Eq Plus Minus Mul Div Exclam Comma Dot
%type <llPtr> goal Expression Statement StatementsList MacroDefinition MacroDefExpression MacroDefStatement MainClass MainPart MiniGoal
%type <llPtr> MacroDefinitionMultiple NextPart TypeDeclaration IdentifierDeclarations IdentifierDeclarationsFinal MethodDeclaration MethodDeclarationMultiple
%type <llPtr> Parameters ParametersFinal Type ExpressionList PrimaryExpression Number
%type <llPtr> DefineExpr0 DefineExpr1 DefineExpr2 
%type <llPtr> DefineStmt0 DefineStmt1 DefineStmt2 

%%

goal: MiniGoal {$$ = $1; printLL($$);}
;

MiniGoal: MacroDefinitionMultiple MainPart
		{
			$$ = $1;
			if($$ != NULL) attach_lists($$, $2);
			else $$ = $2;
		}
        | MainPart {$$ = $1;}
;

MacroDefinitionMultiple: MacroDefinition MacroDefinitionMultiple
					   {
						$$ = $1;
						attach_lists($$, $2);
					   }
                       | MacroDefinition {$$ = $1;}
;

MacroDefinition: MacroDefStatement {$$ = $1;}
               | MacroDefExpression {$$ = $1;}
;

MacroDefExpression: DefineExpr0 Identifier OParen CParen OParen Expression CParen
                  {
                  $$ = $1;
                  attach_lists($$, $2);
                  attach_lists($$, $3);
                  attach_lists($$, $4);
                  attach_lists($$, $5);
                  attach_lists($$, $6);
                  attach_lists($$, $7);
                  }
                  | DefineExpr1 Identifier OParen Identifier CParen OParen Expression CParen 
				  {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
					attach_lists($$, $8);
				  }
                  | DefineExpr2 Identifier OParen Identifier Comma Identifier CParen OParen Expression CParen 
				  {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
					attach_lists($$, $8);
					attach_lists($$, $9);
					attach_lists($$, $10);
				 }
;

MacroDefStatement: DefineStmt0 Identifier OParen CParen OCurly StatementsList CCurly
				 {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
				 }
                 | DefineStmt1 Identifier OParen Identifier CParen OCurly StatementsList CCurly
				 {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
					attach_lists($$, $8);
				 }
                 | DefineStmt2 Identifier OParen Identifier Comma Identifier CParen OCurly StatementsList CCurly
				 {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
					attach_lists($$, $8);
					attach_lists($$, $9);
					attach_lists($$, $10);
				 }
;

MainPart: MainClass NextPart
		{
			$$ = $1;
			attach_lists($$, $2);
		}
;

NextPart: {$$ = NULL;}
        | TypeDeclaration NextPart
		{
			$$ = $1;
			attach_lists($$, $2);
		}
;

TypeDeclaration: Class Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly
				{
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
				}
               | Class Identifier Extends Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly
			    {
					$$ = $1;
					attach_lists($$, $2);
					attach_lists($$, $3);
					attach_lists($$, $4);
					attach_lists($$, $5);
					attach_lists($$, $6);
					attach_lists($$, $7);
					attach_lists($$, $8);
				 }
;

IdentifierDeclarations: {$$ = NULL;}
                      | IdentifierDeclarations IdentifierDeclarationsFinal
					  {
						$$ = $1;
						if($$ != NULL) attach_lists($$, $2);
						else $$ = $2;
					  }
;

IdentifierDeclarationsFinal: Type Identifier SColon
						    {
								$$ = $1;
								attach_lists($$, $2);
								attach_lists($$, $3);
						    }
;

MethodDeclarationMultiple: {$$ = NULL;}
                         | MethodDeclaration MethodDeclarationMultiple
						 {
							$$ = $1;
							attach_lists($$, $2);
						 }
;

MethodDeclaration:  Public Type Identifier OParen Parameters CParen OCurly
                        IdentifierDeclarations
                        StatementsList
                        Return Expression SColon
                    CCurly
					{
						$$ = $1;
						attach_lists($$, $2);
						attach_lists($$, $3);
						attach_lists($$, $4);
						attach_lists($$, $5);
						attach_lists($$, $6);
						attach_lists($$, $7);
						attach_lists($$, $8);
						attach_lists($$, $9);
						attach_lists($$, $10);
						attach_lists($$, $11);
						attach_lists($$, $12);
						attach_lists($$, $13);
					}
                 |  Public Type Identifier OParen CParen OCurly
                        IdentifierDeclarations
                        StatementsList
                        Return Expression SColon
                    CCurly
					{
						$$ = $1;
						attach_lists($$, $2);
						attach_lists($$, $3);
						attach_lists($$, $4);
						attach_lists($$, $5);
						attach_lists($$, $6);
						attach_lists($$, $7);
						attach_lists($$, $8);
						attach_lists($$, $9);
						attach_lists($$, $10);
						attach_lists($$, $11);
						attach_lists($$, $12);
					}
;

Parameters: ParametersFinal {$$ = $1;}
          | ParametersFinal Comma Parameters
		  {
			  $$ = $1;
			  attach_lists($$, $2);
		  }
;

ParametersFinal: Type Identifier 
			   {
				   $$ = $1;
				   attach_lists($$, $2);
			   }
;

MainClass:  Class Identifier OCurly 
                Public Static Void Main OParen String OSqre CSqre Identifier CParen OCurly 
                    PrintStatement OParen Expression CParen SColon 
                CCurly
            CCurly
			{
				$$ = $1;
            	attach_lists($$, $2);
            	attach_lists($$, $3);
            	attach_lists($$, $4);
            	attach_lists($$, $5);
            	attach_lists($$, $6);
				attach_lists($$, $7);
				attach_lists($$, $8);
            	attach_lists($$, $9);
            	attach_lists($$, $10);
            	attach_lists($$, $11);
            	attach_lists($$, $12);
				attach_lists($$, $13);
				attach_lists($$, $14);
            	attach_lists($$, $15);
            	attach_lists($$, $16);
            	attach_lists($$, $17);
            	attach_lists($$, $18);
				attach_lists($$, $19);
				attach_lists($$, $20);
				attach_lists($$, $21);
			}
;

Type: Int OSqre CSqre
	{
		$$ = $1;
		attach_lists($$, $2);
		attach_lists($$, $3);
	}
    | Boolean {$$ = $1;}
    | Int {$$ = $1;}
    | Identifier {$$ = $1;}
;

StatementsList: {$$ = NULL;}
              | Statement StatementsList 
			  {
				$$ = $1;
				attach_lists($$, $2);
			  }
;

Statement: OCurly StatementsList CCurly
         {
			$$ = $1;
			attach_lists($$, $2);
			attach_lists($$, $3);
         }
         | PrintStatement OParen Expression CParen SColon
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
		 }
         | Identifier Eq Expression SColon
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
		 }
         | Identifier OSqre Expression CSqre Eq Expression SColon
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
            attach_lists($$, $6);
			attach_lists($$, $7);
		 }
         | If OParen Expression CParen Statement
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
		 }
         | If OParen Expression CParen Statement Else Statement
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
            attach_lists($$, $6);
			      attach_lists($$, $7);
		 }
         | While OParen Expression CParen Statement
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
		 }
         | Identifier OParen ExpressionList CParen SColon
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
		 }
         | Identifier OParen CParen SColon
		 {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
		 }
;

ExpressionList: Expression
              {
                $$ = $1;
              }
              | Expression Comma ExpressionList
              {
                $$ = $1;
                attach_lists($$, $2);
                attach_lists($$, $3);
              }
;

Expression: PrimaryExpression Land PrimaryExpression 
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Lor PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Neq PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Leq PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Plus PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Minus PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Mul PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression Div PrimaryExpression
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression OSqre PrimaryExpression CSqre
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
          }
          | PrimaryExpression Dot Length
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | PrimaryExpression
          {
            $$ = $1;
          }
          | PrimaryExpression Dot Identifier OParen CParen
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
          }
          | PrimaryExpression Dot Identifier OParen ExpressionList CParen
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
            attach_lists($$, $5);
            attach_lists($$, $6);
          }
          | Identifier OParen CParen
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
          }
          | Identifier OParen ExpressionList CParen
          {
            $$ = $1;
            attach_lists($$, $2);
            attach_lists($$, $3);
            attach_lists($$, $4);
          }
;

PrimaryExpression: Number       { $$ = $1; }
                 | Btrue        { $$ = $1; }
                 | Bfalse       { $$ = $1; }
                 | Identifier   { $$ = $1; }
                 | This         { $$ = $1; }
                 | New Int OSqre Expression CSqre 
                 {
                    $$ = $1; 
                    attach_lists($$, $2);
                    attach_lists($$, $3);
                    attach_lists($$, $4);
                    attach_lists($$, $5);
                 }
                 | New Identifier OParen CParen
                 {
                    $$ = $1; 
                    attach_lists($$, $2);
                    attach_lists($$, $3);
                    attach_lists($$, $4);
                 }
                 | Exclam Expression 
                 {
                    $$ = $1; 
                    attach_lists($$, $2);
                 }
                 | OParen Expression CParen
                 {
                    $$ = $1;
                    attach_lists($$, $2);
                    attach_lists($$, $3);
                 }
;

Class: CLASS                { LL* temp = returnLL("\nclass "); $$ = temp;} ;
OCurly: OCURLY              { LL* temp = returnLL(" {\n"); $$ = temp;} ;
CCurly: CCURLY              { LL* temp = returnLL("\n}\n"); $$ = temp;} ;
Public: PUBLIC              { LL* temp = returnLL("public "); $$ = temp;} ;
Static: STATIC              { LL* temp = returnLL("static "); $$ = temp;} ;
Void: VOID                  { LL* temp = returnLL("void "); $$ = temp;} ;
Main: MAIN                  { LL* temp = returnLL("main "); $$ = temp;} ;
OParen: OPAREN              { LL* temp = returnLL(" ("); $$ = temp;} ;
CParen: CPAREN              { LL* temp = returnLL(") "); $$ = temp;} ;
String: STRING              { LL* temp = returnLL("String "); $$ = temp;} ;
OSqre: OSQRE                { LL* temp = returnLL(" ["); $$ = temp;} ;
CSqre: CSQRE                { LL* temp = returnLL("] "); $$ = temp;} ;
PrintStatement: PRNTSTMT    { LL* temp = returnLL("System.out.println"); $$ = temp;} ;
SColon: SCOLON              { LL* temp = returnLL(";\n"); $$ = temp;} ;
Dot: DOT                    { LL* temp = returnLL("."); $$ = temp;} ;
Length: LENGTH              { LL* temp = returnLL("length"); $$ = temp;} ;
This: THIS                  { LL* temp = returnLL("this"); $$ = temp;} ;
New: NEW                    { LL* temp = returnLL("new "); $$ = temp;} ;
Int: INT                    { LL* temp = returnLL("int "); $$ = temp;} ;
Boolean: BOOLEAN            { LL* temp = returnLL("boolean "); $$ = temp;} ;
Exclam: EXCLAM              { LL* temp = returnLL("!"); $$ = temp;} ;
Return: RETURN              { LL* temp = returnLL("return "); $$ = temp;} ;
Extends: EXTENDS            { LL* temp = returnLL("extends "); $$ = temp;} ;
Eq: EQ                      { LL* temp = returnLL(" = "); $$ = temp;} ;
If: IF                      { LL* temp = returnLL("if "); $$ = temp;} ;
Else: ELSE                  { LL* temp = returnLL("else "); $$ = temp;} ;
While: WHILE                { LL* temp = returnLL("while "); $$ = temp;} ;
Comma: COMMA                { LL* temp = returnLL(","); $$ = temp;} ;
Land: LAND                  { LL* temp = returnLL(" && "); $$ = temp;} ;
Lor: LOR                    { LL* temp = returnLL(" || "); $$ = temp;} ;
Neq: NEQ                    { LL* temp = returnLL(" != "); $$ = temp;} ;
Leq: LEQ                    { LL* temp = returnLL(" <= "); $$ = temp;} ;
Plus: PLUS                  { LL* temp = returnLL(" + "); $$ = temp;} ;
Minus: MINUS                { LL* temp = returnLL(" - "); $$ = temp;} ;
Mul: MUL                    { LL* temp = returnLL(" * "); $$ = temp;} ;
Div: DIV                    { LL* temp = returnLL(" / "); $$ = temp;} ;
Btrue: BTRUE                { LL* temp = returnLL("true"); $$ = temp;} ;
Bfalse: BFALSE              { LL* temp = returnLL("false"); $$ = temp;} ;
DefineExpr0: DEFINEEXPR0    { LL* temp = returnLL("#defineexpr0 "); $$ = temp;} ;
DefineExpr1: DEFINEEXPR1    { LL* temp = returnLL("#defineexpr1 "); $$ = temp;} ;
DefineExpr2: DEFINEEXPR2    { LL* temp = returnLL("#defineexpr2 "); $$ = temp;} ;

DefineStmt0: DEFINESTMT0	  { LL* temp = returnLL("#definestmt0 "); $$ = temp;} ;
DefineStmt1: DEFINESTMT1	  { LL* temp = returnLL("#definestmt1 "); $$ = temp;} ;
DefineStmt2: DEFINESTMT2	  { LL* temp = returnLL("#definestmt2 "); $$ = temp;} ;

Identifier: ID              { LL* temp = returnLL($1); $$ = temp;} ;
Number: NUM                 { LL* temp = returnLL($1); $$ = temp;} ;
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