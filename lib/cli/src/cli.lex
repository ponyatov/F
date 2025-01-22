%{
    #include "cli.hpp"
    char* yyfile = nullptr;
%}

%option yylineno noyywrap

s [+\-]
n [0-9]

%%
#[^\n]*     {}              // line comment
[ \t\r\n]+  {}              // drop spaces

{s}?{n}+    TOKEN(Int,INT)

.           {yyerror("");}  // any undetected char
