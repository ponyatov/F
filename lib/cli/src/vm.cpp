#include "os.hpp"
#include "vm.hpp"

Cell D[Dsz];  ///< data stack
uint Dp = 0;  ///< data stack pointer
uint R[Rsz];  ///< return stack
uint Rp = 0;  ///< return stack pointer
byte M[Msz];  ///< main memory, bytes
uint Cp = 0;  ///< compiler pointer
uint Ip = 0;  ///< instruction pointer

void push(Cell c) {
    assert(Dp < Dsz);
    D[Dp++] = c;
}

void push(int n) { push(Cell{t : T::INT, v : {n : n}}); }
void push(float f) { push(Cell{t : T::NUM, v : {f : f}}); }
void push(char c) { push(Cell{t : T::CHAR, v : {c : c}}); }
void push(char *id) { push(Cell{t : T::ID, v : {s : id}}); }

void nop() {}

void halt() {
#ifdef POSIX
    exit(0);
#else   //
    for (;;)
        ;
    POSIX
#endif  // POSIX
}

#ifdef POSIX
void dump() {
    fprintf(stderr, "D:[ ");
    for (uint i = 0; i < Dp; i++) {
        fprintf(stderr, "%i:", i);
        Cell c = D[i];
        switch (c.t) {
            default:
                fprintf(stderr, "?:? ");
                break;
        }
    }
    fprintf(stderr, "]\n");
}
#endif  // POSIX
