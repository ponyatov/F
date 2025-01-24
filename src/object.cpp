#include "object.hpp"
#include <assert.h>
#include <sstream>

Object::Object() : ref(0) {}

Object::~Object() { assert(ref == 0); }

#include <cxxabi.h>

std::string Object::tag() const {
    int status;
    std::string s =
        abi::__cxa_demangle(typeid(*this).name(), NULL, NULL, &status);

    return s;
}

std::string Object::val() const { return value; }

std::string Object::head() const {
    std::ostringstream os;
    os << '<' << tag() << ':' << val() << '>';
    return os.str();
}

std::string Object::dump() const { return head(); }
