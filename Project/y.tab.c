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
#line 1 "parser.y"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<string.h>

// Function declarations
int yylex(void);
int yyerror();
char *yytext;

typedef struct node
{ 
    char *token;
    struct node **nodes;
    int count;
} node;

// Tree functions
node *makeNode(char* token);
void addNode(node **father, node *descendant);
void printtree(node* tree, int tab);
void printArgsList(node** argsList, int argCount);
void addElement(node ***, node *, int);
#define YYSTYPE struct node*

node *temp_node = NULL;

// args-list
node** argsList = NULL;
int counter_argsList = 0;

// parameter-list
node** parList = NULL;
int counter_parlist = 0;

// var-list
node** varList = NULL;
int counter_varList = 0;

#line 112 "y.tab.c"

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
    BOOL = 258,                    /* BOOL  */
    CHAR = 259,                    /* CHAR  */
    INT = 260,                     /* INT  */
    REAL = 261,                    /* REAL  */
    STRING = 262,                  /* STRING  */
    INT_POINTER = 263,             /* INT_POINTER  */
    CHAR_POINTER = 264,            /* CHAR_POINTER  */
    REAL_POINTER = 265,            /* REAL_POINTER  */
    ADDRESS = 266,                 /* ADDRESS  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    DO = 270,                      /* DO  */
    FOR = 271,                     /* FOR  */
    FUNCTION = 272,                /* FUNCTION  */
    VAR = 273,                     /* VAR  */
    ARG_ARROW = 274,               /* ARG_ARROW  */
    RETURN = 275,                  /* RETURN  */
    NULL_TOKEN = 276,              /* NULL_TOKEN  */
    VOID = 277,                    /* VOID  */
    AND = 278,                     /* AND  */
    ASSIGNMENT = 279,              /* ASSIGNMENT  */
    EQUALS = 280,                  /* EQUALS  */
    GREATER_THAN = 281,            /* GREATER_THAN  */
    GREATER_EQUALS = 282,          /* GREATER_EQUALS  */
    LOWER_THAN = 283,              /* LOWER_THAN  */
    LOWER_EQUALS = 284,            /* LOWER_EQUALS  */
    NOT = 285,                     /* NOT  */
    NOT_EQUALS = 286,              /* NOT_EQUALS  */
    OR = 287,                      /* OR  */
    SUBSTRACT = 288,               /* SUBSTRACT  */
    ADD = 289,                     /* ADD  */
    MULTIPLY = 290,                /* MULTIPLY  */
    DIVIDE = 291,                  /* DIVIDE  */
    TRUE = 292,                    /* TRUE  */
    FALSE = 293,                   /* FALSE  */
    CHAR_LITERAL = 294,            /* CHAR_LITERAL  */
    INTEGER_LITERAL = 295,         /* INTEGER_LITERAL  */
    INTEGER_LITERAL_HEX = 296,     /* INTEGER_LITERAL_HEX  */
    REAL_LITERAL = 297,            /* REAL_LITERAL  */
    STRING_LITERAL = 298,          /* STRING_LITERAL  */
    IDENTIFIER = 299,              /* IDENTIFIER  */
    COMMENT = 300,                 /* COMMENT  */
    COLON = 301,                   /* COLON  */
    SEMICOLON = 302,               /* SEMICOLON  */
    COMMA = 303,                   /* COMMA  */
    VERTICAL_BAR = 304,            /* VERTICAL_BAR  */
    START_CURLY_BRACKETS = 305,    /* START_CURLY_BRACKETS  */
    END_CURLY_BRACKETS = 306,      /* END_CURLY_BRACKETS  */
    START_ROUND_BRACKETS = 307,    /* START_ROUND_BRACKETS  */
    END_ROUND_BRACKETS = 308,      /* END_ROUND_BRACKETS  */
    START_SQUARE_BRACKETS = 309,   /* START_SQUARE_BRACKETS  */
    END_SQUARE_BRACKETS = 310      /* END_SQUARE_BRACKETS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BOOL 258
#define CHAR 259
#define INT 260
#define REAL 261
#define STRING 262
#define INT_POINTER 263
#define CHAR_POINTER 264
#define REAL_POINTER 265
#define ADDRESS 266
#define IF 267
#define ELSE 268
#define WHILE 269
#define DO 270
#define FOR 271
#define FUNCTION 272
#define VAR 273
#define ARG_ARROW 274
#define RETURN 275
#define NULL_TOKEN 276
#define VOID 277
#define AND 278
#define ASSIGNMENT 279
#define EQUALS 280
#define GREATER_THAN 281
#define GREATER_EQUALS 282
#define LOWER_THAN 283
#define LOWER_EQUALS 284
#define NOT 285
#define NOT_EQUALS 286
#define OR 287
#define SUBSTRACT 288
#define ADD 289
#define MULTIPLY 290
#define DIVIDE 291
#define TRUE 292
#define FALSE 293
#define CHAR_LITERAL 294
#define INTEGER_LITERAL 295
#define INTEGER_LITERAL_HEX 296
#define REAL_LITERAL 297
#define STRING_LITERAL 298
#define IDENTIFIER 299
#define COMMENT 300
#define COLON 301
#define SEMICOLON 302
#define COMMA 303
#define VERTICAL_BAR 304
#define START_CURLY_BRACKETS 305
#define END_CURLY_BRACKETS 306
#define START_ROUND_BRACKETS 307
#define END_ROUND_BRACKETS 308
#define START_SQUARE_BRACKETS 309
#define END_SQUARE_BRACKETS 310

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
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
  YYSYMBOL_BOOL = 3,                       /* BOOL  */
  YYSYMBOL_CHAR = 4,                       /* CHAR  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_STRING = 7,                     /* STRING  */
  YYSYMBOL_INT_POINTER = 8,                /* INT_POINTER  */
  YYSYMBOL_CHAR_POINTER = 9,               /* CHAR_POINTER  */
  YYSYMBOL_REAL_POINTER = 10,              /* REAL_POINTER  */
  YYSYMBOL_ADDRESS = 11,                   /* ADDRESS  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_FOR = 16,                       /* FOR  */
  YYSYMBOL_FUNCTION = 17,                  /* FUNCTION  */
  YYSYMBOL_VAR = 18,                       /* VAR  */
  YYSYMBOL_ARG_ARROW = 19,                 /* ARG_ARROW  */
  YYSYMBOL_RETURN = 20,                    /* RETURN  */
  YYSYMBOL_NULL_TOKEN = 21,                /* NULL_TOKEN  */
  YYSYMBOL_VOID = 22,                      /* VOID  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_ASSIGNMENT = 24,                /* ASSIGNMENT  */
  YYSYMBOL_EQUALS = 25,                    /* EQUALS  */
  YYSYMBOL_GREATER_THAN = 26,              /* GREATER_THAN  */
  YYSYMBOL_GREATER_EQUALS = 27,            /* GREATER_EQUALS  */
  YYSYMBOL_LOWER_THAN = 28,                /* LOWER_THAN  */
  YYSYMBOL_LOWER_EQUALS = 29,              /* LOWER_EQUALS  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_NOT_EQUALS = 31,                /* NOT_EQUALS  */
  YYSYMBOL_OR = 32,                        /* OR  */
  YYSYMBOL_SUBSTRACT = 33,                 /* SUBSTRACT  */
  YYSYMBOL_ADD = 34,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 35,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 36,                    /* DIVIDE  */
  YYSYMBOL_TRUE = 37,                      /* TRUE  */
  YYSYMBOL_FALSE = 38,                     /* FALSE  */
  YYSYMBOL_CHAR_LITERAL = 39,              /* CHAR_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL = 40,           /* INTEGER_LITERAL  */
  YYSYMBOL_INTEGER_LITERAL_HEX = 41,       /* INTEGER_LITERAL_HEX  */
  YYSYMBOL_REAL_LITERAL = 42,              /* REAL_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 43,            /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 44,                /* IDENTIFIER  */
  YYSYMBOL_COMMENT = 45,                   /* COMMENT  */
  YYSYMBOL_COLON = 46,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 47,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 48,                     /* COMMA  */
  YYSYMBOL_VERTICAL_BAR = 49,              /* VERTICAL_BAR  */
  YYSYMBOL_START_CURLY_BRACKETS = 50,      /* START_CURLY_BRACKETS  */
  YYSYMBOL_END_CURLY_BRACKETS = 51,        /* END_CURLY_BRACKETS  */
  YYSYMBOL_START_ROUND_BRACKETS = 52,      /* START_ROUND_BRACKETS  */
  YYSYMBOL_END_ROUND_BRACKETS = 53,        /* END_ROUND_BRACKETS  */
  YYSYMBOL_START_SQUARE_BRACKETS = 54,     /* START_SQUARE_BRACKETS  */
  YYSYMBOL_END_SQUARE_BRACKETS = 55,       /* END_SQUARE_BRACKETS  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_s = 57,                         /* s  */
  YYSYMBOL_code = 58,                      /* code  */
  YYSYMBOL_function_procedure = 59,        /* function_procedure  */
  YYSYMBOL_functions = 60,                 /* functions  */
  YYSYMBOL_function = 61,                  /* function  */
  YYSYMBOL_procedure = 62,                 /* procedure  */
  YYSYMBOL_args = 63,                      /* args  */
  YYSYMBOL_args_list = 64,                 /* args_list  */
  YYSYMBOL_parameters_list = 65,           /* parameters_list  */
  YYSYMBOL_body = 66,                      /* body  */
  YYSYMBOL_body_after_functions_declared = 67, /* body_after_functions_declared  */
  YYSYMBOL_body_after_delarations = 68,    /* body_after_delarations  */
  YYSYMBOL_statements = 69,                /* statements  */
  YYSYMBOL_assignment_statement = 70,      /* assignment_statement  */
  YYSYMBOL_lhs = 71,                       /* lhs  */
  YYSYMBOL_function_call_statement = 72,   /* function_call_statement  */
  YYSYMBOL_function_parms = 73,            /* function_parms  */
  YYSYMBOL_if_statement = 74,              /* if_statement  */
  YYSYMBOL_if_else_statement = 75,         /* if_else_statement  */
  YYSYMBOL_while_statement = 76,           /* while_statement  */
  YYSYMBOL_do_while_statement = 77,        /* do_while_statement  */
  YYSYMBOL_for_statement = 78,             /* for_statement  */
  YYSYMBOL_code_block_statement = 79,      /* code_block_statement  */
  YYSYMBOL_return_statement = 80,          /* return_statement  */
  YYSYMBOL_type = 81,                      /* type  */
  YYSYMBOL_id = 82,                        /* id  */
  YYSYMBOL_integer_literal = 83,           /* integer_literal  */
  YYSYMBOL_bool__literal = 84,             /* bool__literal  */
  YYSYMBOL_literal_lexemes = 85,           /* literal_lexemes  */
  YYSYMBOL_variable_declarations = 86,     /* variable_declarations  */
  YYSYMBOL_variable_declare = 87,          /* variable_declare  */
  YYSYMBOL_variable_list_helper = 88,      /* variable_list_helper  */
  YYSYMBOL_variable_list = 89,             /* variable_list  */
  YYSYMBOL_expression = 90,                /* expression  */
  YYSYMBOL_operator = 91                   /* operator  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   319

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    57,    57,    59,    59,    62,    67,    73,
      87,   102,   112,   117,   128,   141,   146,   154,   161,   167,
     171,   177,   182,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   201,   209,   218,   223,   229,   236,   237,   241,
     250,   260,   269,   278,   284,   289,   295,   303,   304,   305,
     306,   307,   308,   309,   313,   318,   319,   323,   324,   328,
     329,   330,   331,   332,   333,   337,   342,   348,   356,   361,
     371,   376,   388,   394,   401,   404,   405,   406,   407,   408,
     409,   410,   411,   412,   413,   414,   415,   416
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
  "\"end of file\"", "error", "\"invalid token\"", "BOOL", "CHAR", "INT",
  "REAL", "STRING", "INT_POINTER", "CHAR_POINTER", "REAL_POINTER",
  "ADDRESS", "IF", "ELSE", "WHILE", "DO", "FOR", "FUNCTION", "VAR",
  "ARG_ARROW", "RETURN", "NULL_TOKEN", "VOID", "AND", "ASSIGNMENT",
  "EQUALS", "GREATER_THAN", "GREATER_EQUALS", "LOWER_THAN", "LOWER_EQUALS",
  "NOT", "NOT_EQUALS", "OR", "SUBSTRACT", "ADD", "MULTIPLY", "DIVIDE",
  "TRUE", "FALSE", "CHAR_LITERAL", "INTEGER_LITERAL",
  "INTEGER_LITERAL_HEX", "REAL_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "COMMENT", "COLON", "SEMICOLON", "COMMA", "VERTICAL_BAR",
  "START_CURLY_BRACKETS", "END_CURLY_BRACKETS", "START_ROUND_BRACKETS",
  "END_ROUND_BRACKETS", "START_SQUARE_BRACKETS", "END_SQUARE_BRACKETS",
  "$accept", "s", "code", "function_procedure", "functions", "function",
  "procedure", "args", "args_list", "parameters_list", "body",
  "body_after_functions_declared", "body_after_delarations", "statements",
  "assignment_statement", "lhs", "function_call_statement",
  "function_parms", "if_statement", "if_else_statement", "while_statement",
  "do_while_statement", "for_statement", "code_block_statement",
  "return_statement", "type", "id", "integer_literal", "bool__literal",
  "literal_lexemes", "variable_declarations", "variable_declare",
  "variable_list_helper", "variable_list", "expression", "operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,   -48,   -41,    92,   -21,   -17,   239,  -110,    -2,    46,
    -110,  -110,    34,  -110,  -110,  -110,     7,    31,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,     6,   239,   239,    49,
     -17,    12,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -110,   193,   239,   -17,  -110,
      16,    92,  -110,    53,  -110,  -110,  -110,  -110,   261,   239,
     135,   164,    20,    29,    59,    67,  -110,   239,   283,    60,
    -110,   -26,  -110,  -110,  -110,   -38,    44,   283,   121,    92,
      92,   239,   239,   261,   -17,    45,    58,   283,   140,   250,
     -17,   239,  -110,    98,  -110,   178,   216,    -3,  -110,    68,
      94,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,    69,
    -110,   -27,   283,    92,    70,   -17,   250,   -17,   116,   -17,
    -110,   239,    71,  -110,  -110,    76,  -110,  -110,    81,    83,
       4,   283,  -110,    92,    18,    18,   250,  -110,    18,    84,
    -110,    88,  -110,  -110,  -110,  -110,  -110
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    54,     0,     0,
       2,     7,     3,     5,     6,     4,     0,     0,    24,    25,
      26,    27,    28,    29,    30,    31,    35,     0,     0,     0,
       0,     0,    75,    77,    78,    79,    80,    81,    83,    84,
      85,    82,    86,    87,    76,    58,    57,    60,    55,    56,
      62,    63,    64,    61,    59,    74,     0,     0,     0,    45,
       0,    20,    21,    19,    65,     1,     8,    23,     0,     0,
       0,     0,     0,     0,     0,    12,    46,     0,    72,    68,
      70,     0,    44,    22,    66,    63,    64,    32,     0,     0,
       0,     0,     0,     0,     0,     0,    11,    73,     0,     0,
       0,     0,    34,    39,    41,     0,     0,     0,    15,     0,
       0,    69,    47,    48,    49,    50,    53,    51,    52,     0,
      71,     0,    37,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,    40,    42,     0,    13,    16,     0,     0,
       0,    38,    36,     0,     0,     0,     0,    43,     0,     0,
      18,     0,    14,     7,    17,    10,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,  -110,   -11,   134,  -110,  -110,  -110,  -110,    11,
    -104,   133,  -110,     0,   -25,   -22,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,  -109,     1,  -110,  -110,    47,
    -110,    96,    72,  -110,    -4,   -31
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,   148,    13,    14,    95,    96,   107,
     149,   150,    61,    62,    16,    17,    18,   121,    19,    20,
      21,    22,    23,    24,    25,   119,    26,    53,    54,    55,
      63,    64,    80,    81,    87,    57
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    66,    56,    29,    27,    73,    31,    52,    74,   -33,
       1,    28,     2,     3,     4,   -33,    58,   136,     6,   139,
      99,   131,   100,    70,    71,    77,   132,     7,    52,    52,
       1,    30,     2,     3,     4,     5,    58,   152,     6,    77,
      77,   151,     7,   126,   154,   127,    65,    77,     8,    59,
     146,     5,   127,    78,    67,    68,    77,    77,    52,    79,
      69,    83,     7,    72,    75,    88,    77,    82,     8,    86,
      52,    58,    91,    97,    77,    77,    92,     1,    52,     2,
       3,     4,     5,    93,    98,     6,    94,   105,   106,   103,
     104,    77,    52,    52,    52,   108,   101,   122,   109,    52,
     135,    79,    52,    74,     1,   110,     2,     3,     4,     7,
      77,   123,     6,   129,   128,     8,   130,   134,   142,   112,
     113,   114,   115,   133,   116,   117,   118,   141,   137,   143,
     108,   144,    52,   145,    12,   155,     7,   153,   138,   156,
     140,    60,     8,   147,    32,   111,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    32,    84,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,   120,     0,     0,     0,   102,    45,    46,    47,
      48,    49,    50,    51,     7,     0,     0,    32,    89,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    32,     0,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,     0,    32,    90,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
       0,   124,     0,     0,     0,     0,     0,     0,     0,    32,
      76,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,   112,   113,   114,   115,     0,   116,   117,
     118,     0,    32,   125,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,     7,    32,     0,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    85,     7,    32,     0,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

static const yytype_int16 yycheck[] =
{
       0,    12,     6,     3,    52,    30,     5,     6,    30,    47,
      12,    52,    14,    15,    16,    53,    18,   126,    20,   128,
      46,    48,    48,    27,    28,    56,    53,    44,    27,    28,
      12,    52,    14,    15,    16,    17,    18,   146,    20,    70,
      71,   145,    44,    46,   148,    48,     0,    78,    50,    51,
      46,    17,    48,    57,    47,    24,    87,    88,    57,    58,
      54,    61,    44,    14,    52,    69,    97,    51,    50,    68,
      69,    18,    52,    77,   105,   106,    47,    12,    77,    14,
      15,    16,    17,    24,    24,    20,    19,    91,    92,    89,
      90,   122,    91,    92,    93,    94,    52,   101,    53,    98,
     125,   100,   101,   125,    12,    47,    14,    15,    16,    44,
     141,    13,    20,    19,    46,    50,    47,    47,    47,     3,
       4,     5,     6,   123,     8,     9,    10,   131,   127,    53,
     129,    50,   131,    50,     0,    51,    44,   148,    22,    51,
     129,     8,    50,   143,    23,    98,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    23,    63,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,   100,    -1,    -1,    -1,    55,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    23,    53,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    23,    -1,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    -1,    23,    53,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      47,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     3,     4,     5,     6,    -1,     8,     9,
      10,    -1,    23,    47,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    23,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    14,    15,    16,    17,    20,    44,    50,    57,
      58,    59,    60,    61,    62,    69,    70,    71,    72,    74,
      75,    76,    77,    78,    79,    80,    82,    52,    52,    69,
      52,    82,    23,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    82,    83,    84,    85,    90,    91,    18,    51,
      67,    68,    69,    86,    87,     0,    59,    47,    24,    54,
      90,    90,    14,    70,    71,    52,    47,    91,    90,    82,
      88,    89,    51,    69,    87,    43,    82,    90,    90,    53,
      53,    52,    47,    24,    19,    63,    64,    90,    24,    46,
      48,    52,    55,    69,    69,    90,    90,    65,    82,    53,
      47,    85,     3,     4,     5,     6,     8,     9,    10,    81,
      88,    73,    90,    13,    53,    47,    46,    48,    46,    19,
      47,    48,    53,    69,    47,    70,    81,    82,    22,    81,
      65,    90,    47,    53,    50,    50,    46,    69,    60,    66,
      67,    66,    81,    59,    66,    51,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    70,    70,    71,    71,    72,    73,    73,    74,
      75,    76,    77,    78,    79,    79,    80,    81,    81,    81,
      81,    81,    81,    81,    82,    83,    83,    84,    84,    85,
      85,    85,    85,    85,    85,    86,    86,    87,    88,    88,
      89,    89,    90,    90,    90,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,    10,
      10,     1,     0,     4,     6,     1,     3,     2,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     4,     1,     7,     1,     3,     5,
       7,     5,     7,     9,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     1,     3,
       1,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
  case 2: /* s: code  */
