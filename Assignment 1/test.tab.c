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

    int yylex(void);
    void yyerror(const char *);

#line 80 "test.tab.c"

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
    DEFINESTMT0 = 261,             /* DEFINESTMT0  */
    DEFINESTMT1 = 262,             /* DEFINESTMT1  */
    DEFINESTMT2 = 263,             /* DEFINESTMT2  */
    CLASS = 264,                   /* CLASS  */
    PUBLIC = 265,                  /* PUBLIC  */
    STATIC = 266,                  /* STATIC  */
    MAIN = 267,                    /* MAIN  */
    RETURN = 268,                  /* RETURN  */
    EXTENDS = 269,                 /* EXTENDS  */
    INT = 270,                     /* INT  */
    BOOLEAN = 271,                 /* BOOLEAN  */
    VOID = 272,                    /* VOID  */
    STRING = 273,                  /* STRING  */
    IF = 274,                      /* IF  */
    WHILE = 275,                   /* WHILE  */
    LENGTH = 276,                  /* LENGTH  */
    ELSE = 277,                    /* ELSE  */
    NEW = 278,                     /* NEW  */
    THIS = 279,                    /* THIS  */
    BTRUE = 280,                   /* BTRUE  */
    BFALSE = 281,                  /* BFALSE  */
    PRNTSTMT = 282,                /* PRNTSTMT  */
    OPAREN = 283,                  /* OPAREN  */
    CPAREN = 284,                  /* CPAREN  */
    OCURLY = 285,                  /* OCURLY  */
    CCURLY = 286,                  /* CCURLY  */
    OSQRE = 287,                   /* OSQRE  */
    CSQRE = 288,                   /* CSQRE  */
    SCOLON = 289,                  /* SCOLON  */
    LAND = 290,                    /* LAND  */
    LOR = 291,                     /* LOR  */
    NEQ = 292,                     /* NEQ  */
    LEQ = 293,                     /* LEQ  */
    EQ = 294,                      /* EQ  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MUL = 297,                     /* MUL  */
    DIV = 298,                     /* DIV  */
    EXCLAM = 299,                  /* EXCLAM  */
    COMMA = 300,                   /* COMMA  */
    DOT = 301,                     /* DOT  */
    ID = 302,                      /* ID  */
    NUM = 303                      /* NUM  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 10 "test.y"

    int num;
    char* id;

#line 180 "test.tab.c"

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
  YYSYMBOL_DEFINESTMT0 = 6,                /* DEFINESTMT0  */
  YYSYMBOL_DEFINESTMT1 = 7,                /* DEFINESTMT1  */
  YYSYMBOL_DEFINESTMT2 = 8,                /* DEFINESTMT2  */
  YYSYMBOL_CLASS = 9,                      /* CLASS  */
  YYSYMBOL_PUBLIC = 10,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 11,                    /* STATIC  */
  YYSYMBOL_MAIN = 12,                      /* MAIN  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_EXTENDS = 14,                   /* EXTENDS  */
  YYSYMBOL_INT = 15,                       /* INT  */
  YYSYMBOL_BOOLEAN = 16,                   /* BOOLEAN  */
  YYSYMBOL_VOID = 17,                      /* VOID  */
  YYSYMBOL_STRING = 18,                    /* STRING  */
  YYSYMBOL_IF = 19,                        /* IF  */
  YYSYMBOL_WHILE = 20,                     /* WHILE  */
  YYSYMBOL_LENGTH = 21,                    /* LENGTH  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_NEW = 23,                       /* NEW  */
  YYSYMBOL_THIS = 24,                      /* THIS  */
  YYSYMBOL_BTRUE = 25,                     /* BTRUE  */
  YYSYMBOL_BFALSE = 26,                    /* BFALSE  */
  YYSYMBOL_PRNTSTMT = 27,                  /* PRNTSTMT  */
  YYSYMBOL_OPAREN = 28,                    /* OPAREN  */
  YYSYMBOL_CPAREN = 29,                    /* CPAREN  */
  YYSYMBOL_OCURLY = 30,                    /* OCURLY  */
  YYSYMBOL_CCURLY = 31,                    /* CCURLY  */
  YYSYMBOL_OSQRE = 32,                     /* OSQRE  */
  YYSYMBOL_CSQRE = 33,                     /* CSQRE  */
  YYSYMBOL_SCOLON = 34,                    /* SCOLON  */
  YYSYMBOL_LAND = 35,                      /* LAND  */
  YYSYMBOL_LOR = 36,                       /* LOR  */
  YYSYMBOL_NEQ = 37,                       /* NEQ  */
  YYSYMBOL_LEQ = 38,                       /* LEQ  */
  YYSYMBOL_EQ = 39,                        /* EQ  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MUL = 42,                       /* MUL  */
  YYSYMBOL_DIV = 43,                       /* DIV  */
  YYSYMBOL_EXCLAM = 44,                    /* EXCLAM  */
  YYSYMBOL_COMMA = 45,                     /* COMMA  */
  YYSYMBOL_DOT = 46,                       /* DOT  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_NUM = 48,                       /* NUM  */
  YYSYMBOL_YYACCEPT = 49,                  /* $accept  */
  YYSYMBOL_goal = 50,                      /* goal  */
  YYSYMBOL_MacroDefinitionMultiple = 51,   /* MacroDefinitionMultiple  */
  YYSYMBOL_MacroDefinition = 52,           /* MacroDefinition  */
  YYSYMBOL_MacroDefExpression = 53,        /* MacroDefExpression  */
  YYSYMBOL_MacroDefStatement = 54,         /* MacroDefStatement  */
  YYSYMBOL_MainPart = 55,                  /* MainPart  */
  YYSYMBOL_NextPart = 56,                  /* NextPart  */
  YYSYMBOL_TypeDeclaration = 57,           /* TypeDeclaration  */
  YYSYMBOL_IdentifierDeclarations = 58,    /* IdentifierDeclarations  */
  YYSYMBOL_IdentifierDeclarationsFinal = 59, /* IdentifierDeclarationsFinal  */
  YYSYMBOL_MethodDeclarationMultiple = 60, /* MethodDeclarationMultiple  */
  YYSYMBOL_MethodDeclaration = 61,         /* MethodDeclaration  */
  YYSYMBOL_Parameters = 62,                /* Parameters  */
  YYSYMBOL_ParametersFinal = 63,           /* ParametersFinal  */
  YYSYMBOL_MainClass = 64,                 /* MainClass  */
  YYSYMBOL_Type = 65,                      /* Type  */
  YYSYMBOL_StatementsList = 66,            /* StatementsList  */
  YYSYMBOL_Statement = 67,                 /* Statement  */
  YYSYMBOL_ExpressionList = 68,            /* ExpressionList  */
  YYSYMBOL_Expression = 69,                /* Expression  */
  YYSYMBOL_PrimaryExpression = 70,         /* PrimaryExpression  */
  YYSYMBOL_Class = 71,                     /* Class  */
  YYSYMBOL_OCurly = 72,                    /* OCurly  */
  YYSYMBOL_CCurly = 73,                    /* CCurly  */
  YYSYMBOL_Public = 74,                    /* Public  */
  YYSYMBOL_Static = 75,                    /* Static  */
  YYSYMBOL_Void = 76,                      /* Void  */
  YYSYMBOL_Main = 77,                      /* Main  */
  YYSYMBOL_OParen = 78,                    /* OParen  */
  YYSYMBOL_CParen = 79,                    /* CParen  */
  YYSYMBOL_String = 80,                    /* String  */
  YYSYMBOL_OSqre = 81,                     /* OSqre  */
  YYSYMBOL_CSqre = 82,                     /* CSqre  */
  YYSYMBOL_PrintStatement = 83,            /* PrintStatement  */
  YYSYMBOL_SColon = 84,                    /* SColon  */
  YYSYMBOL_Dot = 85,                       /* Dot  */
  YYSYMBOL_Length = 86,                    /* Length  */
  YYSYMBOL_This = 87,                      /* This  */
  YYSYMBOL_New = 88,                       /* New  */
  YYSYMBOL_Int = 89,                       /* Int  */
  YYSYMBOL_Boolean = 90,                   /* Boolean  */
  YYSYMBOL_Exclam = 91,                    /* Exclam  */
  YYSYMBOL_Return = 92,                    /* Return  */
  YYSYMBOL_Extends = 93,                   /* Extends  */
  YYSYMBOL_Eq = 94,                        /* Eq  */
  YYSYMBOL_If = 95,                        /* If  */
  YYSYMBOL_While = 96,                     /* While  */
  YYSYMBOL_Else = 97,                      /* Else  */
  YYSYMBOL_Comma = 98,                     /* Comma  */
  YYSYMBOL_Land = 99,                      /* Land  */
  YYSYMBOL_Lor = 100,                      /* Lor  */
  YYSYMBOL_Neq = 101,                      /* Neq  */
  YYSYMBOL_Leq = 102,                      /* Leq  */
  YYSYMBOL_Plus = 103,                     /* Plus  */
  YYSYMBOL_Minus = 104,                    /* Minus  */
  YYSYMBOL_Mul = 105,                      /* Mul  */
  YYSYMBOL_Div = 106,                      /* Div  */
  YYSYMBOL_Btrue = 107,                    /* Btrue  */
  YYSYMBOL_Bfalse = 108,                   /* Bfalse  */
  YYSYMBOL_Identifier = 109,               /* Identifier  */
  YYSYMBOL_Number = 110                    /* Number  */
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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   377

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   303


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
      45,    46,    47,    48
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    38,    38,    39,    42,    43,    46,    47,    50,    51,
      52,    55,    56,    57,    60,    63,    64,    67,    68,    71,
      72,    75,    78,    79,    82,    87,    94,    95,    98,   101,
     108,   109,   110,   111,   114,   115,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   129,   130,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   200,
     201
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
  "DEFINEEXPR1", "DEFINEEXPR2", "DEFINESTMT0", "DEFINESTMT1",
  "DEFINESTMT2", "CLASS", "PUBLIC", "STATIC", "MAIN", "RETURN", "EXTENDS",
  "INT", "BOOLEAN", "VOID", "STRING", "IF", "WHILE", "LENGTH", "ELSE",
  "NEW", "THIS", "BTRUE", "BFALSE", "PRNTSTMT", "OPAREN", "CPAREN",
  "OCURLY", "CCURLY", "OSQRE", "CSQRE", "SCOLON", "LAND", "LOR", "NEQ",
  "LEQ", "EQ", "PLUS", "MINUS", "MUL", "DIV", "EXCLAM", "COMMA", "DOT",
  "ID", "NUM", "$accept", "goal", "MacroDefinitionMultiple",
  "MacroDefinition", "MacroDefExpression", "MacroDefStatement", "MainPart",
  "NextPart", "TypeDeclaration", "IdentifierDeclarations",
  "IdentifierDeclarationsFinal", "MethodDeclarationMultiple",
  "MethodDeclaration", "Parameters", "ParametersFinal", "MainClass",
  "Type", "StatementsList", "Statement", "ExpressionList", "Expression",
  "PrimaryExpression", "Class", "OCurly", "CCurly", "Public", "Static",
  "Void", "Main", "OParen", "CParen", "String", "OSqre", "CSqre",
  "PrintStatement", "SColon", "Dot", "Length", "This", "New", "Int",
  "Boolean", "Exclam", "Return", "Extends", "Eq", "If", "While", "Else",
  "Comma", "Land", "Lor", "Neq", "Leq", "Plus", "Minus", "Mul", "Div",
  "Btrue", "Bfalse", "Identifier", "Number", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-173)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     202,   -38,   -38,   -38,   -38,   -38,   -38,  -173,    15,     4,
     346,  -173,  -173,  -173,     4,   -38,  -173,   -10,   -10,   -10,
     -10,   -10,   -10,  -173,  -173,  -173,  -173,     4,   -38,    -6,
    -173,    21,   -38,   -38,    21,   -38,   -38,  -173,    16,  -173,
      35,  -173,   -10,    21,     7,    -6,    21,     7,  -173,  -173,
     -38,  -173,    52,   277,   -10,  -173,   -38,   108,    -6,   -38,
      10,    -6,  -173,    49,  -173,  -173,  -173,  -173,  -173,  -173,
      21,   297,   277,  -173,    -4,   277,  -173,  -173,   -10,  -173,
     277,    21,  -173,  -173,  -173,    41,   108,   108,   -10,   -10,
     -10,    37,   108,    21,  -173,  -173,  -173,    13,   -38,    45,
    -173,  -173,  -173,  -173,    66,  -173,  -173,  -173,  -173,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,   277,   -11,   277,   277,
     277,   277,   277,   277,   277,   277,    21,    45,   -10,  -173,
     244,    21,   -10,  -173,  -173,  -173,    41,   277,   277,   277,
    -173,   244,   277,   277,    41,    -6,  -173,  -173,    10,    47,
      46,    10,  -173,   -10,    46,  -173,  -173,  -173,   -10,  -173,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,   277,    21,
      21,     7,  -173,  -173,   277,  -173,    21,    21,    21,    21,
      47,    46,    47,  -173,   108,   -38,  -173,  -173,  -173,  -173,
      13,    69,  -173,   244,    46,  -173,  -173,   277,    21,    47,
     108,   108,    47,  -173,    50,  -173,    41,   -10,  -173,  -173,
      45,    21,  -173,  -173,  -173,  -173,  -173,    71,  -173,  -173,
     277,  -173,    55,    46,  -173,  -173,   108,    47,    21,     7,
     -38,    -6,   -38,  -173,  -173,    -6,    10,  -173,  -173,    21,
    -173,  -173,   229,    -6,   229,    75,    37,    67,    75,  -173,
     277,   -10,   277,    47,   277,    47,    41,    21,    41,  -173,
      47,  -173,    41,    41,  -173
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    71,     0,     0,
       5,     7,     6,     3,    15,     0,   109,     0,     0,     0,
       0,     0,     0,     1,     2,     4,    14,    15,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    16,     0,    72,
       0,    79,     0,     0,     0,     0,     0,     0,    93,    19,
       0,    74,     0,     0,     0,    98,     0,    34,     0,     0,
      22,     0,    75,     0,    88,    87,   107,   108,    91,   110,
       0,    57,     0,    66,     0,     0,    63,    64,    65,    62,
       0,     0,    95,    96,    83,     0,    34,    34,     0,     0,
       0,     0,    34,     0,    89,    90,    20,     0,     0,    32,
      31,    33,    19,    76,     0,     8,    81,    99,   100,   101,
     102,   103,   104,   105,   106,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,     0,     0,    73,    11,    35,     0,     0,     0,     0,
      94,     0,     0,     0,     0,     0,    23,    17,     0,     0,
       0,    22,    77,     0,     0,    65,    86,    56,     0,    47,
      48,    49,    50,    51,    52,    53,    54,    70,     0,     0,
       0,    45,    60,     9,     0,    36,     0,     0,     0,     0,
       0,     0,     0,    12,    34,     0,    84,    21,    82,    30,
       0,     0,    55,     0,     0,    68,    61,     0,     0,     0,
       0,     0,     0,    44,     0,    38,     0,     0,    18,    80,
       0,     0,    58,    67,    46,    10,    37,    40,    42,    43,
       0,    13,     0,     0,    59,    97,     0,     0,     0,    26,
       0,     0,     0,    41,    39,     0,     0,    28,    19,     0,
      19,    27,    34,     0,    34,     0,    33,     0,     0,    92,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
       0,    24,     0,     0,    29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -173,  -173,    85,  -173,  -173,  -173,    90,    74,  -173,   -95,
    -173,   -48,  -173,  -132,  -173,  -173,  -140,   -70,  -172,  -129,
      54,   159,     6,    22,   -44,    65,  -173,  -173,  -173,    20,
     120,  -173,   -52,  -133,  -141,   -23,  -173,  -173,  -173,  -173,
      38,  -173,  -173,  -135,  -173,   -79,  -173,  -173,  -173,   -41,
    -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,  -173,
      -1,  -173
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,    26,    27,    60,
      96,    97,   146,   228,   229,    14,    98,    85,    86,   170,
     171,    71,    15,    87,   134,   148,    63,   104,   153,    72,
      42,   210,   142,   189,    88,   187,   117,   157,    73,    74,
      99,   100,    75,   250,    50,   143,    89,    90,   226,    56,
     118,   119,   120,   121,   122,   123,   124,   125,    76,    77,
      78,    79
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,    18,    19,    20,    21,    22,    59,   151,   185,    16,
     156,    94,   179,     7,    29,    23,   135,   136,    30,   116,
      28,   192,   144,    51,    39,    94,    95,    38,   217,   218,
      48,    43,    44,    28,    46,    47,    16,    31,    32,    33,
      34,    35,    36,    16,   133,    51,    39,   150,   204,    61,
      41,    40,    55,   147,   233,    81,    91,    16,    93,   101,
      49,   213,    53,    62,   211,    30,   103,    57,   214,   106,
      94,    95,   133,   128,    80,   168,   140,   106,   152,   188,
      92,   186,   230,   102,    41,    91,    91,   209,   249,   140,
     232,    91,   175,   225,    84,    25,   230,   149,   130,    24,
     183,    37,    16,   190,   241,    52,   251,    70,   137,   138,
     139,   141,   127,   252,   206,   155,   158,   155,   155,   155,
     155,   155,   155,   155,   155,   220,   126,    82,    83,   129,
     197,     0,     0,     0,   131,    84,     0,     0,    39,     0,
       0,     0,     0,   242,     0,   244,   208,   101,   169,     0,
     101,     0,   174,     0,    45,    16,     0,   203,   223,   205,
       0,     0,   221,    54,     0,     0,    58,   184,     0,     0,
       0,     0,   245,   191,   248,     0,   216,     0,   193,   219,
       0,     0,     0,    91,   207,     0,     0,     0,   236,     0,
     105,   176,   177,   178,     0,     0,   181,   182,     0,    91,
      91,   132,     0,     0,   234,     1,     2,     3,     4,     5,
       6,     7,   259,   145,   261,     0,     0,     0,   263,   264,
       0,   101,   194,     0,     0,    91,     0,   222,   198,   237,
     256,   239,   258,     0,     0,   101,     0,   262,     0,     0,
       0,   246,     0,   246,    94,    95,   167,     0,    82,    83,
     172,   173,     0,   238,     0,     0,    84,   240,     0,    39,
       0,   180,     0,     0,     0,   247,   141,    64,    65,    66,
      67,   254,    30,    41,   227,   154,    16,   159,   160,   161,
     162,   163,   164,   165,   166,     0,     0,     0,    68,   195,
     196,    16,    69,     0,     0,     0,   199,   200,   201,   202,
      64,    65,    66,    67,   253,    30,   255,     0,   257,     0,
       0,     0,     0,   212,     0,     0,     0,     0,   215,     0,
       0,    68,     0,     0,    16,    69,     0,     0,     0,   106,
       0,   224,   107,   108,   109,   110,     0,   111,   112,   113,
     114,     0,   231,   115,     0,     0,     0,     0,   235,     1,
       2,     3,     4,     5,     6,     0,     0,     0,     0,   243,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   260
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,     4,     5,     6,    47,   102,   148,    47,
      21,    15,   141,     9,    15,     0,    86,    87,    28,    71,
      14,   154,    92,    10,    30,    15,    16,    28,   200,   201,
      14,    32,    33,    27,    35,    36,    47,    17,    18,    19,
      20,    21,    22,    47,    31,    10,    30,    99,   181,    50,
      29,    29,    45,    97,   226,    56,    57,    47,    59,    60,
      38,   194,    42,    11,   193,    28,    17,    45,   197,    32,
      15,    16,    31,    74,    54,   127,    39,    32,    12,    33,
      58,    34,   222,    61,    29,    86,    87,    18,    13,    39,
     223,    92,   136,    22,    27,    10,   236,    98,    78,     9,
     144,    27,    47,   151,   236,    40,   247,    53,    88,    89,
      90,    91,    74,   248,   184,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   204,    72,    19,    20,    75,
     171,    -1,    -1,    -1,    80,    27,    -1,    -1,    30,    -1,
      -1,    -1,    -1,   238,    -1,   240,   190,   148,   128,    -1,
     151,    -1,   132,    -1,    34,    47,    -1,   180,   210,   182,
      -1,    -1,   206,    43,    -1,    -1,    46,   145,    -1,    -1,
      -1,    -1,   242,   153,   244,    -1,   199,    -1,   158,   202,
      -1,    -1,    -1,   184,   185,    -1,    -1,    -1,   229,    -1,
      70,   137,   138,   139,    -1,    -1,   142,   143,    -1,   200,
     201,    81,    -1,    -1,   227,     3,     4,     5,     6,     7,
       8,     9,   256,    93,   258,    -1,    -1,    -1,   262,   263,
      -1,   222,   168,    -1,    -1,   226,    -1,   207,   174,   230,
     253,   232,   255,    -1,    -1,   236,    -1,   260,    -1,    -1,
      -1,   242,    -1,   244,    15,    16,   126,    -1,    19,    20,
     130,   131,    -1,   231,    -1,    -1,    27,   235,    -1,    30,
      -1,   141,    -1,    -1,    -1,   243,   246,    23,    24,    25,
      26,   251,    28,    29,   220,   116,    47,   118,   119,   120,
     121,   122,   123,   124,   125,    -1,    -1,    -1,    44,   169,
     170,    47,    48,    -1,    -1,    -1,   176,   177,   178,   179,
      23,    24,    25,    26,   250,    28,   252,    -1,   254,    -1,
      -1,    -1,    -1,   193,    -1,    -1,    -1,    -1,   198,    -1,
      -1,    44,    -1,    -1,    47,    48,    -1,    -1,    -1,    32,
      -1,   211,    35,    36,    37,    38,    -1,    40,    41,    42,
      43,    -1,   222,    46,    -1,    -1,    -1,    -1,   228,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,   239,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   257
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,     9,    50,    51,
      52,    53,    54,    55,    64,    71,    47,   109,   109,   109,
     109,   109,   109,     0,    55,    51,    56,    57,    71,   109,
      28,    78,    78,    78,    78,    78,    78,    56,   109,    30,
      72,    29,    79,   109,   109,    79,   109,   109,    14,    72,
      93,    10,    74,    78,    79,    45,    98,    72,    79,    98,
      58,   109,    11,    75,    23,    24,    25,    26,    44,    48,
      69,    70,    78,    87,    88,    91,   107,   108,   109,   110,
      78,   109,    19,    20,    27,    66,    67,    72,    83,    95,
      96,   109,    72,   109,    15,    16,    59,    60,    65,    89,
      90,   109,    72,    17,    76,    79,    32,    35,    36,    37,
      38,    40,    41,    42,    43,    46,    81,    85,    99,   100,
     101,   102,   103,   104,   105,   106,    69,    89,   109,    69,
      78,    69,    79,    31,    73,    66,    66,    78,    78,    78,
      39,    78,    81,    94,    66,    79,    61,    73,    74,   109,
      81,    58,    12,    77,    70,   109,    21,    86,   109,    70,
      70,    70,    70,    70,    70,    70,    70,    79,    81,    78,
      68,    69,    79,    79,    78,    73,    69,    69,    69,    68,
      79,    69,    69,    73,    72,    65,    34,    84,    33,    82,
      60,    78,    82,    78,    69,    79,    79,    98,    69,    79,
      79,    79,    79,    84,    82,    84,    66,   109,    73,    18,
      80,    68,    79,    82,    68,    79,    84,    67,    67,    84,
      94,    73,    78,    81,    79,    22,    97,    69,    62,    63,
      65,    79,    82,    67,    84,    79,    98,   109,    72,   109,
      72,    62,    58,    79,    58,    66,   109,    72,    66,    13,
      92,    83,    92,    69,    78,    69,    84,    69,    84,    73,
      79,    73,    84,    73,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    59,    60,    60,    61,    61,    62,    62,    63,    64,
      65,    65,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     2,     1,     1,     1,     7,     8,
      10,     7,     8,    10,     2,     0,     2,     6,     8,     0,
       2,     3,     0,     2,    13,    12,     1,     3,     2,    21,
       3,     1,     1,     1,     0,     2,     3,     5,     4,     7,
       5,     7,     5,     5,     4,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     3,     1,     5,     6,
       3,     4,     1,     1,     1,     1,     1,     5,     4,     2,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
  case 71: /* Class: CLASS  */
