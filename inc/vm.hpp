#pragma once

#include "object.hpp"

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup core
/// @{
/// @brief Virtual Machine
class VM : public Object {};
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

/// @brief `( -- )` do nothing
class Nop : public Cmd {};
/// @brief `( -- )` stop system
class Halt : public Cmd {};
/// @}
