#include <assert.h>
#include <sstream>
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
