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
  YYSYMBOL_functions = 59,                 /* functions  */
  YYSYMBOL_function = 60,                  /* function  */
  YYSYMBOL_procedure = 61,                 /* procedure  */
  YYSYMBOL_args = 62,                      /* args  */
  YYSYMBOL_args_list = 63,                 /* args_list  */
  YYSYMBOL_parameters_list = 64,           /* parameters_list  */
  YYSYMBOL_body = 65,                      /* body  */
  YYSYMBOL_body_after_functions_declared = 66, /* body_after_functions_declared  */
  YYSYMBOL_body_after_delarations = 67,    /* body_after_delarations  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_assignment_statement = 69,      /* assignment_statement  */
  YYSYMBOL_lhs = 70,                       /* lhs  */
  YYSYMBOL_function_call_statement = 71,   /* function_call_statement  */
  YYSYMBOL_function_parms = 72,            /* function_parms  */
  YYSYMBOL_if_statement = 73,              /* if_statement  */
  YYSYMBOL_if_else_statement = 74,         /* if_else_statement  */
  YYSYMBOL_while_statement = 75,           /* while_statement  */
  YYSYMBOL_do_while_statement = 76,        /* do_while_statement  */
  YYSYMBOL_for_statement = 77,             /* for_statement  */
  YYSYMBOL_code_block_statement = 78,      /* code_block_statement  */
  YYSYMBOL_return_statement = 79,          /* return_statement  */
  YYSYMBOL_type = 80,                      /* type  */
  YYSYMBOL_id = 81,                        /* id  */
  YYSYMBOL_integer_literal = 82,           /* integer_literal  */
  YYSYMBOL_bool__literal = 83,             /* bool__literal  */
  YYSYMBOL_literal_lexemes = 84,           /* literal_lexemes  */
  YYSYMBOL_variable_declarations = 85,     /* variable_declarations  */
  YYSYMBOL_variable_declare = 86,          /* variable_declare  */
  YYSYMBOL_var_declare = 87,               /* var_declare  */
  YYSYMBOL_variable_list = 88,             /* variable_list  */
  YYSYMBOL_variable_list_helper = 89,      /* variable_list_helper  */
  YYSYMBOL_string_declare = 90,            /* string_declare  */
  YYSYMBOL_string_list = 91,               /* string_list  */
  YYSYMBOL_string_list_helper = 92,        /* string_list_helper  */
  YYSYMBOL_expression = 93,                /* expression  */
  YYSYMBOL_operator = 94                   /* operator  */
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
#define YYFINAL  21
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

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
       0,    55,    55,    57,    59,    59,    59,    62,    76,    91,
     101,   106,   117,   130,   135,   143,   150,   156,   160,   166,
     170,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     189,   197,   206,   211,   217,   224,   225,   229,   238,   248,
     257,   266,   272,   277,   283,   291,   292,   293,   294,   295,
     296,   297,   301,   306,   307,   311,   312,   316,   317,   318,
     319,   320,   321,   325,   330,   336,   337,   340,   348,   353,
     359,   364,   374,   382,   387,   393,   401,   415,   421,   428,
     431,   432,   433,   434,   435,   436,   437,   438,   439,   440,
     441,   442,   443
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
  "$accept", "s", "code", "functions", "function", "procedure", "args",
  "args_list", "parameters_list", "body", "body_after_functions_declared",
  "body_after_delarations", "statements", "assignment_statement", "lhs",
  "function_call_statement", "function_parms", "if_statement",
  "if_else_statement", "while_statement", "do_while_statement",
  "for_statement", "code_block_statement", "return_statement", "type",
  "id", "integer_literal", "bool__literal", "literal_lexemes",
  "variable_declarations", "variable_declare", "var_declare",
  "variable_list", "variable_list_helper", "string_declare", "string_list",
  "string_list_helper", "expression", "operator", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-106)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-18)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      36,   -25,   -25,   -25,    23,  -106,  -106,  -106,  -106,    15,
    -106,  -106,  -106,  -106,   -12,    -2,  -106,     5,    37,    17,
    -106,  -106,  -106,   332,  -106,   -25,    30,   196,   180,   -25,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,   146,   332,  -106,   -25,    14,    13,
    -106,  -106,  -106,  -106,  -106,  -106,  -106,  -106,    21,  -106,
      51,   332,   394,    25,  -106,    32,    57,  -106,   196,   394,
     180,   -25,   396,   -25,  -106,  -106,  -106,    29,    33,    26,
      20,    20,   180,    34,    35,   147,    39,   332,    -3,    20,
      41,  -106,   147,  -106,  -106,    60,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,    31,     7,    42,  -106,   332,   332,
      74,   -25,   263,  -106,    44,    15,  -106,  -106,  -106,   354,
     332,  -106,   191,   220,    47,   332,    72,  -106,  -106,    53,
      54,   286,   177,   147,   147,   332,   309,   354,  -106,   332,
    -106,  -106,    92,  -106,   234,   -25,   -22,   394,   147,    61,
      83,   332,    62,  -106,  -106,   332,   394,  -106,   249,   147,
    -106
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     3,     4,     5,     6,
      63,    65,    66,    52,     0,     0,    73,     0,    70,     0,
      68,     1,    64,     0,    72,     0,    10,     0,     0,     0,
      80,    82,    83,    84,    85,    86,    88,    89,    90,    87,
      91,    92,    81,    56,    55,    58,    53,    54,    60,    61,
      62,    59,    57,    79,     0,     0,    74,     0,     0,     9,
      71,    45,    46,    47,    48,    51,    49,    50,     0,    69,
      75,     0,    77,     0,    13,     0,     0,    67,     0,    78,
       0,     0,     0,     0,    76,    11,    14,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    16,    18,    19,    21,     0,    22,    23,    24,    25,
      26,    27,    28,    29,    33,     6,     0,    12,     0,     0,
       0,     0,     0,    43,     0,    17,    15,     8,    20,     0,
       0,     7,     0,     0,     0,     0,     0,    44,    42,    61,
      62,     0,     0,     0,     0,     0,     0,     0,    31,     0,
      30,    32,    37,    39,     0,     0,     0,    35,     0,     0,
       0,     0,     0,    38,    40,     0,    36,    34,     0,     0,
      41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,  -106,  -106,   110,  -106,  -106,  -106,  -106,    43,   -70,
      18,  -106,   -92,    -8,  -105,  -106,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,  -106,   -62,    -1,  -106,  -106,   -19,     6,
      -4,  -106,  -106,    86,  -106,  -106,    93,   -16,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,    99,     7,     8,    58,    59,    73,   100,
     101,   102,   103,   104,   105,   106,   156,   107,   108,   109,
     110,   111,   112,   113,    68,    50,    51,    52,    53,   115,
      10,    11,    19,    20,    12,    15,    16,   141,    55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    17,    18,   120,     1,    22,     9,    54,    60,    93,
     128,    94,    95,    96,     1,     3,   136,    97,    85,    13,
      88,   116,     1,    21,    14,     3,   161,     1,    18,   126,
     117,   162,    93,     3,    94,    95,    96,     2,     3,    72,
      97,    13,    23,     1,    71,    24,    25,    98,   123,    57,
     160,   152,   153,     2,     3,    79,    74,    26,   -17,    84,
      76,    27,    71,    28,    13,    29,   163,    75,    77,    71,
      98,    80,    92,    81,    81,    78,    83,   170,    82,    90,
      86,   122,    74,    91,   129,   130,   118,   119,   134,   114,
     114,   121,   127,   131,   114,   138,   147,   114,   114,   145,
     148,   114,   132,   133,   125,   158,   149,   165,   164,   167,
       6,    22,    71,   135,   142,    69,   124,     0,    56,   146,
     114,    22,    71,    71,     0,     0,    89,     0,   140,   154,
       0,    71,    71,   157,     0,     0,    71,     0,     0,     0,
       0,     0,   114,   114,    71,   166,     0,    71,     0,   168,
       0,     0,     0,     0,   114,     0,    71,   114,    71,    93,
       0,    94,    95,    96,     0,     0,     0,    97,   114,    30,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    61,    62,    63,    64,     0,    65,    66,
      67,    13,     0,     0,     0,     0,     0,    98,     0,     0,
      30,    70,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    30,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,     0,     0,
       0,     0,   151,    43,    44,    45,    46,    47,    48,    49,
      13,     0,     0,    30,   143,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,    30,   144,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    30,   159,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
       0,     0,   169,     0,     0,     0,     0,     0,     0,    30,
     137,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,   150,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    30,   155,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    13,    30,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,   139,    13,    61,
      62,    63,    64,     0,    65,    66,    67,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    30,    87,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42
};

