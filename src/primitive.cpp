#include <string>
#include <sstream>
#include <bitset>
#include "primitive.hpp"

Int::Int(int n) : Prim(), value(n) {}

std::string Int::val() const {
    std::ostringstream os;
    os << value;
    return os.str();
}

Int::Int(char *s) : Int(std::stol(s, nullptr, 0x0A)) {}
Hex::Hex(char *s) : Int(std::stol(s, nullptr, 0x10)) {}
Oct::Oct(char *s) : Int(std::stol(s, nullptr, 0x08)) {}
Bin::Bin(char *s) : Int(std::stol(s, nullptr, 0x02)) {}

std::string Hex::val() const {
    std::ostringstream os;
    os << std::hex << value;
    return os.str();
}

std::string Oct::val() const {
    std::ostringstream os;
    os << std::oct << value;
    return os.str();
}

std::string Bin::val() const {
    std::ostringstream os;
    std::bitset<sizeof(value * 8)> b(value);
    os << b;
    return os.str();
}
