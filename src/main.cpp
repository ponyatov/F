#include "os.hpp"
#include "cli.hpp"

void arg(int argc, char *argv) {
#ifdef POSIX
    fprintf(stderr, "\targ[%i] = <%s>\n", argc, argv);
#endif
    if (argc >= 1) {
        yyfile = argv;
#ifdef POSIX
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
#else  // POSIX
#error MCU parser not implemented
#endif  // POSIX
        yyfile = nullptr;
    }
}
