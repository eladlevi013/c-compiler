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
  YYSYMBOL_arg_declare = 63,               /* arg_declare  */
  YYSYMBOL_args_list = 64,                 /* args_list  */
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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

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
       0,    55,    55,    57,    57,    59,    59,    59,    62,    76,
      91,    96,   101,   106,   113,   118,   125,   132,   138,   142,
     148,   152,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   171,   179,   188,   193,   199,   206,   207,   211,   220,
     230,   239,   248,   254,   259,   265,   273,   274,   275,   276,
     277,   278,   279,   283,   288,   289,   293,   294,   298,   299,
     300,   301,   302,   303,   307,   312,   318,   319,   322,   330,
     335,   341,   346,   356,   364,   369,   375,   383,   397,   403,
     410,   413,   414,   415,   416,   417,   418,   419,   420,   421,
     422,   423,   424,   425
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
  "arg_declare", "args_list", "body", "body_after_functions_declared",
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

#define YYPACT_NINF (-115)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -7,   -18,   -18,    29,  -115,  -115,  -115,  -115,   -31,  -115,
    -115,   -15,     6,  -115,  -115,    22,    22,   310,   -18,  -115,
     -40,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
       9,   136,    -2,     3,   107,   107,   -18,     4,    17,    16,
      18,   -18,   299,     7,   107,   -31,    21,  -115,    16,  -115,
    -115,    43,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
      14,     2,  -115,  -115,  -115,    24,    19,    15,  -115,   299,
     299,    62,   -18,    58,    13,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
     230,   299,  -115,    32,  -115,  -115,  -115,   321,   299,  -115,
    -115,   299,  -115,   -18,   172,   186,    34,   299,    64,   254,
     310,   -18,  -115,   299,   343,  -115,    42,    39,   253,   141,
     155,  -115,    16,    16,   299,   276,   321,  -115,    47,  -115,
     343,  -115,   299,  -115,  -115,    73,    87,  -115,   201,   -18,
    -115,    -4,   343,   254,    16,    54,    79,   299,    57,  -115,
    -115,  -115,   299,   343,  -115,   215,    16,  -115
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      12,     0,     0,     0,     2,     3,     5,     6,     4,    10,
      53,     0,     0,    14,     1,     0,    12,     0,     0,    11,
       0,    46,    47,    48,    49,    52,    50,    51,    13,    15,
       0,     0,     0,     0,    12,    12,     0,     0,     0,     0,
       0,     0,     0,     0,    12,     7,     0,    17,    19,    20,
      22,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      34,    18,    64,    66,    67,     0,     0,     0,    74,     0,
       0,     0,     0,    71,     0,    69,    81,    83,    84,    85,
      86,    87,    89,    90,    91,    88,    92,    93,    82,    57,
      56,    59,    54,    55,    61,    62,    63,    60,    58,    80,
       0,     0,    44,     0,    16,     9,    21,     0,     0,    65,
       8,     0,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,    78,    43,    62,    63,     0,     0,
       0,    75,     0,     0,     0,     0,     0,    72,     0,    70,
      79,    32,     0,    31,    33,    76,    38,    40,     0,     0,
      68,     0,    36,     0,     0,     0,     0,     0,     0,    77,
      39,    41,     0,    37,    35,     0,     0,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,  -115,   105,  -115,  -115,     8,    92,  -115,   -29,
      65,  -115,   -37,    37,   -68,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,   -28,    -1,  -115,  -115,  -114,  -115,
      50,  -115,  -115,    -5,  -115,  -115,    23,   -24,   -50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    44,     6,     7,    45,     9,    12,    46,
      47,    48,    49,    50,    51,    52,   151,    53,    54,    55,
      56,    57,    58,    59,    28,    96,    97,    98,    99,    61,
      62,    63,    74,    75,    64,    67,    68,   128,   101
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      11,    13,    71,    33,   118,   137,    65,    15,     8,    36,
       1,   106,     2,    30,    36,   104,    15,    29,   100,    37,
      41,    38,    39,    40,    20,    41,    10,    42,    37,    14,
      38,    39,    40,    60,    60,    66,    42,    16,    60,   159,
      73,     2,    60,    60,   157,   114,   115,    60,    34,   158,
     123,    10,    17,    35,    18,    31,    69,    43,   102,   120,
      10,   121,   112,   113,   123,   123,    43,   107,   108,    70,
      72,    60,   105,   111,   123,   110,   116,   124,   123,   123,
     123,   156,   119,   125,   129,   123,   134,   130,   136,   141,
     123,   142,   138,   135,   150,   146,   147,   153,   123,   140,
     154,   161,   123,   162,   164,     5,   127,    19,   103,   117,
     148,   109,    66,   123,    36,   123,   139,   160,   152,    37,
      73,    38,    39,    40,     1,    41,     2,    42,     0,   167,
       0,    60,    60,   163,     0,     0,   131,     0,   165,    21,
      22,    23,    24,     0,    25,    26,    27,     0,    60,     0,
       0,    10,     0,    60,     0,     0,     0,    43,    32,     0,
       0,     0,     0,     0,    76,    60,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    76,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,    76,   144,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    76,
     145,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,     0,    76,   132,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    76,   133,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,     0,    76,   155,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,   166,     0,
       0,     0,     0,     0,     0,     0,    76,   122,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
       0,    89,    90,    91,    92,    93,    94,    95,    10,    76,
     143,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    21,    22,    23,    24,     0,    25,    26,
      27,     0,    76,   149,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    10,    76,     0,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   126,    10,    76,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88
};