#line 161 "test.y"
             {printf("class ");}
#line 1474 "test.tab.c"
    break;

  case 72: /* OCurly: OCURLY  */
#line 162 "test.y"
               {printf(" {\n");}
#line 1480 "test.tab.c"
    break;

  case 73: /* CCurly: CCURLY  */
#line 163 "test.y"
               {printf("\n}\n");}
#line 1486 "test.tab.c"
    break;

  case 74: /* Public: PUBLIC  */
#line 164 "test.y"
               {printf("public ");}
#line 1492 "test.tab.c"
    break;

  case 75: /* Static: STATIC  */
#line 165 "test.y"
               {printf("static ");}
#line 1498 "test.tab.c"
    break;

  case 76: /* Void: VOID  */
#line 166 "test.y"
           {printf("void ");}
#line 1504 "test.tab.c"
    break;

  case 77: /* Main: MAIN  */
#line 167 "test.y"
           {printf("main ");}
#line 1510 "test.tab.c"
    break;

  case 78: /* OParen: OPAREN  */
#line 168 "test.y"
               {printf(" ( ");}
#line 1516 "test.tab.c"
    break;

  case 79: /* CParen: CPAREN  */
#line 169 "test.y"
               {printf(" ) ");}
#line 1522 "test.tab.c"
    break;

  case 80: /* String: STRING  */
