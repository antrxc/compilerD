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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node types for AST
typedef enum {
    NODE_PROGRAM,
    NODE_FUNCTION,
    NODE_DECLARATION,
    NODE_IF,
    NODE_WHILE,
    NODE_FOR,
    NODE_RETURN,
    NODE_COMPOUND,
    NODE_EXPRESSION,
    NODE_OPERATOR,
    NODE_IDENTIFIER,
    NODE_CONSTANT,
    NODE_TYPE
} NodeType;

typedef struct Node {
    NodeType type;
    char* value;
    struct Node* left;
    struct Node* right;
    struct Node* next;
    struct Node* children;
} Node;

Node* create_node(NodeType type, const char* value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->type = type;
    node->value = value ? strdup(value) : NULL;
    node->left = node->right = node->next = node->children = NULL;
    return node;
}

void print_ast(Node* node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) printf("  ");
    
    switch(node->type) {
        case NODE_PROGRAM: printf("Program\n"); break;
        case NODE_FUNCTION: printf("Function: %s\n", node->value); break;
        case NODE_DECLARATION: printf("Declaration: %s\n", node->value); break;
        case NODE_IF: printf("If\n"); break;
        case NODE_WHILE: printf("While\n"); break;
        case NODE_FOR: printf("For\n"); break;
        case NODE_RETURN: printf("Return\n"); break;
        case NODE_COMPOUND: printf("Compound\n"); break;
        case NODE_EXPRESSION: printf("Expression\n"); break;
        case NODE_OPERATOR: printf("Operator: %s\n", node->value); break;
        case NODE_IDENTIFIER: printf("Identifier: %s\n", node->value); break;
        case NODE_CONSTANT: printf("Constant: %s\n", node->value); break;
        case NODE_TYPE: printf("Type: %s\n", node->value); break;
    }

    if (node->children) print_ast(node->children, depth + 1);
    if (node->left) print_ast(node->left, depth + 1);
    if (node->right) print_ast(node->right, depth + 1);
    if (node->next) print_ast(node->next, depth);
}

void yyerror(const char *s);
int yylex(void);
Node* ast_root = NULL;

