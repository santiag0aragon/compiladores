/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_Void = 258,
     T_Bool = 259,
     T_Int = 260,
     T_Double = 261,
     T_String = 262,
     T_Class = 263,
     T_LessEqual = 264,
     T_GreaterEqual = 265,
     T_Equal = 266,
     T_NotEqual = 267,
     T_Dims = 268,
     T_Increment = 269,
     T_Decrement = 270,
     T_And = 271,
     T_Or = 272,
     T_Null = 273,
     T_Extends = 274,
     T_This = 275,
     T_Interface = 276,
     T_Implements = 277,
     T_While = 278,
     T_For = 279,
     T_If = 280,
     T_Else = 281,
     T_Return = 282,
     T_Break = 283,
     T_Switch = 284,
     T_Case = 285,
     T_Default = 286,
     T_New = 287,
     T_NewArray = 288,
     T_Print = 289,
     T_ReadInteger = 290,
     T_ReadLine = 291,
     T_Identifier = 292,
     T_StringConstant = 293,
     T_IntConstant = 294,
     T_DoubleConstant = 295,
     T_BoolConstant = 296,
     LOWER_THAN_ELSE = 297,
     UMINUS = 298
   };
#endif
/* Tokens.  */
#define T_Void 258
#define T_Bool 259
#define T_Int 260
#define T_Double 261
#define T_String 262
#define T_Class 263
#define T_LessEqual 264
#define T_GreaterEqual 265
#define T_Equal 266
#define T_NotEqual 267
#define T_Dims 268
#define T_Increment 269
#define T_Decrement 270
#define T_And 271
#define T_Or 272
#define T_Null 273
#define T_Extends 274
#define T_This 275
#define T_Interface 276
#define T_Implements 277
#define T_While 278
#define T_For 279
#define T_If 280
#define T_Else 281
#define T_Return 282
#define T_Break 283
#define T_Switch 284
#define T_Case 285
#define T_Default 286
#define T_New 287
#define T_NewArray 288
#define T_Print 289
#define T_ReadInteger 290
#define T_ReadLine 291
#define T_Identifier 292
#define T_StringConstant 293
#define T_IntConstant 294
#define T_DoubleConstant 295
#define T_BoolConstant 296
#define LOWER_THAN_ELSE 297
#define UMINUS 298




/* Copy the first part of user declarations.  */
#line 11 "parser.y"


/* Just like lex, the text within this first region delimited by %{ and %}
 * is assumed to be C/C++ code and will be copied verbatim to the y.tab.c
 * file ahead of the definitions of the yyparse() function. Add other header
 * file inclusions or C++ variable declarations/prototypes that are needed
 * by your code here.
 */
#include "scanner.h" // for yylex
#include "parser.h"
#include "errors.h"