#line 170 "test.y"
               {printf(" String ");}
#line 1528 "test.tab.c"
    break;

  case 81: /* OSqre: OSQRE  */
#line 171 "test.y"
             {printf(" [ ");}
#line 1534 "test.tab.c"
    break;

  case 82: /* CSqre: CSQRE  */
#line 172 "test.y"
             {printf(" ] ");}
#line 1540 "test.tab.c"
    break;

  case 83: /* PrintStatement: PRNTSTMT  */
#line 173 "test.y"
                         {printf(" System.out.println ");}
#line 1546 "test.tab.c"
    break;

  case 84: /* SColon: SCOLON  */
#line 174 "test.y"
               {printf(" ;\n");}
#line 1552 "test.tab.c"
    break;

  case 85: /* Dot: DOT  */
#line 175 "test.y"
         {printf(" . ");}
#line 1558 "test.tab.c"
    break;

  case 86: /* Length: LENGTH  */
#line 176 "test.y"
               {printf(" length ");}
#line 1564 "test.tab.c"
    break;

  case 87: /* This: THIS  */
#line 177 "test.y"
           {printf(" this ");}
#line 1570 "test.tab.c"
    break;

  case 88: /* New: NEW  */
#line 178 "test.y"
         {printf(" new ");}
#line 1576 "test.tab.c"
    break;

  case 89: /* Int: INT  */
