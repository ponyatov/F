#pragma once

#include "object.hpp"

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup core
/// @{
/// @brief Virtual Machine
class VM : public Object {
   public:
    VM();
    std::string val() const;
    /// @name stack operations
    /// @{
    /// @brief `( -- o)`
    void push(Object* o);
    /// @brief `( o -- )`
    Object* pop();
    /// @brief `( ... -- )`
    void clean();
    /// @}

   private:
    /// @brief @ref D size
    static const size_t Dsz = 0x10;
    /// @brief data stack
    Object* D[Dsz];
    /// @brief @ref D pointer
    uint8_t Dp;
};

/// @brief global main @ref VM
extern VM vm;
/// @}
