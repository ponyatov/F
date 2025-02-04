#include "cli.hpp"
#include "os.hpp"

void yyerror(const char* msg) {
#ifdef POSIX
    fprintf(stderr, "\n\n%s:%i %s\n\n", yyfile, yylineno, msg);
    exit(-1);
#else
    for (;;)
        ;  // halt
#endif  // POSIX
}
