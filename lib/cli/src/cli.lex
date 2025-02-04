%{
    #include "cli.hpp"
    #include "vm.hpp"
    #include "cmd.hpp"
    char* yyfile = nullptr;
%}

%option yylineno noyywrap nounput

s [+\-]
n [0-9]

%%
#[^\n]*             {}              // line comment
[ \t\r\n]+          {}              // drop spaces

"0x"[0-9a-fA-F]+    TOKE2(Hex,INT)
"0o"[0-7]+          TOKE2(Oct,INT)
"0b"[01]+           TOKE2(Bin,INT)
{s}?{n}+            TOKEN(Int,INT)  // /

"nop"               TOCMD(Nop ,CMD)
"halt"              TOCMD(Halt,CMD)
"."                 TOCMD(Dot ,CMD)

"add"               TOCMD(Add ,CMD)
"mul"               TOCMD(Mul ,CMD)
"sub"               TOCMD(Sub ,CMD)
"div"               TOCMD(Div ,CMD)

.                   {yyerror("");}  // any undetected char
