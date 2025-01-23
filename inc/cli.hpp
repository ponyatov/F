#pragma once

#include <stdio.h>
#include <iostream>
#include "core.hpp"

/// @defgroup cli cli
/// @brief CLI: Command Line Interface
/// @ingroup core
/// @{
/// @name lexer
/// @{
extern int yylex();
extern int yylineno;
extern char* yytext;
extern char* yyfile;
extern FILE* yyin;
/// @}
/// @name parser
/// @{
extern int yyparse();
extern void yyerror(const char* msg);
#include "cli.parser.hpp"
/// @}
/// @name lexer
/// @{
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }
#define TOKE2(C, X)                   \
    {                                 \
        yylval.o = new C(&yytext[2]); \
        return X;                     \
    }
#define TOCMD(C, X)         \
    {                       \
        yylval.o = new C(); \
        return X;           \
    }
/// @}
/// @}