#line 141 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,              /* IDENTIFIER  */
    INTEGER = 259,                 /* INTEGER  */
    FLOAT_CONST = 260,             /* FLOAT_CONST  */
    CHAR_CONST = 261,              /* CHAR_CONST  */
    STRING_LITERAL = 262,          /* STRING_LITERAL  */
    AUTO = 263,                    /* AUTO  */
    BREAK = 264,                   /* BREAK  */
    CASE = 265,                    /* CASE  */
    CHAR = 266,                    /* CHAR  */
    CONST = 267,                   /* CONST  */
    CONTINUE = 268,                /* CONTINUE  */
    DEFAULT = 269,                 /* DEFAULT  */
    DO = 270,                      /* DO  */
    DOUBLE = 271,                  /* DOUBLE  */
    ELSE = 272,                    /* ELSE  */
    ENUM = 273,                    /* ENUM  */
    EXTERN = 274,                  /* EXTERN  */
    FLOAT_TYPE = 275,              /* FLOAT_TYPE  */
    FOR = 276,                     /* FOR  */
    GOTO = 277,                    /* GOTO  */
    IF = 278,                      /* IF  */
    INT = 279,                     /* INT  */
    LONG = 280,                    /* LONG  */
    REGISTER = 281,                /* REGISTER  */
    RETURN = 282,                  /* RETURN  */
    SHORT = 283,                   /* SHORT  */
    SIGNED = 284,                  /* SIGNED  */
    SIZEOF = 285,                  /* SIZEOF  */
    STATIC = 286,                  /* STATIC  */
    STRUCT = 287,                  /* STRUCT  */
    SWITCH = 288,                  /* SWITCH  */
    TYPEDEF = 289,                 /* TYPEDEF  */
    UNION = 290,                   /* UNION  */
    UNSIGNED = 291,                /* UNSIGNED  */
    VOID = 292,                    /* VOID  */
    VOLATILE = 293,                /* VOLATILE  */
    WHILE = 294,                   /* WHILE  */
    PLUS = 295,                    /* PLUS  */
    MINUS = 296,                   /* MINUS  */
    MULTIPLY = 297,                /* MULTIPLY  */
    DIVIDE = 298,                  /* DIVIDE  */
    MODULO = 299,                  /* MODULO  */
    INCREMENT = 300,               /* INCREMENT  */
    DECREMENT = 301,               /* DECREMENT  */
    ASSIGN = 302,                  /* ASSIGN  */
    PLUS_ASSIGN = 303,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 304,            /* MINUS_ASSIGN  */
    MUL_ASSIGN = 305,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 306,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 307,              /* MOD_ASSIGN  */
    LEFT_SHIFT_ASSIGN = 308,       /* LEFT_SHIFT_ASSIGN  */
    RIGHT_SHIFT_ASSIGN = 309,      /* RIGHT_SHIFT_ASSIGN  */
    AND_ASSIGN = 310,              /* AND_ASSIGN  */
    XOR_ASSIGN = 311,              /* XOR_ASSIGN  */
    OR_ASSIGN = 312,               /* OR_ASSIGN  */
    EQUAL = 313,                   /* EQUAL  */
    NOT_EQUAL = 314,               /* NOT_EQUAL  */
    GREATER = 315,                 /* GREATER  */
    LESS = 316,                    /* LESS  */
    GREATER_EQUAL = 317,           /* GREATER_EQUAL  */
    LESS_EQUAL = 318,              /* LESS_EQUAL  */
    LOGICAL_AND = 319,             /* LOGICAL_AND  */
    LOGICAL_OR = 320,              /* LOGICAL_OR  */
    LOGICAL_NOT = 321,             /* LOGICAL_NOT  */
    BIT_AND = 322,                 /* BIT_AND  */
    BIT_OR = 323,                  /* BIT_OR  */
    BIT_XOR = 324,                 /* BIT_XOR  */
    LEFT_SHIFT = 325,              /* LEFT_SHIFT  */
    RIGHT_SHIFT = 326,             /* RIGHT_SHIFT  */
    BIT_NOT = 327,                 /* BIT_NOT  */
    QUESTION = 328,                /* QUESTION  */
    COLON = 329,                   /* COLON  */
    ARROW = 330,                   /* ARROW  */
    DOT = 331,                     /* DOT  */
    LPAREN = 332,                  /* LPAREN  */
    RPAREN = 333,                  /* RPAREN  */
    LBRACE = 334,                  /* LBRACE  */
    RBRACE = 335,                  /* RBRACE  */
    LBRACKET = 336,                /* LBRACKET  */
    RBRACKET = 337,                /* RBRACKET  */
    COMMA = 338,                   /* COMMA  */
    SEMICOLON = 339,               /* SEMICOLON  */
    ELLIPSIS = 340                 /* ELLIPSIS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFIER 258
#define INTEGER 259
#define FLOAT_CONST 260
#define CHAR_CONST 261
#define STRING_LITERAL 262
#define AUTO 263
#define BREAK 264
#define CASE 265
#define CHAR 266
#define CONST 267
#define CONTINUE 268
#define DEFAULT 269
#define DO 270
#define DOUBLE 271
#define ELSE 272
#define ENUM 273
#define EXTERN 274
#define FLOAT_TYPE 275
#define FOR 276
#define GOTO 277
#define IF 278
#define INT 279
#define LONG 280
#define REGISTER 281
#define RETURN 282
#define SHORT 283
#define SIGNED 284
#define SIZEOF 285
#define STATIC 286
#define STRUCT 287
#define SWITCH 288
#define TYPEDEF 289
#define UNION 290
#define UNSIGNED 291
#define VOID 292
#define VOLATILE 293
#define WHILE 294
#define PLUS 295
#define MINUS 296
#define MULTIPLY 297
#define DIVIDE 298
#define MODULO 299
#define INCREMENT 300
#define DECREMENT 301
#define ASSIGN 302
#define PLUS_ASSIGN 303
#define MINUS_ASSIGN 304
#define MUL_ASSIGN 305
#define DIV_ASSIGN 306
#define MOD_ASSIGN 307
#define LEFT_SHIFT_ASSIGN 308
#define RIGHT_SHIFT_ASSIGN 309
#define AND_ASSIGN 310
#define XOR_ASSIGN 311
#define OR_ASSIGN 312
#define EQUAL 313
#define NOT_EQUAL 314
#define GREATER 315
#define LESS 316
#define GREATER_EQUAL 317
#define LESS_EQUAL 318
#define LOGICAL_AND 319
#define LOGICAL_OR 320
#define LOGICAL_NOT 321
#define BIT_AND 322
#define BIT_OR 323
#define BIT_XOR 324
#define LEFT_SHIFT 325
#define RIGHT_SHIFT 326
#define BIT_NOT 327
#define QUESTION 328
#define COLON 329
#define ARROW 330
#define DOT 331
#define LPAREN 332
#define RPAREN 333
#define LBRACE 334
#define RBRACE 335
#define LBRACKET 336
#define RBRACKET 337
#define COMMA 338
#define SEMICOLON 339
#define ELLIPSIS 340

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 71 "parser.y"

    int integer;
    float float_val;
    char *string;
    char character;
    struct Node* node;

#line 372 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_INTEGER = 4,                    /* INTEGER  */
  YYSYMBOL_FLOAT_CONST = 5,                /* FLOAT_CONST  */
  YYSYMBOL_CHAR_CONST = 6,                 /* CHAR_CONST  */
  YYSYMBOL_STRING_LITERAL = 7,             /* STRING_LITERAL  */
  YYSYMBOL_AUTO = 8,                       /* AUTO  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CASE = 10,                      /* CASE  */
  YYSYMBOL_CHAR = 11,                      /* CHAR  */
  YYSYMBOL_CONST = 12,                     /* CONST  */
  YYSYMBOL_CONTINUE = 13,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 14,                   /* DEFAULT  */
  YYSYMBOL_DO = 15,                        /* DO  */
  YYSYMBOL_DOUBLE = 16,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_ENUM = 18,                      /* ENUM  */
  YYSYMBOL_EXTERN = 19,                    /* EXTERN  */
  YYSYMBOL_FLOAT_TYPE = 20,                /* FLOAT_TYPE  */
  YYSYMBOL_FOR = 21,                       /* FOR  */
  YYSYMBOL_GOTO = 22,                      /* GOTO  */
  YYSYMBOL_IF = 23,                        /* IF  */
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_LONG = 25,                      /* LONG  */
  YYSYMBOL_REGISTER = 26,                  /* REGISTER  */
  YYSYMBOL_RETURN = 27,                    /* RETURN  */
  YYSYMBOL_SHORT = 28,                     /* SHORT  */
  YYSYMBOL_SIGNED = 29,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 30,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 31,                    /* STATIC  */
  YYSYMBOL_STRUCT = 32,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 33,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 34,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 35,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 36,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 37,                      /* VOID  */
  YYSYMBOL_VOLATILE = 38,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 39,                     /* WHILE  */
  YYSYMBOL_PLUS = 40,                      /* PLUS  */
  YYSYMBOL_MINUS = 41,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 42,                  /* MULTIPLY  */
  YYSYMBOL_DIVIDE = 43,                    /* DIVIDE  */
  YYSYMBOL_MODULO = 44,                    /* MODULO  */
  YYSYMBOL_INCREMENT = 45,                 /* INCREMENT  */
  YYSYMBOL_DECREMENT = 46,                 /* DECREMENT  */
  YYSYMBOL_ASSIGN = 47,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 48,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 49,              /* MINUS_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 50,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 51,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 52,                /* MOD_ASSIGN  */
  YYSYMBOL_LEFT_SHIFT_ASSIGN = 53,         /* LEFT_SHIFT_ASSIGN  */
  YYSYMBOL_RIGHT_SHIFT_ASSIGN = 54,        /* RIGHT_SHIFT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 55,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 56,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 57,                 /* OR_ASSIGN  */
  YYSYMBOL_EQUAL = 58,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 59,                 /* NOT_EQUAL  */
  YYSYMBOL_GREATER = 60,                   /* GREATER  */
  YYSYMBOL_LESS = 61,                      /* LESS  */
  YYSYMBOL_GREATER_EQUAL = 62,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 63,                /* LESS_EQUAL  */
  YYSYMBOL_LOGICAL_AND = 64,               /* LOGICAL_AND  */
  YYSYMBOL_LOGICAL_OR = 65,                /* LOGICAL_OR  */
  YYSYMBOL_LOGICAL_NOT = 66,               /* LOGICAL_NOT  */
  YYSYMBOL_BIT_AND = 67,                   /* BIT_AND  */
  YYSYMBOL_BIT_OR = 68,                    /* BIT_OR  */
  YYSYMBOL_BIT_XOR = 69,                   /* BIT_XOR  */
  YYSYMBOL_LEFT_SHIFT = 70,                /* LEFT_SHIFT  */
  YYSYMBOL_RIGHT_SHIFT = 71,               /* RIGHT_SHIFT  */
  YYSYMBOL_BIT_NOT = 72,                   /* BIT_NOT  */
  YYSYMBOL_QUESTION = 73,                  /* QUESTION  */
  YYSYMBOL_COLON = 74,                     /* COLON  */
  YYSYMBOL_ARROW = 75,                     /* ARROW  */
  YYSYMBOL_DOT = 76,                       /* DOT  */
  YYSYMBOL_LPAREN = 77,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 78,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 79,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 80,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 81,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 82,                  /* RBRACKET  */
  YYSYMBOL_COMMA = 83,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 84,                 /* SEMICOLON  */
  YYSYMBOL_ELLIPSIS = 85,                  /* ELLIPSIS  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_program = 87,                   /* program  */
  YYSYMBOL_translation_unit = 88,          /* translation_unit  */
  YYSYMBOL_external_declaration = 89,      /* external_declaration  */
  YYSYMBOL_function_definition = 90,       /* function_definition  */
  YYSYMBOL_parameter_list_opt = 91,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 92,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 93,     /* parameter_declaration  */
  YYSYMBOL_declaration = 94,               /* declaration  */
  YYSYMBOL_type_specifier = 95,            /* type_specifier  */
  YYSYMBOL_init_declarator_list = 96,      /* init_declarator_list  */
  YYSYMBOL_init_declarator = 97,           /* init_declarator  */
  YYSYMBOL_compound_statement = 98,        /* compound_statement  */
  YYSYMBOL_declaration_list = 99,          /* declaration_list  */
  YYSYMBOL_statement_list = 100,           /* statement_list  */
  YYSYMBOL_statement = 101,                /* statement  */
  YYSYMBOL_expression_statement = 102,     /* expression_statement  */
  YYSYMBOL_selection_statement = 103,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 104,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 105,           /* jump_statement  */
  YYSYMBOL_expression = 106,               /* expression  */
  YYSYMBOL_assignment_expression = 107,    /* assignment_expression  */
  YYSYMBOL_conditional_expression = 108,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 109,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 110,   /* logical_and_expression  */
  YYSYMBOL_equality_expression = 111,      /* equality_expression  */
  YYSYMBOL_relational_expression = 112,    /* relational_expression  */
  YYSYMBOL_additive_expression = 113,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 114, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 115,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 116,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 117        /* primary_expression  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  62
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  101

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   340


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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   134,   134,   145,   147,   155,   157,   162,   173,   174,
     179,   181,   189,   197,   207,   208,   209,   210,   214,   216,
     224,   226,   236,   243,   249,   257,   259,   267,   269,   277,
     279,   281,   283,   285,   290,   292,   297,   304,   315,   325,
     331,   339,   344,   346,   355,   360,   362,   371,   373,   382,
     384,   393,   395,   404,   406,   415,   417,   426,   428,   436,
     441,   443,   449
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
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "INTEGER", "FLOAT_CONST", "CHAR_CONST", "STRING_LITERAL", "AUTO",
  "BREAK", "CASE", "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE",
  "ELSE", "ENUM", "EXTERN", "FLOAT_TYPE", "FOR", "GOTO", "IF", "INT",
  "LONG", "REGISTER", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC",
  "STRUCT", "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE",
  "WHILE", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", "INCREMENT",
  "DECREMENT", "ASSIGN", "PLUS_ASSIGN", "MINUS_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_SHIFT_ASSIGN", "RIGHT_SHIFT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "EQUAL", "NOT_EQUAL", "GREATER",
  "LESS", "GREATER_EQUAL", "LESS_EQUAL", "LOGICAL_AND", "LOGICAL_OR",
  "LOGICAL_NOT", "BIT_AND", "BIT_OR", "BIT_XOR", "LEFT_SHIFT",
  "RIGHT_SHIFT", "BIT_NOT", "QUESTION", "COLON", "ARROW", "DOT", "LPAREN",
  "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET", "COMMA",
  "SEMICOLON", "ELLIPSIS", "$accept", "program", "translation_unit",
  "external_declaration", "function_definition", "parameter_list_opt",
  "parameter_list", "parameter_declaration", "declaration",
  "type_specifier", "init_declarator_list", "init_declarator",
  "compound_statement", "declaration_list", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "postfix_expression", "primary_expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      38,   -81,   -81,   -81,   -81,     5,    38,   -81,   -81,   -81,
       9,   -81,   -81,   -36,   -80,   -81,    52,    38,    10,   -81,
     -81,   -81,    52,    52,   -81,   -81,   -81,   -47,   -45,   -33,
     -38,   -12,     4,    13,   -81,   -81,   -26,   -22,   -81,    60,
      20,   -81,   -81,   -10,    52,    52,    52,    52,    52,    52,
      52,   -13,    38,   -81,   -81,   -45,   -81,   -33,   -38,   -12,
       4,   -81,   -81,    -3,   -81,   -81,    -7,    28,    -6,   -81,
     -81,   -81,    10,   -81,     3,     6,   -81,   -81,   -81,   -81,
     -81,   -11,    52,   -81,    -5,    52,   -81,    12,   -81,   -81,
     -81,     0,   -81,    17,   -81,    61,    61,    55,   -81,    61,
     -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    17,    14,    16,     0,     2,     3,     5,     6,
       0,     1,     4,    20,     0,    18,     0,     8,     0,    13,
      60,    61,     0,     0,    21,    41,    42,    44,    45,    47,
      49,    51,    53,    55,    57,    59,     0,     9,    10,     0,
      20,    19,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,    62,    46,    55,    48,    50,    52,
      54,    56,    43,     0,     7,    11,     0,     0,     0,    24,
      35,    25,     0,    29,     0,     0,    27,    30,    31,    32,
      33,     0,     0,    40,     0,     0,    26,     0,    23,    28,
      34,     0,    39,     0,    22,     0,     0,    36,    38,     0,
      37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,    91,   -81,   -81,   -81,    47,   -20,   -15,
     -81,    85,    53,   -81,    33,    19,   -81,   -81,   -81,   -81,
      34,    58,   -81,   -81,    65,    66,    64,    70,    78,    76,
     -81,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,    36,    37,    38,     9,    10,
      14,    15,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    21,    39,    18,    19,    11,    20,    21,     1,    20,
      21,    16,    13,    40,     1,    20,    21,     2,    44,    45,
      66,     3,    47,     2,    67,    46,    66,     3,    48,    66,
      67,    20,    21,    67,     4,    66,    68,    39,    22,    67,
       4,    17,    68,    71,    22,    68,    49,    22,    72,     1,
      24,    68,    51,    22,    86,    20,    21,    43,     2,    72,
      50,    52,     3,    53,    20,    21,    63,    16,    54,    22,
      82,    85,    99,    90,    23,     4,    63,    69,    95,    92,
      23,    70,    63,    23,    66,    63,    88,    70,    67,    23,
      70,    63,    94,    22,    89,    96,    70,    12,    42,    65,
      68,    84,    22,    41,    64,    23,    89,    87,    62,    55,
      58,    57,    83,     0,    97,    98,    91,    59,   100,    93,
      56,    56,    56,    56,    56,    61,    60,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,    23,     0,
      63,     0,     0,     0,     0,    70
};

static const yytype_int8 yycheck[] =
{
       3,     4,    17,    83,    84,     0,     3,     4,    11,     3,
       4,    47,     3,     3,    11,     3,     4,    20,    65,    64,
      23,    24,    60,    20,    27,    58,    23,    24,    40,    23,
      27,     3,     4,    27,    37,    23,    39,    52,    41,    27,
      37,    77,    39,    63,    41,    39,    42,    41,    63,    11,
      16,    39,    78,    41,    74,     3,     4,    23,    20,    74,
      47,    83,    24,     3,     3,     4,    79,    47,    78,    41,
      77,    77,    17,    84,    77,    37,    79,    80,    78,    84,
      77,    84,    79,    77,    23,    79,    80,    84,    27,    77,
      84,    79,    80,    41,    75,    78,    84,     6,    22,    52,
      39,    67,    41,    18,    51,    77,    87,    74,    50,    44,
      46,    45,    84,    -1,    95,    96,    82,    47,    99,    85,
      44,    45,    46,    47,    48,    49,    48,    -1,    -1,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    77,    -1,
      79,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    11,    20,    24,    37,    87,    88,    89,    90,    94,
      95,     0,    89,     3,    96,    97,    47,    77,    83,    84,
       3,     4,    41,    77,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,    91,    92,    93,    95,
       3,    97,   115,   106,    65,    64,    58,    60,    40,    42,
      47,    78,    83,     3,    78,   110,   115,   111,   112,   113,
     114,   115,   107,    79,    98,    93,    23,    27,    39,    80,
      84,    94,    95,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    77,    84,   106,    77,    94,   100,    80,   101,
      84,   106,    84,   106,    80,    78,    78,   101,   101,    17,
     101
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    90,    91,    91,
      92,    92,    93,    94,    95,    95,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    99,    99,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   103,   103,   104,   105,
     105,   106,   107,   107,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     117,   117,   117
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     0,     1,
       1,     3,     2,     3,     1,     1,     1,     1,     1,     3,
       1,     3,     4,     3,     2,     1,     2,     1,     2,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     3,
       2,     1,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     2,     1,
       1,     1,     3
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
  case 2: /* program: translation_unit  */