#line 55 "parser.y"
        { printtree(yyvsp[0], 0); }
#line 1484 "y.tab.c"
    break;

  case 4: /* code: statements  */
#line 57 "parser.y"
                            { yyval = yyvsp[0]; }
#line 1490 "y.tab.c"
    break;

  case 7: /* functions: function_procedure  */
#line 63 "parser.y"
    {
        yyval = makeNode("CODE");
        addNode(&yyval, yyvsp[0]);
    }
#line 1499 "y.tab.c"
    break;

  case 8: /* functions: functions function_procedure  */
#line 68 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 1507 "y.tab.c"
    break;

  case 9: /* function: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
#line 74 "parser.y"
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode(yyvsp[-8]->token));
        addNode(&func_node, yyvsp[-6]);
        node* type_node = makeNode("TYPE");
        addNode(&type_node, yyvsp[-3]);
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, yyvsp[-1]);
        addNode(&func_node, body_node);
        yyval = func_node;
    }
#line 1524 "y.tab.c"
    break;

  case 10: /* procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
#line 88 "parser.y"
    {
        node* func_node = makeNode("FUNCTION");
        addNode(&func_node, makeNode(yyvsp[-8]->token));
        addNode(&func_node, yyvsp[-6]);
        node* type_node = makeNode("RET VOID");
        addNode(&func_node, type_node);
        node* body_node = makeNode("BODY");
        addNode(&body_node, yyvsp[-1]);
        addNode(&func_node, body_node);
        yyval = func_node;
    }
#line 1540 "y.tab.c"
    break;

  case 11: /* args: args_list  */
