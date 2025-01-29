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
    /// @brief `( ... -- )`
    void clean(void);
    /// @}

   private:
    /// @brief @ref D size
    static const size_t Dsz = 0x10;
    /// @brief data stack
    Object* D[Dsz];
    /// @brief @ref D pointer
    size_t Dp;
};

/// @brief global main @ref VM
extern VM vm;
/// @}

/// @defgroup cmd cmd
/// @ingroup vm
/// @brief @ref VM commands
/// @{

/// @brief @ref VM command
class Cmd : public Object {
   public:
    /// @brief `<cmd:`
    std::string tag() const;
    /// @brief `:cmd_name>`
    std::string val() const;
};

/// @brief `nop ( -- )` do nothing
class Nop : public Cmd {
   public:
    void exec(void);
};

/// @brief `halt ( -- )` stop system
class Halt : public Cmd {
   public:
    void exec(void);
};

/// @brief `. ( ... -- )` clean stack
class Dot : public Cmd {
   public:
    void exec(void);
};

/// @brief `dump ( -- )` print stack
/// @}