#line 179 "test.y"
         {printf(" int ");}
#line 1582 "test.tab.c"
    break;

  case 90: /* Boolean: BOOLEAN  */
#line 180 "test.y"
                 {printf(" boolean ");}
#line 1588 "test.tab.c"
    break;

  case 91: /* Exclam: EXCLAM  */
#line 181 "test.y"
               {printf(" ! ");}
#line 1594 "test.tab.c"
    break;

  case 92: /* Return: RETURN  */
#line 182 "test.y"
               {printf(" return ");}
#line 1600 "test.tab.c"
    break;

  case 93: /* Extends: EXTENDS  */
#line 183 "test.y"
                 {printf(" extends ");}
#line 1606 "test.tab.c"
    break;

  case 94: /* Eq: EQ  */
#line 184 "test.y"
       {printf(" = ");}
#line 1612 "test.tab.c"
    break;

  case 95: /* If: IF  */
#line 185 "test.y"
       {printf(" if ");}
#line 1618 "test.tab.c"
    break;

  case 96: /* While: WHILE  */
#line 186 "test.y"
             {printf(" while ");}
#line 1624 "test.tab.c"
    break;

  case 97: /* Else: ELSE  */
#line 187 "test.y"
           {printf(" else ");}
#line 1630 "test.tab.c"
    break;

  case 98: /* Comma: COMMA  */
