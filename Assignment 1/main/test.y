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
    } Node;

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
    } LL;

	//macros global variables

	typedef struct Macro {
		char* macroId;
		LL* args;
		LL* replacement;
		struct Macro* next;

		//0 - expr0, 1 - multi, -1 - stmt0, -2 - multi
		int macroType;  
	} Macro;
	
	typedef struct macroList {
		struct Macro* head;
		struct Macro* tail;
	} macroList;

	macroList* macroTable;
	void initiate_macro_list()
	{
		macroTable = (macroList*)malloc(sizeof(macroList));
		macroTable->head = NULL;
		macroTable->tail = NULL;
	}

	//macros global variables close

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

	void addMacro(Macro* macro)
	{
		fprintf(stderr, "addMacro called with %s\n", macro->macroId);
		if(macroTable->head == NULL)
		{
			macroTable->head = macro;
			macroTable->tail = macro;
		}
		else
		{
			macroTable->tail->next = macro;
			macroTable->tail = macro;
		}
	}

	void create_macro_definition_expr0(LL* idList, LL* exprList)
	{
		fprintf(stderr, "create_macro_definition_expr0 called\n");
		LL* args = returnLL(idList->head->data);
		fprintf(stderr, "args created with %s\n", args->head->data);
		LL* replacement = returnLL(exprList->head->data);
		Node* ptr = exprList->head->next;
		while(ptr != NULL)
		{
			LL* temp = returnLL(ptr->data);
			attach_lists(replacement, temp);
			ptr = ptr->next;
		}

		Macro* temp = (Macro*)malloc(sizeof(Macro));
		temp->macroId = strdup(idList->head->data);
		temp->args = args;
		temp->replacement = replacement;
		temp->next = NULL;
		temp->macroType = 0;
		addMacro(temp);
	}

	void create_macro_definition_stmt0(LL* idList, LL* stmtList)
	{
		fprintf(stderr, "create_macro_definition_stmt0 called\n");
		LL* args = returnLL(idList->head->data);
		fprintf(stderr, "args created with %s\n", args->head->data);
		LL* replacement = returnLL(stmtList->head->data);
		Node* ptr = stmtList->head->next;
		while(ptr != NULL)
		{
			LL* temp = returnLL(ptr->data);
			attach_lists(replacement, temp);
			ptr = ptr->next;
		}

		Macro* temp = (Macro*)malloc(sizeof(Macro));
		temp->macroId = strdup(idList->head->data);
		temp->args = args;
		temp->replacement = replacement;
		temp->next = NULL;
		temp->macroType = -1;
		addMacro(temp);
	}

	LL* replace_macro_stmt0(LL* idList)
	{
		fprintf(stderr, "replace_macro_stmt0 called\n");
		Macro* temp = macroTable->head;
		while(temp != NULL)
		{
			if(strcmp(temp->macroId, idList->head->data) == 0)
			{
				if(temp->macroType == -1)
				{
					LL* temp2 = returnLL(temp->replacement->head->data);
					Node* ptr = temp->replacement->head->next;
					while(ptr != NULL)
					{
						LL* temp3 = returnLL(ptr->data);
						attach_lists(temp2, temp3);
						ptr = ptr->next;
					}
					return temp2;
				}
			}
			temp = temp->next;
		}
		return NULL;
	}

	LL* replace_macro_expr0(LL* idList)
	{
		fprintf(stderr, "replace_macro_expr0 called\n");
		Macro* temp = macroTable->head;
		while(temp != NULL)
		{
			if(strcmp(temp->macroId, idList->head->data) == 0)
			{
				if(temp->macroType == 0)
				{
					LL* temp2 = returnLL(temp->replacement->head->data);
					Node* ptr = temp->replacement->head->next;
					while(ptr != NULL)
					{
						LL* temp3 = returnLL(ptr->data);
						attach_lists(temp2, temp3);
						ptr = ptr->next;
					}
					return temp2;
				}
			}
			temp = temp->next;
		}
		return replace_macro_stmt0(idList);
	}

	//Expression with multi argument
	void create_macro_definition_expr_multi(LL* idList, LL* exprList)
	{
		fprintf(stderr, "create_macro_definition_expr_multi called\n");
		LL* args = returnLL(idList->head->data);
		fprintf(stderr, "args created with %s\n", args->head->data);

		Node* ptr = idList->head->next;
		while(ptr != NULL)
		{
			LL* temp = returnLL(ptr->data);
			attach_lists(args, temp);
			ptr = ptr->next;
		}

		LL* replacement = returnLL(exprList->head->data);
		ptr = exprList->head->next;
		while(ptr != NULL)
		{
			LL* temp = returnLL(ptr->data);
			attach_lists(replacement, temp);
			ptr = ptr->next;
		}

		Macro* temp = (Macro*)malloc(sizeof(Macro));
		temp->macroId = strdup(idList->head->data);
		temp->args = args;
		temp->replacement = replacement;
		temp->next = NULL;
		temp->macroType = 1;
		addMacro(temp);
	}

	LL* replace_macro_expr_multi(LL* idList)
	{
		fprintf(stderr, "replace_macro_expr_multi called\n");
		Macro* temp = macroTable->head;
		while(temp != NULL)
		{
			if(strcmp(temp->macroId, idList->head->data) == 0)
			{
				if(temp->macroType == 1)
				{
					LL* temp2 = returnLL(temp->replacement->head->data);
					Node* ptr = temp->replacement->head->next;
					while(ptr != NULL)
					{
						LL* temp3 = returnLL(ptr->data);
						attach_lists(temp2, temp3);
						ptr = ptr->next;
					}
					//temp2 has whole expression
					break;
				}
			}
			temp = temp->next;
		}

		Node* ptr = idList->head->next;
		Node* macroArgs = temp->args->head->next;
		while(ptr != NULL)
		{
			char* identifierTemp = strdup(ptr->data);
			char* macroId = strdup(macroArgs->data);
			Node* ptr2 = temp2->head;
			while(ptr2 != NULL)
			{
				if(strcmp(ptr2->data, macroId) == 0)
				{
					ptr2->data = strdup(identifierTemp);
				}
				ptr2 = ptr2->next;
			}
			ptr = ptr->next;
			macroArgs = macroArgs->next;
		}

		return temp2;
	}
