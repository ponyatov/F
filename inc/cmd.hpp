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

/// @brief `add ( a b -- a+b )`
class Add : public Cmd {
   public:
    void exec(void);
};

/// @brief `sub ( a b -- a-b )`
class Sub : public Cmd {
   public:
    void exec(void);
};

/// @brief `mul ( a b -- a*b )`
class Mul : public Cmd {
   public:
    void exec(void);
};

/// @brief `div ( a b -- a/b )` integer division
class Div : public Cmd {
   public:
    void exec(void);
};

/// @brief `dump ( -- )` print stack
/// @}