#line 135 "parser.y"
    { 
        (yyval.node) = create_node(NODE_PROGRAM, "program");
        (yyval.node)->children = (yyvsp[0].node);
        ast_root = (yyval.node);
        printf("\nAbstract Syntax Tree:\n");
        print_ast(ast_root, 0);
    }
#line 1574 "y.tab.c"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 146 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1580 "y.tab.c"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 148 "parser.y"
    { 
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->next = (yyvsp[0].node);
    }
#line 1589 "y.tab.c"
    break;

  case 5: /* external_declaration: function_definition  */
#line 156 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1595 "y.tab.c"
    break;

  case 6: /* external_declaration: declaration  */
#line 158 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1601 "y.tab.c"
    break;

  case 7: /* function_definition: type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement  */
#line 163 "parser.y"
    {
        (yyval.node) = create_node(NODE_FUNCTION, (yyvsp[-4].string));
        (yyval.node)->left = (yyvsp[-5].node);
        (yyval.node)->right = (yyvsp[0].node);
        printf("PARSER: Function definition found: %s\n", (yyvsp[-4].string));
    }
#line 1612 "y.tab.c"
    break;

  case 8: /* parameter_list_opt: %empty  */
#line 173 "parser.y"
    { (yyval.node) = NULL; }
#line 1618 "y.tab.c"
    break;

  case 9: /* parameter_list_opt: parameter_list  */
