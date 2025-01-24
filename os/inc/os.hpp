#pragma once

/// @defgroup os os
/// @ingroup cross

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifdef LINUX
#include "linux.hpp"
#include "main.hpp"
#endif

#ifdef MINGW
#include "mingw.hpp"
#include "main.hpp"
#endif
