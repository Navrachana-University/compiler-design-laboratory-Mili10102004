
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "lyricslang.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE *yyin;
extern int yylineno;
int yylex(void);
void yyerror(const char *s);

#define MAX_VARIABLES 100

struct Variable {
    char *name;
    int value;
    int is_defined;
};
struct Variable symbolTable[MAX_VARIABLES];
int variableCount = 0;

void setVariable(char *name, int value) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            symbolTable[i].value = value;
            symbolTable[i].is_defined = 1;
            printf("Variable '%s' updated to %d.\n", name, value);
            return;
        }
    }
    if (variableCount < MAX_VARIABLES) {
        symbolTable[variableCount].name = strdup(name);
        symbolTable[variableCount].value = value;
        symbolTable[variableCount].is_defined = 1;
        printf("Variable '%s' set to %d.\n", name, value);
        variableCount++;
    } else {
        fprintf(stderr, "Error: Variable symbol table is full.\n");
    }
}

int getVariable(char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if (symbolTable[i].is_defined) {
                return symbolTable[i].value;
            } else {
                fprintf(stderr, "Error: Variable '%s' used before assignment.\n", name);
                return 0;
            }
        }
    }
    fprintf(stderr, "Error: Variable '%s' not declared.\n", name);
    return 0;
}

#define MAX_FUNCTIONS 100
struct FunctionSymbol {
    char *name;
};
struct FunctionSymbol functionTable[MAX_FUNCTIONS];
int functionCount = 0;

void addFunctionSymbol(char *name) {
    if (functionCount < MAX_FUNCTIONS) {
        functionTable[functionCount].name = strdup(name);
        printf("Function '%s' defined.\n", name);
        functionCount++;
    } else {
        fprintf(stderr, "Error: Function symbol table is full.\n");
    }
}


/* Line 189 of yacc.c  */
#line 147 "lyricslang.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     STRING = 259,
     NUMBER = 260,
     VALUE = 261,
     PRINT = 262,
     INPUT = 263,
     IF = 264,
     ELSEIF = 265,
     ELSE = 266,
     WHILE = 267,
     FOR = 268,
     FUNCTION = 269,
     RETURN = 270,
     BREAK = 271,
     CONTINUE = 272,
     DONE_KEYWORD = 273,
     VAR_DECL = 274,
     TRUE_KEYWORD = 275,
     FALSE_KEYWORD = 276,
     IS_VALID = 277,
     SWITCH = 278,
     CASE = 279,
     DEFAULT = 280,
     EQUALS = 281,
     EQ_OP = 282,
     NE_OP = 283,
     LT_OP = 284,
     GT_OP = 285,
     LE_OP = 286,
     GE_OP = 287,
     PLUS = 288,
     MINUS = 289,
     MULTIPLY = 290,
     DIVIDE = 291,
     COLON = 292
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 74 "lyricslang.y"

    int num;
    char *str;
    int val;
    void *ptr;



