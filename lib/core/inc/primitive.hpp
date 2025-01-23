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
    Int(int n);
    std::string val();
};

/// @brief hexadecimal
class Hex : public Int {
   public:
    Hex(char *s);
};

/// @brief octal
class Oct : public Int {
   public:
    Oct(char *s);
};

/// @brief binary
class Bin : public Int {
   public:
    Bin(char *s);
};

/// @}
