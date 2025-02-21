#pragma once

#include "types.hpp"

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup core
/// @{

/// @name flow control
/// @{
extern void nop();   ///> `( -- )` no operation
extern void halt();  ///> `( -- )` stop system
/// @}

/// @}
