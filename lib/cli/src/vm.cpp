#include "os.hpp"
#include "vm.hpp"

Cell D[Dsz];  ///< data stack
uint Dp = 0;  ///< data stack pointer
uint R[Rsz];  ///< return stack
uint Rp = 0;  ///< return stack pointer
byte M[Msz];  ///< main memory, bytes
uint Cp = 0;  ///< compiler pointer
uint Ip = 0;  ///< instruction pointer

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
