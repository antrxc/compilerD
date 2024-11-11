/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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

#line 245 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
