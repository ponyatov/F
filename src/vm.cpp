#include <assert.h>
#include <sstream>
#include <iostream>
#include "vm.hpp"
#include "object.hpp"

std::string Cmd::tag() const { return "cmd:"; }
std::string Cmd::val() const { return Object::tag(); }

VM::VM() : Object(), Dp(0) {}

std::string VM::val() const {
    std::ostringstream os;
    for (int i = 0; i < Dp; i++) os << D[i]->head(" ");
    os << ' ';
    return os.str();
}

VM vm;

void VM::push(Object *o) {
    assert(Dp < Dsz);
    D[Dp++] = o;
}

void VM::clean() {
    for (int i = Dp - 1; i >= 0; i--) {
        std::cerr << D[i]->head("del: ") << std::endl;
        delete D[i];
    }
    Dp = 0;
}

void Nop::exec() {  //
    std::cerr << "nop" << std::endl;
}

void Halt::exec() {
    std::cerr << "halt" << std::endl;
    exit(0);
}

void Dot::exec() {
    std::cerr << "." << std::endl;
    vm.clean();
}
