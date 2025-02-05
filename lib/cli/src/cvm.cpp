#include "cvm.hpp"

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
void push(char* id) { push(Cell{t : T::ID, v : {s : id}}); }

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

const char* t_dump(T t) {
    switch (t) {
        case T::INT:
            return "int";
        case T::HEX:
            return "hex";
        case T::OCT:
            return "oct";
        case T::BIN:
            return "bin";
        case T::NUM:
            return "num";
        case T::CMD:
            return "cmd";
        default:
            return "?";
    }
}

const char* op_dump(Op op) {
    switch (op) {
        case Op::nop:
            return "nop";
        case Op::halt:
            return "halt";
        case Op::dup:
            return "dup";
        case Op::drop:
            return "drop";
        case Op::swap:
            return "swap";
        case Op::over:
            return "over";
        case Op::add:
            return "add";
        case Op::sub:
            return "sub";
        case Op::mul:
            return "mul";
        case Op::div:
            return "div";
        case Op::dump:
            return "dump";
        case Op::key:
            return "key";
        case Op::emit:
            return "emit";
        default:
            return "?";
    }
}

#ifdef POSIX
void dump() {
    fprintf(stderr, "D:[ ");
    for (uint i = 0; i < Dp; i++) {
        Cell c = D[i];
        fprintf(stderr, "%s:", t_dump(c.t));
        switch (c.t) {
            case T::INT:
                fprintf(stderr, "%i ", c.v.n);
                break;
            case T::HEX:
                fprintf(stderr, "%x ", c.v.n);
                break;
            case T::OCT:
                fprintf(stderr, "%o ", c.v.n);
                break;
            case T::BIN:
                fprintf(stderr, "%i ", c.v.n);
                break;
            case T::NUM:
                fprintf(stderr, "%f ", c.v.f);
                break;
            case T::CHAR:
                fprintf(stderr, "%c ", c.v.c);
                break;
            case T::CMD:
                fprintf(stderr, "%s ", op_dump(c.v.op));
                break;
            case T::ID:
                fprintf(stderr, "%s ", c.v.s);
                break;
            default:
                fprintf(stderr, "%i ", c.v.n);
                break;
        }
    }
    fprintf(stderr, "]\n");
}
#endif  // POSIX
