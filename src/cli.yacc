%{
    #include "cli.hpp"
    #include "vm.hpp"
%}

%defines %union { Object *o; }

%token <o> INT CMD
%type  <o> ex

%%
syntax: | syntax ex   { $2->exec();
                        std::cerr << vm.dump() << std::endl; }

ex : INT
   | CMD