static const yytype_int16 yycheck[] =
{
       1,     2,    39,    31,    72,   119,    35,    47,     0,     7,
      17,    48,    19,    53,     7,    44,    47,    18,    42,    12,
      18,    14,    15,    16,    16,    18,    44,    20,    12,     0,
      14,    15,    16,    34,    35,    36,    20,    52,    39,   153,
      41,    19,    43,    44,    48,    69,    70,    48,    50,    53,
     100,    44,    46,    50,    48,    46,    52,    50,    51,    46,
      44,    48,    47,    48,   114,   115,    50,    24,    54,    52,
      52,    72,    51,    54,   124,    51,    14,   101,   128,   129,
     130,   149,    24,    51,   108,   135,    52,   111,    24,    47,
     140,    52,   120,   117,    47,   132,   133,    24,   148,   123,
      13,    47,   152,    24,    47,     0,   107,    15,    43,    72,
     134,    61,   113,   163,     7,   165,   121,   154,   142,    12,
     121,    14,    15,    16,    17,    18,    19,    20,    -1,   166,
      -1,   132,   133,   157,    -1,    -1,   113,    -1,   162,     3,
       4,     5,     6,    -1,     8,     9,    10,    -1,   149,    -1,
      -1,    44,    -1,   154,    -1,    -1,    -1,    50,    22,    -1,
      -1,    -1,    -1,    -1,    23,   166,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    23,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    23,    55,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    23,
      55,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    -1,    23,    53,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    23,    53,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    23,    53,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    23,    47,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    23,
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
       0,    17,    19,    57,    58,    59,    60,    61,    62,    63,
      44,    81,    64,    81,     0,    47,    52,    46,    48,    63,
      62,     3,     4,     5,     6,     8,     9,    10,    80,    81,
      53,    46,    22,    80,    50,    50,     7,    12,    14,    15,
      16,    18,    20,    50,    59,    62,    65,    66,    67,    68,
      69,    70,    71,    73,    74,    75,    76,    77,    78,    79,
      81,    85,    86,    87,    90,    65,    81,    91,    92,    52,
      52,    68,    52,    81,    88,    89,    23,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    81,    82,    83,    84,
      93,    94,    51,    66,    65,    51,    68,    24,    54,    86,
      51,    54,    47,    48,    93,    93,    14,    69,    70,    24,
      46,    48,    47,    94,    93,    51,    43,    81,    93,    93,
      93,    92,    53,    53,    52,    93,    24,    84,    80,    89,
      93,    47,    52,    47,    55,    55,    68,    68,    93,    47,
      47,    72,    93,    24,    13,    53,    70,    48,    53,    84,
      68,    47,    24,    93,    47,    93,    53,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    59,    60,    61,
      62,    62,    62,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    69,    69,    70,    70,    71,    72,    72,    73,    74,
      75,    76,    77,    78,    78,    79,    80,    80,    80,    80,
      80,    80,    80,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    85,    85,    86,    86,    87,    88,
      88,    89,    89,    90,    91,    91,    92,    92,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,    10,    10,
       1,     3,     0,     4,     1,     3,     2,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     1,     7,     1,     3,     5,     7,
       5,     7,    10,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     5,     1,
       3,     1,     3,     3,     1,     3,     4,     6,     2,     3,
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
  case 2: /* s: code  */
#line 55 "parser.y"
        { printtree(yyvsp[0], 0); }
#line 1506 "y.tab.c"
    break;

  case 4: /* code: args  */
#line 57 "parser.y"
                      { yyval = makeNode("CODE"); addNode(&yyval, yyvsp[0]); }
#line 1512 "y.tab.c"
    break;

  case 8: /* function: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON type START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
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
#line 1529 "y.tab.c"
    break;

  case 9: /* procedure: FUNCTION id START_ROUND_BRACKETS args END_ROUND_BRACKETS COLON VOID START_CURLY_BRACKETS body END_CURLY_BRACKETS  */
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
#line 1545 "y.tab.c"
    break;

  case 10: /* args: arg_declare  */
#line 92 "parser.y"
    {
        yyval = makeNode("ARGS");
        addNode(&yyval,yyvsp[0]);
    }
#line 1554 "y.tab.c"
    break;

  case 11: /* args: args SEMICOLON arg_declare  */
#line 97 "parser.y"
    {
        addNode(&yyval,yyvsp[0]);
    }
#line 1562 "y.tab.c"
    break;

  case 12: /* args: %empty  */
#line 101 "parser.y"
    {
        yyval = makeNode("ARGS NONE");
    }
#line 1570 "y.tab.c"
    break;

  case 13: /* arg_declare: ARG_ARROW args_list COLON type  */
#line 107 "parser.y"
    {
        addNode(&yyvsp[0],yyvsp[-2]);
        yyval = yyvsp[0];
    }
#line 1579 "y.tab.c"
    break;

  case 14: /* args_list: id  */
#line 114 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval,yyvsp[0]);
    }
