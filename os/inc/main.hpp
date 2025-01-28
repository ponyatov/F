#pragma once

/// @defgroup main main
/// @ingroup core
/// @{
#ifdef POSIX
extern int main(int argc, char* argv[]);
#endif  // POSIX

/// @brief process command line / bootloader argument
extern void arg(int argc, char* argv);

/// @brief setup system
extern void setup(void);

/// @brief event loop
extern void loop(void);

/// @}
