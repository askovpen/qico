/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     DATESTR = 258,
     GAPSTR = 259,
     PHSTR = 260,
     TIMESTR = 261,
     ADDRSTR = 262,
     PATHSTR = 263,
     ANYSTR = 264,
     IDENT = 265,
     NUMBER = 266,
     AROP = 267,
     LOGOP = 268,
     EQ = 269,
     NE = 270,
     GT = 271,
     GE = 272,
     LT = 273,
     LE = 274,
     AND = 275,
     OR = 276,
     NOT = 277,
     XOR = 278,
     LB = 279,
     RB = 280,
     COMMA = 281,
     ADDRESS = 282,
     ITIME = 283,
     CONNSTR = 284,
     SPEED = 285,
     CONNECT = 286,
     PHONE = 287,
     MAILER = 288,
     CID = 289,
     FLTIME = 290,
     FLDATE = 291,
     EXEC = 292,
     FLLINE = 293,
     PORT = 294,
     FLFILE = 295,
     HOST = 296,
     SFREE = 297
   };
#endif
/* Tokens.  */
#define DATESTR 258
#define GAPSTR 259
#define PHSTR 260
#define TIMESTR 261
#define ADDRSTR 262
#define PATHSTR 263
#define ANYSTR 264
#define IDENT 265
#define NUMBER 266
#define AROP 267
#define LOGOP 268
#define EQ 269
#define NE 270
#define GT 271
#define GE 272
#define LT 273
#define LE 274
#define AND 275
#define OR 276
#define NOT 277
#define XOR 278
#define LB 279
#define RB 280
#define COMMA 281
#define ADDRESS 282
#define ITIME 283
#define CONNSTR 284
#define SPEED 285
#define CONNECT 286
#define PHONE 287
#define MAILER 288
#define CID 289
#define FLTIME 290
#define FLDATE 291
#define EXEC 292
#define FLLINE 293
#define PORT 294
#define FLFILE 295
#define HOST 296
#define SFREE 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