#line 103 "parser.y"
    {
        node* temp = makeNode("ARGS");
        temp->nodes = argsList;
        temp->count = counter_argsList;
        yyval = temp;
        argsList = NULL;
        counter_argsList=0;
    }
#line 1553 "y.tab.c"
    break;

  case 12: /* args: %empty  */
#line 112 "parser.y"
    {
        yyval = makeNode("ARGS NONE");
    }
#line 1561 "y.tab.c"
    break;

  case 13: /* args_list: ARG_ARROW parameters_list COLON type  */
#line 118 "parser.y"
    {
        yyvsp[0]->nodes = parList;
        yyvsp[0]->count = counter_parlist;
        addElement(&argsList, yyvsp[0], counter_argsList);
        counter_argsList++;
        
        // Resetting
        parList = NULL;
        counter_parlist = 0;
    }
#line 1576 "y.tab.c"
    break;

  case 14: /* args_list: args_list SEMICOLON ARG_ARROW parameters_list COLON type  */
#line 129 "parser.y"
    {
        yyvsp[0]->nodes = parList;
        yyvsp[0]->count = counter_parlist;
        addElement(&argsList, yyvsp[0], counter_argsList);
        counter_argsList++;

        // Resetting
        parList = NULL;
        counter_parlist = 0;
    }
