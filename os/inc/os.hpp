#pragma once

/// @defgroup os os
/// @ingroup cross

#ifdef LINUX
#include "linux.hpp"
#include "main.hpp"
#endif

#ifdef MINGW
#include "mingw.hpp"
#include "main.hpp"
#endif
