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

"0x"[0-9a-fA-F]+    TOKE2(Hex,INT)
"0o"[0-7]+          TOKE2(Oct,INT)
"0b"[01]+           TOKE2(Bin,INT)
{s}?{n}+            TOKEN(Int,INT)  // /

.                   {yyerror("");}  // any undetected char
