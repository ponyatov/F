#include <string>
#include "primitive.hpp"

Int::Int(char *s) : Prim(), value(std::stoi(s, nullptr, 0x0A)) {}

std::string Int::val() {
    std::ostringstream os;
    os << value;
    return os.str();
}