#line 1588 "y.tab.c"
    break;

  case 15: /* args_list: args_list COMMA id  */
#line 119 "parser.y"
    {
        addNode(&yyval,yyvsp[0]);
    }
#line 1596 "y.tab.c"
    break;

  case 16: /* body: functions body  */
#line 126 "parser.y"
    {
        node* body_node = makeNode("BODY");
        addNode(&body_node, yyvsp[-1]);
        addNode(&body_node, yyvsp[0]);
        yyval = body_node;
    }
#line 1607 "y.tab.c"
    break;

  case 17: /* body: body_after_functions_declared  */
#line 133 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1615 "y.tab.c"
    break;

  case 18: /* body_after_functions_declared: variable_declarations  */
#line 139 "parser.y"
    {

    }
#line 1623 "y.tab.c"
    break;

  case 19: /* body_after_functions_declared: body_after_delarations  */
#line 143 "parser.y"
    {
       yyval = yyvsp[0];
    }
#line 1631 "y.tab.c"
    break;

  case 20: /* body_after_delarations: statements  */
#line 149 "parser.y"
    {
       yyval = yyvsp[0];
    }
#line 1639 "y.tab.c"
    break;

  case 21: /* body_after_delarations: body_after_delarations statements  */
#line 153 "parser.y"
    {
       addNode(&yyval,yyvsp[0]);
    }
#line 1647 "y.tab.c"
    break;

  case 22: /* statements: assignment_statement  */
#line 159 "parser.y"
                         { yyval = yyvsp[0];}
#line 1653 "y.tab.c"
    break;

  case 23: /* statements: function_call_statement  */
#line 160 "parser.y"
                              { yyval = yyvsp[0]; }
#line 1659 "y.tab.c"
    break;

  case 24: /* statements: if_statement  */
#line 161 "parser.y"
                   { yyval = yyvsp[0]; }
#line 1665 "y.tab.c"
    break;

  case 25: /* statements: if_else_statement  */
#line 162 "parser.y"
                        { yyval = yyvsp[0]; }
#line 1671 "y.tab.c"
    break;

  case 26: /* statements: while_statement  */
#line 163 "parser.y"
                      { yyval = yyvsp[0]; }
#line 1677 "y.tab.c"
    break;

  case 27: /* statements: do_while_statement  */
#line 164 "parser.y"
                         { yyval = yyvsp[0]; }
#line 1683 "y.tab.c"
    break;

  case 28: /* statements: for_statement  */
#line 165 "parser.y"
                    { yyval = yyvsp[0]; }
#line 1689 "y.tab.c"
    break;

  case 29: /* statements: code_block_statement  */
#line 166 "parser.y"
                           { yyval = yyvsp[0]; }
