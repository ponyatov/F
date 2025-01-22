#pragma once

#include "core.hpp"

/// @defgroup prim prim
/// @brief Primitive types
/// @{

/// @brief any primitive commons
class Prim : public Object {
   public:
    Prim() : Object() {}
};

/// @brief integer
class Int : public Prim {
    int value;

   public:
    Int(char *s);
    std::string val();
};

/// @}