#line 175 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1624 "y.tab.c"
    break;

  case 10: /* parameter_list: parameter_declaration  */
#line 180 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1630 "y.tab.c"
    break;

  case 11: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 182 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        (yyval.node)->next = (yyvsp[0].node);
    }
#line 1639 "y.tab.c"
    break;

  case 12: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 190 "parser.y"
    {
        (yyval.node) = create_node(NODE_DECLARATION, (yyvsp[0].string));
        (yyval.node)->left = (yyvsp[-1].node);
    }
#line 1648 "y.tab.c"
    break;

  case 13: /* declaration: type_specifier init_declarator_list SEMICOLON  */
#line 198 "parser.y"
    {
        (yyval.node) = create_node(NODE_DECLARATION, "var_decl");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[-1].node);
        printf("PARSER: Variable declaration processed\n");
    }
#line 1659 "y.tab.c"
    break;

  case 14: /* type_specifier: INT  */
#line 207 "parser.y"
          { (yyval.node) = create_node(NODE_TYPE, "int"); }
#line 1665 "y.tab.c"
    break;

  case 15: /* type_specifier: CHAR  */
#line 208 "parser.y"
           { (yyval.node) = create_node(NODE_TYPE, "char"); }
#line 1671 "y.tab.c"
    break;

  case 16: /* type_specifier: VOID  */
