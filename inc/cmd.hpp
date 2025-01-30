#pragma once

#include "object.hpp"

/// @defgroup cmd cmd
/// @ingroup vm
/// @brief @ref VM commands
/// @{

/// @brief @ref VM command
class Cmd : public Object {
   public:
    /// @brief `<cmd:`
    std::string tag() const override;
    /// @brief `:cmd_name>`
    std::string val() const override;
};

/// @brief `nop ( -- )` do nothing
class Nop : public Cmd {
   public:
    void exec() override;
};

/// @brief `halt ( -- )` stop system
class Halt : public Cmd {
   public:
    void exec() override;
};

/// @brief `. ( ... -- )` clean stack
class Dot : public Cmd {
   public:
    void exec() override;
};

/// @brief `add ( a b -- a+b )`
class Add : public Cmd {
   public:
    void exec() override;
};

/// @brief `sub ( a b -- a-b )`
class Sub : public Cmd {
   public:
    void exec() override;
};

/// @brief `mul ( a b -- a*b )`
class Mul : public Cmd {
   public:
    void exec() override;
};

/// @brief `div ( a b -- a/b )` integer division
class Div : public Cmd {
   public:
    void exec() override;
};

/// @brief `dump ( -- )` print stack
/// @}
