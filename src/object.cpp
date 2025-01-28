#include "object.hpp"
#include <assert.h>
#include <sstream>

Object::Object() : ref(0) {}

Object::~Object() { assert(ref == 0); }

#include <cxxabi.h>

std::string Object::tag() const {
    std::string ret =
        abi::__cxa_demangle(typeid(*this).name(), NULL, NULL, nullptr);
    for (char &c : ret) c = tolower(c);
    return ret;
}

std::string Object::val() const { return value; }

std::string Object::head(std::string prefix) const {
    std::ostringstream os;
    os << prefix << '<' << tag() << ':' << val() << '>';
    return os.str();
}

std::string Object::dump() const { return head(); }

#include "vm.hpp"

void Object::exec() { vm.push(this); }
void Object::comp() { abort(); }