static const yytype_int16 yycheck[] =
{
       1,     2,     3,    95,     7,     9,     0,    23,    27,    12,
     102,    14,    15,    16,     7,    18,   121,    20,    80,    44,
      82,    91,     7,     0,    25,    18,    48,     7,    29,    99,
      92,    53,    12,    18,    14,    15,    16,    17,    18,    55,
      20,    44,    54,     7,    54,    47,    48,    50,    51,    19,
     155,   143,   144,    17,    18,    71,    57,    52,    51,    78,
      47,    24,    72,    46,    44,    48,   158,    53,    47,    79,
      50,    46,    46,    48,    48,    24,    19,   169,    46,    50,
      81,    97,    83,    50,    24,    54,    52,    52,    14,    90,
      91,    52,    51,    51,    95,    51,    24,    98,    99,    52,
      47,   102,   118,   119,    98,    13,    52,    24,    47,    47,
       0,   115,   122,   121,   130,    29,    98,    -1,    25,   135,
     121,   125,   132,   133,    -1,    -1,    83,    -1,   129,   145,
      -1,   141,   142,   149,    -1,    -1,   146,    -1,    -1,    -1,
      -1,    -1,   143,   144,   154,   161,    -1,   157,    -1,   165,
      -1,    -1,    -1,    -1,   155,    -1,   166,   158,   168,    12,
      -1,    14,    15,    16,    -1,    -1,    -1,    20,   169,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,     3,     4,     5,     6,    -1,     8,     9,
      10,    44,    -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,
      23,    55,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    23,    -1,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    55,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    23,    53,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    -1,    23,    53,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    23,    53,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    53,    -1,    -1,    -1,    -1,    -1,    -1,    23,
      47,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    23,    47,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    23,    47,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    23,    -1,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,     3,
       4,     5,     6,    -1,     8,     9,    10,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    23,    22,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,    17,    18,    57,    58,    59,    60,    61,    85,
      86,    87,    90,    44,    81,    91,    92,    81,    81,    88,
      89,     0,    86,    54,    47,    48,    52,    24,    46,    48,
      23,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      81,    82,    83,    84,    93,    94,    92,    19,    62,    63,
      84,     3,     4,     5,     6,     8,     9,    10,    80,    89,
      55,    94,    93,    64,    81,    53,    47,    47,    24,    93,
      46,    48,    46,    19,    84,    80,    81,    22,    80,    64,
      50,    50,    46,    12,    14,    15,    16,    20,    50,    59,
      65,    66,    67,    68,    69,    70,    71,    73,    74,    75,
      76,    77,    78,    79,    81,    85,    65,    80,    52,    52,
      68,    52,    93,    51,    66,    85,    65,    51,    68,    24,
      54,    51,    93,    93,    14,    69,    70,    47,    51,    43,
      81,    93,    93,    53,    53,    52,    93,    24,    47,    52,
      47,    55,    68,    68,    93,    47,    72,    93,    13,    53,
      70,    48,    53,    68,    47,    24,    93,    47,    93,    53,
      68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    59,    59,    59,    60,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      69,    69,    70,    70,    71,    72,    72,    73,    74,    75,
      76,    77,    78,    78,    79,    80,    80,    80,    80,    80,
      80,    80,    81,    82,    82,    83,    83,    84,    84,    84,
      84,    84,    84,    85,    85,    86,    86,    87,    88,    88,
      89,    89,    90,    91,    91,    92,    92,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,    10,    10,     1,
       0,     4,     6,     1,     3,     2,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     1,     7,     1,     3,     5,     7,     5,
       7,    10,     3,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     5,     1,     3,
       1,     3,     3,     1,     3,     4,     6,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 1521 "y.tab.c"
    break;

  case 3: /* code: functions  */
#line 57 "parser.y"
                { yyval = makeNode("CODE"); addNode(&yyval, yyvsp[0]); }
#line 1527 "y.tab.c"
    break;

  case 7: /* function: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
#line 63 "parser.y"
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
#line 1544 "y.tab.c"
    break;

  case 8: /* procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
#line 77 "parser.y"
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
#line 1560 "y.tab.c"
    break;

  case 9: /* args: args_list  */
#line 92 "parser.y"
    {
        node* temp = makeNode("ARGS");
        temp->nodes = argsList;
        temp->count = counter_argsList;
        yyval = temp;
        argsList = NULL;
        counter_argsList=0;
    }
#line 1573 "y.tab.c"
    break;

  case 10: /* args: %empty  */
#line 101 "parser.y"
    {
        yyval = makeNode("ARGS NONE");
    }
#line 1581 "y.tab.c"
    break;

  case 11: /* args_list: ARG_ARROW parameters_list COLON type  */
#line 107 "parser.y"
    {
        yyvsp[0]->nodes = parList;
        yyvsp[0]->count = counter_parlist;
        addElement(&argsList, yyvsp[0], counter_argsList);
        counter_argsList++;
        
        // Resetting
        parList = NULL;
        counter_parlist = 0;
    }
#line 1596 "y.tab.c"
    break;

  case 12: /* args_list: args_list SEMICOLON ARG_ARROW parameters_list COLON type  */
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
#line 1611 "y.tab.c"
    break;

  case 13: /* parameters_list: id  */
#line 131 "parser.y"
    {
        addElement(&parList, yyvsp[0], counter_parlist);
        counter_parlist++;
    }
#line 1620 "y.tab.c"
    break;

  case 14: /* parameters_list: parameters_list COMMA id  */
#line 136 "parser.y"
    {
        addElement(&parList, yyvsp[0], counter_parlist);
        counter_parlist++;
    }
#line 1629 "y.tab.c"
    break;

  case 15: /* body: functions body  */
#line 144 "parser.y"
    {
        node* body_node = makeNode("BODY");
        addNode(&body_node, yyvsp[-1]);
        addNode(&body_node, yyvsp[0]);
        yyval = body_node;
    }
#line 1640 "y.tab.c"
    break;

  case 16: /* body: body_after_functions_declared  */
#line 151 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1648 "y.tab.c"
    break;

  case 17: /* body_after_functions_declared: variable_declarations  */
#line 157 "parser.y"
    {

    }
#line 1656 "y.tab.c"
    break;

  case 18: /* body_after_functions_declared: body_after_delarations  */
#line 161 "parser.y"
    {
       yyval = yyvsp[0];
    }
#line 1664 "y.tab.c"
    break;

  case 19: /* body_after_delarations: statements  */
#line 167 "parser.y"
    {
       yyval = yyvsp[0];
    }
#line 1672 "y.tab.c"
    break;

  case 20: /* body_after_delarations: body_after_delarations statements  */
#line 171 "parser.y"
    {
       addNode(&yyval,yyvsp[0]);
    }
#line 1680 "y.tab.c"
    break;

  case 21: /* statements: assignment_statement  */
#line 177 "parser.y"
                         { yyval = yyvsp[0];}
#line 1686 "y.tab.c"
    break;

  case 22: /* statements: function_call_statement  */
#line 178 "parser.y"
                              { yyval = yyvsp[0]; }
#line 1692 "y.tab.c"
    break;

  case 23: /* statements: if_statement  */
#line 179 "parser.y"
                   { yyval = yyvsp[0]; }
#line 1698 "y.tab.c"
    break;

  case 24: /* statements: if_else_statement  */
#line 180 "parser.y"
                        { yyval = yyvsp[0]; }
#line 1704 "y.tab.c"
    break;

  case 25: /* statements: while_statement  */
#line 181 "parser.y"
                      { yyval = yyvsp[0]; }
#line 1710 "y.tab.c"
    break;

  case 26: /* statements: do_while_statement  */
#line 182 "parser.y"
                         { yyval = yyvsp[0]; }
#line 1716 "y.tab.c"
    break;

  case 27: /* statements: for_statement  */
#line 183 "parser.y"
                    { yyval = yyvsp[0]; }
#line 1722 "y.tab.c"
    break;

  case 28: /* statements: code_block_statement  */
#line 184 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1728 "y.tab.c"
    break;

  case 29: /* statements: return_statement  */
#line 185 "parser.y"
                       { yyval = yyvsp[0]; }
#line 1734 "y.tab.c"
    break;

  case 30: /* assignment_statement: lhs ASSIGNMENT expression SEMICOLON  */
#line 190 "parser.y"
    {
        node *assignment_node = makeNode("=");
        addNode(&assignment_node, yyvsp[-3]);
        addNode(&assignment_node, yyvsp[-1]);
        yyval = assignment_node;

    }
#line 1746 "y.tab.c"
    break;

  case 31: /* assignment_statement: lhs ASSIGNMENT STRING_LITERAL SEMICOLON  */
#line 198 "parser.y"
    {
        node* assignment_node = makeNode("=");
        addNode(&assignment_node,yyvsp[-3]);
        addNode(&assignment_node,yyvsp[-1]);
        yyval = assignment_node; 
    }
#line 1757 "y.tab.c"
    break;

  case 32: /* lhs: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS  */
#line 207 "parser.y"
    {
        yyval = yyvsp[-3];
        addNode(&yyval,yyvsp[-1]); //TO CHECK!!
    }
#line 1766 "y.tab.c"
    break;

  case 33: /* lhs: id  */
#line 212 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1774 "y.tab.c"
    break;

  case 34: /* function_call_statement: lhs ASSIGNMENT id START_ROUND_BRACKETS function_parms END_ROUND_BRACKETS SEMICOLON  */
#line 218 "parser.y"
    {
        //ADD
    }
#line 1782 "y.tab.c"
    break;

  case 37: /* if_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 230 "parser.y"
    {
        node* if_node = makeNode("IF");
        addNode(&if_node, yyvsp[-2]);
        addNode(&if_node, yyvsp[0]);
        yyval = if_node;
    }
#line 1793 "y.tab.c"
    break;

  case 38: /* if_else_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements  */
#line 239 "parser.y"
    {
        node* if_else_node = makeNode("IF-ELSE");
        addNode(&if_else_node, yyvsp[-4]);
        addNode(&if_else_node, yyvsp[-2]);
        addNode(&if_else_node, yyvsp[0]);
        yyval = if_else_node;
    }
#line 1805 "y.tab.c"
    break;

  case 39: /* while_statement: WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 249 "parser.y"
    {
        node* while_node = makeNode("WHILE");
        addNode(&while_node, yyvsp[-2]);
        addNode(&while_node, yyvsp[0]);
        yyval = while_node;
    }
#line 1816 "y.tab.c"
    break;

  case 40: /* do_while_statement: DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON  */
#line 258 "parser.y"
    {
        node* do_while_node = makeNode("DO-WHILE");
        addNode(&do_while_node, yyvsp[-5]);
        addNode(&do_while_node, yyvsp[-2]);
        yyval = do_while_node;
    }
#line 1827 "y.tab.c"
    break;

  case 41: /* for_statement: FOR START_ROUND_BRACKETS assignment_statement expression SEMICOLON lhs ASSIGNMENT expression END_ROUND_BRACKETS statements  */
#line 267 "parser.y"
    {
        //NeEd tO FIX SPEAK TO איילון 
    }
#line 1835 "y.tab.c"
    break;

  case 42: /* code_block_statement: START_CURLY_BRACKETS body_after_functions_declared END_CURLY_BRACKETS  */
#line 273 "parser.y"
    {
        yyval = makeNode("BLOCK");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1844 "y.tab.c"
    break;

  case 43: /* code_block_statement: START_CURLY_BRACKETS END_CURLY_BRACKETS  */
#line 278 "parser.y"
    {
        yyval = makeNode("BLOCK");
    }
#line 1852 "y.tab.c"
    break;

  case 44: /* return_statement: RETURN expression SEMICOLON  */
#line 284 "parser.y"
    {
        yyval = makeNode("RET");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1861 "y.tab.c"
    break;

  case 45: /* type: BOOL  */
#line 291 "parser.y"
         { yyval = makeNode("BOOL"); }
#line 1867 "y.tab.c"
    break;

  case 46: /* type: CHAR  */
#line 292 "parser.y"
           { yyval = makeNode("CHAR"); }
#line 1873 "y.tab.c"
    break;

  case 47: /* type: INT  */
#line 293 "parser.y"
          { yyval = makeNode("INT"); }
#line 1879 "y.tab.c"
    break;

  case 48: /* type: REAL  */
#line 294 "parser.y"
           { yyval = makeNode("REAL"); }
#line 1885 "y.tab.c"
    break;

  case 49: /* type: CHAR_POINTER  */
#line 295 "parser.y"
                   { yyval = makeNode("CHAR_POINTER"); }
#line 1891 "y.tab.c"
    break;

  case 50: /* type: REAL_POINTER  */
#line 296 "parser.y"
                   { yyval = makeNode("REAL_POINTER"); }
#line 1897 "y.tab.c"
    break;

  case 51: /* type: INT_POINTER  */
#line 297 "parser.y"
                  { yyval = makeNode("INT_POINTER"); }
#line 1903 "y.tab.c"
    break;

  case 52: /* id: IDENTIFIER  */
#line 301 "parser.y"
               {
        yyval = makeNode(yytext);
    }
#line 1911 "y.tab.c"
    break;

  case 53: /* integer_literal: INTEGER_LITERAL  */
#line 306 "parser.y"
                    { yyval = makeNode("INT");}
#line 1917 "y.tab.c"
    break;

  case 54: /* integer_literal: INTEGER_LITERAL_HEX  */
#line 307 "parser.y"
                          { yyval = makeNode("INT");}
#line 1923 "y.tab.c"
    break;

  case 55: /* bool__literal: FALSE  */
#line 311 "parser.y"
          { yyval = makeNode("FALSE");}
#line 1929 "y.tab.c"
    break;

  case 56: /* bool__literal: TRUE  */
#line 312 "parser.y"
           { yyval = makeNode("TRUE");}
#line 1935 "y.tab.c"
    break;

  case 57: /* literal_lexemes: bool__literal  */
#line 316 "parser.y"
                  { yyval = yyvsp[0]; }
#line 1941 "y.tab.c"
    break;

  case 58: /* literal_lexemes: CHAR_LITERAL  */
#line 317 "parser.y"
                   { yyval = makeNode("CHAR");}
#line 1947 "y.tab.c"
    break;

  case 59: /* literal_lexemes: integer_literal  */
#line 318 "parser.y"
                      { yyval = yyvsp[0];}
#line 1953 "y.tab.c"
    break;

  case 60: /* literal_lexemes: REAL_LITERAL  */
#line 319 "parser.y"
                   { yyval = makeNode("REAL"); }
#line 1959 "y.tab.c"
    break;

  case 61: /* literal_lexemes: STRING_LITERAL  */
#line 320 "parser.y"
                     { yyval = makeNode("STRING"); }
#line 1965 "y.tab.c"
    break;

  case 62: /* literal_lexemes: id  */
#line 321 "parser.y"
         { yyval = yyvsp[0]; }
#line 1971 "y.tab.c"
    break;

  case 63: /* variable_declarations: variable_declare  */
#line 326 "parser.y"
    {
        yyval = makeNode("variable_declarations");
        addNode(&yyval, yyvsp[0]);
    }
#line 1980 "y.tab.c"
    break;

  case 64: /* variable_declarations: variable_declarations variable_declare  */
#line 331 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 1988 "y.tab.c"
    break;

  case 67: /* var_declare: VAR variable_list COLON type SEMICOLON  */
#line 341 "parser.y"
    {
        addNode(&yyvsp[-1], yyvsp[-3]);
        yyval = yyvsp[-1];
    }
#line 1997 "y.tab.c"
    break;

  case 68: /* variable_list: variable_list_helper  */
#line 349 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 2006 "y.tab.c"
    break;

  case 69: /* variable_list: variable_list COMMA variable_list_helper  */
#line 354 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 2014 "y.tab.c"
    break;

  case 70: /* variable_list_helper: id  */
#line 360 "parser.y"
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, yyvsp[0]);
    }
#line 2023 "y.tab.c"
    break;

  case 71: /* variable_list_helper: id ASSIGNMENT literal_lexemes  */
#line 365 "parser.y"
    {
        // Creating the ASSIGNMENT node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, yyvsp[-2]);
        addNode(&temp_assinment_node, yyvsp[0]);
        yyval = temp_assinment_node;
    }
#line 2035 "y.tab.c"
    break;

  case 72: /* string_declare: STRING string_list SEMICOLON  */
#line 375 "parser.y"
    {
        node* string_node = makeNode("STRING");
        addNode(&string_node,yyvsp[-1]);
        yyval = string_node;
    }
#line 2045 "y.tab.c"
    break;

  case 73: /* string_list: string_list_helper  */
#line 383 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 2054 "y.tab.c"
    break;

  case 74: /* string_list: string_list COMMA string_list_helper  */
#line 388 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 2062 "y.tab.c"
    break;

  case 75: /* string_list_helper: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS  */
#line 394 "parser.y"
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, yyvsp[-3]); 
        node* lenght_node = makeNode("LENGTH");
        addNode(&lenght_node, yyvsp[-1]);
        addNode(&yyval, lenght_node);
    }
