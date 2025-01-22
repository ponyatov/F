#include <string>
#include "primitive.hpp"

Int::Int(char *s) : Prim(), value(std::stoi(s, nullptr, 0x0A)) {}