%}

%union {
    int num;
    char* id;
    LL* llPtr;
}

%token <id> DEFINEEXPR0 DEFINEEXPR1 DEFINEEXPR2 DEFINEEXPR
%token <id> DEFINESTMT0 DEFINESTMT1 DEFINESTMT2 DEFINESTMT
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
%type <llPtr> Parameters ParametersFinal Type ExpressionList PrimaryExpression Number IdentifiersList ExtraIdentifier
%type <llPtr> DefineExpr0 DefineExpr1 DefineExpr2 DefineExpr
%type <llPtr> DefineStmt0 DefineStmt1 DefineStmt2 DefineStmt

%%

goal: MiniGoal {$$ = $1; printLL($$);}
;

MiniGoal: MacroDefinitionMultiple MainPart
		{
			$$ = $2;
		}
        | MainPart {$$ = $1;}
;

MacroDefinitionMultiple: MacroDefinition MacroDefinitionMultiple
                       | MacroDefinition
;

MacroDefinition: MacroDefStatement
               | MacroDefExpression
;

MacroDefExpression: DefineExpr Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OParen Expression CParen
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
				  | DefineExpr0 Identifier OParen CParen OParen Expression CParen
				  {
					create_macro_definition_expr0($2, $6);
				  }
                  | DefineExpr1 Identifier OParen Identifier CParen OParen Expression CParen 
				  {
					LL* idList = returnLL($2);
					LL* first_argument = returnLL($4);
					attach_lists(idList, first_argument);
					create_macro_definition_expr_multi(idList, $7);
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

MacroDefStatement: DefineStmt Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OCurly StatementsList CCurly
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
				 | DefineStmt0 Identifier OParen CParen OCurly StatementsList CCurly
				 {
					create_macro_definition_stmt0($2, $6);
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

IdentifiersList: {$$ = NULL;}
			   | ExtraIdentifier IdentifiersList
			   {
					$$ = $1;
					attach_lists($$, $2);
			   }
;

ExtraIdentifier: Comma Identifier
				{
					$$ = $1;
					attach_lists($$, $2);
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
            $$ = replace_macro_expr0($1);
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
			$$ = replace_macro_expr0($1);
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

Class: CLASS                { $$ = returnLL("class ");} ;
OCurly: OCURLY              { $$ = returnLL(" {\n");} ;
CCurly: CCURLY              { $$ = returnLL("}\n");} ;
Public: PUBLIC              { $$ = returnLL("public ");} ;
Static: STATIC              { $$ = returnLL("static ");} ;
Void: VOID                  { $$ = returnLL("void ");} ;
Main: MAIN                  { $$ = returnLL("main ");} ;
OParen: OPAREN              { $$ = returnLL("(");} ;
CParen: CPAREN              { $$ = returnLL(")");} ;
String: STRING              { $$ = returnLL("String ");} ;
OSqre: OSQRE                { $$ = returnLL("[");} ;
CSqre: CSQRE                { $$ = returnLL("] ");} ;
PrintStatement: PRNTSTMT    { $$ = returnLL("System.out.println");} ;
SColon: SCOLON              { $$ = returnLL(";\n");} ;
Dot: DOT                    { $$ = returnLL(".");} ;
Length: LENGTH              { $$ = returnLL("length");} ;
This: THIS                  { $$ = returnLL("this");} ;
New: NEW                    { $$ = returnLL("new ");} ;
Int: INT                    { $$ = returnLL("int ");} ;
Boolean: BOOLEAN            { $$ = returnLL("boolean ");} ;
Exclam: EXCLAM              { $$ = returnLL("!");} ;
Return: RETURN              { $$ = returnLL("return ");} ;
Extends: EXTENDS            { $$ = returnLL("extends ");} ;
Eq: EQ                      { $$ = returnLL(" = ");} ;
If: IF                      { $$ = returnLL("if ");} ;
Else: ELSE                  { $$ = returnLL("else ");} ;
While: WHILE                { $$ = returnLL("while ");} ;
Comma: COMMA                { $$ = returnLL(",");} ;
Land: LAND                  { $$ = returnLL(" && ");} ;
Lor: LOR                    { $$ = returnLL(" || ");} ;
Neq: NEQ                    { $$ = returnLL(" != ");} ;
Leq: LEQ                    { $$ = returnLL(" <= ");} ;
Plus: PLUS                  { $$ = returnLL(" + ");} ;
Minus: MINUS                { $$ = returnLL(" - ");} ;
Mul: MUL                    { $$ = returnLL(" * ");} ;
Div: DIV                    { $$ = returnLL(" / ");} ;
Btrue: BTRUE                { $$ = returnLL("true");} ;
Bfalse: BFALSE              { $$ = returnLL("false");} ;
DefineExpr0: DEFINEEXPR0    { $$ = returnLL("#defineexpr0 ");} ;
DefineExpr1: DEFINEEXPR1    { $$ = returnLL("#defineexpr1 ");} ;
DefineExpr2: DEFINEEXPR2    { $$ = returnLL("#defineexpr2 ");} ;
DefineExpr: DEFINEEXPR		{ $$ = returnLL("#defineexpr ");} ;
DefineStmt0: DEFINESTMT0	{ $$ = returnLL("#definestmt0 ");} ;
DefineStmt1: DEFINESTMT1	{ $$ = returnLL("#definestmt1 ");} ;
DefineStmt2: DEFINESTMT2	{ $$ = returnLL("#definestmt2 ");} ;
DefineStmt: DEFINESTMT		{ $$ = returnLL("#definestmt ");} ;

Identifier: ID              { $$ = returnLL($1);} ;
Number: NUM                 { $$ = returnLL($1);} ;
%%

void yyerror(const char *s)
{
    printf("Parser error: Invalid Syntax");
}

int main()
{
	initiate_macro_list();
    yyparse();
    return 0;
}

#include "lex.yy.c" 