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

#line 128 "test.tab.c"

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
#line 58 "test.y"

    int num;
    char* id;
    LL* llPtr;

#line 231 "test.tab.c"

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
  YYSYMBOL_DefineExpr = 116,               /* DefineExpr  */
  YYSYMBOL_DefineStmt0 = 117,              /* DefineStmt0  */
  YYSYMBOL_DefineStmt1 = 118,              /* DefineStmt1  */
  YYSYMBOL_DefineStmt2 = 119,              /* DefineStmt2  */
  YYSYMBOL_DefineStmt = 120,               /* DefineStmt  */
  YYSYMBOL_Identifier = 121,               /* Identifier  */
  YYSYMBOL_Number = 122                    /* Number  */
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
#define YYFINAL  25
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   397

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  300

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
       0,    94,    94,    97,   103,   106,   111,   114,   115,   118,
     134,   144,   155,   170,   186,   196,   207,   222,   229,   230,
     237,   246,   259,   260,   268,   276,   277,   284,   291,   292,
     299,   319,   340,   341,   348,   355,   385,   391,   392,   393,
     396,   397,   404,   410,   418,   425,   435,   443,   453,   461,
     469,   478,   482,   490,   496,   502,   508,   514,   520,   526,
     532,   538,   545,   551,   555,   563,   572,   578,   587,   588,
     589,   590,   591,   592,   600,   607,   612,   620,   621,   622,
     623,   624,   625,   626,   627,   628,   629,   630,   631,   632,
     633,   634,   635,   636,   637,   638,   639,   640,   641,   642,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   652,
     653,   654,   655,   656,   657,   658,   659,   661,   662,   663,
     664,   665,   667,   668
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
  "Btrue", "Bfalse", "DefineExpr0", "DefineExpr1", "DefineExpr",
  "DefineStmt0", "DefineStmt1", "DefineStmt2", "DefineStmt", "Identifier",
  "Number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-203)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     378,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,    25,
    -203,    15,   387,  -203,  -203,  -203,    15,   -14,   -14,   -14,
     -14,   -14,   -14,   -14,   -14,  -203,  -203,  -203,  -203,    15,
     -14,  -203,    10,    21,    21,    21,    21,    21,    21,    21,
    -203,    -1,  -203,    50,  -203,    49,   -14,   -14,    49,   -14,
     -14,   -14,  -203,  -203,   -14,  -203,    69,  -203,    21,   -11,
      38,    10,    49,    38,    38,     5,    10,  -203,    67,   301,
    -203,    21,   -14,   -14,   115,    10,   -14,   -14,  -203,  -203,
    -203,    68,    50,   -14,    27,    53,  -203,  -203,  -203,  -203,
      77,  -203,  -203,  -203,  -203,  -203,  -203,    49,   324,   301,
    -203,     4,   301,  -203,  -203,    21,  -203,   301,    49,    38,
    -203,  -203,  -203,    68,   115,   115,    21,    21,    21,    58,
     115,    49,    38,  -203,  -203,  -203,    64,   -14,  -203,    59,
       5,  -203,    21,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,   301,    56,   301,   301,   301,   301,   301,
     301,   301,   301,    49,    53,    21,  -203,   310,    49,    21,
     -14,  -203,  -203,    68,   301,   301,   301,  -203,   310,   301,
     301,    68,    10,   -14,  -203,  -203,    21,  -203,  -203,    68,
      82,    59,  -203,  -203,  -203,    21,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,   301,    49,    49,    38,  -203,
    -203,   301,   -14,  -203,    49,    49,    49,    49,    64,    59,
      64,  -203,   115,   -14,    32,  -203,  -203,    53,  -203,   310,
      59,  -203,  -203,   301,    49,    49,   -14,    38,    64,   115,
     115,    64,  -203,    66,  -203,    68,    49,    49,    38,   -14,
      10,    59,    49,  -203,  -203,  -203,  -203,    21,  -203,  -203,
    -203,    91,  -203,  -203,   301,  -203,    10,    10,    27,  -203,
    -203,   -14,  -203,   301,  -203,   115,    64,   115,  -203,  -203,
     293,    49,    49,  -203,  -203,    68,   293,   104,    58,    10,
    -203,  -203,   104,  -203,   301,    92,   301,    64,    21,    64,
      68,   301,    68,  -203,    49,  -203,    64,    68,    68,  -203
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,   115,   116,   117,   118,   119,   120,   121,    77,     0,
       2,     0,     6,     8,     7,     4,    18,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     3,     5,    17,    18,
       0,   122,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,    78,     0,    84,     0,     0,     0,     0,     0,
       0,     0,    99,    22,     0,    80,     0,    85,     0,     0,
       0,     0,     0,     0,     0,    28,     0,    81,     0,     0,
     104,     0,     0,     0,    40,     0,     0,     0,    95,    96,
      23,     0,    28,     0,     0,    38,    37,    39,    22,    82,
       0,    94,    93,   113,   114,    97,   123,     0,    63,     0,
      72,     0,     0,    69,    70,    71,    68,     0,     0,     0,
     101,   103,    89,     0,    40,    40,     0,     0,     0,     0,
      40,     0,     0,    79,    20,    29,     0,     0,    87,     0,
      28,    83,     0,    10,   105,   106,   107,   108,   109,   110,
     111,   112,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,    14,    41,     0,     0,     0,     0,   100,     0,     0,
       0,     0,     0,     0,    90,    24,     0,    88,    36,     0,
       0,     0,    71,    92,    62,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    76,     0,     0,     0,    51,    66,
      11,     0,    25,    42,     0,     0,     0,     0,     0,     0,
       0,    15,    40,    25,     0,    21,    86,     0,    61,     0,
       0,    74,    67,     0,     0,     0,    25,     0,     0,     0,
       0,     0,    50,     0,    44,     0,     0,     0,    32,     0,
       0,     0,     0,    64,    73,    52,    12,     0,    26,    27,
      43,    46,    48,    49,     0,    16,     0,     0,     0,    34,
      22,     0,    65,     0,   102,     0,     0,    40,    22,    33,
      40,     0,     0,    47,    45,     0,    40,     0,    39,     0,
       9,    13,     0,    98,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,     0,    30,     0,     0,     0,    35
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -203,  -203,  -203,   110,  -203,  -203,  -203,   113,    96,  -203,
     -80,  -203,  -202,  -203,   -66,  -203,  -122,  -203,  -203,   -72,
     -25,  -190,  -158,     9,   228,    12,   -23,   -67,    98,  -203,
    -203,  -203,    35,    61,  -203,   -71,  -162,  -146,    18,  -203,
    -203,  -203,  -203,    44,  -203,  -203,  -134,  -203,   -83,  -203,
    -203,  -203,    54,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
    -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,  -203,
     -17,  -203
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    14,    15,    28,    29,
      65,    80,   225,   226,    81,    82,   237,   238,    16,    83,
     113,   114,   197,   198,    98,    17,   115,   124,    84,    68,
      90,   132,    99,    58,   217,   169,   178,   116,   175,   144,
     184,   100,   101,    85,    86,   102,   284,    54,   170,   117,
     265,   118,    72,   145,   146,   147,   148,   149,   150,   151,
     152,   103,   104,    18,    19,    20,    21,    22,    23,    24,
     105,   106
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    33,    34,    35,    36,    37,    38,    39,   130,    43,
     207,   236,   127,    41,   129,    52,   125,    55,    53,   218,
      57,    78,    78,    79,   248,    25,     8,   143,    30,    59,
      60,    42,    62,    63,    64,    31,    70,    66,    74,   251,
     252,    30,    42,    88,    78,    79,   161,   233,    87,    78,
      79,    44,   120,    31,    31,   108,   109,   119,   244,   121,
     122,   242,    55,    57,   179,   245,   126,    87,    45,    46,
      47,    48,    49,    50,    51,   273,    31,   183,    97,   261,
      57,    31,    67,   195,   155,    70,    89,   128,    44,   162,
     163,   131,   128,    69,   177,   171,   203,   119,   119,   167,
     174,   123,   216,   119,   211,    31,   107,   167,   153,    61,
     176,   156,   215,    87,    73,   264,   158,    76,    77,   283,
      71,   112,    27,    75,    26,    40,   182,   185,   182,   182,
     182,   182,   182,   182,   182,   182,   269,   110,   111,   288,
     157,    56,   239,   202,   112,   154,   241,    42,   286,   212,
     254,   164,   165,   166,   168,     0,   213,     0,   133,     0,
       0,     0,     0,   160,    31,     0,     0,   180,   255,   159,
       0,     0,     0,   204,   205,   206,   173,     0,   209,   210,
     270,     0,   172,     0,     0,   227,   239,   235,   276,     0,
     196,     0,     0,     0,   201,   119,   227,    87,     0,     0,
       0,     0,     0,     0,   220,     0,     0,     0,   281,   227,
     224,   214,   119,   119,   194,     0,     0,   260,   199,   200,
     219,     0,   259,   293,     0,   295,   232,     0,   234,   208,
     298,   299,     0,   267,   268,     0,     0,     0,     0,     0,
       0,    87,   275,     0,   271,   277,   250,     0,   119,   253,
     119,   282,   223,   278,     0,     0,   285,   221,   222,   278,
       0,     0,     0,   266,     0,   228,   229,   230,   231,     0,
       0,     0,   272,     0,     0,   240,     0,     0,     0,     0,
     243,   249,   263,     0,   274,   246,   247,     0,     0,     0,
       0,     0,   258,   287,     0,   289,     0,   256,   257,     0,
     294,     0,     0,   262,     0,   290,     0,   292,     0,     0,
      78,    79,     0,   168,   297,   110,   111,     0,     0,     0,
       0,     0,   112,   291,     0,    42,    91,    92,    93,    94,
       0,    44,   279,   280,     0,    91,    92,    93,    94,     0,
      44,    57,    31,     0,     0,     0,     0,    95,     0,     0,
      31,    96,     0,     0,     0,   296,    95,     0,   128,    31,
      96,   134,   135,   136,   137,     0,   138,   139,   140,   141,
       0,   181,   142,   186,   187,   188,   189,   190,   191,   192,
     193,     1,     2,     0,     3,     4,     5,     6,     7,     8,
       1,     2,     0,     3,     4,     5,     6,     7
};