#line 1591 "y.tab.c"
    break;

  case 15: /* parameters_list: id  */
#line 142 "parser.y"
    {
        addElement(&parList, yyvsp[0], counter_parlist);
        counter_parlist++;
    }
#line 1600 "y.tab.c"
    break;

  case 16: /* parameters_list: parameters_list COMMA id  */
#line 147 "parser.y"
    {
        addElement(&parList, yyvsp[0], counter_parlist);
        counter_parlist++;
    }
#line 1609 "y.tab.c"
    break;

  case 17: /* body: functions body  */
#line 155 "parser.y"
    {
        node* body_node = makeNode("BODY");
        addNode(&body_node, yyvsp[-1]);
        addNode(&body_node, yyvsp[0]);
        yyval = body_node;
    }
#line 1620 "y.tab.c"
    break;

  case 18: /* body: body_after_functions_declared  */
#line 162 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1628 "y.tab.c"
    break;

  case 19: /* body_after_functions_declared: variable_declarations  */
#line 168 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1636 "y.tab.c"
    break;

  case 20: /* body_after_functions_declared: body_after_delarations  */
#line 172 "parser.y"
    {
       yyval = yyvsp[0];
    }
#line 1644 "y.tab.c"
    break;

  case 21: /* body_after_delarations: statements  */
