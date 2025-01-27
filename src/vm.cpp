#include "vm.hpp"
#include "object.hpp"

std::string Cmd::tag() const { return "cmd:"; }
std::string Cmd::val() const { return Object::tag(); }