#line 2074 "y.tab.c"
    break;

  case 76: /* string_list_helper: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS ASSIGNMENT literal_lexemes  */
#line 402 "parser.y"
    {
        // Creating the ASSIGNMENT node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, yyvsp[-5]);
        node* lenght_node = makeNode("LENGTH");
        addNode(&lenght_node, yyvsp[-3]);
        addNode(&yyval, lenght_node);
        addNode(&temp_assinment_node, yyvsp[0]);
        yyval = temp_assinment_node;
    }
#line 2089 "y.tab.c"
    break;

  case 77: /* expression: operator expression  */
#line 416 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2099 "y.tab.c"
    break;

  case 78: /* expression: expression operator expression  */
#line 422 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[-2]);
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2110 "y.tab.c"
    break;

  case 79: /* expression: literal_lexemes  */
#line 428 "parser.y"
                        { yyval = yyvsp[0];}
#line 2116 "y.tab.c"
    break;

  case 80: /* operator: AND  */
#line 431 "parser.y"
        { yyval = makeNode("&&"); }
#line 2122 "y.tab.c"
    break;

  case 81: /* operator: DIVIDE  */
#line 432 "parser.y"
             { yyval = makeNode("/"); }
#line 2128 "y.tab.c"
    break;

  case 82: /* operator: EQUALS  */