#line 178 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 1653 "y.tab.c"
    break;

  case 22: /* body_after_delarations: body_after_delarations statements  */
#line 183 "parser.y"
    {
       addNode(&yyval, yyvsp[0]);
    }
#line 1661 "y.tab.c"
    break;

  case 23: /* statements: assignment_statement SEMICOLON  */
#line 189 "parser.y"
                                   { yyval = yyvsp[-1];}
#line 1667 "y.tab.c"
    break;

  case 24: /* statements: function_call_statement  */
#line 190 "parser.y"
                              { yyval = yyvsp[0]; }
#line 1673 "y.tab.c"
    break;

  case 25: /* statements: if_statement  */
#line 191 "parser.y"
                   { yyval = yyvsp[0]; }
#line 1679 "y.tab.c"
    break;

  case 26: /* statements: if_else_statement  */
#line 192 "parser.y"
                        { yyval = yyvsp[0]; }
#line 1685 "y.tab.c"
    break;

  case 27: /* statements: while_statement  */
#line 193 "parser.y"
                      { yyval = yyvsp[0]; }
#line 1691 "y.tab.c"
    break;

  case 28: /* statements: do_while_statement  */
#line 194 "parser.y"
                         { yyval = yyvsp[0]; }
#line 1697 "y.tab.c"
    break;

  case 29: /* statements: for_statement  */