#line 209 "parser.y"
           { (yyval.node) = create_node(NODE_TYPE, "void"); }
#line 1677 "y.tab.c"
    break;

  case 17: /* type_specifier: FLOAT_TYPE  */
#line 210 "parser.y"
                 { (yyval.node) = create_node(NODE_TYPE, "float"); }
#line 1683 "y.tab.c"
    break;

  case 18: /* init_declarator_list: init_declarator  */
#line 215 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1689 "y.tab.c"
    break;

  case 19: /* init_declarator_list: init_declarator_list COMMA init_declarator  */
#line 217 "parser.y"
    {
        (yyval.node) = (yyvsp[-2].node);
        (yyval.node)->next = (yyvsp[0].node);
    }
#line 1698 "y.tab.c"
    break;

  case 20: /* init_declarator: IDENTIFIER  */
#line 225 "parser.y"
    { (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[0].string)); }
#line 1704 "y.tab.c"
    break;

  case 21: /* init_declarator: IDENTIFIER ASSIGN expression  */
#line 227 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "=");
        (yyval.node)->left = create_node(NODE_IDENTIFIER, (yyvsp[-2].string));
        (yyval.node)->right = (yyvsp[0].node);
        printf("PARSER: Variable initialization processed\n");
    }
#line 1715 "y.tab.c"
    break;

  case 22: /* compound_statement: LBRACE declaration_list statement_list RBRACE  */
