#include "cli.hpp"
#include <iostream>

void yyerror(const char* msg) {
    std::cerr << std::endl
              << yyfile << ':' << yylineno << ' ' << msg << " [" << yytext
              << ']' << std::endl;
    exit(-1);
}