#line 195 "parser.y"
                    { yyval = yyvsp[0]; }
#line 1703 "y.tab.c"
    break;

  case 30: /* statements: code_block_statement  */
#line 196 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1709 "y.tab.c"
    break;

  case 31: /* statements: return_statement  */
#line 197 "parser.y"
                       { yyval = yyvsp[0]; }
#line 1715 "y.tab.c"
    break;

  case 32: /* assignment_statement: lhs ASSIGNMENT expression  */
#line 202 "parser.y"
    {
        node *assignment_node = makeNode("=");
        addNode(&assignment_node, yyvsp[-2]);
        addNode(&assignment_node, yyvsp[0]);
        yyval = assignment_node;

    }
#line 1727 "y.tab.c"
    break;

  case 33: /* assignment_statement: lhs ASSIGNMENT STRING_LITERAL  */
#line 210 "parser.y"
    {
        node* assignment_node = makeNode("=");
        addNode(&assignment_node,yyvsp[-2]);
        addNode(&assignment_node,yyvsp[0]);
        yyval = assignment_node; 
    }
#line 1738 "y.tab.c"
    break;

  case 34: /* lhs: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS  */
#line 219 "parser.y"
    {
        yyval = yyvsp[-3];
        addNode(&yyval,yyvsp[-1]); //TO CHECK!!
    }
#line 1747 "y.tab.c"
    break;

  case 35: /* lhs: id  */
#line 224 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1755 "y.tab.c"
    break;

  case 36: /* function_call_statement: lhs ASSIGNMENT id START_ROUND_BRACKETS function_parms END_ROUND_BRACKETS SEMICOLON  */
#line 230 "parser.y"
    {
        //ADD
    }
#line 1763 "y.tab.c"
    break;

  case 39: /* if_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 242 "parser.y"
    {
        node* if_node = makeNode("IF");
        addNode(&if_node, yyvsp[-2]);
        addNode(&if_node, yyvsp[0]);
        yyval = if_node;
    }
#line 1774 "y.tab.c"
    break;

  case 40: /* if_else_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements  */
#line 251 "parser.y"
    {
        node* if_else_node = makeNode("IF-ELSE");
        addNode(&if_else_node, yyvsp[-4]);
        addNode(&if_else_node, yyvsp[-2]);
        addNode(&if_else_node, yyvsp[0]);
        yyval = if_else_node;
    }
#line 1786 "y.tab.c"
    break;

  case 41: /* while_statement: WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 261 "parser.y"
    {
        node* while_node = makeNode("WHILE");
        addNode(&while_node, yyvsp[-2]);
        addNode(&while_node, yyvsp[0]);
        yyval = while_node;
    }
#line 1797 "y.tab.c"
    break;

  case 42: /* do_while_statement: DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON  */
#line 270 "parser.y"
    {
        node* do_while_node = makeNode("DO-WHILE");
        addNode(&do_while_node, yyvsp[-5]);
        addNode(&do_while_node, yyvsp[-2]);
        yyval = do_while_node;
    }
