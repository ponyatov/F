%{
    #include "cli.hpp"
    char* yyfile = nullptr;
%}

%option yylineno noyywrap

s [+\-]
n [0-9]

%%
#[^\n]*             {}              // line comment
[ \t\r\n]+          {}              // drop spaces

0x{s}?[0-9a-fA-F]+  TOKEN(Int,INT)  // \ integer
0o{s}?[0-7]+        TOKEN(Hex,INT)
0b{s}?[01]+         TOKEN(Oct,INT)
{s}?{n}+            TOKEN(Bin,INT)  // /

.                   {yyerror("");}  // any undetected char
