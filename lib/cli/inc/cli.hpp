#pragma once

#include <stdio.h>
#include <iostream>
#include "core.hpp"

/// @defgroup cli cli
/// @brief CLI: Command Line Interface
/// @ingroup core
/// @{

extern int yylex();
extern int yylineno;
extern char* yytext;
extern char* yyfile;
extern FILE* yyin;
extern int yyparse();
extern void yyerror(const char* msg);
#include "cli.parser.hpp"
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }
/// @}