#line 1808 "y.tab.c"
    break;

  case 43: /* for_statement: FOR START_ROUND_BRACKETS assignment_statement SEMICOLON expression SEMICOLON assignment_statement END_ROUND_BRACKETS statements  */
#line 279 "parser.y"
    {
        // 
    }
#line 1816 "y.tab.c"
    break;

  case 44: /* code_block_statement: START_CURLY_BRACKETS body_after_functions_declared END_CURLY_BRACKETS  */
#line 285 "parser.y"
    {
        yyval = makeNode("BLOCK");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1825 "y.tab.c"
    break;

  case 45: /* code_block_statement: START_CURLY_BRACKETS END_CURLY_BRACKETS  */
#line 290 "parser.y"
    {
        yyval = makeNode("BLOCK");
    }
#line 1833 "y.tab.c"
    break;

  case 46: /* return_statement: RETURN expression SEMICOLON  */
#line 296 "parser.y"
    {
        yyval = makeNode("RET");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1842 "y.tab.c"
    break;

  case 47: /* type: BOOL  */
#line 303 "parser.y"
         { yyval = makeNode("BOOL"); }
#line 1848 "y.tab.c"
    break;

  case 48: /* type: CHAR  */
#line 304 "parser.y"
           { yyval = makeNode("CHAR"); }
#line 1854 "y.tab.c"
    break;

  case 49: /* type: INT  */
#line 305 "parser.y"
          { yyval = makeNode("INT"); }
#line 1860 "y.tab.c"
    break;

  case 50: /* type: REAL  */
#line 306 "parser.y"
           { yyval = makeNode("REAL"); }
#line 1866 "y.tab.c"
    break;

  case 51: /* type: CHAR_POINTER  */
#line 307 "parser.y"
                   { yyval = makeNode("CHAR_POINTER"); }
#line 1872 "y.tab.c"
    break;

  case 52: /* type: REAL_POINTER  */
#line 308 "parser.y"
                   { yyval = makeNode("REAL_POINTER"); }
#line 1878 "y.tab.c"
    break;

  case 53: /* type: INT_POINTER  */
#line 309 "parser.y"
                  { yyval = makeNode("INT_POINTER"); }
#line 1884 "y.tab.c"
    break;

  case 54: /* id: IDENTIFIER  */
#line 313 "parser.y"
               {
        yyval = makeNode(yytext);
    }
#line 1892 "y.tab.c"
    break;

  case 55: /* integer_literal: INTEGER_LITERAL  */
#line 318 "parser.y"
                    { yyval = makeNode("INT");}
#line 1898 "y.tab.c"
    break;

  case 56: /* integer_literal: INTEGER_LITERAL_HEX  */
#line 319 "parser.y"
                          { yyval = makeNode("INT");}
#line 1904 "y.tab.c"
    break;

  case 57: /* bool__literal: FALSE  */
#line 323 "parser.y"
          { yyval = makeNode("FALSE");}
#line 1910 "y.tab.c"
    break;

  case 58: /* bool__literal: TRUE  */
#line 324 "parser.y"
           { yyval = makeNode("TRUE");}
#line 1916 "y.tab.c"
    break;

  case 59: /* literal_lexemes: bool__literal  */
#line 328 "parser.y"
                  { yyval = yyvsp[0]; }
#line 1922 "y.tab.c"
    break;

  case 60: /* literal_lexemes: CHAR_LITERAL  */
#line 329 "parser.y"
                   { yyval = makeNode("CHAR");}
#line 1928 "y.tab.c"
    break;

  case 61: /* literal_lexemes: integer_literal  */
#line 330 "parser.y"
                      { yyval = yyvsp[0];}
#line 1934 "y.tab.c"
    break;

  case 62: /* literal_lexemes: REAL_LITERAL  */
#line 331 "parser.y"
                   { yyval = makeNode("REAL"); }
#line 1940 "y.tab.c"
    break;

  case 63: /* literal_lexemes: STRING_LITERAL  */
#line 332 "parser.y"
                     { yyval = makeNode("STRING"); }
#line 1946 "y.tab.c"
    break;

  case 64: /* literal_lexemes: id  */
#line 333 "parser.y"
         { yyval = yyvsp[0]; }
#line 1952 "y.tab.c"
    break;

  case 65: /* variable_declarations: variable_declare  */
#line 338 "parser.y"
    {
        yyval = makeNode("variable_declarations");
        addNode(&yyval, yyvsp[0]);
    }
#line 1961 "y.tab.c"
    break;

  case 66: /* variable_declarations: variable_declarations variable_declare  */
#line 343 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 1969 "y.tab.c"
    break;

  case 67: /* variable_declare: VAR variable_list COLON type SEMICOLON  */
#line 349 "parser.y"
    {
        addNode(&yyvsp[-1], yyvsp[-3]);
        yyval = yyvsp[-1];
    }
#line 1978 "y.tab.c"
    break;

  case 68: /* variable_list_helper: id  */
#line 357 "parser.y"
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, yyvsp[0]);
    }
