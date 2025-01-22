%{
    #include "cli.hpp"
%}

%defines %union { Object *o; }

%token <o> INT
%type  <o> ex

%%
syntax: | syntax ex     { std::cerr << $2->dump() << std::endl; }

ex : INT