#line 433 "parser.y"
             { yyval = makeNode("=="); }
#line 2134 "y.tab.c"
    break;

  case 83: /* operator: GREATER_THAN  */
#line 434 "parser.y"
                   { yyval = makeNode(">"); }
#line 2140 "y.tab.c"
    break;

  case 84: /* operator: GREATER_EQUALS  */
#line 435 "parser.y"
                     { yyval = makeNode(">="); }
#line 2146 "y.tab.c"
    break;

  case 85: /* operator: LOWER_THAN  */
#line 436 "parser.y"
                 { yyval = makeNode("<"); }
#line 2152 "y.tab.c"
    break;

  case 86: /* operator: LOWER_EQUALS  */
#line 437 "parser.y"
                   { yyval = makeNode("<="); }
#line 2158 "y.tab.c"
    break;

  case 87: /* operator: SUBSTRACT  */
#line 438 "parser.y"
                { yyval = makeNode("-"); }
#line 2164 "y.tab.c"
    break;

  case 88: /* operator: NOT  */
#line 439 "parser.y"
          { yyval = makeNode("!"); }
#line 2170 "y.tab.c"
    break;

  case 89: /* operator: NOT_EQUALS  */
#line 440 "parser.y"
                 { yyval = makeNode("!="); }
#line 2176 "y.tab.c"
    break;

  case 90: /* operator: OR  */
#line 441 "parser.y"
         { yyval = makeNode("||"); }
#line 2182 "y.tab.c"
    break;

  case 91: /* operator: ADD  */
#line 442 "parser.y"
          { yyval = makeNode("+"); }
#line 2188 "y.tab.c"
    break;

  case 92: /* operator: MULTIPLY  */
#line 443 "parser.y"
               { yyval = makeNode("*"); }
#line 2194 "y.tab.c"
    break;


#line 2198 "y.tab.c"

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

#line 445 "parser.y"


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
        for (i = 0; i < tab-1; i++) {
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