#line 1987 "y.tab.c"
    break;

  case 69: /* variable_list_helper: id ASSIGNMENT literal_lexemes  */
#line 362 "parser.y"
    {
        // Creating the equal node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, yyvsp[-2]);
        addNode(&temp_assinment_node, yyvsp[0]);
        yyval = temp_assinment_node;
    }
#line 1999 "y.tab.c"
    break;

  case 70: /* variable_list: variable_list_helper  */
#line 372 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 2008 "y.tab.c"
    break;

  case 71: /* variable_list: variable_list COMMA variable_list_helper  */
#line 377 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 2016 "y.tab.c"
    break;

  case 72: /* expression: operator expression  */
#line 389 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2026 "y.tab.c"
    break;

  case 73: /* expression: expression operator expression  */
#line 395 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[-2]);
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2037 "y.tab.c"
    break;

  case 74: /* expression: literal_lexemes  */
#line 401 "parser.y"
                        { yyval = yyvsp[0];}
#line 2043 "y.tab.c"
    break;

  case 75: /* operator: AND  */
#line 404 "parser.y"
        { yyval = makeNode("&&"); }
#line 2049 "y.tab.c"
    break;

  case 76: /* operator: DIVIDE  */
#line 405 "parser.y"
             { yyval = makeNode("/"); }
#line 2055 "y.tab.c"
    break;

  case 77: /* operator: EQUALS  */
#line 406 "parser.y"
             { yyval = makeNode("=="); }
#line 2061 "y.tab.c"
    break;

  case 78: /* operator: GREATER_THAN  */
#line 407 "parser.y"
                   { yyval = makeNode(">"); }
#line 2067 "y.tab.c"
    break;

  case 79: /* operator: GREATER_EQUALS  */
#line 408 "parser.y"
                     { yyval = makeNode(">="); }
#line 2073 "y.tab.c"
    break;

  case 80: /* operator: LOWER_THAN  */
#line 409 "parser.y"
                 { yyval = makeNode("<"); }
#line 2079 "y.tab.c"
    break;

  case 81: /* operator: LOWER_EQUALS  */
#line 410 "parser.y"
                   { yyval = makeNode("<="); }
#line 2085 "y.tab.c"
    break;

  case 82: /* operator: SUBSTRACT  */
#line 411 "parser.y"
                { yyval = makeNode("-"); }
#line 2091 "y.tab.c"
    break;

  case 83: /* operator: NOT  */
#line 412 "parser.y"
          { yyval = makeNode("!"); }
#line 2097 "y.tab.c"
    break;

  case 84: /* operator: NOT_EQUALS  */
#line 413 "parser.y"
                 { yyval = makeNode("!="); }
#line 2103 "y.tab.c"
    break;

  case 85: /* operator: OR  */
#line 414 "parser.y"
         { yyval = makeNode("||"); }
#line 2109 "y.tab.c"
    break;

  case 86: /* operator: ADD  */
#line 415 "parser.y"
          { yyval = makeNode("+"); }
#line 2115 "y.tab.c"
    break;

  case 87: /* operator: MULTIPLY  */
#line 416 "parser.y"
               { yyval = makeNode("*"); }
#line 2121 "y.tab.c"
    break;


#line 2125 "y.tab.c"

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

#line 418 "parser.y"


#include "lex.yy.c"
int main()
{
    return yyparse();
}

int yyerror() 
{ 
    printf("YOUR ERROR pisher!\n");
    return 0; 
}

void printArgsList(node** argsList, int argCount) {
    if (argCount == 0) {
        printf("No arguments\n");
        return;
    }
    printf("Arguments:\n");
    for (int i = 0; i < argCount; i++) {
        printf("arg%d: %s\n", i+1, argsList[i]->token);
    }
}

node *makeNode(char *token)
{
    node *newnode = (node*)malloc(sizeof(node));
    char *newstr = (char*)malloc(strlen(token) + 1);
    strcpy(newstr, token);
    newnode->token = newstr;
    newnode->count = 0;
    newnode->nodes = NULL;
    return newnode;
}

void addNode(node **father, node *descendant)
{
    (*father)->nodes = (node**) realloc((*father)->nodes, ((*father)->count + 1) * sizeof(node*));
    (*father)->nodes[(*father)->count++] = descendant;
}

void addElement(node ***list, node *element, int size) {
    *list = (node**) realloc(*list, (size+1) * sizeof(node*));
    (*list)[size] = element;
}

void printtree(node* tree, int tab) {
    int i;
    char* token = tree->token;

    if (*token) {
        for (i = 0; i < tab; i++) {
            printf("\t");
        }
        printf("(%s\n", token);
    }
    else
        tab -= 1;
    if (tree->nodes) {
        for (int j = 0; j < tree->count; j++) {
            printtree(tree->nodes[j], tab + 1);
        }
    }
    for (i = 0; i < tab; i++) {
        printf("\t");
    }
    if (*token)
        printf(")\n");
}
