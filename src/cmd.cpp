#include "vm.hpp"
#include "cmd.hpp"
#include <iostream>

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

void Add::exec() {
    std::cerr << "add" << std::endl;
    Object *a = vm.pop(), *b = vm.pop();
    vm.push(a->add(b));
}

void Sub::exec() {}
void Mul::exec() {}
void Div::exec() {}