/* Line 214 of yacc.c  */
#line 229 "lyricslang.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 241 "lyricslang.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   270

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  137

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,    40,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    24,    26,    28,    30,    32,    35,    38,    40,
      42,    46,    50,    54,    58,    64,    69,    78,    79,    81,
      83,    86,    92,    93,    96,   103,   113,   123,   124,   130,
     131,   135,   142,   146,   147,   149,   152,   154,   156,   158,
     160,   162,   166,   170,   174,   178,   182,   186,   190,   194,
     196,   198,   202,   206,   208,   210,   214
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      44,     0,    -1,    45,    -1,    46,    -1,    45,    46,    -1,
      65,    -1,    48,    -1,    49,    -1,    50,    -1,    51,    -1,
      52,    -1,    57,    -1,    58,    -1,    59,    -1,    62,    -1,
      63,    -1,    16,    38,    -1,    17,    38,    -1,    47,    -1,
      38,    -1,    39,    45,    40,    -1,     7,    67,    38,    -1,
       7,     4,    38,    -1,     8,    70,    38,    -1,    19,    70,
      26,    67,    38,    -1,    70,    26,    67,    38,    -1,     9,
      41,    66,    42,    47,    53,    56,    18,    -1,    -1,    54,
      -1,    55,    -1,    54,    55,    -1,    10,    41,    66,    42,
      47,    -1,    -1,    11,    47,    -1,    12,    41,    66,    42,
      47,    18,    -1,    13,    41,    50,    66,    38,    64,    42,
      47,    18,    -1,    23,    41,    67,    42,    39,    60,    61,
      40,    18,    -1,    -1,    60,    24,    67,    37,    45,    -1,
      -1,    25,    37,    45,    -1,    14,    70,    41,    42,    47,
      18,    -1,    15,    64,    38,    -1,    -1,    67,    -1,    67,
      38,    -1,    67,    -1,    70,    -1,     5,    -1,    20,    -1,
      21,    -1,    67,    27,    67,    -1,    67,    28,    67,    -1,
      67,    29,    67,    -1,    67,    30,    67,    -1,    67,    31,
      67,    -1,    67,    32,    67,    -1,    67,    33,    68,    -1,
      67,    34,    68,    -1,    68,    -1,    69,    -1,    68,    35,
      69,    -1,    68,    36,    69,    -1,     5,    -1,    70,    -1,
      41,    67,    42,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   108,   109,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     131,   135,   136,   140,   162,   166,   170,   186,   187,   191,
     192,   196,   200,   201,   205,   209,   213,   216,   218,   221,
     223,   227,   231,   234,   236,   240,   244,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     264,   265,   266,   270,   271,   272,   276
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "STRING", "NUMBER",
  "VALUE", "PRINT", "INPUT", "IF", "ELSEIF", "ELSE", "WHILE", "FOR",
  "FUNCTION", "RETURN", "BREAK", "CONTINUE", "DONE_KEYWORD", "VAR_DECL",
  "TRUE_KEYWORD", "FALSE_KEYWORD", "IS_VALID", "SWITCH", "CASE", "DEFAULT",
  "EQUALS", "EQ_OP", "NE_OP", "LT_OP", "GT_OP", "LE_OP", "GE_OP", "PLUS",
  "MINUS", "MULTIPLY", "DIVIDE", "COLON", "';'", "'{'", "'}'", "'('",
  "')'", "$accept", "program", "statement_list", "statement",
  "block_statement", "print_statement", "input_statement",
  "variable_declaration_statement", "assignment_statement", "if_statement",
  "else_if_clauses_opt", "else_if_clauses", "else_if_clause",
  "else_clause_opt", "while_statement", "for_statement",
  "switch_statement", "case_list", "default_case_opt",
  "function_definition", "return_statement", "expression_opt",
  "expression_statement", "condition", "expression", "term", "factor",
  "identifier", 0
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
     285,   286,   287,   288,   289,   290,   291,   292,    59,   123,
     125,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      47,    48,    48,    49,    50,    51,    52,    53,    53,    54,
      54,    55,    56,    56,    57,    58,    59,    60,    60,    61,
      61,    62,    63,    64,    64,    65,    66,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    67,
      68,    68,    68,    69,    69,    69,    70
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       3,     3,     3,     3,     5,     4,     8,     0,     1,     1,
       2,     5,     0,     2,     6,     9,     9,     0,     5,     0,
       3,     6,     3,     0,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     3,     1,     1,     3,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    66,    48,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,    49,    50,     0,    19,     0,     0,     0,
       2,     3,    18,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     5,     0,    59,    60,    47,     0,     0,
      47,     0,     0,     0,     0,     0,     0,    44,    16,    17,
       0,     0,     0,     0,     1,     4,     0,     0,     0,     0,
       0,     0,     0,     0,    45,     0,     0,     0,    22,    21,
      23,     0,    46,     0,     0,     0,    42,     0,     0,    20,
      65,    51,    52,    53,    54,    55,    56,    63,    57,    64,
      58,    61,    62,     0,     0,     0,     0,     0,     0,     0,
      25,    27,     0,    43,     0,    24,    37,     0,    32,    28,
      29,    34,     0,    41,    39,     0,     0,     0,    30,     0,
       0,     0,     0,     0,    33,    26,     0,     0,     0,     0,
       0,    35,     0,    40,    36,    31,    38
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
     108,   109,   110,   117,    28,    29,    30,   114,   122,    31,
      32,    46,    33,    71,    34,    35,    36,    40
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -74
static const yytype_int16 yypact[] =
{
     174,   -74,   -29,     6,    -1,   -27,   -22,   -18,    -1,    10,
     -13,    -2,    -1,   -74,   -74,    -9,   -74,   174,    10,    45,
     174,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,   -74,   -74,   -74,   171,     4,   -74,     2,    15,   189,
      14,    20,    10,    10,    29,    23,    32,   236,   -74,   -74,
      35,    10,   135,    77,   -74,   -74,    10,    10,    10,    10,
      10,    10,    13,    13,   -74,    13,    13,    10,   -74,   -74,
     -74,    25,   236,    30,    10,    31,   -74,    10,   136,   -74,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,     4,   -74,
       4,   -74,   -74,   201,    37,    37,    33,    37,   213,    39,
     -74,    64,    61,    10,    62,   -74,   -74,    40,    78,    64,
     -74,   -74,    46,   -74,    17,    10,    37,    72,   -74,    37,
      10,    54,    52,    53,   -74,   -74,    76,   225,   174,    79,
      37,   -74,   174,   174,   -74,   -74,   174
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -74,   -74,   -12,   -19,   -73,   -74,   -74,    55,   -74,   -74,
     -74,   -74,   -11,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     -74,     9,   -74,   -40,    26,    -7,    -6,     0
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -65
static const yytype_int16 yytable[] =
{
      37,    55,     1,    73,    41,    52,   -63,   -63,    45,     1,
      38,     2,    50,     1,    42,     2,     1,    37,    87,    43,
      37,   101,   102,    44,   104,    48,    13,    14,    67,    39,
      13,    14,    51,    55,    96,    47,    49,   -64,   -64,    65,
      66,   120,   121,   124,    53,    54,   126,    18,    12,   -64,
     -64,    18,    37,    68,    18,    88,    90,   135,    70,    91,
      92,    77,    89,    89,    75,    89,    89,    94,    72,    72,
      76,   103,    95,    97,   107,   123,    17,    78,   106,   111,
     113,   115,    81,    82,    83,    84,    85,    86,   119,   116,
     125,   128,   129,    93,   131,   130,     0,   134,   118,    74,
      72,     0,     0,    98,    56,    57,    58,    59,    60,    61,
      62,    63,   112,     0,    55,     0,   133,    55,     0,    80,
     136,     0,     0,     0,     0,     0,     0,     0,    37,    47,
       0,     0,    37,    37,     0,     0,    37,     0,     1,     0,
       2,    72,     3,     4,     5,     0,   127,     6,     7,     8,
       9,    10,    11,     0,    12,    13,    14,     0,    15,     0,
       0,     0,     0,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,    16,    17,    79,    18,     1,    99,     2,
       0,     3,     4,     5,     0,     0,     6,     7,     8,     9,
      10,    11,     0,    12,    13,    14,     0,    15,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,    64,
       0,     0,    16,    17,     0,    18,    56,    57,    58,    59,
      60,    61,    62,    63,     0,     0,     0,    69,    56,    57,
      58,    59,    60,    61,    62,    63,     0,     0,     0,   100,
      56,    57,    58,    59,    60,    61,    62,    63,     0,     0,
       0,   105,    56,    57,    58,    59,    60,    61,    62,    63,
       0,     0,   132,    56,    57,    58,    59,    60,    61,    62,
      63
};

static const yytype_int16 yycheck[] =
{
       0,    20,     3,    43,     4,    17,    35,    36,     8,     3,
       4,     5,    12,     3,    41,     5,     3,    17,     5,    41,
      20,    94,    95,    41,    97,    38,    20,    21,    26,     3,
      20,    21,    41,    52,    74,     9,    38,    35,    36,    35,
      36,    24,    25,   116,    18,     0,   119,    41,    19,    35,
      36,    41,    52,    38,    41,    62,    63,   130,    38,    65,
      66,    26,    62,    63,    41,    65,    66,    42,    42,    43,
      38,    38,    42,    42,    10,   115,    39,    51,    39,    18,
      18,    41,    56,    57,    58,    59,    60,    61,    42,    11,
      18,    37,    40,    67,    18,    42,    -1,    18,   109,    44,
      74,    -1,    -1,    77,    27,    28,    29,    30,    31,    32,
      33,    34,   103,    -1,   133,    -1,   128,   136,    -1,    42,
     132,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   103,
      -1,    -1,   132,   133,    -1,    -1,   136,    -1,     3,    -1,
       5,   115,     7,     8,     9,    -1,   120,    12,    13,    14,
      15,    16,    17,    -1,    19,    20,    21,    -1,    23,    -1,
      -1,    -1,    -1,    27,    28,    29,    30,    31,    32,    33,
      34,    -1,    -1,    38,    39,    40,    41,     3,    42,     5,
      -1,     7,     8,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    -1,    19,    20,    21,    -1,    23,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      -1,    -1,    38,    39,    -1,    41,    27,    28,    29,    30,
      31,    32,    33,    34,    -1,    -1,    -1,    38,    27,    28,
      29,    30,    31,    32,    33,    34,    -1,    -1,    -1,    38,
      27,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    38,    27,    28,    29,    30,    31,    32,    33,    34,
      -1,    -1,    37,    27,    28,    29,    30,    31,    32,    33,
      34
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     7,     8,     9,    12,    13,    14,    15,
      16,    17,    19,    20,    21,    23,    38,    39,    41,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    57,    58,
      59,    62,    63,    65,    67,    68,    69,    70,     4,    67,
      70,    70,    41,    41,    41,    70,    64,    67,    38,    38,
      70,    41,    45,    67,     0,    46,    27,    28,    29,    30,
      31,    32,    33,    34,    38,    35,    36,    26,    38,    38,
      38,    66,    67,    66,    50,    41,    38,    26,    67,    40,
      42,    67,    67,    67,    67,    67,    67,     5,    68,    70,
      68,    69,    69,    67,    42,    42,    66,    42,    67,    42,
      38,    47,    47,    38,    47,    38,    39,    10,    53,    54,
      55,    18,    64,    18,    60,    41,    11,    56,    55,    42,
      24,    25,    61,    66,    47,    18,    47,    67,    37,    40,
      42,    18,    37,    45,    18,    47,    45
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
# if YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 20:

/* Line 1455 of yacc.c  */
#line 131 "lyricslang.y"
    { (yyval.val) = 0; ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 135 "lyricslang.y"
    { printf("Saying: %d\n", (yyvsp[(2) - (3)].val)); ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 136 "lyricslang.y"
    { printf("Saying: %s\n", (yyvsp[(2) - (3)].str)); if ((yyvsp[(2) - (3)].str)) free((yyvsp[(2) - (3)].str)); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 140 "lyricslang.y"
    {
        char buffer[256];
        printf("Enter value for %s: ", (yyvsp[(2) - (3)].str));
        if (fgets(buffer, sizeof(buffer), stdin)) {
            buffer[strcspn(buffer, "\n")] = 0;  // Remove newline
            char *endptr;
            int val = strtol(buffer, &endptr, 10);
            if (*endptr == '\0') {
                setVariable((yyvsp[(2) - (3)].str), val);
            } else {
                printf("Read string: %s\n", buffer);
                // Optional: store as string if symbol table supports it
            }
        } else {
            fprintf(stderr, "Failed to read input. Setting '%s' to 0.\n", (yyvsp[(2) - (3)].str));
            setVariable((yyvsp[(2) - (3)].str), 0);
        }
        if ((yyvsp[(2) - (3)].str)) free((yyvsp[(2) - (3)].str));
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 162 "lyricslang.y"
    { setVariable((yyvsp[(2) - (5)].str), (yyvsp[(4) - (5)].val)); if ((yyvsp[(2) - (5)].str)) free((yyvsp[(2) - (5)].str)); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 166 "lyricslang.y"
    { setVariable((yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].val)); if ((yyvsp[(1) - (4)].str)) free((yyvsp[(1) - (4)].str)); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 170 "lyricslang.y"
    {
        printf("If condition evaluated to: %d\n", (yyvsp[(3) - (8)].val));
        if ((yyvsp[(3) - (8)].val) != 0) {
            printf("Executing the 'ify' block.\n");
        } else if ((yyvsp[(6) - (8)].ptr) != NULL) {
            printf("Skipping 'maybe' blocks (not fully implemented).\n");
            if ((yyvsp[(7) - (8)].ptr) != NULL) {
                printf("Executing the 'nope' block.\n");
            }
        } else if ((yyvsp[(7) - (8)].ptr) != NULL) {
            printf("Executing the 'nope' block.\n");
        }
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 186 "lyricslang.y"
    { (yyval.ptr) = NULL; ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 187 "lyricslang.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 191 "lyricslang.y"
    { (yyval.ptr) = (yyvsp[(1) - (1)].ptr); ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 192 "lyricslang.y"
    { (yyval.ptr) = NULL; ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 196 "lyricslang.y"
    { printf("Elseif condition evaluated to: %d\n", (yyvsp[(3) - (5)].val)); (yyval.ptr) = NULL; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 200 "lyricslang.y"
    { (yyval.ptr) = NULL; ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 201 "lyricslang.y"
    { (yyval.ptr) = (void *)(yyvsp[(2) - (2)].val); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 205 "lyricslang.y"
    { printf("While loop parsed.\n"); ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 209 "lyricslang.y"
    { printf("For loop parsed.\n"); ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 213 "lyricslang.y"
    { printf("Switch statement parsed.\n"); ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 218 "lyricslang.y"
    { printf("Case parsed.\n"); ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 223 "lyricslang.y"
    { printf("Default case parsed.\n"); ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 227 "lyricslang.y"
    { addFunctionSymbol((yyvsp[(2) - (6)].str)); if ((yyvsp[(2) - (6)].str)) free((yyvsp[(2) - (6)].str)); ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 231 "lyricslang.y"
    { printf("Return statement parsed.\n"); ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 248 "lyricslang.y"
    { (yyval.val) = getVariable((yyvsp[(1) - (1)].str)); if ((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 249 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 250 "lyricslang.y"
    { (yyval.val) = 1; ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 251 "lyricslang.y"
    { (yyval.val) = 0; ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 252 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) == (yyvsp[(3) - (3)].val)); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 253 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) != (yyvsp[(3) - (3)].val)); ;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 254 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) < (yyvsp[(3) - (3)].val)); ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 255 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) > (yyvsp[(3) - (3)].val)); ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 256 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) <= (yyvsp[(3) - (3)].val)); ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 257 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(1) - (3)].val) >= (yyvsp[(3) - (3)].val)); ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 258 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) + (yyvsp[(3) - (3)].val); ;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 259 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) - (yyvsp[(3) - (3)].val); ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 260 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (1)].val); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 265 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (3)].val) * (yyvsp[(3) - (3)].val); ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 266 "lyricslang.y"
    { (yyval.val) = ((yyvsp[(3) - (3)].val) != 0) ? (yyvsp[(1) - (3)].val) / (yyvsp[(3) - (3)].val) : (fprintf(stderr, "Error: Division by zero.\n"), 0); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 270 "lyricslang.y"
    { (yyval.val) = (yyvsp[(1) - (1)].num); ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 271 "lyricslang.y"
    { (yyval.val) = getVariable((yyvsp[(1) - (1)].str)); if ((yyvsp[(1) - (1)].str)) free((yyvsp[(1) - (1)].str)); ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 272 "lyricslang.y"
    { (yyval.val) = (yyvsp[(2) - (3)].val); ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 276 "lyricslang.y"
    { (yyval.str) = strdup((yyvsp[(1) - (1)].str)); ;}
    break;



/* Line 1455 of yacc.c  */
#line 1891 "lyricslang.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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



/* Line 1675 of yacc.c  */
#line 279 "lyricslang.y"


int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    } else {
        yyin = stdin;
    }

    printf("Starting parse...\n");
    if (yyparse() == 0) {
        printf("Parsing completed successfully!\n");
    } else {
        printf("Parsing failed.\n");
    }
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}

