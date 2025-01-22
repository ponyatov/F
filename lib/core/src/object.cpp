#include "object.hpp"
#include <assert.h>
#include <sstream>

Object::Object() : ref(0) {}

Object::~Object() { assert(ref == 0); }

#include <cxxabi.h>

std::string Object::tag() {
    int status;
    return abi::__cxa_demangle(typeid(*this).name(), NULL, NULL, &status);
}

std::string Object::val() { return value; }

std::string Object::head() {
    std::ostringstream os;
    os << '<' << tag() << ':' << val() << '>';
    return os.str();
}

std::string Object::dump() { return head(); }
