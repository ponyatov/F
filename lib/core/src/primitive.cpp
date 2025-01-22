#include "primitive.hpp"

Int::Int(char *s):Prim(),value(stol(s,nullptr,0x0A)) {}