#line 1695 "y.tab.c"
    break;

  case 30: /* statements: return_statement  */
#line 167 "parser.y"
                       { yyval = yyvsp[0]; }
#line 1701 "y.tab.c"
    break;

  case 31: /* assignment_statement: lhs ASSIGNMENT expression SEMICOLON  */
#line 172 "parser.y"
    {
        node *assignment_node = makeNode("=");
        addNode(&assignment_node, yyvsp[-3]);
        addNode(&assignment_node, yyvsp[-1]);
        yyval = assignment_node;

    }
#line 1713 "y.tab.c"
    break;

  case 32: /* assignment_statement: lhs ASSIGNMENT STRING_LITERAL SEMICOLON  */
#line 180 "parser.y"
    {
        node* assignment_node = makeNode("=");
        addNode(&assignment_node,yyvsp[-3]);
        addNode(&assignment_node,yyvsp[-1]);
        yyval = assignment_node; 
    }
#line 1724 "y.tab.c"
    break;

  case 33: /* lhs: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS  */
#line 189 "parser.y"
    {
        yyval = yyvsp[-3];
        addNode(&yyval,yyvsp[-1]); //TO CHECK!!
    }
#line 1733 "y.tab.c"
    break;

  case 34: /* lhs: id  */
#line 194 "parser.y"
    {
        yyval = yyvsp[0];
    }
#line 1741 "y.tab.c"
    break;

  case 35: /* function_call_statement: lhs ASSIGNMENT id START_ROUND_BRACKETS function_parms END_ROUND_BRACKETS SEMICOLON  */
#line 200 "parser.y"
    {
        //ADD
    }
#line 1749 "y.tab.c"
    break;

  case 38: /* if_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 212 "parser.y"
    {
        node* if_node = makeNode("IF");
        addNode(&if_node, yyvsp[-2]);
        addNode(&if_node, yyvsp[0]);
        yyval = if_node;
    }
#line 1760 "y.tab.c"
    break;

  case 39: /* if_else_statement: IF START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements ELSE statements  */
#line 221 "parser.y"
    {
        node* if_else_node = makeNode("IF-ELSE");
        addNode(&if_else_node, yyvsp[-4]);
        addNode(&if_else_node, yyvsp[-2]);
        addNode(&if_else_node, yyvsp[0]);
        yyval = if_else_node;
    }
#line 1772 "y.tab.c"
    break;

  case 40: /* while_statement: WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS statements  */
#line 231 "parser.y"
    {
        node* while_node = makeNode("WHILE");
        addNode(&while_node, yyvsp[-2]);
        addNode(&while_node, yyvsp[0]);
        yyval = while_node;
    }
#line 1783 "y.tab.c"
    break;

  case 41: /* do_while_statement: DO statements WHILE START_ROUND_BRACKETS expression END_ROUND_BRACKETS SEMICOLON  */
#line 240 "parser.y"
    {
        node* do_while_node = makeNode("DO-WHILE");
        addNode(&do_while_node, yyvsp[-5]);
        addNode(&do_while_node, yyvsp[-2]);
        yyval = do_while_node;
    }
#line 1794 "y.tab.c"
    break;

  case 42: /* for_statement: FOR START_ROUND_BRACKETS assignment_statement expression SEMICOLON lhs ASSIGNMENT expression END_ROUND_BRACKETS statements  */
#line 249 "parser.y"
    {
        //NeEd tO FIX SPEAK TO איילון 
    }
#line 1802 "y.tab.c"
    break;

  case 43: /* code_block_statement: START_CURLY_BRACKETS body_after_functions_declared END_CURLY_BRACKETS  */
