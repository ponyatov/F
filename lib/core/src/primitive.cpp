#include <string>
#include <sstream>
#include "primitive.hpp"

Int::Int(int n) : Prim(), value(n) {}

std::string Int::val() {
    std::ostringstream os;
    os << value;
    return os.str();
}

Int::Int(char *s) : Int(std::stoi(s, nullptr, 0x0A)) {}
Hex::Hex(char *s) : Int(std::stoi(s, nullptr, 0x10)) {}
Oct::Oct(char *s) : Int(std::stoi(s, nullptr, 0x08)) {}
Bin::Bin(char *s) : Int(std::stoi(s, nullptr, 0x02)) {}
