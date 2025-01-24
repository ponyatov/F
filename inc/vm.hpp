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
class Cmd : public Object {};

/// @brief `( -- )` do nothing
class Nop : public Cmd {};
/// @brief `( -- )` stop system
class Halt : public Cmd {};
/// @}