#line 255 "parser.y"
    {
        yyval = makeNode("BLOCK");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1811 "y.tab.c"
    break;

  case 44: /* code_block_statement: START_CURLY_BRACKETS END_CURLY_BRACKETS  */
#line 260 "parser.y"
    {
        yyval = makeNode("BLOCK");
    }
#line 1819 "y.tab.c"
    break;

  case 45: /* return_statement: RETURN expression SEMICOLON  */
#line 266 "parser.y"
    {
        yyval = makeNode("RET");
        addNode(&yyval, yyvsp[-1]);
    }
#line 1828 "y.tab.c"
    break;

  case 46: /* type: BOOL  */
#line 273 "parser.y"
         { yyval = makeNode("BOOL"); }
#line 1834 "y.tab.c"
    break;

  case 47: /* type: CHAR  */
#line 274 "parser.y"
           { yyval = makeNode("CHAR"); }
#line 1840 "y.tab.c"
    break;

  case 48: /* type: INT  */
#line 275 "parser.y"
          { yyval = makeNode("INT"); }
#line 1846 "y.tab.c"
    break;

  case 49: /* type: REAL  */
#line 276 "parser.y"
           { yyval = makeNode("REAL"); }
#line 1852 "y.tab.c"
    break;

  case 50: /* type: CHAR_POINTER  */
#line 277 "parser.y"
                   { yyval = makeNode("CHAR_POINTER"); }
#line 1858 "y.tab.c"
    break;

  case 51: /* type: REAL_POINTER  */
#line 278 "parser.y"
                   { yyval = makeNode("REAL_POINTER"); }
#line 1864 "y.tab.c"
    break;

  case 52: /* type: INT_POINTER  */
#line 279 "parser.y"
                  { yyval = makeNode("INT_POINTER"); }
#line 1870 "y.tab.c"
    break;

  case 53: /* id: IDENTIFIER  */
#line 283 "parser.y"
               {
        yyval = makeNode(yytext);
    }
#line 1878 "y.tab.c"
    break;

  case 54: /* integer_literal: INTEGER_LITERAL  */
#line 288 "parser.y"
                    { yyval = makeNode("INT");}
#line 1884 "y.tab.c"
    break;

  case 55: /* integer_literal: INTEGER_LITERAL_HEX  */
#line 289 "parser.y"
                          { yyval = makeNode("INT");}
#line 1890 "y.tab.c"
    break;

  case 56: /* bool__literal: FALSE  */
#line 293 "parser.y"
          { yyval = makeNode("FALSE");}
#line 1896 "y.tab.c"
    break;

  case 57: /* bool__literal: TRUE  */
#line 294 "parser.y"
           { yyval = makeNode("TRUE");}
#line 1902 "y.tab.c"
    break;

  case 58: /* literal_lexemes: bool__literal  */
#line 298 "parser.y"
                  { yyval = yyvsp[0]; }
#line 1908 "y.tab.c"
    break;

  case 59: /* literal_lexemes: CHAR_LITERAL  */
#line 299 "parser.y"
                   { yyval = makeNode("CHAR");}
#line 1914 "y.tab.c"
    break;

  case 60: /* literal_lexemes: integer_literal  */
#line 300 "parser.y"
                      { yyval = yyvsp[0];}
#line 1920 "y.tab.c"
    break;

  case 61: /* literal_lexemes: REAL_LITERAL  */
#line 301 "parser.y"
                   { yyval = makeNode("REAL"); }
#line 1926 "y.tab.c"
    break;

  case 62: /* literal_lexemes: STRING_LITERAL  */
#line 302 "parser.y"
                     { yyval = makeNode("STRING"); }
#line 1932 "y.tab.c"
    break;

  case 63: /* literal_lexemes: id  */
#line 303 "parser.y"
         { yyval = yyvsp[0]; }
#line 1938 "y.tab.c"
    break;

  case 64: /* variable_declarations: variable_declare  */
#line 308 "parser.y"
    {
        yyval = makeNode("variable_declarations");
        addNode(&yyval, yyvsp[0]);
    }
#line 1947 "y.tab.c"
    break;

  case 65: /* variable_declarations: variable_declarations variable_declare  */
#line 313 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 1955 "y.tab.c"
    break;

  case 68: /* var_declare: VAR variable_list COLON type SEMICOLON  */
#line 323 "parser.y"
    {
        addNode(&yyvsp[-1], yyvsp[-3]);
        yyval = yyvsp[-1];
    }
#line 1964 "y.tab.c"
    break;

  case 69: /* variable_list: variable_list_helper  */
#line 331 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 1973 "y.tab.c"
    break;

  case 70: /* variable_list: variable_list COMMA variable_list_helper  */
#line 336 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 1981 "y.tab.c"
    break;

  case 71: /* variable_list_helper: id  */
#line 342 "parser.y"
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, yyvsp[0]);
    }
#line 1990 "y.tab.c"
    break;

  case 72: /* variable_list_helper: id ASSIGNMENT literal_lexemes  */
#line 347 "parser.y"
    {
        // Creating the ASSIGNMENT node
        node* temp_assinment_node = makeNode("=");
        addNode(&temp_assinment_node, yyvsp[-2]);
        addNode(&temp_assinment_node, yyvsp[0]);
        yyval = temp_assinment_node;
    }