#line 237 "parser.y"
    {
        (yyval.node) = create_node(NODE_COMPOUND, "compound");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[-1].node);
        printf("PARSER: Compound statement processed\n");
    }
#line 1726 "y.tab.c"
    break;

  case 23: /* compound_statement: LBRACE statement_list RBRACE  */
#line 244 "parser.y"
    {
        (yyval.node) = create_node(NODE_COMPOUND, "compound");
        (yyval.node)->children = (yyvsp[-1].node);
        printf("PARSER: Compound statement processed\n");
    }
#line 1736 "y.tab.c"
    break;

  case 24: /* compound_statement: LBRACE RBRACE  */
#line 250 "parser.y"
    {
        (yyval.node) = create_node(NODE_COMPOUND, "compound");
        printf("PARSER: Empty compound statement processed\n");
    }
#line 1745 "y.tab.c"
    break;

  case 25: /* declaration_list: declaration  */
#line 258 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1751 "y.tab.c"
    break;

  case 26: /* declaration_list: declaration_list declaration  */
#line 260 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->next = (yyvsp[0].node);
    }
#line 1760 "y.tab.c"
    break;

  case 27: /* statement_list: statement  */
#line 268 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1766 "y.tab.c"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 270 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
        (yyval.node)->next = (yyvsp[0].node);
    }