#line 188 "test.y"
             {printf(" , ");}
#line 1636 "test.tab.c"
    break;

  case 99: /* Land: LAND  */
#line 189 "test.y"
           {printf(" && ");}
#line 1642 "test.tab.c"
    break;

  case 100: /* Lor: LOR  */
#line 190 "test.y"
         {printf(" || ");}
#line 1648 "test.tab.c"
    break;

  case 101: /* Neq: NEQ  */
#line 191 "test.y"
         {printf(" != ");}
#line 1654 "test.tab.c"
    break;

  case 102: /* Leq: LEQ  */
#line 192 "test.y"
         {printf(" <= ");}
#line 1660 "test.tab.c"
    break;

  case 103: /* Plus: PLUS  */
#line 193 "test.y"
           {printf(" + ");}
#line 1666 "test.tab.c"
    break;

  case 104: /* Minus: MINUS  */
#line 194 "test.y"
             {printf(" - ");}
#line 1672 "test.tab.c"
    break;

  case 105: /* Mul: MUL  */
#line 195 "test.y"
         {printf(" * ");}
#line 1678 "test.tab.c"
    break;

  case 106: /* Div: DIV  */
#line 196 "test.y"
         {printf(" / ");}
#line 1684 "test.tab.c"
    break;

  case 107: /* Btrue: BTRUE  */
#line 197 "test.y"
             {printf(" true ");}
#line 1690 "test.tab.c"
    break;

  case 108: /* Bfalse: BFALSE  */
#line 198 "test.y"
               {printf(" false ");}
#line 1696 "test.tab.c"
    break;

  case 109: /* Identifier: ID  */
#line 200 "test.y"
               {printf(" %s ", (yyvsp[0].id));}
#line 1702 "test.tab.c"
    break;

  case 110: /* Number: NUM  */
#line 201 "test.y"
            {printf(" %d ", (yyvsp[0].num));}
#line 1708 "test.tab.c"
    break;


#line 1712 "test.tab.c"

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

#line 202 "test.y"


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
