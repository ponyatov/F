#include "os.hpp"
#include "cli.hpp"

void setup() {}
void loop() { exit(0); }

void arg(int argc, char *argv) {
#ifdef POSIX
    fprintf(stderr, "\targ[%i] = <%s>\n", argc, argv);
#endif
    if (argc >= 1) cli(argv);
}