void yyerror(char *msg); // standard error-handling routine



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 41 "parser.y"
{
    Program 				*program;
    int 					integerConstant;
    bool 					boolConstant;
    const char 				*stringConstant;
    double 					doubleConstant;
    char 					identifier[MaxIdentLen+1]; // +1 for terminating null
    Decl 					*decl;
    VarDecl 				*vardecl;
    FnDecl 					*fndecl;
    ClassDecl 				*classdecl;
    InterfaceDecl 			*interfacedecl;  
    Type 					*simpletype;
    NamedType 				*namedtype;

    List<NamedType*> 		*implements;
    List<Decl*> 			*declList;
    List<VarDecl*> 			*vardecls;
    StmtBlock 				*stmtblock;
    Stmt 					*stmt;
    IfStmt 					*ifstmt;
    ForStmt 				*forstmt;
    WhileStmt 				*whilestmt;
    ReturnStmt 				*rtnstmt;	
    BreakStmt 				*brkstmt;
			//SwitchStmt 				*switchstmt;
			//    CaseStmt 				*casestmt;
			//    DefaultStmt 			*defaultstmt;
    PrintStmt 				*pntstmt;
    List<Stmt*> 			*stmts;
			//    List<CaseStmt*> 		*casestmts;
    Expr 					*expr;
    Expr 					*optionalexpr;
    List<Expr*> 			*exprs;
    Call 					*call;
    IntConstant 			*intconst;
    DoubleConstant 			*doubleconst;
    BoolConstant 			*boolconst;
    StringConstant 			*stringconst;
    NullConstant 			*nullconst;
    ArithmeticExpr 			*arithmeticexpr;
    RelationalExpr 			*relationalexpr;
    EqualityExpr   			*equalityexpr;
    LogicalExpr    			*logicalexpr;
    AssignExpr     			*assignexpr;
			//    PostfixExpr    			*postfixexpr;
    LValue 					*lvalue;
    FieldAccess 			*fieldaccess;
    ArrayAccess 			*arrayaccess;
}
/* Line 193 of yacc.c.  */
#line 249 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 274 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
    YYLTYPE yyls;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   706

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  229

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,     2,     2,    50,     2,     2,
      56,    57,    48,    46,    58,    47,    54,    49,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,    55,
      44,    43,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    53,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    59,     2,    60,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    18,
      22,    24,    26,    28,    30,    32,    35,    37,    44,    51,
      56,    59,    60,    68,    75,    81,    87,    92,    99,   106,
     112,   115,   118,   122,   124,   127,   129,   131,   133,   134,
     140,   145,   148,   150,   157,   164,   169,   173,   177,   180,
     183,   185,   188,   190,   192,   194,   196,   198,   200,   202,
     204,   207,   213,   221,   227,   237,   241,   244,   250,   252,
     254,   256,   258,   260,   264,   266,   268,   270,   272,   276,
     280,   285,   292,   296,   300,   304,   308,   312,   316,   319,
     323,   327,   331,   335,   339,   343,   347,   351,   354,   358,
     360,   361,   363,   365,   369,   374,   379,   386,   388,   389,
     391,   393,   395,   397,   399,   401,   403,   405,   407
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    65,    -1,    65,    66,    -1,    66,    -1,
      67,    -1,    70,    -1,    72,    -1,    78,    -1,    68,    37,
      55,    -1,     5,    -1,     6,    -1,     4,    -1,     7,    -1,
      37,    -1,    68,    13,    -1,    37,    -1,    68,    37,    56,
      71,    57,    81,    -1,     3,    37,    56,    71,    57,    81,
      -1,    71,    58,    68,    37,    -1,    68,    37,    -1,    -1,
       8,    37,    73,    74,    59,    76,    60,    -1,     8,    37,
      73,    74,    59,    60,    -1,     8,    37,    74,    59,    60,
      -1,     8,    37,    73,    59,    60,    -1,     8,    37,    59,
      60,    -1,     8,    37,    74,    59,    76,    60,    -1,     8,
      37,    73,    59,    76,    60,    -1,     8,    37,    59,    76,
      60,    -1,    19,    37,    -1,    22,    75,    -1,    75,    58,
      69,    -1,    69,    -1,    76,    77,    -1,    77,    -1,    67,
      -1,    70,    -1,    -1,    21,    37,    59,    79,    60,    -1,
      21,    37,    59,    60,    -1,    79,    80,    -1,    80,    -1,
      68,    37,    56,    71,    57,    55,    -1,     3,    37,    56,
      71,    57,    55,    -1,    59,    82,    83,    60,    -1,    59,
      82,    60,    -1,    59,    83,    60,    -1,    59,    60,    -1,
      82,    67,    -1,    67,    -1,    83,    84,    -1,    84,    -1,
      85,    -1,    86,    -1,    87,    -1,    89,    -1,    88,    -1,
      90,    -1,    81,    -1,    98,    55,    -1,    25,    56,    91,
      57,    84,    -1,    25,    56,    91,    57,    84,    26,    84,
      -1,    23,    56,    91,    57,    84,    -1,    24,    56,    98,
      55,    91,    55,    98,    57,    84,    -1,    27,    98,    55,
      -1,    28,    55,    -1,    34,    56,    97,    57,    55,    -1,
      92,    -1,   102,    -1,    99,    -1,    20,    -1,   100,    -1,
      56,    91,    57,    -1,    93,    -1,    94,    -1,    95,    -1,
      96,    -1,    35,    56,    57,    -1,    36,    56,    57,    -1,
      32,    56,    37,    57,    -1,    33,    56,    91,    58,    68,
      57,    -1,    99,    43,    91,    -1,    91,    46,    91,    -1,
      91,    47,    91,    -1,    91,    48,    91,    -1,    91,    49,
      91,    -1,    91,    50,    91,    -1,    47,    91,    -1,    91,
      11,    91,    -1,    91,    12,    91,    -1,    91,    44,    91,
      -1,    91,    45,    91,    -1,    91,     9,    91,    -1,    91,
      10,    91,    -1,    91,    16,    91,    -1,    91,    17,    91,
      -1,    51,    91,    -1,    97,    58,    91,    -1,    91,    -1,
      -1,    91,    -1,    37,    -1,    91,    54,    37,    -1,    91,
      53,    91,    62,    -1,    37,    56,   101,    57,    -1,    91,
      54,    37,    56,   101,    57,    -1,    97,    -1,    -1,   103,
      -1,   104,    -1,   105,    -1,   106,    -1,   107,    -1,    39,
      -1,    40,    -1,    41,    -1,    38,    -1,    18,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   193,   193,   203,   204,   207,   208,   209,   210,   213,
     219,   220,   221,   222,   223,   224,   227,   231,   235,   242,
     246,   247,   250,   254,   259,   263,   267,   271,   275,   279,
     286,   295,   300,   302,   306,   307,   310,   311,   312,   315,
     319,   325,   329,   335,   339,   346,   350,   354,   358,   368,
     369,   372,   373,   376,   377,   378,   379,   380,   382,   383,
     384,   390,   392,   397,   401,   405,   408,   429,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   444,   445,
     446,   447,   453,   457,   458,   459,   460,   461,   462,   470,
     472,   476,   478,   480,   482,   486,   488,   490,   494,   495,
     498,   499,   503,   504,   505,   513,   515,   522,   523,   526,
     527,   528,   529,   530,   533,   536,   539,   542,   545
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_Void", "T_Bool", "T_Int", "T_Double",
  "T_String", "T_Class", "T_LessEqual", "T_GreaterEqual", "T_Equal",
  "T_NotEqual", "T_Dims", "T_Increment", "T_Decrement", "T_And", "T_Or",
  "T_Null", "T_Extends", "T_This", "T_Interface", "T_Implements",
  "T_While", "T_For", "T_If", "T_Else", "T_Return", "T_Break", "T_Switch",
  "T_Case", "T_Default", "T_New", "T_NewArray", "T_Print", "T_ReadInteger",
  "T_ReadLine", "T_Identifier", "T_StringConstant", "T_IntConstant",
  "T_DoubleConstant", "T_BoolConstant", "LOWER_THAN_ELSE", "'='", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "UMINUS", "'['", "'.'",
  "';'", "'('", "')'", "','", "'{'", "'}'", "':'", "']'", "$accept",
  "Program", "DeclList", "Decl", "VarDecl", "Type", "NamedType", "FnDecl",
  "Variables", "ClassDecl", "Extend", "Impl", "Implements", "Fields",
  "Field", "InterfaceDecl", "Prototypes", "Prototype", "StmtBlock",
  "VarDecls", "Stmts", "Stmt", "IfStmt", "WhileStmt", "ForStmt",
  "ReturnStmt", "BreakStmt", "PrintStmt", "Expr", "AssignExpr",
  "ArithmeticExpr", "EqualityExpr", "RelationalExpr", "LogicalExpr",
  "Exprs", "OptionalExpr", "LValue", "Call", "Actuals", "Constant",
  "IntConstant", "DoubleConstant", "BoolConstant", "StringConstant",
  "NullConstant", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,    61,    60,    62,    43,    45,    42,    47,
      37,    33,   298,    91,    46,    59,    40,    41,    44,   123,
     125,    58,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    65,    66,    66,    66,    66,    67,
      68,    68,    68,    68,    68,    68,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    74,    75,    75,    76,    76,    77,    77,    77,    78,
      78,    79,    79,    80,    80,    81,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      84,    85,    85,    86,    87,    88,    89,    90,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    93,    93,    93,    93,    93,    93,    94,
      94,    95,    95,    95,    95,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,   100,   100,   101,   101,   102,
     102,   102,   102,   102,   103,   104,   105,   106,   107
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     6,     6,     4,
       2,     0,     7,     6,     5,     5,     4,     6,     6,     5,
       2,     2,     3,     1,     2,     1,     1,     1,     0,     5,
       4,     2,     1,     6,     6,     4,     3,     3,     2,     2,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     5,     7,     5,     9,     3,     2,     5,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     3,     3,
       4,     6,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       0,     1,     1,     3,     4,     4,     6,     1,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,    10,    11,    13,     0,     0,    14,     0,
       2,     4,     5,     0,     6,     7,     8,     0,     0,     0,
       1,     3,    15,     0,    21,     0,     0,     0,     0,     0,
       0,     9,    21,     0,     0,    30,    16,    33,    31,    26,
      36,    37,     0,    35,     0,     0,     0,     0,    40,     0,
       0,    42,     0,    20,     0,     0,     0,    29,    34,    25,
       0,     0,    24,     0,     0,     0,    39,    41,     0,   100,
      18,     0,    32,    28,    23,     0,    27,    21,    21,    17,
     118,    71,     0,     0,     0,   100,     0,     0,     0,     0,
       0,     0,   102,   117,   114,   115,   116,     0,     0,     0,
      48,    50,     0,    59,   100,   100,    52,    53,    54,    55,
      57,    56,    58,   101,    68,    74,    75,    76,    77,     0,
      70,    72,    69,   109,   110,   111,   112,   113,    19,    22,
       0,     0,     0,   100,     0,   102,     0,    66,     0,     0,
       0,     0,     0,   108,    88,    97,     0,     0,    46,    49,
     100,    47,    51,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    60,     0,
       0,     0,     0,     0,     0,    65,     0,     0,    99,     0,
      78,    79,   107,     0,    73,    45,    93,    94,    89,    90,
      95,    96,    91,    92,    83,    84,    85,    86,    87,     0,
     103,    82,    44,    43,   100,     0,   100,    80,     0,     0,
       0,   105,   104,   108,    63,     0,    61,     0,    67,    98,
       0,   100,   100,    81,   106,     0,    62,   100,    64
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     9,    10,    11,    40,    13,    37,    41,    34,    15,
      28,    29,    38,    42,    43,    16,    50,    51,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   182,   119,   120,   121,   183,   122,
     123,   124,   125,   126,   127
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -104
static const yytype_int16 yypact[] =
{
     184,   -30,  -104,  -104,  -104,  -104,    -7,    -5,  -104,    22,
     184,  -104,  -104,    -8,  -104,  -104,  -104,   -28,    92,    25,
    -104,  -104,  -104,   -22,    13,    -2,    52,    53,   -19,    32,
      89,  -104,    13,    -1,   -15,  -104,  -104,  -104,    44,  -104,
    -104,  -104,   101,  -104,   125,    64,   136,    73,  -104,     0,
     141,  -104,    29,  -104,    68,    13,    52,  -104,  -104,  -104,
     149,   160,  -104,   165,    79,    80,  -104,  -104,    68,   210,
    -104,    51,  -104,  -104,  -104,   176,  -104,    13,    13,  -104,
    -104,  -104,    94,   102,   103,   650,   105,   118,   119,   120,
     121,   144,    26,  -104,  -104,  -104,  -104,   650,   650,   650,
    -104,  -104,    72,  -104,   258,   565,  -104,  -104,  -104,  -104,
    -104,  -104,  -104,   449,  -104,  -104,  -104,  -104,  -104,   148,
     114,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,  -104,
      41,    58,   650,   650,   650,   150,   152,  -104,   167,   650,
     650,   151,   153,   650,    67,    67,   360,   156,  -104,  -104,
     595,  -104,  -104,   650,   650,   650,   650,   650,   650,   650,
     650,   650,   650,   650,   650,   650,   650,   175,  -104,   650,
     163,   164,   374,   168,   423,  -104,   169,   310,   449,    76,
    -104,  -104,   166,   170,  -104,  -104,   528,   528,   506,   506,
     517,   495,   528,   528,   145,   145,    67,    67,    67,   291,
     173,   449,  -104,  -104,   625,   650,   625,  -104,    13,   177,
     650,  -104,  -104,   650,  -104,   437,   196,    -9,  -104,   449,
     174,   650,   625,  -104,  -104,   182,  -104,   625,  -104
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,  -104,   230,    14,   -24,   185,    15,   -16,  -104,
    -104,   224,  -104,   -23,    37,  -104,  -104,   203,   -27,  -104,
     154,  -103,  -104,  -104,  -104,  -104,  -104,  -104,   -88,  -104,
    -104,  -104,  -104,  -104,   115,   -84,  -104,  -104,    43,  -104,
    -104,  -104,  -104,  -104,  -104
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -15
static const yytype_int16 yytable[] =
{
      33,   136,   152,    26,    22,    22,    49,    17,    33,   144,
     145,   146,    22,    22,    12,    14,    52,     2,     3,     4,
       5,    60,    20,    63,    12,    14,    49,    70,    24,    23,
      18,    71,    19,    31,    32,    35,    53,    65,    75,   -14,
      44,    79,    54,    55,   172,   102,   174,   152,   223,   173,
       8,   177,   178,    33,    33,   178,     1,     2,     3,     4,
       5,   130,   131,   -14,    22,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,    58,
     102,   201,   143,   101,    30,    22,    68,    55,   128,    36,
       8,    46,    47,     2,     3,     4,     5,    58,   170,    55,
      58,   214,    56,   216,     1,     2,     3,     4,     5,   147,
      64,    25,    58,    39,    26,   171,    55,   215,   149,   226,
     166,   167,   219,    61,   228,   178,     8,    69,     1,     2,
       3,     4,     5,   209,   210,    77,    78,   225,     8,     1,
       2,     3,     4,     5,    47,     2,     3,     4,     5,    48,
     132,    27,     1,     2,     3,     4,     5,   169,   133,   134,
     137,    57,     8,     1,     2,     3,     4,     5,     1,     2,
       3,     4,     5,     8,   138,   139,   140,   141,     8,     1,
       2,     3,     4,     5,   217,    59,     8,     1,     2,     3,
       4,     5,     6,   163,   164,   165,    62,     8,   166,   167,
     142,    66,     8,   168,   176,     7,   143,   175,   180,    73,
     181,    31,   200,     8,     2,     3,     4,     5,   202,   203,
      74,     8,   222,   205,   210,    76,   207,   211,    80,   213,
      81,   224,   218,    82,    83,    84,   129,    85,    86,   227,
      21,    72,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    45,    67,     0,   179,   220,    97,   150,     0,
       0,    98,     2,     3,     4,     5,    99,     0,     0,    69,
     100,     0,     0,     0,     0,     0,    80,     0,    81,     0,
       0,    82,    83,    84,     0,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
     153,   154,   155,   156,     0,    97,     0,   157,   158,    98,
       0,     0,     0,     0,    99,     0,     0,    69,   148,   153,
     154,   155,   156,     0,     0,     0,   157,   158,     0,     0,
       0,     0,     0,     0,     0,   159,   160,   161,   162,   163,
     164,   165,     0,     0,   166,   167,     0,     0,     0,     0,
       0,     0,     0,   212,   159,   160,   161,   162,   163,   164,
     165,     0,     0,   166,   167,     0,     0,     0,   208,   153,
     154,   155,   156,     0,     0,     0,   157,   158,     0,     0,
       0,     0,     0,   153,   154,   155,   156,     0,     0,     0,
     157,   158,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   159,   160,   161,   162,   163,   164,
     165,     0,     0,   166,   167,     0,     0,   184,   159,   160,
     161,   162,   163,   164,   165,     0,     0,   166,   167,     0,
       0,   204,   153,   154,   155,   156,     0,     0,     0,   157,
     158,     0,     0,     0,     0,     0,   153,   154,   155,   156,
       0,     0,     0,   157,   158,     0,     0,     0,   153,   154,
     155,   156,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,   166,   167,     0,     0,
     206,   159,   160,   161,   162,   163,   164,   165,     0,     0,
     166,   167,   221,   159,   160,   161,   162,   163,   164,   165,
       0,     0,   166,   167,   153,   154,   155,   156,     0,     0,
       0,   157,     0,     0,     0,   153,   154,   -15,   -15,     0,
       0,     0,     0,     0,     0,     0,   153,   154,   155,   156,
       0,     0,     0,     0,     0,     0,     0,   -15,   -15,   159,
     160,   161,   162,   163,   164,   165,     0,     0,   166,   167,
     159,   160,   161,   162,   163,   164,   165,     0,     0,   166,
     167,   159,   160,   161,   162,   163,   164,   165,     0,     0,
     166,   167,   -15,   -15,   161,   162,   163,   164,   165,     0,
       0,   166,   167,    80,     0,    81,     0,     0,    82,    83,
      84,     0,    85,    86,     0,     0,     0,    87,    88,    89,
      90,    91,   135,    93,    94,    95,    96,     0,     0,     0,
       0,     0,    97,    80,     0,    81,    98,     0,    82,    83,
      84,    99,    85,    86,    69,   151,     0,    87,    88,    89,
      90,    91,   135,    93,    94,    95,    96,     0,     0,     0,
       0,     0,    97,    80,     0,    81,    98,     0,    82,    83,
      84,    99,    85,    86,    69,   185,     0,    87,    88,    89,
      90,    91,   135,    93,    94,    95,    96,     0,    80,     0,
      81,     0,    97,     0,     0,     0,    98,     0,     0,     0,
       0,    99,    87,    88,    69,    90,    91,   135,    93,    94,
      95,    96,     0,     0,     0,     0,     0,    97,     0,     0,
       0,    98,     0,     0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      24,    85,   105,    22,    13,    13,    30,    37,    32,    97,
      98,    99,    13,    13,     0,     0,    32,     4,     5,     6,
       7,    44,     0,    46,    10,    10,    50,    54,    56,    37,
      37,    55,    37,    55,    56,    37,    37,    37,    61,    13,
      59,    68,    57,    58,   132,    69,   134,   150,    57,   133,
      37,   139,   140,    77,    78,   143,     3,     4,     5,     6,
       7,    77,    78,    37,    13,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,    42,
     104,   169,    56,    69,    59,    13,    57,    58,    37,    37,
      37,    59,     3,     4,     5,     6,     7,    60,    57,    58,
      63,   204,    58,   206,     3,     4,     5,     6,     7,    37,
      37,    19,    75,    60,    22,    57,    58,   205,   104,   222,
      53,    54,   210,    59,   227,   213,    37,    59,     3,     4,
       5,     6,     7,    57,    58,    56,    56,   221,    37,     3,
       4,     5,     6,     7,     3,     4,     5,     6,     7,    60,
      56,    59,     3,     4,     5,     6,     7,    43,    56,    56,
      55,    60,    37,     3,     4,     5,     6,     7,     3,     4,
       5,     6,     7,    37,    56,    56,    56,    56,    37,     3,
       4,     5,     6,     7,   208,    60,    37,     3,     4,     5,
       6,     7,     8,    48,    49,    50,    60,    37,    53,    54,
      56,    60,    37,    55,    37,    21,    56,    55,    57,    60,
      57,    55,    37,    37,     4,     5,     6,     7,    55,    55,
      60,    37,    26,    55,    58,    60,    57,    57,    18,    56,
      20,    57,    55,    23,    24,    25,    60,    27,    28,    57,
      10,    56,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    28,    50,    -1,   140,   213,    47,   104,    -1,
      -1,    51,     4,     5,     6,     7,    56,    -1,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    18,    -1,    20,    -1,
      -1,    23,    24,    25,    -1,    27,    28,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       9,    10,    11,    12,    -1,    47,    -1,    16,    17,    51,
      -1,    -1,    -1,    -1,    56,    -1,    -1,    59,    60,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    62,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    -1,    58,     9,
      10,    11,    12,    -1,    -1,    -1,    16,    17,    -1,    -1,
      -1,    -1,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    -1,    53,    54,    -1,    -1,    57,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    54,    -1,
      -1,    57,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,    -1,    -1,    -1,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    17,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    54,    -1,    -1,
      57,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    54,    55,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53,    54,     9,    10,    11,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    54,
      44,    45,    46,    47,    48,    49,    50,    -1,    -1,    53,
      54,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    54,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    53,    54,    18,    -1,    20,    -1,    -1,    23,    24,
      25,    -1,    27,    28,    -1,    -1,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    18,    -1,    20,    51,    -1,    23,    24,
      25,    56,    27,    28,    59,    60,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    18,    -1,    20,    51,    -1,    23,    24,
      25,    56,    27,    28,    59,    60,    -1,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    -1,    18,    -1,
      20,    -1,    47,    -1,    -1,    -1,    51,    -1,    -1,    -1,
      -1,    56,    32,    33,    59,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,
      -1,    51,    -1,    -1,    -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    21,    37,    64,
      65,    66,    67,    68,    70,    72,    78,    37,    37,    37,
       0,    66,    13,    37,    56,    19,    22,    59,    73,    74,
      59,    55,    56,    68,    71,    37,    37,    69,    75,    60,
      67,    70,    76,    77,    59,    74,    59,     3,    60,    68,
      79,    80,    71,    37,    57,    58,    58,    60,    77,    60,
      76,    59,    60,    76,    37,    37,    60,    80,    57,    59,
      81,    68,    69,    60,    60,    76,    60,    56,    56,    81,
      18,    20,    23,    24,    25,    27,    28,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    47,    51,    56,
      60,    67,    68,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    98,
      99,   100,   102,   103,   104,   105,   106,   107,    37,    60,
      71,    71,    56,    56,    56,    37,    98,    55,    56,    56,
      56,    56,    56,    56,    91,    91,    91,    37,    60,    67,
      83,    60,    84,     9,    10,    11,    12,    16,    17,    44,
      45,    46,    47,    48,    49,    50,    53,    54,    55,    43,
      57,    57,    91,    98,    91,    55,    37,    91,    91,    97,
      57,    57,    97,   101,    57,    60,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      37,    91,    55,    55,    57,    55,    57,    57,    58,    57,
      58,    57,    62,    56,    84,    91,    84,    68,    55,    91,
     101,    55,    26,    57,    57,    98,    84,    57,    84
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;
/* Location data for the look-ahead symbol.  */
YYLTYPE yylloc;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;

  /* The location stack.  */
  YYLTYPE yylsa[YYINITDEPTH];
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;
  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[2];

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;
#if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 0;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);
	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);
	YYSTACK_RELOCATE (yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 193 "parser.y"
    { 
																		(yylsp[(1) - (1)]);
																		Program *program = new Program((yyvsp[(1) - (1)].declList));
																		// if no errors, advance to next phase
																	  if (ReportError::NumErrors() == 0){
																			program->Check();
																		}
                                    }
    break;

  case 3:
#line 203 "parser.y"
    { ((yyval.declList)=(yyvsp[(1) - (2)].declList)) -> Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 4:
#line 204 "parser.y"
    { ((yyval.declList) = new List<Decl*>)->Append((yyvsp[(1) - (1)].decl)); }
    break;

  case 5:
#line 207 "parser.y"
    {   }
    break;

  case 6:
#line 208 "parser.y"
    {   }
    break;

  case 7:
#line 209 "parser.y"
    {   }
    break;

  case 8:
#line 210 "parser.y"
    {   }
    break;

  case 9:
#line 214 "parser.y"
    { 
										(yyval.vardecl) = new VarDecl(new Identifier((yylsp[(2) - (3)]), (yyvsp[(2) - (3)].identifier)), (yyvsp[(1) - (3)].simpletype)); 
									}
    break;

  case 10:
#line 219 "parser.y"
    { (yyval.simpletype) = Type::intType; }
    break;

  case 11:
#line 220 "parser.y"
    { (yyval.simpletype) = Type::doubleType; }
    break;

  case 12:
#line 221 "parser.y"
    { (yyval.simpletype) = Type::boolType; }
    break;

  case 13:
#line 222 "parser.y"
    { (yyval.simpletype) = Type::stringType; }
    break;

  case 14:
#line 223 "parser.y"
    { (yyval.simpletype) = new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))); }
    break;

  case 15:
#line 224 "parser.y"
    { (yyval.simpletype) = new ArrayType((yylsp[(1) - (2)]), (yyvsp[(1) - (2)].simpletype)); }
    break;

  case 16:
#line 227 "parser.y"
    { (yyval.namedtype) = new NamedType(new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))); }
    break;

  case 17:
#line 232 "parser.y"
    { (yyval.fndecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)),(yyvsp[(1) - (6)].simpletype), (yyvsp[(4) - (6)].vardecls));
									  (yyval.fndecl) -> SetFunctionBody((yyvsp[(6) - (6)].stmtblock)); 
									}
    break;

  case 18:
#line 236 "parser.y"
    {
										(yyval.fndecl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), Type::voidType , (yyvsp[(4) - (6)].vardecls));
										(yyval.fndecl) -> SetFunctionBody((yyvsp[(6) - (6)].stmtblock));
									}
    break;

  case 19:
#line 243 "parser.y"
    {
										((yyval.vardecls) = (yyvsp[(1) - (4)].vardecls)) -> Append(new VarDecl(new Identifier((yylsp[(4) - (4)]), (yyvsp[(4) - (4)].identifier)),(yyvsp[(3) - (4)].simpletype)));
									}
    break;

  case 20:
#line 246 "parser.y"
    {((yyval.vardecls) = new List<VarDecl*>) -> Append(new VarDecl(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier)),(yyvsp[(1) - (2)].simpletype))); }
    break;

  case 21:
#line 247 "parser.y"
    { ((yyval.vardecls) = new List<VarDecl*>); }
    break;

  case 22:
#line 251 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (7)]), (yyvsp[(2) - (7)].identifier)), (yyvsp[(3) - (7)].namedtype), (yyvsp[(4) - (7)].implements), (yyvsp[(6) - (7)].declList));
									}
    break;

  case 23:
#line 255 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(3) - (6)].namedtype), (yyvsp[(4) - (6)].implements), new List<Decl*>);
								}
    break;

  case 24:
#line 260 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), NULL, (yyvsp[(3) - (5)].implements), new List<Decl*>);
									}
    break;

  case 25:
#line 264 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(3) - (5)].namedtype), new List<NamedType*>, new List<Decl*>);
									}
    break;

  case 26:
#line 268 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].identifier)), NULL, new List<NamedType*>, new List<Decl*>);
									}
    break;

  case 27:
#line 272 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), NULL, (yyvsp[(3) - (6)].implements), (yyvsp[(5) - (6)].declList));
									}
    break;

  case 28:
#line 276 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(3) - (6)].namedtype), new List<NamedType*>, (yyvsp[(5) - (6)].declList));
									}
    break;

  case 29:
#line 280 "parser.y"
    {
										(yyval.classdecl) = new ClassDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), NULL, new List<NamedType*>,  (yyvsp[(4) - (5)].declList));
									}
    break;

  case 30:
#line 287 "parser.y"
    { 
										(yyval.namedtype) = new NamedType(new Identifier((yylsp[(2) - (2)]), (yyvsp[(2) - (2)].identifier))); 
									}
    break;

  case 31:
#line 296 "parser.y"
    { (yyval.implements) = (yyvsp[(2) - (2)].implements); }
    break;

  case 32:
#line 301 "parser.y"
    { ((yyval.implements) = (yyvsp[(1) - (3)].implements)) -> Append((yyvsp[(3) - (3)].namedtype)); }
    break;

  case 33:
#line 302 "parser.y"
    { ((yyval.implements) = new List<NamedType*>)->Append((yyvsp[(1) - (1)].namedtype)); }
    break;

  case 34:
#line 306 "parser.y"
    { ((yyval.declList) = (yyvsp[(1) - (2)].declList))->Append((yyvsp[(2) - (2)].decl)); }
    break;

  case 35:
#line 307 "parser.y"
    { ((yyval.declList) = new List<Decl*>) -> Append((yyvsp[(1) - (1)].decl));  }
    break;

  case 36:
#line 310 "parser.y"
    { }
    break;

  case 37:
#line 311 "parser.y"
    { }
    break;

  case 38:
#line 312 "parser.y"
    { }
    break;

  case 39:
#line 316 "parser.y"
    { 
                                    	(yyval.interfacedecl) = new InterfaceDecl(new Identifier((yylsp[(2) - (5)]), (yyvsp[(2) - (5)].identifier)), (yyvsp[(4) - (5)].declList)); 
                                    }
    break;

  case 40:
#line 320 "parser.y"
    { 
                                    	(yyval.interfacedecl) = new InterfaceDecl(new Identifier((yylsp[(2) - (4)]), (yyvsp[(2) - (4)].identifier)), new List<Decl*>); 
                                    }
    break;

  case 41:
#line 326 "parser.y"
    { 
										((yyval.declList) = (yyvsp[(1) - (2)].declList)) -> Append((yyvsp[(2) - (2)].decl)); 
									}
    break;

  case 42:
#line 330 "parser.y"
    { 
           								((yyval.declList) = new List<Decl*>) -> Append((yyvsp[(1) - (1)].decl)); 
           							}
    break;

  case 43:
#line 336 "parser.y"
    { 
                                    	(yyval.decl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), (yyvsp[(1) - (6)].simpletype), (yyvsp[(4) - (6)].vardecls)); 
                                    }
    break;

  case 44:
#line 340 "parser.y"
    { 
                                    	(yyval.decl) = new FnDecl(new Identifier((yylsp[(2) - (6)]), (yyvsp[(2) - (6)].identifier)), Type::voidType, (yyvsp[(4) - (6)].vardecls)); 
                                    }
    break;

  case 45:
#line 347 "parser.y"
    { 
										(yyval.stmtblock) = new StmtBlock((yyvsp[(2) - (4)].vardecls), (yyvsp[(3) - (4)].stmts)); 
									}
    break;

  case 46:
#line 351 "parser.y"
    { 
           								(yyval.stmtblock) = new StmtBlock((yyvsp[(2) - (3)].vardecls), new List<Stmt*>); 
           							}
    break;

  case 47:
#line 354 "parser.y"
    { 
            							List<VarDecl*> *v = new List<VarDecl*>;
                                    	(yyval.stmtblock) = new StmtBlock(v, (yyvsp[(2) - (3)].stmts));  
                                    }
    break;

  case 48:
#line 358 "parser.y"
    { 
            							List<VarDecl*> *v = new List<VarDecl*>;
                                        List<Stmt*> *s = new List<Stmt*>;
                                        (yyval.stmtblock) = new StmtBlock(v, s);
                                    }
    break;

  case 49:
#line 368 "parser.y"
    { ((yyval.vardecls) = (yyvsp[(1) - (2)].vardecls)) -> Append((yyvsp[(2) - (2)].vardecl)); }
    break;

  case 50:
#line 369 "parser.y"
    { ((yyval.vardecls) = new List<VarDecl*>) -> Append((yyvsp[(1) - (1)].vardecl)); }
    break;

  case 51:
#line 372 "parser.y"
    { ((yyval.stmts) = (yyvsp[(1) - (2)].stmts)) -> Append((yyvsp[(2) - (2)].stmt)); }
    break;

  case 52:
#line 373 "parser.y"
    { ((yyval.stmts) = new List<Stmt*>) -> Append((yyvsp[(1) - (1)].stmt)); }
    break;

  case 53:
#line 376 "parser.y"
    { }
    break;

  case 54:
#line 377 "parser.y"
    { }
    break;

  case 55:
#line 378 "parser.y"
    { }
    break;

  case 56:
#line 379 "parser.y"
    { }
    break;

  case 57:
#line 380 "parser.y"
    { }
    break;

  case 58:
#line 382 "parser.y"
    { }
    break;

  case 59:
#line 383 "parser.y"
    { }
    break;

  case 60:
#line 384 "parser.y"
    { }
    break;

  case 61:
#line 391 "parser.y"
    { (yyval.ifstmt) = new IfStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt), NULL); }
    break;

  case 62:
#line 393 "parser.y"
    { (yyval.ifstmt) = new IfStmt((yyvsp[(3) - (7)].expr), (yyvsp[(5) - (7)].stmt), (yyvsp[(7) - (7)].stmt)); }
    break;

  case 63:
#line 398 "parser.y"
    { (yyval.whilestmt) = new WhileStmt((yyvsp[(3) - (5)].expr), (yyvsp[(5) - (5)].stmt)); }
    break;

  case 64:
#line 402 "parser.y"
    { (yyval.forstmt) = new ForStmt((yyvsp[(3) - (9)].expr), (yyvsp[(5) - (9)].expr), (yyvsp[(7) - (9)].expr), (yyvsp[(9) - (9)].stmt)); }
    break;

  case 65:
#line 405 "parser.y"
    { (yyval.rtnstmt) = new ReturnStmt((yylsp[(1) - (3)]), (yyvsp[(2) - (3)].expr)); }
    break;

  case 66:
#line 408 "parser.y"
    { (yyval.brkstmt) = new BreakStmt((yylsp[(1) - (2)])); }
    break;

  case 67:
#line 430 "parser.y"
    { (yyval.pntstmt) = new PrintStmt((yyvsp[(3) - (5)].exprs)); }
    break;

  case 68:
#line 433 "parser.y"
    { }
    break;

  case 69:
#line 434 "parser.y"
    { }
    break;

  case 70:
#line 435 "parser.y"
    { }
    break;

  case 71:
#line 436 "parser.y"
    { (yyval.expr) = new This((yylsp[(1) - (1)])); }
    break;

  case 72:
#line 437 "parser.y"
    { }
    break;

  case 73:
#line 438 "parser.y"
    { (yyval.expr) = (yyvsp[(2) - (3)].expr); }
    break;

  case 74:
#line 439 "parser.y"
    { }
    break;

  case 75:
#line 440 "parser.y"
    { }
    break;

  case 76:
#line 441 "parser.y"
    { }
    break;

  case 77:
#line 442 "parser.y"
    { }
    break;

  case 78:
#line 444 "parser.y"
    { (yyval.expr) = new ReadIntegerExpr((yylsp[(1) - (3)])); }
    break;

  case 79:
#line 445 "parser.y"
    { (yyval.expr) = new ReadLineExpr((yylsp[(1) - (3)])); }
    break;

  case 80:
#line 446 "parser.y"
    { (yyval.expr) = new NewExpr(Join((yylsp[(1) - (4)]), (yylsp[(3) - (4)])), new NamedType(new Identifier((yylsp[(3) - (4)]), (yyvsp[(3) - (4)].identifier)))); }
    break;

  case 81:
#line 448 "parser.y"
    { 
                                     	(yyval.expr) = new NewArrayExpr(Join((yylsp[(1) - (6)]), (yylsp[(6) - (6)])), (yyvsp[(3) - (6)].expr), (yyvsp[(5) - (6)].simpletype)); 
                                     }
    break;

  case 82:
#line 454 "parser.y"
    { (yyval.assignexpr) = new AssignExpr((yyvsp[(1) - (3)].lvalue), new Operator((yylsp[(2) - (3)]), "="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 83:
#line 457 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "+"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 84:
#line 458 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "-"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 85:
#line 459 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "*"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 86:
#line 460 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "/"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 87:
#line 461 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "%"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 88:
#line 463 "parser.y"
    { (yyval.arithmeticexpr) = new ArithmeticExpr(new Operator((yylsp[(1) - (2)]), "-"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 89:
#line 471 "parser.y"
    { (yyval.equalityexpr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "=="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 90:
#line 473 "parser.y"
    { (yyval.equalityexpr) = new EqualityExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "!="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 91:
#line 477 "parser.y"
    { (yyval.relationalexpr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 92:
#line 479 "parser.y"
    { (yyval.relationalexpr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 93:
#line 481 "parser.y"
    { (yyval.relationalexpr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "<="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 94:
#line 483 "parser.y"
    { (yyval.relationalexpr) = new RelationalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), ">="), (yyvsp[(3) - (3)].expr)); }
    break;

  case 95:
#line 487 "parser.y"
    { (yyval.logicalexpr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "&&"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 96:
#line 489 "parser.y"
    { (yyval.logicalexpr) = new LogicalExpr((yyvsp[(1) - (3)].expr), new Operator((yylsp[(2) - (3)]), "||"), (yyvsp[(3) - (3)].expr)); }
    break;

  case 97:
#line 490 "parser.y"
    { (yyval.logicalexpr) = new LogicalExpr(new Operator((yylsp[(1) - (2)]), "!"), (yyvsp[(2) - (2)].expr)); }
    break;

  case 98:
#line 494 "parser.y"
    { ((yyval.exprs) = (yyvsp[(1) - (3)].exprs))->Append((yyvsp[(3) - (3)].expr)); }
    break;

  case 99:
#line 495 "parser.y"
    { ((yyval.exprs) = new List<Expr*>)->Append((yyvsp[(1) - (1)].expr)); }
    break;

  case 100:
#line 498 "parser.y"
    { (yyval.expr) = new EmptyExpr(); }
    break;

  case 101:
#line 499 "parser.y"
    { (yyval.expr)= (yyvsp[(1) - (1)].expr); }
    break;

  case 102:
#line 503 "parser.y"
    { (yyval.lvalue) = new FieldAccess(NULL, new Identifier((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].identifier))); }
    break;

  case 103:
#line 504 "parser.y"
    { (yyval.lvalue) = new FieldAccess((yyvsp[(1) - (3)].expr), new Identifier((yylsp[(3) - (3)]), (yyvsp[(3) - (3)].identifier))); }
    break;

  case 104:
#line 505 "parser.y"
    { (yyval.lvalue) = new ArrayAccess(Join((yylsp[(1) - (4)]), (yylsp[(4) - (4)])), (yyvsp[(1) - (4)].expr), (yyvsp[(3) - (4)].expr)); }
    break;

  case 105:
#line 514 "parser.y"
    { (yyval.call) = new Call((yylsp[(1) - (4)]), NULL, new Identifier((yylsp[(1) - (4)]), (yyvsp[(1) - (4)].identifier)), (yyvsp[(3) - (4)].exprs)); }
    break;

  case 106:
#line 516 "parser.y"
    { (yyval.call) = new Call(Join((yylsp[(1) - (6)]), (yylsp[(6) - (6)])), (yyvsp[(1) - (6)].expr), new Identifier((yylsp[(3) - (6)]), (yyvsp[(3) - (6)].identifier)), (yyvsp[(5) - (6)].exprs)); }
    break;

  case 108:
#line 523 "parser.y"
    { (yyval.exprs) = new List<Expr*>; }
    break;

  case 109:
#line 526 "parser.y"
    { }
    break;

  case 110:
#line 527 "parser.y"
    { }
    break;

  case 111:
#line 528 "parser.y"
    { }
    break;

  case 112:
#line 529 "parser.y"
    { }
    break;

  case 113:
#line 530 "parser.y"
    { }
    break;

  case 114:
#line 533 "parser.y"
    { (yyval.intconst) = new IntConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].integerConstant)); }
    break;

  case 115:
#line 536 "parser.y"
    { (yyval.doubleconst) = new DoubleConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].doubleConstant)); }
    break;

  case 116:
#line 539 "parser.y"
    { (yyval.boolconst) = new BoolConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].boolConstant)); }
    break;

  case 117:
#line 542 "parser.y"
    { (yyval.stringconst) = new StringConstant((yylsp[(1) - (1)]), (yyvsp[(1) - (1)].stringConstant)); }
    break;

  case 118:
#line 545 "parser.y"
    { (yyval.nullconst) = new NullConstant((yylsp[(1) - (1)])); }
    break;


/* Line 1267 of yacc.c.  */
#line 2441 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the look-ahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 547 "parser.y"


/* The closing %% above marks the end of the Rules section and the beginning
 * of the User Subroutines section. All text from here to the end of the
 * file is copied verbatim to the end of the generated y.tab.c file.
 * This section is where you put definitions of helper functions.
 */

/* Function: InitParser
 * --------------------
 * This function will be called before any calls to yyparse().  It is designed
 * to give you an opportunity to do anything that must be done to initialize
 * the parser (set global variables, configure starting state, etc.). One
 * thing it already does for you is assign the value of the global variable
 * yydebug that controls whether yacc prints debugging information about
 * parser actions (shift/reduce) and contents of state stack during parser.
 * If set to false, no information is printed. Setting it to true will give
 * you a running trail that might be helpful when debugging your parser.
 * Please be sure the variable is set to false when submitting your final
 * version.
 */

void InitParser()
{
   PrintDebug("parser", "Initializing parser");
		 yydebug = false;
		 //yydebug = true;
	
}

