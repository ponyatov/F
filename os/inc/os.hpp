#pragma once

/// @defgroup os os
/// @ingroup cross

/// @defgroup main main
/// @ingroup core
/// @{
extern int main(int argc, char *argv[]);
extern void arg(int argc, char *argv) ;
extern void setup() ;
extern void loop() ;
/// @}

#ifdef POSIX
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#endif  // POSIX

#ifdef LINUX
#include "linux.hpp"
#endif

#ifdef MINGW
#include "mingw.hpp"
#endif