#line 2002 "y.tab.c"
    break;

  case 73: /* string_declare: STRING string_list SEMICOLON  */
#line 357 "parser.y"
    {
        node* string_node = makeNode("STRING");
        addNode(&string_node,yyvsp[-1]);
        yyval = string_node;
    }
#line 2012 "y.tab.c"
    break;

  case 74: /* string_list: string_list_helper  */
#line 365 "parser.y"
    {
        yyval = makeNode("");
        addNode(&yyval, yyvsp[0]);
    }
#line 2021 "y.tab.c"
    break;

  case 75: /* string_list: string_list COMMA string_list_helper  */
#line 370 "parser.y"
    {
        addNode(&yyval, yyvsp[0]);
    }
#line 2029 "y.tab.c"
    break;

  case 76: /* string_list_helper: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS  */
#line 376 "parser.y"
    {
        temp_node = makeNode(""); 
        addNode(&temp_node, yyvsp[-3]); 
        node* lenght_node = makeNode("LENGTH");
        addNode(&lenght_node, yyvsp[-1]);
        addNode(&yyval, lenght_node);
    }
#line 2041 "y.tab.c"
    break;

  case 77: /* string_list_helper: id START_SQUARE_BRACKETS expression END_SQUARE_BRACKETS ASSIGNMENT literal_lexemes  */
#line 384 "parser.y"
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
#line 2056 "y.tab.c"
    break;

  case 78: /* expression: operator expression  */
#line 398 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2066 "y.tab.c"
    break;

  case 79: /* expression: expression operator expression  */
#line 404 "parser.y"
    {
        node* operator_node = makeNode(yyvsp[-1]->token); 
        addNode(&operator_node,yyvsp[-2]);
        addNode(&operator_node,yyvsp[0]);
        yyval = operator_node;
    }
#line 2077 "y.tab.c"
    break;

  case 80: /* expression: literal_lexemes  */
#line 410 "parser.y"
                        { yyval = yyvsp[0];}
#line 2083 "y.tab.c"
    break;

  case 81: /* operator: AND  */
#line 413 "parser.y"
        { yyval = makeNode("&&"); }
#line 2089 "y.tab.c"
    break;

  case 82: /* operator: DIVIDE  */
#line 414 "parser.y"
             { yyval = makeNode("/"); }
#line 2095 "y.tab.c"
    break;

  case 83: /* operator: EQUALS  */
#line 415 "parser.y"
             { yyval = makeNode("=="); }
#line 2101 "y.tab.c"
    break;

  case 84: /* operator: GREATER_THAN  */
#line 416 "parser.y"
                   { yyval = makeNode(">"); }
#line 2107 "y.tab.c"
    break;

  case 85: /* operator: GREATER_EQUALS  */
#line 417 "parser.y"
                     { yyval = makeNode(">="); }
#line 2113 "y.tab.c"
    break;

  case 86: /* operator: LOWER_THAN  */
#line 418 "parser.y"
                 { yyval = makeNode("<"); }
#line 2119 "y.tab.c"
    break;

  case 87: /* operator: LOWER_EQUALS  */
#line 419 "parser.y"
                   { yyval = makeNode("<="); }
#line 2125 "y.tab.c"
    break;

  case 88: /* operator: SUBSTRACT  */
#line 420 "parser.y"
                { yyval = makeNode("-"); }
#line 2131 "y.tab.c"
    break;

  case 89: /* operator: NOT  */
#line 421 "parser.y"
          { yyval = makeNode("!"); }
#line 2137 "y.tab.c"
    break;

  case 90: /* operator: NOT_EQUALS  */
#line 422 "parser.y"
                 { yyval = makeNode("!="); }
#line 2143 "y.tab.c"
    break;

  case 91: /* operator: OR  */
#line 423 "parser.y"
         { yyval = makeNode("||"); }
#line 2149 "y.tab.c"
    break;

  case 92: /* operator: ADD  */
#line 424 "parser.y"
          { yyval = makeNode("+"); }
#line 2155 "y.tab.c"
    break;

  case 93: /* operator: MULTIPLY  */
#line 425 "parser.y"
               { yyval = makeNode("*"); }
#line 2161 "y.tab.c"
    break;


#line 2165 "y.tab.c"

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

#line 427 "parser.y"


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
