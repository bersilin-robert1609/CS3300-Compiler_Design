/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "test.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>

	/*
	 * 1 - enable debug, 0 - disable debug
	 * debug prints in stderr to keep output clean
	 */
	int DEBUG = 0;

    int yylex(void);
    void yyerror(const char *);

    typedef struct Node 
	{ // node for the linked list

        char *data;
        struct Node *next;
    } Node;

    Node* returnNode(char* data)
    { // return a node pointer with the given data

        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;
        return temp;
    }

    typedef struct LinkedList 
	{ // linked list defintion

        Node *head;
        Node *tail;
    } LL;

	typedef struct Macro 
	{ // macro definition

		char* macroId;
		LL* args;			// this has the identifier and the other arguments of the macro call
		LL* replacement;    // this is the replacement for the macro
		struct Macro* next;
		int macroType;  //0 - single , 1 - multi
	} Macro;
	
	typedef struct macroList 
	{ // linked list of macros

		struct Macro* head;
		struct Macro* tail;
	} macroList;

	// global macrotable
	macroList* macroTable;

	void initiate_macro_list()
	{ // initiate the macro list, called from main

		macroTable = (macroList*)malloc(sizeof(macroList));
		macroTable->head = NULL;
		macroTable->tail = NULL;
	}

    LL* returnLL(char* data)
    { // returns a linked list with the given data

		if(DEBUG) fprintf(stderr, "returnLL called %s\n", data);
        LL* temp = (LL*)malloc(sizeof(LL));
        temp->head = returnNode(data);
        temp->tail = temp->head;
        return temp;
    }

    void attach_lists(LL* list1, LL* list2)
    { // attach list2 to the end of list1

		if(DEBUG) fprintf(stderr, "attach_lists called\n");
        if(list2 != NULL && list1 != NULL) 
			list1->tail->next = list2->head;
		else return;
        list1->tail = list2->tail;
    }

	void printLL(LL* list)
	{ // print the linked list, only called once at goal

		if(DEBUG) fprintf(stderr, "printLL called\n");
		Node* temp = list->head;
		int tabCount = 0; // tab count for pretty printing
		while(temp != NULL)
		{	
			if(strcmp(temp->data, "{") == 0)
			{
				printf("%s\n", temp->data);
				tabCount++;
				for(int i=0; i<tabCount; i++) printf("\t");
			}
			else if(strcmp(temp->data, ";") == 0)
			{
				printf("%s\n", temp->data);
				for(int i=0; i<tabCount-1; i++) printf("\t");
				if(temp->next != NULL && strcmp(temp->next->data, "}") != 0) 
					printf("\t");
			}
			else if(strcmp(temp->data, "}") == 0)
			{
				printf("%s\n", temp->data);
				tabCount--;
				for(int i=0; i<tabCount-1; i++) printf("\t");
				if (temp->next != NULL && strcmp(temp->next->data, "}") != 0 && tabCount > 0) 
					printf("\t");
			}
			else printf("%s ", temp->data);
			temp = temp->next;
		}
	}

	void addMacro(Macro* macro)
	{ // add a macro to the macro list

		if(DEBUG) fprintf(stderr, "addMacro called with %s\n", macro->macroId);
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

	void create_macro_definition(LL* idList, LL* exprList)
	{ // create a macro definition - expr and stmt with 0 args

		if(DEBUG) fprintf(stderr, "create_macro_definition_expr0 called\n");
		LL* args = returnLL(idList->head->data); // this just has the identifier for the macro
		if(DEBUG) fprintf(stderr, "args created with %s\n", args->head->data);
		LL* replacement = returnLL(exprList->head->data); 

		Node* ptr = exprList->head->next;
		while(ptr != NULL)
		{ // always copy the contents of the linked list else will cause bugs due to excess traversals

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

	LL* replace_macro(LL* idList)
	{ // replace a macro with its definition - expr and stmt with 0 args

		if(DEBUG) fprintf(stderr, "replace_macro_expr0 called\n");
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

		return NULL; // if no macro found
	}

	void create_macro_definition_multi(LL* idList, LL* exprList)
	{ // create a macro definition - expr and stmt with multi args

		if(DEBUG) fprintf(stderr, "create_macro_definition_expr_multi called\n");
		LL* args = returnLL(idList->head->data);

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

	LL* copy_list(LL* list)
	{ // make a copy of the entire linked list

		LL* temp = (LL*)malloc(sizeof(LL));
		temp->head = (Node*)malloc(sizeof(Node));
		temp->head->data = strdup(list->head->data);
		temp->head->next = NULL;
		temp->tail = temp->head;
		Node* ptr = list->head->next;
		while(ptr != NULL)
		{
			temp->tail->next = (Node*)malloc(sizeof(Node));
			temp->tail->next->data = strdup(ptr->data);
			temp->tail->next->next = NULL;
			temp->tail = temp->tail->next;
			ptr = ptr->next;
		}
		return temp;
	}

	LL* replace_macro_multi(LL* idList, LL* exprList)
	{ // replace a macro with its definition - expr and stmt with multi args

		if(DEBUG) fprintf(stderr, "replace_macro_expr_multi called\n");

		//finding the appropriate macro
		Macro* temp = macroTable->head;
		LL* temp2 =  NULL;
		while(temp != NULL)
		{
			if(strcmp(temp->macroId, idList->head->data) == 0)
			{
				if(temp->macroType == 1)
				{
					temp2 = returnLL(temp->replacement->head->data);
					Node* ptr = temp->replacement->head->next;
					while(ptr != NULL)
					{
						LL* temp3 = returnLL(ptr->data);
						attach_lists(temp2, temp3);
						ptr = ptr->next;
					}
					//temp2 has whole expression/statement replacement
					break;
				}
			}
			temp = temp->next;
		}

		// arguments replacement
		Node* ptr = exprList->head; 
		Node* macroArgs = temp->args->head->next;
		while(macroArgs != NULL)
		{
			char* identifierTemp = strdup(ptr->data);
			char* macroId = strdup(macroArgs->data);
			Node* ptr2 = temp2->head;
			while(ptr2 != NULL)
			{
				if(strcmp(ptr2->data, macroId) == 0) 
					ptr2->data = strdup(identifierTemp);

				ptr2 = ptr2->next;
			}
			ptr = ptr->next;
			macroArgs = macroArgs->next;
		}

		return temp2;
	}

	LL* convertExpressionListToIdentifierList(LL* exprList)
	{ // convert an expression list to an identifier list

		if(DEBUG) fprintf(stderr, "convertExpressionListToIdentifierList called\n");
		LL* idList = NULL;
		Node* ptr = exprList->head;
		int first = 1;
		while(ptr != NULL)
		{
			char* buff = strdup("");
			while(ptr != NULL && strcmp(ptr->data, ",") != 0)
			{
				strncat(buff, ptr->data, strlen(ptr->data));
				ptr = ptr->next;
			}
			if(DEBUG) fprintf(stderr, "buff: %s\n", buff);
			if(first)
			{
				idList = returnLL(buff);
				first = 0;
			}
			else attach_lists(idList, returnLL(buff));
			if(ptr != NULL) ptr = ptr->next;
			else break;
		}
		return idList;
	}

#line 393 "test.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINEEXPR0 = 258,             /* DEFINEEXPR0  */
    DEFINEEXPR1 = 259,             /* DEFINEEXPR1  */
    DEFINEEXPR2 = 260,             /* DEFINEEXPR2  */
    DEFINEEXPR = 261,              /* DEFINEEXPR  */
    DEFINESTMT0 = 262,             /* DEFINESTMT0  */
    DEFINESTMT1 = 263,             /* DEFINESTMT1  */
    DEFINESTMT2 = 264,             /* DEFINESTMT2  */
    DEFINESTMT = 265,              /* DEFINESTMT  */
    CLASS = 266,                   /* CLASS  */
    PUBLIC = 267,                  /* PUBLIC  */
    STATIC = 268,                  /* STATIC  */
    MAIN = 269,                    /* MAIN  */
    RETURN = 270,                  /* RETURN  */
    EXTENDS = 271,                 /* EXTENDS  */
    INT = 272,                     /* INT  */
    BOOLEAN = 273,                 /* BOOLEAN  */
    VOID = 274,                    /* VOID  */
    STRING = 275,                  /* STRING  */
    LENGTH = 276,                  /* LENGTH  */
    IF = 277,                      /* IF  */
    WHILE = 278,                   /* WHILE  */
    ELSE = 279,                    /* ELSE  */
    NEW = 280,                     /* NEW  */
    THIS = 281,                    /* THIS  */
    BTRUE = 282,                   /* BTRUE  */
    BFALSE = 283,                  /* BFALSE  */
    PRNTSTMT = 284,                /* PRNTSTMT  */
    OPAREN = 285,                  /* OPAREN  */
    CPAREN = 286,                  /* CPAREN  */
    OCURLY = 287,                  /* OCURLY  */
    CCURLY = 288,                  /* CCURLY  */
    OSQRE = 289,                   /* OSQRE  */
    CSQRE = 290,                   /* CSQRE  */
    SCOLON = 291,                  /* SCOLON  */
    LAND = 292,                    /* LAND  */
    LOR = 293,                     /* LOR  */
    NEQ = 294,                     /* NEQ  */
    LEQ = 295,                     /* LEQ  */
    EQ = 296,                      /* EQ  */
    PLUS = 297,                    /* PLUS  */
    MINUS = 298,                   /* MINUS  */
    MUL = 299,                     /* MUL  */
    DIV = 300,                     /* DIV  */
    EXCLAM = 301,                  /* EXCLAM  */
    COMMA = 302,                   /* COMMA  */
    DOT = 303,                     /* DOT  */
    ID = 304,                      /* ID  */
    NUM = 305                      /* NUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 323 "test.y"

    int num;
    char* id;
    LL* llPtr;

#line 496 "test.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DEFINEEXPR0 = 3,                /* DEFINEEXPR0  */
  YYSYMBOL_DEFINEEXPR1 = 4,                /* DEFINEEXPR1  */
  YYSYMBOL_DEFINEEXPR2 = 5,                /* DEFINEEXPR2  */
  YYSYMBOL_DEFINEEXPR = 6,                 /* DEFINEEXPR  */
  YYSYMBOL_DEFINESTMT0 = 7,                /* DEFINESTMT0  */
  YYSYMBOL_DEFINESTMT1 = 8,                /* DEFINESTMT1  */
  YYSYMBOL_DEFINESTMT2 = 9,                /* DEFINESTMT2  */
  YYSYMBOL_DEFINESTMT = 10,                /* DEFINESTMT  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_PUBLIC = 12,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 13,                    /* STATIC  */
  YYSYMBOL_MAIN = 14,                      /* MAIN  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_EXTENDS = 16,                   /* EXTENDS  */
  YYSYMBOL_INT = 17,                       /* INT  */
  YYSYMBOL_BOOLEAN = 18,                   /* BOOLEAN  */
  YYSYMBOL_VOID = 19,                      /* VOID  */
  YYSYMBOL_STRING = 20,                    /* STRING  */
  YYSYMBOL_LENGTH = 21,                    /* LENGTH  */
  YYSYMBOL_IF = 22,                        /* IF  */
  YYSYMBOL_WHILE = 23,                     /* WHILE  */
  YYSYMBOL_ELSE = 24,                      /* ELSE  */
  YYSYMBOL_NEW = 25,                       /* NEW  */
  YYSYMBOL_THIS = 26,                      /* THIS  */
  YYSYMBOL_BTRUE = 27,                     /* BTRUE  */
  YYSYMBOL_BFALSE = 28,                    /* BFALSE  */
  YYSYMBOL_PRNTSTMT = 29,                  /* PRNTSTMT  */
  YYSYMBOL_OPAREN = 30,                    /* OPAREN  */
  YYSYMBOL_CPAREN = 31,                    /* CPAREN  */
  YYSYMBOL_OCURLY = 32,                    /* OCURLY  */
  YYSYMBOL_CCURLY = 33,                    /* CCURLY  */
  YYSYMBOL_OSQRE = 34,                     /* OSQRE  */
  YYSYMBOL_CSQRE = 35,                     /* CSQRE  */
  YYSYMBOL_SCOLON = 36,                    /* SCOLON  */
  YYSYMBOL_LAND = 37,                      /* LAND  */
  YYSYMBOL_LOR = 38,                       /* LOR  */
  YYSYMBOL_NEQ = 39,                       /* NEQ  */
  YYSYMBOL_LEQ = 40,                       /* LEQ  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_PLUS = 42,                      /* PLUS  */
  YYSYMBOL_MINUS = 43,                     /* MINUS  */
  YYSYMBOL_MUL = 44,                       /* MUL  */
  YYSYMBOL_DIV = 45,                       /* DIV  */
  YYSYMBOL_EXCLAM = 46,                    /* EXCLAM  */
  YYSYMBOL_COMMA = 47,                     /* COMMA  */
  YYSYMBOL_DOT = 48,                       /* DOT  */
  YYSYMBOL_ID = 49,                        /* ID  */
  YYSYMBOL_NUM = 50,                       /* NUM  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_goal = 52,                      /* goal  */
  YYSYMBOL_MiniGoal = 53,                  /* MiniGoal  */
  YYSYMBOL_MacroDefinitionMultiple = 54,   /* MacroDefinitionMultiple  */
  YYSYMBOL_MacroDefinition = 55,           /* MacroDefinition  */
  YYSYMBOL_MacroDefExpression = 56,        /* MacroDefExpression  */
  YYSYMBOL_MacroDefStatement = 57,         /* MacroDefStatement  */
  YYSYMBOL_MainPart = 58,                  /* MainPart  */
  YYSYMBOL_NextPart = 59,                  /* NextPart  */
  YYSYMBOL_TypeDeclaration = 60,           /* TypeDeclaration  */
  YYSYMBOL_IdentifierDeclarations = 61,    /* IdentifierDeclarations  */
  YYSYMBOL_IdentifierDeclarationsFinal = 62, /* IdentifierDeclarationsFinal  */
  YYSYMBOL_IdentifiersList = 63,           /* IdentifiersList  */
  YYSYMBOL_ExtraIdentifier = 64,           /* ExtraIdentifier  */
  YYSYMBOL_MethodDeclarationMultiple = 65, /* MethodDeclarationMultiple  */
  YYSYMBOL_MethodDeclaration = 66,         /* MethodDeclaration  */
  YYSYMBOL_Parameters = 67,                /* Parameters  */
  YYSYMBOL_ParametersFinal = 68,           /* ParametersFinal  */
  YYSYMBOL_MainClass = 69,                 /* MainClass  */
  YYSYMBOL_Type = 70,                      /* Type  */
  YYSYMBOL_StatementsList = 71,            /* StatementsList  */
  YYSYMBOL_Statement = 72,                 /* Statement  */
  YYSYMBOL_ExpressionList = 73,            /* ExpressionList  */
  YYSYMBOL_Expression = 74,                /* Expression  */
  YYSYMBOL_PrimaryExpression = 75,         /* PrimaryExpression  */
  YYSYMBOL_Class = 76,                     /* Class  */
  YYSYMBOL_OCurly = 77,                    /* OCurly  */
  YYSYMBOL_CCurly = 78,                    /* CCurly  */
  YYSYMBOL_Public = 79,                    /* Public  */
  YYSYMBOL_Static = 80,                    /* Static  */
  YYSYMBOL_Void = 81,                      /* Void  */
  YYSYMBOL_Main = 82,                      /* Main  */
  YYSYMBOL_OParen = 83,                    /* OParen  */
  YYSYMBOL_CParen = 84,                    /* CParen  */
  YYSYMBOL_String = 85,                    /* String  */
  YYSYMBOL_OSqre = 86,                     /* OSqre  */
  YYSYMBOL_CSqre = 87,                     /* CSqre  */
  YYSYMBOL_PrintStatement = 88,            /* PrintStatement  */
  YYSYMBOL_SColon = 89,                    /* SColon  */
  YYSYMBOL_Dot = 90,                       /* Dot  */
  YYSYMBOL_Length = 91,                    /* Length  */
  YYSYMBOL_This = 92,                      /* This  */
  YYSYMBOL_New = 93,                       /* New  */
  YYSYMBOL_Int = 94,                       /* Int  */
  YYSYMBOL_Boolean = 95,                   /* Boolean  */
  YYSYMBOL_Exclam = 96,                    /* Exclam  */
  YYSYMBOL_Return = 97,                    /* Return  */
  YYSYMBOL_Extends = 98,                   /* Extends  */
  YYSYMBOL_Eq = 99,                        /* Eq  */
  YYSYMBOL_If = 100,                       /* If  */
  YYSYMBOL_Else = 101,                     /* Else  */
  YYSYMBOL_While = 102,                    /* While  */
  YYSYMBOL_Comma = 103,                    /* Comma  */
  YYSYMBOL_Land = 104,                     /* Land  */
  YYSYMBOL_Lor = 105,                      /* Lor  */
  YYSYMBOL_Neq = 106,                      /* Neq  */
  YYSYMBOL_Leq = 107,                      /* Leq  */
  YYSYMBOL_Plus = 108,                     /* Plus  */
  YYSYMBOL_Minus = 109,                    /* Minus  */
  YYSYMBOL_Mul = 110,                      /* Mul  */
  YYSYMBOL_Div = 111,                      /* Div  */
  YYSYMBOL_Btrue = 112,                    /* Btrue  */
  YYSYMBOL_Bfalse = 113,                   /* Bfalse  */
  YYSYMBOL_DefineExpr0 = 114,              /* DefineExpr0  */
  YYSYMBOL_DefineExpr1 = 115,              /* DefineExpr1  */
  YYSYMBOL_DefineExpr2 = 116,              /* DefineExpr2  */
  YYSYMBOL_DefineExpr = 117,               /* DefineExpr  */
  YYSYMBOL_DefineStmt0 = 118,              /* DefineStmt0  */
  YYSYMBOL_DefineStmt1 = 119,              /* DefineStmt1  */
  YYSYMBOL_DefineStmt2 = 120,              /* DefineStmt2  */
  YYSYMBOL_DefineStmt = 121,               /* DefineStmt  */
  YYSYMBOL_Identifier = 122,               /* Identifier  */
  YYSYMBOL_Number = 123                    /* Number  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   408

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   359,   359,   362,   366,   369,   370,   373,   374,   377,
     389,   393,   400,   411,   423,   427,   434,   445,   452,   453,
     460,   469,   482,   483,   491,   499,   500,   507,   513,   514,
     521,   541,   562,   563,   571,   578,   608,   614,   615,   616,
     619,   620,   627,   633,   641,   648,   658,   666,   676,   684,
     694,   704,   708,   716,   722,   728,   734,   740,   746,   752,
     758,   764,   771,   777,   781,   789,   798,   806,   817,   818,
     819,   820,   821,   822,   830,   837,   842,   852,   853,   854,
     855,   856,   857,   858,   859,   860,   861,   862,   863,   864,
     865,   866,   867,   868,   869,   870,   871,   872,   873,   874,
     875,   876,   877,   878,   879,   880,   881,   882,   883,   884,
     885,   886,   887,   888,   889,   890,   891,   892,   893,   894,
     895,   896,   897,   899,   900
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DEFINEEXPR0",
  "DEFINEEXPR1", "DEFINEEXPR2", "DEFINEEXPR", "DEFINESTMT0", "DEFINESTMT1",
  "DEFINESTMT2", "DEFINESTMT", "CLASS", "PUBLIC", "STATIC", "MAIN",
  "RETURN", "EXTENDS", "INT", "BOOLEAN", "VOID", "STRING", "LENGTH", "IF",
  "WHILE", "ELSE", "NEW", "THIS", "BTRUE", "BFALSE", "PRNTSTMT", "OPAREN",
  "CPAREN", "OCURLY", "CCURLY", "OSQRE", "CSQRE", "SCOLON", "LAND", "LOR",
  "NEQ", "LEQ", "EQ", "PLUS", "MINUS", "MUL", "DIV", "EXCLAM", "COMMA",
  "DOT", "ID", "NUM", "$accept", "goal", "MiniGoal",
  "MacroDefinitionMultiple", "MacroDefinition", "MacroDefExpression",
  "MacroDefStatement", "MainPart", "NextPart", "TypeDeclaration",
  "IdentifierDeclarations", "IdentifierDeclarationsFinal",
  "IdentifiersList", "ExtraIdentifier", "MethodDeclarationMultiple",
  "MethodDeclaration", "Parameters", "ParametersFinal", "MainClass",
  "Type", "StatementsList", "Statement", "ExpressionList", "Expression",
  "PrimaryExpression", "Class", "OCurly", "CCurly", "Public", "Static",
  "Void", "Main", "OParen", "CParen", "String", "OSqre", "CSqre",
  "PrintStatement", "SColon", "Dot", "Length", "This", "New", "Int",
  "Boolean", "Exclam", "Return", "Extends", "Eq", "If", "Else", "While",
  "Comma", "Land", "Lor", "Neq", "Leq", "Plus", "Minus", "Mul", "Div",
  "Btrue", "Bfalse", "DefineExpr0", "DefineExpr1", "DefineExpr2",
  "DefineExpr", "DefineStmt0", "DefineStmt1", "DefineStmt2", "DefineStmt",
  "Identifier", "Number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-206)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     369,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
      18,  -206,    12,   293,  -206,  -206,  -206,    12,   -24,   -24,
     -24,   -24,   -24,   -24,   -24,   -24,   -24,  -206,  -206,  -206,
    -206,    12,   -24,  -206,    -3,     8,     8,     8,     8,     8,
       8,     8,     8,  -206,    -5,  -206,    35,  -206,    22,   -24,
     -24,   -24,    22,   -24,   -24,   -24,  -206,  -206,   -24,  -206,
      36,  -206,     8,    22,    20,    20,    -3,    22,    20,    20,
      27,    -3,  -206,    49,   297,     8,  -206,   -24,   -24,   255,
      -3,   -24,   -24,  -206,  -206,  -206,    39,    35,   -24,    57,
      53,  -206,  -206,  -206,  -206,    75,  -206,  -206,  -206,  -206,
    -206,  -206,    22,   315,   297,  -206,    17,   297,  -206,  -206,
       8,  -206,   297,    22,    20,  -206,  -206,  -206,    39,   255,
     255,     8,     8,     8,    74,   255,    22,    20,  -206,  -206,
    -206,    56,   -24,  -206,    58,    27,  -206,     8,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,   297,    -1,
     297,   297,   297,   297,   297,   297,   297,   297,    22,    53,
       8,  -206,   263,    22,     8,   -24,  -206,  -206,    39,   297,
     297,   297,  -206,   263,   297,   297,    39,    -3,   -24,  -206,
    -206,     8,  -206,  -206,    39,    83,    58,  -206,  -206,  -206,
       8,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
     297,    22,    22,    20,  -206,  -206,   297,    20,  -206,    22,
      22,    22,    22,    56,    58,    56,  -206,   255,    20,    80,
    -206,  -206,    53,  -206,   263,    58,  -206,  -206,   297,    22,
      22,    20,   -24,    56,   255,   255,    56,  -206,    68,  -206,
      39,    22,    22,    20,   -24,    -3,    58,    22,  -206,  -206,
    -206,  -206,     8,  -206,  -206,  -206,    70,  -206,  -206,   297,
    -206,    -3,    -3,    57,  -206,  -206,   -24,  -206,   297,  -206,
     255,    56,   255,  -206,  -206,   166,    22,    22,  -206,  -206,
      39,   166,    95,    74,    -3,  -206,  -206,    95,  -206,   297,
      87,   297,    56,     8,    56,    39,   297,    39,  -206,    22,
    -206,    56,    39,    39,  -206
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   115,   116,   117,   118,   119,   120,   121,   122,    77,
       0,     2,     0,     6,     8,     7,     4,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     1,     3,     5,
      17,    18,     0,   123,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,    78,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,    99,    22,     0,    80,
       0,    85,     0,     0,     0,     0,     0,     0,     0,     0,
      28,     0,    81,     0,     0,     0,   104,     0,     0,    40,
       0,     0,     0,    95,    96,    23,     0,    28,     0,     0,
      38,    37,    39,    22,    82,     0,    94,    93,   113,   114,
      97,   124,     0,    63,     0,    72,     0,     0,    69,    70,
      71,    68,     0,     0,     0,   101,   103,    89,     0,    40,
      40,     0,     0,     0,     0,    40,     0,     0,    79,    20,
      29,     0,     0,    87,     0,    28,    83,     0,    10,   105,
     106,   107,   108,   109,   110,   111,   112,    91,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    75,     0,     0,     0,     0,    14,    41,     0,     0,
       0,     0,   100,     0,     0,     0,     0,     0,     0,    90,
      24,     0,    88,    36,     0,     0,     0,    71,    92,    62,
       0,    53,    54,    55,    56,    57,    58,    59,    60,    76,
       0,     0,     0,    51,    66,    11,     0,    25,    42,     0,
       0,     0,     0,     0,     0,     0,    15,    40,    25,     0,
      21,    86,     0,    61,     0,     0,    74,    67,     0,     0,
       0,    25,     0,     0,     0,     0,     0,    50,     0,    44,
       0,     0,     0,    32,     0,     0,     0,     0,    64,    73,
      52,    12,     0,    26,    27,    43,    46,    48,    49,     0,
      16,     0,     0,     0,    34,    22,     0,    65,     0,   102,
       0,     0,    40,    22,    33,    40,     0,     0,    47,    45,
       0,    40,     0,    39,     0,     9,    13,     0,    98,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      30,     0,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -206,  -206,  -206,   110,  -206,  -206,  -206,   114,    91,  -206,
     -83,  -206,  -205,  -206,   -70,  -206,  -136,  -206,  -206,   -77,
    -104,  -184,  -151,   -50,   214,    11,   -25,   -27,    82,  -206,
    -206,  -206,    43,   109,  -206,   -47,  -156,  -150,   -28,  -206,
    -206,  -206,  -206,    37,  -206,  -206,  -143,  -206,   -92,  -206,
    -206,  -206,    31,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,  -206,
    -206,   -18,  -206
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    10,    11,    12,    13,    14,    15,    16,    30,    31,
      70,    85,   230,   231,    86,    87,   242,   243,    17,    88,
     118,   119,   202,   203,   103,    18,   120,   129,    89,    73,
      95,   137,   104,    62,   222,   174,   183,   121,   180,   149,
     189,   105,   106,    90,    91,   107,   289,    58,   175,   122,
     270,   123,   232,   150,   151,   152,   153,   154,   155,   156,
     157,   108,   109,    19,    20,    21,    22,    23,    24,    25,
      26,   110,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    35,    36,    37,    38,    39,    40,    41,    42,    46,
     135,    56,   132,   241,    44,   167,   168,   130,    27,    57,
     188,   176,   212,     9,   102,    33,   253,    45,    32,    45,
     223,    63,    64,    65,    83,    67,    68,    69,    47,    59,
      71,    79,    32,   134,    83,    84,    93,    59,    33,    72,
     256,   257,    92,    61,   158,   125,   148,   161,   238,   113,
     114,   124,   163,   126,   127,   184,    33,    76,    94,   249,
     131,    92,   128,   247,    83,    84,    33,   250,    48,    49,
      50,    51,    52,    53,    54,    55,   278,   133,   160,   136,
     266,   166,   179,   182,   269,    77,    78,    83,    84,    81,
      82,   124,   124,   221,    47,    74,    33,   124,   133,   172,
     288,    61,   200,   240,   181,   172,   117,    92,   112,   209,
     210,   211,    43,    29,   214,   215,    28,   274,    60,    33,
     187,   190,   187,   187,   187,   187,   187,   187,   187,   187,
     293,   208,   244,   159,   291,   165,   259,   207,     0,   216,
     225,     0,   217,   162,     0,     0,   229,   220,   178,     0,
     218,    66,     0,     0,   169,   170,   171,   173,   280,     0,
       0,   282,    75,     0,     0,   246,    80,   287,     0,     0,
     185,     0,   275,    83,    84,   237,   244,   239,   115,   116,
     281,     0,     0,     0,     0,   117,     0,     0,    45,   124,
       0,    92,     0,   201,     0,   255,     0,   206,   258,   271,
       0,   138,     0,   260,   254,    33,   124,   124,   277,     0,
     265,     0,   164,     0,   219,     0,   264,     0,     0,     0,
       0,     0,     0,   224,   228,   177,   272,   273,     0,   292,
       0,   294,     0,   279,     0,    92,   299,     0,   276,     0,
       0,     0,   124,   286,   124,     0,     0,   283,     0,   290,
       0,     0,     0,   283,   295,     0,   297,   199,   298,     0,
     300,   204,   205,   302,   263,   303,   304,   115,   116,     0,
       0,     0,   213,     0,   117,     0,     0,    45,    96,    97,
      98,    99,     0,    47,    61,   268,     1,     2,     3,     4,
       5,     6,     7,     8,    33,     0,     0,     0,     0,   100,
     226,   227,    33,   101,     0,     0,     0,     0,   233,   234,
     235,   236,    96,    97,    98,    99,   173,    47,   245,     0,
       0,     0,     0,   248,     0,     0,   296,     0,   251,   252,
       0,     0,     0,   100,     0,     0,    33,   101,     0,   133,
     261,   262,   139,   140,   141,   142,   267,   143,   144,   145,
     146,     0,   186,   147,   191,   192,   193,   194,   195,   196,
     197,   198,     1,     2,     3,     4,     5,     6,     7,     8,
       9,     0,     0,     0,     0,   284,   285,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   301
};

static const yytype_int16 yycheck[] =
{
      18,    19,    20,    21,    22,    23,    24,    25,    26,    34,
      93,    16,    89,   218,    32,   119,   120,    87,     0,    44,
      21,   125,   173,    11,    74,    49,   231,    32,    17,    32,
     186,    49,    50,    51,    17,    53,    54,    55,    30,    12,
      58,    66,    31,    90,    17,    18,    71,    12,    49,    13,
     234,   235,    70,    31,   104,    80,   103,   107,   214,    77,
      78,    79,   112,    81,    82,   135,    49,    47,    19,   225,
      88,    89,    33,   224,    17,    18,    49,   228,    35,    36,
      37,    38,    39,    40,    41,    42,   270,    34,   106,    14,
     246,   118,    36,    35,    24,    64,    65,    17,    18,    68,
      69,   119,   120,    20,    30,    62,    49,   125,    34,    41,
      15,    31,   159,   217,   132,    41,    29,   135,    75,   169,
     170,   171,    31,    13,   174,   175,    12,   263,    46,    49,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     290,   168,   219,   106,   287,   114,   238,   165,    -1,   176,
     200,    -1,   177,   110,    -1,    -1,   206,   184,   127,    -1,
     178,    52,    -1,    -1,   121,   122,   123,   124,   272,    -1,
      -1,   275,    63,    -1,    -1,   222,    67,   281,    -1,    -1,
     137,    -1,   265,    17,    18,   213,   263,   215,    22,    23,
     273,    -1,    -1,    -1,    -1,    29,    -1,    -1,    32,   217,
      -1,   219,    -1,   160,    -1,   233,    -1,   164,   236,   259,
      -1,   102,    -1,   240,   232,    49,   234,   235,   268,    -1,
     245,    -1,   113,    -1,   181,    -1,   244,    -1,    -1,    -1,
      -1,    -1,    -1,   190,   203,   126,   261,   262,    -1,   289,
      -1,   291,    -1,   271,    -1,   263,   296,    -1,   266,    -1,
      -1,    -1,   270,   280,   272,    -1,    -1,   275,    -1,   284,
      -1,    -1,    -1,   281,   292,    -1,   294,   158,   295,    -1,
     297,   162,   163,   301,   243,   302,   303,    22,    23,    -1,
      -1,    -1,   173,    -1,    29,    -1,    -1,    32,    25,    26,
      27,    28,    -1,    30,    31,   252,     3,     4,     5,     6,
       7,     8,     9,    10,    49,    -1,    -1,    -1,    -1,    46,
     201,   202,    49,    50,    -1,    -1,    -1,    -1,   209,   210,
     211,   212,    25,    26,    27,    28,   283,    30,   219,    -1,
      -1,    -1,    -1,   224,    -1,    -1,   293,    -1,   229,   230,
      -1,    -1,    -1,    46,    -1,    -1,    49,    50,    -1,    34,
     241,   242,    37,    38,    39,    40,   247,    42,    43,    44,
      45,    -1,   148,    48,   150,   151,   152,   153,   154,   155,
     156,   157,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,   276,   277,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   299
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      52,    53,    54,    55,    56,    57,    58,    69,    76,   114,
     115,   116,   117,   118,   119,   120,   121,     0,    58,    54,
      59,    60,    76,    49,   122,   122,   122,   122,   122,   122,
     122,   122,   122,    59,   122,    32,    77,    30,    83,    83,
      83,    83,    83,    83,    83,    83,    16,    77,    98,    12,
      79,    31,    84,   122,   122,   122,    84,   122,   122,   122,
      61,   122,    13,    80,    83,    84,    47,   103,   103,    77,
      84,   103,   103,    17,    18,    62,    65,    66,    70,    79,
      94,    95,   122,    77,    19,    81,    25,    26,    27,    28,
      46,    50,    74,    75,    83,    92,    93,    96,   112,   113,
     122,   123,    83,   122,   122,    22,    23,    29,    71,    72,
      77,    88,   100,   102,   122,    77,   122,   122,    33,    78,
      65,   122,    70,    34,    86,    61,    14,    82,    84,    37,
      38,    39,    40,    42,    43,    44,    45,    48,    86,    90,
     104,   105,   106,   107,   108,   109,   110,   111,    74,    94,
     122,    74,    83,    74,    84,   103,    78,    71,    71,    83,
      83,    83,    41,    83,    86,    99,    71,    84,   103,    36,
      89,   122,    35,    87,    65,    83,    75,   122,    21,    91,
     122,    75,    75,    75,    75,    75,    75,    75,    75,    84,
      86,    83,    73,    74,    84,    84,    83,   122,    78,    74,
      74,    74,    73,    84,    74,    74,    78,    77,   122,    83,
      78,    20,    85,    87,    83,    74,    84,    84,   103,    74,
      63,    64,   103,    84,    84,    84,    84,    89,    87,    89,
      71,    63,    67,    68,    70,    84,    86,    73,    84,    87,
      73,    84,    84,    63,   122,    89,    72,    72,    89,    99,
      78,    84,    84,   103,   122,    77,    87,    84,    83,    24,
     101,    74,    77,    77,    67,    61,   122,    74,    72,    89,
      71,    61,    71,   122,    84,    84,    78,    71,    15,    97,
      77,    97,    74,    88,    74,    89,    83,    89,    78,    74,
      78,    84,    89,    78,    78
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    68,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     1,     1,     1,    13,
       7,     8,    10,    13,     7,     8,    10,     2,     0,     2,
       6,     8,     0,     2,     3,     0,     2,     2,     0,     2,
      13,    12,     1,     3,     2,    21,     3,     1,     1,     1,
       0,     2,     3,     5,     4,     7,     5,     7,     5,     5,
       4,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     4,     3,     1,     5,     6,     3,     4,     1,     1,
       1,     1,     1,     5,     4,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* goal: MiniGoal  */
#line 359 "test.y"
               {(yyval.llPtr) = (yyvsp[0].llPtr); printLL((yyval.llPtr));}
#line 1829 "test.tab.c"
    break;

  case 3: /* MiniGoal: MacroDefinitionMultiple MainPart  */
#line 363 "test.y"
                {
			(yyval.llPtr) = (yyvsp[0].llPtr);
		}
#line 1837 "test.tab.c"
    break;

  case 4: /* MiniGoal: MainPart  */
#line 366 "test.y"
                   {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1843 "test.tab.c"
    break;

  case 9: /* MacroDefExpression: DefineExpr Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OParen Expression CParen  */
#line 378 "test.y"
                                  {
					LL* idList = returnLL((yyvsp[-11].llPtr)->head->data);
					LL* first_argument= returnLL((yyvsp[-9].llPtr)->head->data);
					attach_lists(idList, first_argument);
					LL* second_argument = returnLL((yyvsp[-7].llPtr)->head->data);
					attach_lists(idList, second_argument);
					LL* third_argument = returnLL((yyvsp[-5].llPtr)->head->data);
					attach_lists(idList, third_argument);
					attach_lists(idList, (yyvsp[-4].llPtr));
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				  }
#line 1859 "test.tab.c"
    break;

  case 10: /* MacroDefExpression: DefineExpr0 Identifier OParen CParen OParen Expression CParen  */
#line 390 "test.y"
                                  {
					create_macro_definition((yyvsp[-5].llPtr), (yyvsp[-1].llPtr));
				  }
#line 1867 "test.tab.c"
    break;

  case 11: /* MacroDefExpression: DefineExpr1 Identifier OParen Identifier CParen OParen Expression CParen  */
#line 394 "test.y"
                                  {
					LL* idList = returnLL((yyvsp[-6].llPtr)->head->data);
					LL* first_argument = returnLL((yyvsp[-4].llPtr)->head->data);
					attach_lists(idList, first_argument);
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				  }
#line 1878 "test.tab.c"
    break;

  case 12: /* MacroDefExpression: DefineExpr2 Identifier OParen Identifier Comma Identifier CParen OParen Expression CParen  */
#line 401 "test.y"
                                  {
					LL*idList = returnLL((yyvsp[-8].llPtr)->head->data);
					LL*first_argument = returnLL((yyvsp[-6].llPtr)->head->data);
					attach_lists(idList, first_argument);
					LL*second_argument = returnLL((yyvsp[-4].llPtr)->head->data);
					attach_lists(idList, second_argument);
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				 }
#line 1891 "test.tab.c"
    break;

  case 13: /* MacroDefStatement: DefineStmt Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OCurly StatementsList CCurly  */
#line 412 "test.y"
                                 {
					LL* idList = returnLL((yyvsp[-11].llPtr)->head->data);
					LL* first_argument= returnLL((yyvsp[-9].llPtr)->head->data);
					attach_lists(idList, first_argument);
					LL* second_argument = returnLL((yyvsp[-7].llPtr)->head->data);
					attach_lists(idList, second_argument);
					LL* third_argument = returnLL((yyvsp[-5].llPtr)->head->data);
					attach_lists(idList, third_argument);
					attach_lists(idList, (yyvsp[-4].llPtr));
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				 }
#line 1907 "test.tab.c"
    break;

  case 14: /* MacroDefStatement: DefineStmt0 Identifier OParen CParen OCurly StatementsList CCurly  */
#line 424 "test.y"
                                 {
					create_macro_definition((yyvsp[-5].llPtr), (yyvsp[-1].llPtr));
				 }
#line 1915 "test.tab.c"
    break;

  case 15: /* MacroDefStatement: DefineStmt1 Identifier OParen Identifier CParen OCurly StatementsList CCurly  */
#line 428 "test.y"
                                 {
					LL* idList = returnLL((yyvsp[-6].llPtr)->head->data);
					LL* first_argument = returnLL((yyvsp[-4].llPtr)->head->data);
					attach_lists(idList, first_argument);
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				 }
#line 1926 "test.tab.c"
    break;

  case 16: /* MacroDefStatement: DefineStmt2 Identifier OParen Identifier Comma Identifier CParen OCurly StatementsList CCurly  */
#line 435 "test.y"
                                 {
					LL*idList = returnLL((yyvsp[-8].llPtr)->head->data);
					LL*first_argument = returnLL((yyvsp[-6].llPtr)->head->data);
					attach_lists(idList, first_argument);
					LL*second_argument = returnLL((yyvsp[-4].llPtr)->head->data);
					attach_lists(idList, second_argument);
					create_macro_definition_multi(idList, (yyvsp[-1].llPtr));
				 }
#line 1939 "test.tab.c"
    break;

  case 17: /* MainPart: MainClass NextPart  */
#line 446 "test.y"
                {
			(yyval.llPtr) = (yyvsp[-1].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		}
#line 1948 "test.tab.c"
    break;

  case 18: /* NextPart: %empty  */
#line 452 "test.y"
          {(yyval.llPtr) = NULL;}
#line 1954 "test.tab.c"
    break;

  case 19: /* NextPart: TypeDeclaration NextPart  */
#line 454 "test.y"
                {
			(yyval.llPtr) = (yyvsp[-1].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		}
#line 1963 "test.tab.c"
    break;

  case 20: /* TypeDeclaration: Class Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly  */
#line 461 "test.y"
                                {
					(yyval.llPtr) = (yyvsp[-5].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				}
#line 1976 "test.tab.c"
    break;

  case 21: /* TypeDeclaration: Class Identifier Extends Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly  */
#line 470 "test.y"
                            {
					(yyval.llPtr) = (yyvsp[-7].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[-6].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				 }
#line 1991 "test.tab.c"
    break;

  case 22: /* IdentifierDeclarations: %empty  */
#line 482 "test.y"
                        {(yyval.llPtr) = NULL;}
#line 1997 "test.tab.c"
    break;

  case 23: /* IdentifierDeclarations: IdentifierDeclarations IdentifierDeclarationsFinal  */
#line 484 "test.y"
                                          {
						(yyval.llPtr) = (yyvsp[-1].llPtr);
						if((yyval.llPtr) != NULL) attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						else (yyval.llPtr) = (yyvsp[0].llPtr);
					  }
#line 2007 "test.tab.c"
    break;

  case 24: /* IdentifierDeclarationsFinal: Type Identifier SColon  */
#line 492 "test.y"
                                                    {
								(yyval.llPtr) = (yyvsp[-2].llPtr);
								attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
								attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						    }
#line 2017 "test.tab.c"
    break;

  case 25: /* IdentifiersList: %empty  */
#line 499 "test.y"
                 {(yyval.llPtr) = NULL;}
#line 2023 "test.tab.c"
    break;

  case 26: /* IdentifiersList: ExtraIdentifier IdentifiersList  */
#line 501 "test.y"
                           {
					(yyval.llPtr) = (yyvsp[-1].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			   }
#line 2032 "test.tab.c"
    break;

  case 27: /* ExtraIdentifier: Comma Identifier  */
#line 508 "test.y"
                                {
					(yyval.llPtr) = (yyvsp[0].llPtr);
				}
#line 2040 "test.tab.c"
    break;

  case 28: /* MethodDeclarationMultiple: %empty  */
#line 513 "test.y"
                           {(yyval.llPtr) = NULL;}
#line 2046 "test.tab.c"
    break;

  case 29: /* MethodDeclarationMultiple: MethodDeclaration MethodDeclarationMultiple  */
#line 515 "test.y"
                                                 {
							(yyval.llPtr) = (yyvsp[-1].llPtr);
							attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						 }
#line 2055 "test.tab.c"
    break;

  case 30: /* MethodDeclaration: Public Type Identifier OParen Parameters CParen OCurly IdentifierDeclarations StatementsList Return Expression SColon CCurly  */
#line 526 "test.y"
                                        {
						(yyval.llPtr) = (yyvsp[-12].llPtr);
						attach_lists((yyval.llPtr), (yyvsp[-11].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-10].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-9].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-8].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-7].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-6].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
					}
#line 2075 "test.tab.c"
    break;

  case 31: /* MethodDeclaration: Public Type Identifier OParen CParen OCurly IdentifierDeclarations StatementsList Return Expression SColon CCurly  */
#line 546 "test.y"
                                        {
						(yyval.llPtr) = (yyvsp[-11].llPtr);
						attach_lists((yyval.llPtr), (yyvsp[-10].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-9].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-8].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-7].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-6].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
						attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
					}
#line 2094 "test.tab.c"
    break;

  case 32: /* Parameters: ParametersFinal  */
#line 562 "test.y"
                            {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 2100 "test.tab.c"
    break;

  case 33: /* Parameters: ParametersFinal Comma Parameters  */
#line 564 "test.y"
                  {
			  (yyval.llPtr) = (yyvsp[-2].llPtr);
			  attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			  attach_lists((yyval.llPtr), (yyvsp[0].llPtr));	
		  }
#line 2110 "test.tab.c"
    break;

  case 34: /* ParametersFinal: Type Identifier  */
#line 572 "test.y"
                           {
				   (yyval.llPtr) = (yyvsp[-1].llPtr);
				   attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			   }
#line 2119 "test.tab.c"
    break;

  case 35: /* MainClass: Class Identifier OCurly Public Static Void Main OParen String OSqre CSqre Identifier CParen OCurly PrintStatement OParen Expression CParen SColon CCurly CCurly  */
#line 583 "test.y"
                        {
				(yyval.llPtr) = (yyvsp[-20].llPtr);
            	attach_lists((yyval.llPtr), (yyvsp[-19].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-18].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-17].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-16].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-15].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-14].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-13].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-12].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-11].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-10].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-9].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-8].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-7].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-6].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            	attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
				attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			}