#line 1775 "y.tab.c"
    break;

  case 29: /* statement: compound_statement  */
#line 278 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1781 "y.tab.c"
    break;

  case 30: /* statement: expression_statement  */
#line 280 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1787 "y.tab.c"
    break;

  case 31: /* statement: selection_statement  */
#line 282 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1793 "y.tab.c"
    break;

  case 32: /* statement: iteration_statement  */
#line 284 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1799 "y.tab.c"
    break;

  case 33: /* statement: jump_statement  */
#line 286 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1805 "y.tab.c"
    break;

  case 34: /* expression_statement: expression SEMICOLON  */
#line 291 "parser.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 1811 "y.tab.c"
    break;

  case 35: /* expression_statement: SEMICOLON  */
#line 293 "parser.y"
    { (yyval.node) = NULL; }
#line 1817 "y.tab.c"
    break;

  case 36: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 298 "parser.y"
    {
        (yyval.node) = create_node(NODE_IF, "if");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
        printf("PARSER: If statement processed\n");
    }
#line 1828 "y.tab.c"
    break;

  case 37: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 305 "parser.y"
    {
        (yyval.node) = create_node(NODE_IF, "if-else");
        (yyval.node)->left = (yyvsp[-4].node);
        (yyval.node)->right = (yyvsp[-2].node);
        (yyval.node)->children = (yyvsp[0].node);
        printf("PARSER: If-else statement processed\n");
    }
#line 1840 "y.tab.c"
    break;

  case 38: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 316 "parser.y"
    {
        (yyval.node) = create_node(NODE_WHILE, "while");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
        printf("PARSER: While loop processed\n");
    }
#line 1851 "y.tab.c"
    break;

  case 39: /* jump_statement: RETURN expression SEMICOLON  */
#line 326 "parser.y"
    {
        (yyval.node) = create_node(NODE_RETURN, "return");
        (yyval.node)->left = (yyvsp[-1].node);
        printf("PARSER: Return statement processed\n");
    }
#line 1861 "y.tab.c"
    break;

  case 40: /* jump_statement: RETURN SEMICOLON  */
#line 332 "parser.y"
    {
        (yyval.node) = create_node(NODE_RETURN, "return");
        printf("PARSER: Return statement processed\n");
    }
