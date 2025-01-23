%{
    #include "cli.hpp"
%}

%defines %union { Object *o; }

%token <o> INT CMD
%type  <o> ex

%%
syntax: | syntax ex     { std::cerr << $2->dump() << std::endl; }

ex : INT
   | CMD