static const yytype_int16 yycheck[] =
{
      17,    18,    19,    20,    21,    22,    23,    24,    88,    32,
     168,   213,    84,    30,    85,    16,    82,    12,    41,   181,
      31,    17,    17,    18,   226,     0,    11,    98,    16,    46,
      47,    32,    49,    50,    51,    49,    47,    54,    61,   229,
     230,    29,    32,    66,    17,    18,   113,   209,    65,    17,
      18,    30,    75,    49,    49,    72,    73,    74,   220,    76,
      77,   219,    12,    31,   130,   223,    83,    84,    33,    34,
      35,    36,    37,    38,    39,   265,    49,    21,    69,   241,
      31,    49,    13,   154,   101,    47,    19,    34,    30,   114,
     115,    14,    34,    58,    35,   120,   163,   114,   115,    41,
      36,    33,    20,   120,   171,    49,    71,    41,    99,    48,
     127,   102,   179,   130,    60,    24,   107,    63,    64,    15,
      59,    29,    12,    62,    11,    29,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   258,    22,    23,   285,
     105,    43,   214,   160,    29,   101,   217,    32,   282,   172,
     233,   116,   117,   118,   119,    -1,   173,    -1,    97,    -1,
      -1,    -1,    -1,   109,    49,    -1,    -1,   132,   235,   108,
      -1,    -1,    -1,   164,   165,   166,   122,    -1,   169,   170,
     260,    -1,   121,    -1,    -1,   202,   258,   212,   268,    -1,
     155,    -1,    -1,    -1,   159,   212,   213,   214,    -1,    -1,
      -1,    -1,    -1,    -1,   195,    -1,    -1,    -1,   275,   226,
     201,   176,   229,   230,   153,    -1,    -1,   240,   157,   158,
     185,    -1,   239,   290,    -1,   292,   208,    -1,   210,   168,
     297,   298,    -1,   256,   257,    -1,    -1,    -1,    -1,    -1,
      -1,   258,   267,    -1,   261,   270,   228,    -1,   265,   231,
     267,   276,   198,   270,    -1,    -1,   279,   196,   197,   276,
      -1,    -1,    -1,   254,    -1,   204,   205,   206,   207,    -1,
      -1,    -1,   263,    -1,    -1,   214,    -1,    -1,    -1,    -1,
     219,   227,   247,    -1,   266,   224,   225,    -1,    -1,    -1,
      -1,    -1,   238,   284,    -1,   286,    -1,   236,   237,    -1,
     291,    -1,    -1,   242,    -1,   287,    -1,   289,    -1,    -1,
      17,    18,    -1,   278,   296,    22,    23,    -1,    -1,    -1,
      -1,    -1,    29,   288,    -1,    32,    25,    26,    27,    28,
      -1,    30,   271,   272,    -1,    25,    26,    27,    28,    -1,
      30,    31,    49,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    -1,    -1,    -1,   294,    46,    -1,    34,    49,
      50,    37,    38,    39,    40,    -1,    42,    43,    44,    45,
      -1,   143,    48,   145,   146,   147,   148,   149,   150,   151,
     152,     3,     4,    -1,     6,     7,     8,     9,    10,    11,
       3,     4,    -1,     6,     7,     8,     9,    10
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     6,     7,     8,     9,    10,    11,    52,
      53,    54,    55,    56,    57,    58,    69,    76,   114,   115,
     116,   117,   118,   119,   120,     0,    58,    54,    59,    60,
      76,    49,   121,   121,   121,   121,   121,   121,   121,   121,
      59,   121,    32,    77,    30,    83,    83,    83,    83,    83,
      83,    83,    16,    77,    98,    12,    79,    31,    84,   121,
     121,    84,   121,   121,   121,    61,   121,    13,    80,    83,
      47,    84,   103,   103,    77,    84,   103,   103,    17,    18,
      62,    65,    66,    70,    79,    94,    95,   121,    77,    19,
      81,    25,    26,    27,    28,    46,    50,    74,    75,    83,
      92,    93,    96,   112,   113,   121,   122,    83,   121,   121,
      22,    23,    29,    71,    72,    77,    88,   100,   102,   121,
      77,   121,   121,    33,    78,    65,   121,    70,    34,    86,
      61,    14,    82,    84,    37,    38,    39,    40,    42,    43,
      44,    45,    48,    86,    90,   104,   105,   106,   107,   108,
     109,   110,   111,    74,    94,   121,    74,    83,    74,    84,
     103,    78,    71,    71,    83,    83,    83,    41,    83,    86,
      99,    71,    84,   103,    36,    89,   121,    35,    87,    65,
      83,    75,   121,    21,    91,   121,    75,    75,    75,    75,
      75,    75,    75,    75,    84,    86,    83,    73,    74,    84,
      84,    83,   121,    78,    74,    74,    74,    73,    84,    74,
      74,    78,    77,   121,    83,    78,    20,    85,    87,    83,
      74,    84,    84,   103,    74,    63,    64,   121,    84,    84,
      84,    84,    89,    87,    89,    71,    63,    67,    68,    70,
      84,    86,    73,    84,    87,    73,    84,    84,    63,   103,
      89,    72,    72,    89,    99,    78,    84,    84,   103,   121,
      77,    87,    84,    83,    24,   101,    74,    77,    77,    67,
      61,   121,    74,    72,    89,    71,    61,    71,   121,    84,
      84,    78,    71,    15,    97,    77,    97,    74,    88,    74,
      89,    83,    89,    78,    74,    78,    84,    89,    78,    78
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
     119,   120,   121,   122
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
       1,     1,     1,     1
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
#line 94 "test.y"
               {(yyval.llPtr) = (yyvsp[0].llPtr); printLL((yyval.llPtr));}
#line 1558 "test.tab.c"
    break;

  case 3: /* MiniGoal: MacroDefinitionMultiple MainPart  */
#line 98 "test.y"
                {
			(yyval.llPtr) = (yyvsp[-1].llPtr);
			if((yyval.llPtr) != NULL) attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			else (yyval.llPtr) = (yyvsp[0].llPtr);
		}
#line 1568 "test.tab.c"
    break;

  case 4: /* MiniGoal: MainPart  */
#line 103 "test.y"
                   {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1574 "test.tab.c"
    break;

  case 5: /* MacroDefinitionMultiple: MacroDefinition MacroDefinitionMultiple  */
#line 107 "test.y"
                                           {
						(yyval.llPtr) = (yyvsp[-1].llPtr);
						attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
					   }
#line 1583 "test.tab.c"
    break;

  case 6: /* MacroDefinitionMultiple: MacroDefinition  */
#line 111 "test.y"
                                         {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1589 "test.tab.c"
    break;

  case 7: /* MacroDefinition: MacroDefStatement  */
#line 114 "test.y"
                                   {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1595 "test.tab.c"
    break;

  case 8: /* MacroDefinition: MacroDefExpression  */
#line 115 "test.y"
                                    {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1601 "test.tab.c"
    break;

  case 9: /* MacroDefExpression: DefineExpr Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OParen Expression CParen  */
#line 119 "test.y"
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
#line 1621 "test.tab.c"
    break;

  case 10: /* MacroDefExpression: DefineExpr0 Identifier OParen CParen OParen Expression CParen  */
#line 135 "test.y"
                                  {
					(yyval.llPtr) = (yyvsp[-6].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				  }
#line 1635 "test.tab.c"
    break;

  case 11: /* MacroDefExpression: DefineExpr1 Identifier OParen Identifier CParen OParen Expression CParen  */
#line 145 "test.y"
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
#line 1650 "test.tab.c"
    break;

  case 12: /* MacroDefExpression: DefineExpr1 Identifier OParen Identifier Comma Identifier CParen OParen Expression CParen  */
#line 156 "test.y"
                                  {
					(yyval.llPtr) = (yyvsp[-9].llPtr);
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
#line 1667 "test.tab.c"
    break;

  case 13: /* MacroDefStatement: DefineStmt Identifier OParen Identifier Comma Identifier Comma Identifier IdentifiersList CParen OCurly StatementsList CCurly  */
#line 171 "test.y"
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
#line 1687 "test.tab.c"
    break;

  case 14: /* MacroDefStatement: DefineStmt0 Identifier OParen CParen OCurly StatementsList CCurly  */
#line 187 "test.y"
                                 {
					(yyval.llPtr) = (yyvsp[-6].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				 }
#line 1701 "test.tab.c"
    break;

  case 15: /* MacroDefStatement: DefineStmt1 Identifier OParen Identifier CParen OCurly StatementsList CCurly  */
#line 197 "test.y"
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
#line 1716 "test.tab.c"
    break;

  case 16: /* MacroDefStatement: DefineStmt2 Identifier OParen Identifier Comma Identifier CParen OCurly StatementsList CCurly  */
#line 208 "test.y"
                                 {
					(yyval.llPtr) = (yyvsp[-9].llPtr);
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
#line 1733 "test.tab.c"
    break;

  case 17: /* MainPart: MainClass NextPart  */
#line 223 "test.y"
                {
			(yyval.llPtr) = (yyvsp[-1].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		}
#line 1742 "test.tab.c"
    break;

  case 18: /* NextPart: %empty  */
#line 229 "test.y"
          {(yyval.llPtr) = NULL;}
#line 1748 "test.tab.c"
    break;

  case 19: /* NextPart: TypeDeclaration NextPart  */
#line 231 "test.y"
                {
			(yyval.llPtr) = (yyvsp[-1].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		}
#line 1757 "test.tab.c"
    break;

  case 20: /* TypeDeclaration: Class Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly  */
#line 238 "test.y"
                                {
					(yyval.llPtr) = (yyvsp[-5].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				}
#line 1770 "test.tab.c"
    break;

  case 21: /* TypeDeclaration: Class Identifier Extends Identifier OCurly IdentifierDeclarations MethodDeclarationMultiple CCurly  */
#line 247 "test.y"
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
#line 1785 "test.tab.c"
    break;

  case 22: /* IdentifierDeclarations: %empty  */
#line 259 "test.y"
                        {(yyval.llPtr) = NULL;}
#line 1791 "test.tab.c"
    break;

  case 23: /* IdentifierDeclarations: IdentifierDeclarations IdentifierDeclarationsFinal  */
#line 261 "test.y"
                                          {
						(yyval.llPtr) = (yyvsp[-1].llPtr);
						if((yyval.llPtr) != NULL) attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						else (yyval.llPtr) = (yyvsp[0].llPtr);
					  }
#line 1801 "test.tab.c"
    break;

  case 24: /* IdentifierDeclarationsFinal: Type Identifier SColon  */
#line 269 "test.y"
                                                    {
								(yyval.llPtr) = (yyvsp[-2].llPtr);
								attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
								attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						    }
#line 1811 "test.tab.c"
    break;

  case 25: /* IdentifiersList: %empty  */
#line 276 "test.y"
                 {(yyval.llPtr) = NULL;}
#line 1817 "test.tab.c"
    break;

  case 26: /* IdentifiersList: ExtraIdentifier IdentifiersList  */
#line 278 "test.y"
                           {
					(yyval.llPtr) = (yyvsp[-1].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			   }
#line 1826 "test.tab.c"
    break;

  case 27: /* ExtraIdentifier: Identifier Comma  */
#line 285 "test.y"
                                {
					(yyval.llPtr) = (yyvsp[-1].llPtr);
					attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
				}
#line 1835 "test.tab.c"
    break;

  case 28: /* MethodDeclarationMultiple: %empty  */
#line 291 "test.y"
                           {(yyval.llPtr) = NULL;}
#line 1841 "test.tab.c"
    break;

  case 29: /* MethodDeclarationMultiple: MethodDeclaration MethodDeclarationMultiple  */
#line 293 "test.y"
                                                 {
							(yyval.llPtr) = (yyvsp[-1].llPtr);
							attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
						 }
#line 1850 "test.tab.c"
    break;

  case 30: /* MethodDeclaration: Public Type Identifier OParen Parameters CParen OCurly IdentifierDeclarations StatementsList Return Expression SColon CCurly  */
#line 304 "test.y"
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
#line 1870 "test.tab.c"
    break;

  case 31: /* MethodDeclaration: Public Type Identifier OParen CParen OCurly IdentifierDeclarations StatementsList Return Expression SColon CCurly  */
#line 324 "test.y"
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
#line 1889 "test.tab.c"
    break;

  case 32: /* Parameters: ParametersFinal  */
#line 340 "test.y"
                            {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1895 "test.tab.c"
    break;

  case 33: /* Parameters: ParametersFinal Comma Parameters  */
#line 342 "test.y"
                  {
			  (yyval.llPtr) = (yyvsp[-2].llPtr);
			  attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
		  }
#line 1904 "test.tab.c"
    break;

  case 34: /* ParametersFinal: Type Identifier  */
#line 349 "test.y"
                           {
				   (yyval.llPtr) = (yyvsp[-1].llPtr);
				   attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			   }
#line 1913 "test.tab.c"
    break;

  case 35: /* MainClass: Class Identifier OCurly Public Static Void Main OParen String OSqre CSqre Identifier CParen OCurly PrintStatement OParen Expression CParen SColon CCurly CCurly  */
#line 360 "test.y"
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
#line 1941 "test.tab.c"
    break;

  case 36: /* Type: Int OSqre CSqre  */
#line 386 "test.y"
        {
		(yyval.llPtr) = (yyvsp[-2].llPtr);
		attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
		attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
	}
#line 1951 "test.tab.c"
    break;

  case 37: /* Type: Boolean  */
#line 391 "test.y"
              {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1957 "test.tab.c"
    break;

  case 38: /* Type: Int  */
#line 392 "test.y"
          {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1963 "test.tab.c"
    break;

  case 39: /* Type: Identifier  */
#line 393 "test.y"
                 {(yyval.llPtr) = (yyvsp[0].llPtr);}
#line 1969 "test.tab.c"
    break;

  case 40: /* StatementsList: %empty  */
#line 396 "test.y"
                {(yyval.llPtr) = NULL;}
#line 1975 "test.tab.c"
    break;

  case 41: /* StatementsList: Statement StatementsList  */
#line 398 "test.y"
                          {
				(yyval.llPtr) = (yyvsp[-1].llPtr);
				attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
			  }
#line 1984 "test.tab.c"
    break;

  case 42: /* Statement: OCurly StatementsList CCurly  */
#line 405 "test.y"
         {
			(yyval.llPtr) = (yyvsp[-2].llPtr);
			attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
         }
#line 1994 "test.tab.c"
    break;

  case 43: /* Statement: PrintStatement OParen Expression CParen SColon  */
#line 411 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2006 "test.tab.c"
    break;

  case 44: /* Statement: Identifier Eq Expression SColon  */
#line 419 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2017 "test.tab.c"
    break;

  case 45: /* Statement: Identifier OSqre Expression CSqre Eq Expression SColon  */
#line 426 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-6].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2031 "test.tab.c"
    break;

  case 46: /* Statement: If OParen Expression CParen Statement  */
#line 436 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2043 "test.tab.c"
    break;

  case 47: /* Statement: If OParen Expression CParen Statement Else Statement  */
#line 444 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-6].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-5].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
			      attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2057 "test.tab.c"
    break;

  case 48: /* Statement: While OParen Expression CParen Statement  */
#line 454 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2069 "test.tab.c"
    break;

  case 49: /* Statement: Identifier OParen ExpressionList CParen SColon  */
#line 462 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2081 "test.tab.c"
    break;

  case 50: /* Statement: Identifier OParen CParen SColon  */
#line 470 "test.y"
                 {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
		 }
#line 2092 "test.tab.c"
    break;

  case 51: /* ExpressionList: Expression  */
#line 479 "test.y"
              {
                (yyval.llPtr) = (yyvsp[0].llPtr);
              }
#line 2100 "test.tab.c"
    break;

  case 52: /* ExpressionList: Expression Comma ExpressionList  */
#line 483 "test.y"
              {
                (yyval.llPtr) = (yyvsp[-2].llPtr);
                attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
              }
#line 2110 "test.tab.c"
    break;

  case 53: /* Expression: PrimaryExpression Land PrimaryExpression  */
#line 491 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2120 "test.tab.c"
    break;

  case 54: /* Expression: PrimaryExpression Lor PrimaryExpression  */
#line 497 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2130 "test.tab.c"
    break;

  case 55: /* Expression: PrimaryExpression Neq PrimaryExpression  */
#line 503 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2140 "test.tab.c"
    break;

  case 56: /* Expression: PrimaryExpression Leq PrimaryExpression  */
#line 509 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2150 "test.tab.c"
    break;

  case 57: /* Expression: PrimaryExpression Plus PrimaryExpression  */
#line 515 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2160 "test.tab.c"
    break;

  case 58: /* Expression: PrimaryExpression Minus PrimaryExpression  */
#line 521 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2170 "test.tab.c"
    break;

  case 59: /* Expression: PrimaryExpression Mul PrimaryExpression  */
#line 527 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2180 "test.tab.c"
    break;

  case 60: /* Expression: PrimaryExpression Div PrimaryExpression  */
#line 533 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2190 "test.tab.c"
    break;

  case 61: /* Expression: PrimaryExpression OSqre PrimaryExpression CSqre  */
#line 539 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2201 "test.tab.c"
    break;

  case 62: /* Expression: PrimaryExpression Dot Length  */
#line 546 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2211 "test.tab.c"
    break;

  case 63: /* Expression: PrimaryExpression  */
#line 552 "test.y"
          {
            (yyval.llPtr) = (yyvsp[0].llPtr);
          }
#line 2219 "test.tab.c"
    break;

  case 64: /* Expression: PrimaryExpression Dot Identifier OParen CParen  */
#line 556 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-4].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2231 "test.tab.c"
    break;

  case 65: /* Expression: PrimaryExpression Dot Identifier OParen ExpressionList CParen  */
#line 564 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-5].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-4].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2244 "test.tab.c"
    break;

  case 66: /* Expression: Identifier OParen CParen  */
#line 573 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-2].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2254 "test.tab.c"
    break;

  case 67: /* Expression: Identifier OParen ExpressionList CParen  */
#line 579 "test.y"
          {
            (yyval.llPtr) = (yyvsp[-3].llPtr);
            attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
            attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
          }
#line 2265 "test.tab.c"
    break;

  case 68: /* PrimaryExpression: Number  */
#line 587 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2271 "test.tab.c"
    break;

  case 69: /* PrimaryExpression: Btrue  */
#line 588 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2277 "test.tab.c"
    break;

  case 70: /* PrimaryExpression: Bfalse  */
#line 589 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2283 "test.tab.c"
    break;

  case 71: /* PrimaryExpression: Identifier  */
#line 590 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2289 "test.tab.c"
    break;

  case 72: /* PrimaryExpression: This  */
#line 591 "test.y"
                                { (yyval.llPtr) = (yyvsp[0].llPtr); }
#line 2295 "test.tab.c"
    break;

  case 73: /* PrimaryExpression: New Int OSqre Expression CSqre  */
#line 593 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-4].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[-3].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2307 "test.tab.c"
    break;

  case 74: /* PrimaryExpression: New Identifier OParen CParen  */
#line 601 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-3].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[-2].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2318 "test.tab.c"
    break;

  case 75: /* PrimaryExpression: Exclam Expression  */
#line 608 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-1].llPtr); 
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2327 "test.tab.c"
    break;

  case 76: /* PrimaryExpression: OParen Expression CParen  */
#line 613 "test.y"
                 {
                    (yyval.llPtr) = (yyvsp[-2].llPtr);
                    attach_lists((yyval.llPtr), (yyvsp[-1].llPtr));
                    attach_lists((yyval.llPtr), (yyvsp[0].llPtr));
                 }
#line 2337 "test.tab.c"
    break;

  case 77: /* Class: CLASS  */
#line 620 "test.y"
                            { LL* temp = returnLL("\nclass "); (yyval.llPtr) = temp;}
#line 2343 "test.tab.c"
    break;

  case 78: /* OCurly: OCURLY  */
#line 621 "test.y"
                            { LL* temp = returnLL(" {\n"); (yyval.llPtr) = temp;}
#line 2349 "test.tab.c"
    break;

  case 79: /* CCurly: CCURLY  */
#line 622 "test.y"
                            { LL* temp = returnLL("\n}\n"); (yyval.llPtr) = temp;}
#line 2355 "test.tab.c"
    break;

  case 80: /* Public: PUBLIC  */
#line 623 "test.y"
                            { LL* temp = returnLL("public "); (yyval.llPtr) = temp;}
#line 2361 "test.tab.c"
    break;

  case 81: /* Static: STATIC  */
#line 624 "test.y"
                            { LL* temp = returnLL("static "); (yyval.llPtr) = temp;}
#line 2367 "test.tab.c"
    break;

  case 82: /* Void: VOID  */
#line 625 "test.y"
                            { LL* temp = returnLL("void "); (yyval.llPtr) = temp;}
#line 2373 "test.tab.c"
    break;

  case 83: /* Main: MAIN  */
#line 626 "test.y"
                            { LL* temp = returnLL("main "); (yyval.llPtr) = temp;}
#line 2379 "test.tab.c"
    break;

  case 84: /* OParen: OPAREN  */
#line 627 "test.y"
                            { LL* temp = returnLL(" ("); (yyval.llPtr) = temp;}
#line 2385 "test.tab.c"
    break;

  case 85: /* CParen: CPAREN  */
#line 628 "test.y"
                            { LL* temp = returnLL(") "); (yyval.llPtr) = temp;}
#line 2391 "test.tab.c"
    break;

  case 86: /* String: STRING  */
#line 629 "test.y"
                            { LL* temp = returnLL("String "); (yyval.llPtr) = temp;}
#line 2397 "test.tab.c"
    break;

  case 87: /* OSqre: OSQRE  */
#line 630 "test.y"
                            { LL* temp = returnLL(" ["); (yyval.llPtr) = temp;}
#line 2403 "test.tab.c"
    break;

  case 88: /* CSqre: CSQRE  */
#line 631 "test.y"
                            { LL* temp = returnLL("] "); (yyval.llPtr) = temp;}
#line 2409 "test.tab.c"
    break;

  case 89: /* PrintStatement: PRNTSTMT  */
#line 632 "test.y"
                            { LL* temp = returnLL("System.out.println"); (yyval.llPtr) = temp;}
#line 2415 "test.tab.c"
    break;

  case 90: /* SColon: SCOLON  */
#line 633 "test.y"
                            { LL* temp = returnLL(";\n"); (yyval.llPtr) = temp;}
#line 2421 "test.tab.c"
    break;

  case 91: /* Dot: DOT  */
#line 634 "test.y"
                            { LL* temp = returnLL("."); (yyval.llPtr) = temp;}
#line 2427 "test.tab.c"
    break;

  case 92: /* Length: LENGTH  */
#line 635 "test.y"
                            { LL* temp = returnLL("length"); (yyval.llPtr) = temp;}
#line 2433 "test.tab.c"
    break;

  case 93: /* This: THIS  */
#line 636 "test.y"
                            { LL* temp = returnLL("this"); (yyval.llPtr) = temp;}
#line 2439 "test.tab.c"
    break;

  case 94: /* New: NEW  */
#line 637 "test.y"
                            { LL* temp = returnLL("new "); (yyval.llPtr) = temp;}
#line 2445 "test.tab.c"
    break;

  case 95: /* Int: INT  */
#line 638 "test.y"
                            { LL* temp = returnLL("int "); (yyval.llPtr) = temp;}
#line 2451 "test.tab.c"
    break;

  case 96: /* Boolean: BOOLEAN  */
#line 639 "test.y"
                            { LL* temp = returnLL("boolean "); (yyval.llPtr) = temp;}
#line 2457 "test.tab.c"
    break;

  case 97: /* Exclam: EXCLAM  */
#line 640 "test.y"
                            { LL* temp = returnLL("!"); (yyval.llPtr) = temp;}
#line 2463 "test.tab.c"
    break;

  case 98: /* Return: RETURN  */
#line 641 "test.y"
                            { LL* temp = returnLL("return "); (yyval.llPtr) = temp;}
#line 2469 "test.tab.c"
    break;

  case 99: /* Extends: EXTENDS  */
#line 642 "test.y"
                            { LL* temp = returnLL("extends "); (yyval.llPtr) = temp;}
#line 2475 "test.tab.c"
    break;

  case 100: /* Eq: EQ  */
#line 643 "test.y"
                            { LL* temp = returnLL(" = "); (yyval.llPtr) = temp;}
#line 2481 "test.tab.c"
    break;

  case 101: /* If: IF  */
#line 644 "test.y"
                            { LL* temp = returnLL("if "); (yyval.llPtr) = temp;}
#line 2487 "test.tab.c"
    break;

  case 102: /* Else: ELSE  */
#line 645 "test.y"
                            { LL* temp = returnLL("else "); (yyval.llPtr) = temp;}
#line 2493 "test.tab.c"
    break;

  case 103: /* While: WHILE  */
#line 646 "test.y"
                            { LL* temp = returnLL("while "); (yyval.llPtr) = temp;}
#line 2499 "test.tab.c"
    break;

  case 104: /* Comma: COMMA  */
#line 647 "test.y"
                            { LL* temp = returnLL(","); (yyval.llPtr) = temp;}
#line 2505 "test.tab.c"
    break;

  case 105: /* Land: LAND  */
#line 648 "test.y"
                            { LL* temp = returnLL(" && "); (yyval.llPtr) = temp;}
#line 2511 "test.tab.c"
    break;

  case 106: /* Lor: LOR  */
#line 649 "test.y"
                            { LL* temp = returnLL(" || "); (yyval.llPtr) = temp;}
#line 2517 "test.tab.c"
    break;

  case 107: /* Neq: NEQ  */
#line 650 "test.y"
                            { LL* temp = returnLL(" != "); (yyval.llPtr) = temp;}
#line 2523 "test.tab.c"
    break;

  case 108: /* Leq: LEQ  */
#line 651 "test.y"
                            { LL* temp = returnLL(" <= "); (yyval.llPtr) = temp;}
#line 2529 "test.tab.c"
    break;

  case 109: /* Plus: PLUS  */
#line 652 "test.y"
                            { LL* temp = returnLL(" + "); (yyval.llPtr) = temp;}
#line 2535 "test.tab.c"
    break;

  case 110: /* Minus: MINUS  */
#line 653 "test.y"
                            { LL* temp = returnLL(" - "); (yyval.llPtr) = temp;}
#line 2541 "test.tab.c"
    break;

  case 111: /* Mul: MUL  */
#line 654 "test.y"
                            { LL* temp = returnLL(" * "); (yyval.llPtr) = temp;}
#line 2547 "test.tab.c"
    break;

  case 112: /* Div: DIV  */
#line 655 "test.y"
                            { LL* temp = returnLL(" / "); (yyval.llPtr) = temp;}
#line 2553 "test.tab.c"
    break;

  case 113: /* Btrue: BTRUE  */
#line 656 "test.y"
                            { LL* temp = returnLL("true"); (yyval.llPtr) = temp;}
#line 2559 "test.tab.c"
    break;

  case 114: /* Bfalse: BFALSE  */
#line 657 "test.y"
                            { LL* temp = returnLL("false"); (yyval.llPtr) = temp;}
#line 2565 "test.tab.c"
    break;

  case 115: /* DefineExpr0: DEFINEEXPR0  */
#line 658 "test.y"
                            { LL* temp = returnLL("#defineexpr0 "); (yyval.llPtr) = temp;}
#line 2571 "test.tab.c"
    break;

  case 116: /* DefineExpr1: DEFINEEXPR1  */
#line 659 "test.y"
                            { LL* temp = returnLL("#defineexpr1 "); (yyval.llPtr) = temp;}
#line 2577 "test.tab.c"
    break;

  case 117: /* DefineExpr: DEFINEEXPR  */
#line 661 "test.y"
                                { LL* temp = returnLL("#defineexpr "); (yyval.llPtr) = temp;}
#line 2583 "test.tab.c"
    break;

  case 118: /* DefineStmt0: DEFINESTMT0  */
#line 662 "test.y"
                                { LL* temp = returnLL("#definestmt0 "); (yyval.llPtr) = temp;}
#line 2589 "test.tab.c"
    break;

  case 119: /* DefineStmt1: DEFINESTMT1  */
#line 663 "test.y"
                                { LL* temp = returnLL("#definestmt1 "); (yyval.llPtr) = temp;}
#line 2595 "test.tab.c"
    break;

  case 120: /* DefineStmt2: DEFINESTMT2  */
#line 664 "test.y"
                                { LL* temp = returnLL("#definestmt2 "); (yyval.llPtr) = temp;}
#line 2601 "test.tab.c"
    break;

  case 121: /* DefineStmt: DEFINESTMT  */
#line 665 "test.y"
                                { LL* temp = returnLL("#definestmt "); (yyval.llPtr) = temp;}
#line 2607 "test.tab.c"
    break;

  case 122: /* Identifier: ID  */
#line 667 "test.y"
                            { LL* temp = returnLL((yyvsp[0].id)); (yyval.llPtr) = temp;}
#line 2613 "test.tab.c"
    break;

  case 123: /* Number: NUM  */
#line 668 "test.y"
                            { LL* temp = returnLL((yyvsp[0].id)); (yyval.llPtr) = temp;}
#line 2619 "test.tab.c"
    break;


#line 2623 "test.tab.c"

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

#line 669 "test.y"


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
