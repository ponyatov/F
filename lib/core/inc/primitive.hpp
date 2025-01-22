#pragma once

/// @defgroup prim prim
/// @brief Primitive types
/// @{

class Prim : public Object {};

class Int : public Prim {
    int value;

   public:
    Int(char *s);
};

/// @}