#line 1870 "y.tab.c"
    break;

  case 41: /* expression: assignment_expression  */
#line 340 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1876 "y.tab.c"
    break;

  case 42: /* assignment_expression: conditional_expression  */
#line 345 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1882 "y.tab.c"
    break;

  case 43: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 347 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "=");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1892 "y.tab.c"
    break;

  case 44: /* conditional_expression: logical_or_expression  */
#line 356 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1898 "y.tab.c"
    break;

  case 45: /* logical_or_expression: logical_and_expression  */
#line 361 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1904 "y.tab.c"
    break;

  case 46: /* logical_or_expression: logical_or_expression LOGICAL_OR logical_and_expression  */
#line 363 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "||");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1914 "y.tab.c"
    break;

  case 47: /* logical_and_expression: equality_expression  */
#line 372 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1920 "y.tab.c"
    break;

  case 48: /* logical_and_expression: logical_and_expression LOGICAL_AND equality_expression  */
#line 374 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "&&");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1930 "y.tab.c"
    break;

  case 49: /* equality_expression: relational_expression  */
#line 383 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1936 "y.tab.c"
    break;

  case 50: /* equality_expression: equality_expression EQUAL relational_expression  */
#line 385 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "==");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1946 "y.tab.c"
    break;

  case 51: /* relational_expression: additive_expression  */
#line 394 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1952 "y.tab.c"
    break;

  case 52: /* relational_expression: relational_expression GREATER additive_expression  */
#line 396 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, ">");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1962 "y.tab.c"
    break;

  case 53: /* additive_expression: multiplicative_expression  */
#line 405 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1968 "y.tab.c"
    break;

  case 54: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 407 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "+");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1978 "y.tab.c"
    break;

  case 55: /* multiplicative_expression: unary_expression  */
#line 416 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1984 "y.tab.c"
    break;

  case 56: /* multiplicative_expression: multiplicative_expression MULTIPLY unary_expression  */
#line 418 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "*");
        (yyval.node)->left = (yyvsp[-2].node);
        (yyval.node)->right = (yyvsp[0].node);
    }
#line 1994 "y.tab.c"
    break;

  case 57: /* unary_expression: postfix_expression  */
#line 427 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 2000 "y.tab.c"
    break;

  case 58: /* unary_expression: MINUS unary_expression  */
#line 429 "parser.y"
    {
        (yyval.node) = create_node(NODE_OPERATOR, "-");
        (yyval.node)->left = (yyvsp[0].node);
    }
#line 2009 "y.tab.c"
    break;

  case 59: /* postfix_expression: primary_expression  */
#line 437 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 2015 "y.tab.c"
    break;

  case 60: /* primary_expression: IDENTIFIER  */
#line 442 "parser.y"
    { (yyval.node) = create_node(NODE_IDENTIFIER, (yyvsp[0].string)); }
#line 2021 "y.tab.c"
    break;

  case 61: /* primary_expression: INTEGER  */
#line 444 "parser.y"
    { 
        char str[32];
        sprintf(str, "%d", (yyvsp[0].integer));
        (yyval.node) = create_node(NODE_CONSTANT, str);
    }
#line 2031 "y.tab.c"
    break;

  case 62: /* primary_expression: LPAREN expression RPAREN  */
#line 450 "parser.y"
    { (yyval.node) = (yyvsp[-1].node); }
#line 2037 "y.tab.c"
    break;


#line 2041 "y.tab.c"

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

#line 453 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "PARSER Error: %s\n", s);
}

extern FILE* yyin;

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <input-file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        printf("Error: Cannot open file '%s'\n", argv[1]);
        return 1;
    }

    printf("\n=== Starting Compilation Process ===\n\n");
    printf("Phase 1: Lexical Analysis\n");
    printf("--------------------------------\n");
    
    yyin = input_file;
    
    printf("\nPhase 2: Syntax Analysis\n");
    printf("--------------------------------\n");
    
    int result = yyparse();
    
    fclose(input_file);
    
    if (result == 0) {
        printf("\n=== Syntax Analysis Successful ===\n");
        printf("AST generated successfully.\n");
        printf("You can use this AST for semantic analysis and code generation.\n");
    } else {
        printf("\n=== Syntax Analysis Failed ===\n");
    }
    
    return result;
} 
