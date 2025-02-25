#include "core.hpp"

Object::Object() {
    ref = 0;
    next = pool;  // \ register object in global @ref pool
    pool = this;  // /
}

Object::~Object() { assert(!ref); }