#line 2147 "test.tab.c"
    break;

  case 36: /* Type: Int OSqre CSqre  */
#line 609 "test.y"
        {
		(yyval.llPtr) = (yyvsp[-2].llPtr);
		attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
		attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
	}
#line 2157 "test.tab.c"
    break;

  case 37: /* Type: Boolean  */
#line 614 "test.y"
              {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 2163 "test.tab.c"
    break;

  case 38: /* Type: Int  */
#line 615 "test.y"
          {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 2169 "test.tab.c"
    break;

  case 39: /* Type: Identifier  */
#line 616 "test.y"
                 {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 2175 "test.tab.c"
    break;

  case 40: /* StatementsList: %empty  */
#line 619 "test.y"
                {(yyval.llPtr) = NULL;}
#line 2181 "test.tab.c"
    break;

  case 41: /* StatementsList: Statement StatementsList  */
#line 621 "test.y"
                          {
				(yyval.llPtr) = (yyvsp[-1].llPtr);
				attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			  }
#line 2190 "test.tab.c"
    break;

  case 42: /* Statement: OCurly StatementsList CCurly  */
#line 628 "test.y"
         {
			(yyval.llPtr) = (yyvsp[-2].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
         }
#line 2200 "test.tab.c"
    break;

  case 43: /* Statement: PrintStatement OParen Expression CParen SColon  */
#line 634 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2212 "test.tab.c"
    break;

  case 44: /* Statement: Identifier Eq Expression SColon  */
#line 642 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2223 "test.tab.c"
    break;

  case 45: /* Statement: Identifier OSqre Expression CSqre Eq Expression SColon  */
#line 649 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-6].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2237 "test.tab.c"
    break;

  case 46: /* Statement: If OParen Expression CParen Statement  */
#line 659 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2249 "test.tab.c"
    break;

  case 47: /* Statement: If OParen Expression CParen Statement Else Statement  */
#line 667 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-6].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2263 "test.tab.c"
    break;

  case 48: /* Statement: While OParen Expression CParen Statement  */
#line 677 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2275 "test.tab.c"
    break;

  case 49: /* Statement: Identifier OParen ExpressionList CParen SColon  */
#line 685 "test.y"
                 {
            LL* identifierList = convertExpressionListToIdentifierList((yyvsp[-2].llPtr));
			(yyval.llPtr) = replace_macro_multi((yyvsp[-4].llPtr), identifierList);
			LL* temp = returnLL("{");
			attach_lists(temp, (yyval.llPtr));
			LL* temp2 = returnLL("}");
			attach_lists(temp, temp2);
			(yyval.llPtr) = temp;
		 }
#line 2289 "test.tab.c"
    break;

  case 50: /* Statement: Identifier OParen CParen SColon  */
#line 695 "test.y"
                 {
            (yyval.llPtr) = replace_macro((yyvsp[-3].llPtr));
			LL* temp = (yyvsp[-2].llPtr);
			attach_lists((yyvsp[-2].llPtr), (yyval.llPtr));
			attach_lists((yyvsp[-2].llPtr), (yyvsp[-1].llPtr));
			(yyval.llPtr) = (yyvsp[-2].llPtr);
		 }
#line 2301 "test.tab.c"
    break;

  case 51: /* ExpressionList: Expression  */
#line 705 "test.y"
              {
                (yyval.llPtr) = (yyvsp[0].llPtr);
              }
#line 2309 "test.tab.c"
    break;

  case 52: /* ExpressionList: Expression Comma ExpressionList  */
#line 709 "test.y"
              {
                (yyval.llPtr) = (yyvsp[-2].llPtr);
                attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
              }
#line 2319 "test.tab.c"
    break;

  case 53: /* Expression: PrimaryExpression Land PrimaryExpression  */
#line 717 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2329 "test.tab.c"
    break;

  case 54: /* Expression: PrimaryExpression Lor PrimaryExpression  */
#line 723 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2339 "test.tab.c"
    break;

  case 55: /* Expression: PrimaryExpression Neq PrimaryExpression  */
#line 729 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2349 "test.tab.c"
    break;

  case 56: /* Expression: PrimaryExpression Leq PrimaryExpression  */
#line 735 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2359 "test.tab.c"
    break;

  case 57: /* Expression: PrimaryExpression Plus PrimaryExpression  */
#line 741 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2369 "test.tab.c"
    break;

  case 58: /* Expression: PrimaryExpression Minus PrimaryExpression  */
#line 747 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2379 "test.tab.c"
    break;

  case 59: /* Expression: PrimaryExpression Mul PrimaryExpression  */
#line 753 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2389 "test.tab.c"
    break;

  case 60: /* Expression: PrimaryExpression Div PrimaryExpression  */
#line 759 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2399 "test.tab.c"
    break;

  case 61: /* Expression: PrimaryExpression OSqre PrimaryExpression CSqre  */
#line 765 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2410 "test.tab.c"
    break;

  case 62: /* Expression: PrimaryExpression Dot Length  */
#line 772 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2420 "test.tab.c"
    break;

  case 63: /* Expression: PrimaryExpression  */
#line 778 "test.y"
          {
            (yyval.llPtr) = (yyvsp[0].llPtr);
          }
#line 2428 "test.tab.c"
    break;

  case 64: /* Expression: PrimaryExpression Dot Identifier OParen CParen  */
#line 782 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2440 "test.tab.c"
    break;

  case 65: /* Expression: PrimaryExpression Dot Identifier OParen ExpressionList CParen  */
#line 790 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-5].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2453 "test.tab.c"
    break;

  case 66: /* Expression: Identifier OParen CParen  */
#line 799 "test.y"
          {
			(yyval.llPtr) = replace_macro((yyvsp[-2].llPtr));
			LL* temp = (yyvsp[-1].llPtr);
			attach_lists((yyvsp[-1].llPtr), (yyval.llPtr));
			attach_lists((yyvsp[-1].llPtr), (yyvsp[0].llPtr));
			(yyval.llPtr) = (yyvsp[-1].llPtr);
          }
#line 2465 "test.tab.c"
    break;

  case 67: /* Expression: Identifier OParen ExpressionList CParen  */
#line 807 "test.y"
          {
            LL* identifierList = convertExpressionListToIdentifierList((yyvsp[-1].llPtr));
			(yyval.llPtr) = replace_macro_multi((yyvsp[-3].llPtr), identifierList);
			LL* temp = (yyvsp[-2].llPtr);
			attach_lists((yyvsp[-2].llPtr), (yyval.llPtr));
			attach_lists((yyvsp[-2].llPtr), (yyvsp[0].llPtr));
			(yyval.llPtr) = (yyvsp[-2].llPtr);
          }
#line 2478 "test.tab.c"
    break;

  case 68: /* PrimaryExpression: Number  */
#line 817 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2484 "test.tab.c"
    break;

  case 69: /* PrimaryExpression: Btrue  */
#line 818 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2490 "test.tab.c"
    break;

  case 70: /* PrimaryExpression: Bfalse  */
#line 819 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2496 "test.tab.c"
    break;

  case 71: /* PrimaryExpression: Identifier  */
#line 820 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2502 "test.tab.c"
    break;

  case 72: /* PrimaryExpression: This  */
#line 821 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2508 "test.tab.c"
    break;

  case 73: /* PrimaryExpression: New Int OSqre Expression CSqre  */
#line 823 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-4].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2520 "test.tab.c"
    break;

  case 74: /* PrimaryExpression: New Identifier OParen CParen  */
#line 831 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-3].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2531 "test.tab.c"
    break;

  case 75: /* PrimaryExpression: Exclam Expression  */
#line 838 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-1].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2540 "test.tab.c"
    break;

  case 76: /* PrimaryExpression: OParen Expression CParen  */
#line 843 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-2].llPtr);
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2550 "test.tab.c"
    break;

  case 77: /* Class: CLASS  */
#line 852 "test.y"
                            { (yyval.llPtr) = returnLL("class");}
#line 2556 "test.tab.c"
    break;

  case 78: /* OCurly: OCURLY  */
#line 853 "test.y"
                            { (yyval.llPtr) = returnLL("{");}
#line 2562 "test.tab.c"
    break;

  case 79: /* CCurly: CCURLY  */
#line 854 "test.y"
                            { (yyval.llPtr) = returnLL("}");}
#line 2568 "test.tab.c"
    break;

  case 80: /* Public: PUBLIC  */
#line 855 "test.y"
                            { (yyval.llPtr) = returnLL("public");}
#line 2574 "test.tab.c"
    break;

  case 81: /* Static: STATIC  */
#line 856 "test.y"
                            { (yyval.llPtr) = returnLL("static");}
#line 2580 "test.tab.c"
    break;

  case 82: /* Void: VOID  */
#line 857 "test.y"
                            { (yyval.llPtr) = returnLL("void");}
#line 2586 "test.tab.c"
    break;

  case 83: /* Main: MAIN  */
#line 858 "test.y"
                            { (yyval.llPtr) = returnLL("main");}
#line 2592 "test.tab.c"
    break;

  case 84: /* OParen: OPAREN  */
#line 859 "test.y"
                            { (yyval.llPtr) = returnLL("(");}
#line 2598 "test.tab.c"
    break;

  case 85: /* CParen: CPAREN  */
#line 860 "test.y"
                            { (yyval.llPtr) = returnLL(")");}
#line 2604 "test.tab.c"
    break;

  case 86: /* String: STRING  */
#line 861 "test.y"
                            { (yyval.llPtr) = returnLL("String ");}
#line 2610 "test.tab.c"
    break;

  case 87: /* OSqre: OSQRE  */
#line 862 "test.y"
                            { (yyval.llPtr) = returnLL("[");}
#line 2616 "test.tab.c"
    break;

  case 88: /* CSqre: CSQRE  */
#line 863 "test.y"
                            { (yyval.llPtr) = returnLL("]");}
#line 2622 "test.tab.c"
    break;

  case 89: /* PrintStatement: PRNTSTMT  */
#line 864 "test.y"
                            { (yyval.llPtr) = returnLL("System.out.println");}
#line 2628 "test.tab.c"
    break;

  case 90: /* SColon: SCOLON  */
#line 865 "test.y"
                            { (yyval.llPtr) = returnLL(";");}
#line 2634 "test.tab.c"
    break;

  case 91: /* Dot: DOT  */
#line 866 "test.y"
                            { (yyval.llPtr) = returnLL(".");}
#line 2640 "test.tab.c"
    break;

  case 92: /* Length: LENGTH  */
#line 867 "test.y"
                            { (yyval.llPtr) = returnLL("length");}
#line 2646 "test.tab.c"
    break;

  case 93: /* This: THIS  */
#line 868 "test.y"
                            { (yyval.llPtr) = returnLL("this");}
#line 2652 "test.tab.c"
    break;

  case 94: /* New: NEW  */
#line 869 "test.y"
                            { (yyval.llPtr) = returnLL("new");}
#line 2658 "test.tab.c"
    break;

  case 95: /* Int: INT  */
#line 870 "test.y"
                            { (yyval.llPtr) = returnLL("int");}
#line 2664 "test.tab.c"
    break;

  case 96: /* Boolean: BOOLEAN  */
#line 871 "test.y"
                            { (yyval.llPtr) = returnLL("boolean");}
#line 2670 "test.tab.c"
    break;

  case 97: /* Exclam: EXCLAM  */
#line 872 "test.y"
                            { (yyval.llPtr) = returnLL("!");}
#line 2676 "test.tab.c"
    break;

  case 98: /* Return: RETURN  */
#line 873 "test.y"
                            { (yyval.llPtr) = returnLL("return");}
#line 2682 "test.tab.c"
    break;

  case 99: /* Extends: EXTENDS  */
#line 874 "test.y"
                            { (yyval.llPtr) = returnLL("extends");}
#line 2688 "test.tab.c"
    break;

  case 100: /* Eq: EQ  */
#line 875 "test.y"
                            { (yyval.llPtr) = returnLL("=");}
#line 2694 "test.tab.c"
    break;

  case 101: /* If: IF  */
#line 876 "test.y"
                            { (yyval.llPtr) = returnLL("if");}
#line 2700 "test.tab.c"
    break;

  case 102: /* Else: ELSE  */
#line 877 "test.y"
                            { (yyval.llPtr) = returnLL("else");}
#line 2706 "test.tab.c"
    break;

  case 103: /* While: WHILE  */
#line 878 "test.y"
                            { (yyval.llPtr) = returnLL("while");}
#line 2712 "test.tab.c"
    break;

  case 104: /* Comma: COMMA  */
#line 879 "test.y"
                            { (yyval.llPtr) = returnLL(",");}
#line 2718 "test.tab.c"
    break;

  case 105: /* Land: LAND  */
#line 880 "test.y"
                            { (yyval.llPtr) = returnLL("&&");}
#line 2724 "test.tab.c"
    break;

  case 106: /* Lor: LOR  */
#line 881 "test.y"
                            { (yyval.llPtr) = returnLL("||");}
#line 2730 "test.tab.c"
    break;

  case 107: /* Neq: NEQ  */
#line 882 "test.y"
                            { (yyval.llPtr) = returnLL("!=");}
#line 2736 "test.tab.c"
    break;

  case 108: /* Leq: LEQ  */
#line 883 "test.y"
                            { (yyval.llPtr) = returnLL("<=");}
#line 2742 "test.tab.c"
    break;

  case 109: /* Plus: PLUS  */
#line 884 "test.y"
                            { (yyval.llPtr) = returnLL("+");}
#line 2748 "test.tab.c"
    break;

  case 110: /* Minus: MINUS  */
#line 885 "test.y"
                            { (yyval.llPtr) = returnLL("-");}
#line 2754 "test.tab.c"
    break;

  case 111: /* Mul: MUL  */
#line 886 "test.y"
                            { (yyval.llPtr) = returnLL("*");}
#line 2760 "test.tab.c"
    break;

  case 112: /* Div: DIV  */
#line 887 "test.y"
                            { (yyval.llPtr) = returnLL("/");}
#line 2766 "test.tab.c"
    break;

  case 113: /* Btrue: BTRUE  */
#line 888 "test.y"
                            { (yyval.llPtr) = returnLL("true");}
#line 2772 "test.tab.c"
    break;

  case 114: /* Bfalse: BFALSE  */
#line 889 "test.y"
                            { (yyval.llPtr) = returnLL("false");}
#line 2778 "test.tab.c"
    break;

  case 115: /* DefineExpr0: DEFINEEXPR0  */
#line 890 "test.y"
                            { (yyval.llPtr) = returnLL("#defineexpr0 ");}
#line 2784 "test.tab.c"
    break;

  case 116: /* DefineExpr1: DEFINEEXPR1  */
#line 891 "test.y"
                            { (yyval.llPtr) = returnLL("#defineexpr1 ");}
#line 2790 "test.tab.c"
    break;

  case 117: /* DefineExpr2: DEFINEEXPR2  */
#line 892 "test.y"
                            { (yyval.llPtr) = returnLL("#defineexpr2 ");}
#line 2796 "test.tab.c"
    break;

  case 118: /* DefineExpr: DEFINEEXPR  */
#line 893 "test.y"
                                { (yyval.llPtr) = returnLL("#defineexpr ");}
#line 2802 "test.tab.c"
    break;

  case 119: /* DefineStmt0: DEFINESTMT0  */
#line 894 "test.y"
                                { (yyval.llPtr) = returnLL("#definestmt0 ");}
#line 2808 "test.tab.c"
    break;

  case 120: /* DefineStmt1: DEFINESTMT1  */
#line 895 "test.y"
                                { (yyval.llPtr) = returnLL("#definestmt1 ");}
#line 2814 "test.tab.c"
    break;

  case 121: /* DefineStmt2: DEFINESTMT2  */
#line 896 "test.y"
                                { (yyval.llPtr) = returnLL("#definestmt2 ");}
#line 2820 "test.tab.c"
    break;

  case 122: /* DefineStmt: DEFINESTMT  */
#line 897 "test.y"
                                { (yyval.llPtr) = returnLL("#definestmt ");}
#line 2826 "test.tab.c"
    break;

  case 123: /* Identifier: ID  */
#line 899 "test.y"
                            { (yyval.llPtr) = returnLL((yyvsp[0].id));}
#line 2832 "test.tab.c"
    break;

  case 124: /* Number: NUM  */
#line 900 "test.y"
                            { (yyval.llPtr) = returnLL((yyvsp[0].id));}
#line 2838 "test.tab.c"
    break;


#line 2842 "test.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 901 "test.y"


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
