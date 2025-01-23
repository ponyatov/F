#pragma once

#include "core.hpp"

/// @defgroup prim prim
/// @ingroup object
/// @brief primitive types
/// @{

/// @brief any primitive commons
class Prim : public Object {
   public:
    Prim() : Object() {}
};

/// @}

/// @defgroup int int
/// @brief integer
/// @ingroup prim
/// @{

/// @brief integer
class Int : public Prim {
   protected:
    int value;

   public:
    Int(int n);
    Int(char *s);
    std::string val();
};

/// @brief hexadecimal
class Hex : public Int {
   public:
    Hex(char *s);
    std::string val();
};

/// @brief octal
class Oct : public Int {
   public:
    Oct(char *s);
    std::string val();
};

/// @brief binary
class Bin : public Int {
   public:
    Bin(char *s);
    std::string val();
};

/// @}
