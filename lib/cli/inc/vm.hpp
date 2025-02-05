#pragma once

#include "hw.hpp"

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup cli
/// @{

/// @brief `<T:` type tag
enum class T : int {
    NIL,   ///< `<nil:` null
    BOOL,  ///< `<bool:` boolean
    BYTE,  ///< `<byte:>` single byte
    INT,   ///< `<int:` integer
    NUM,   ///< `<num: floating poinr
    CHAR,  ///< `<char:` single character
    STR,   ///< `<str:` ASCII string
    ID,    ///< `<id:` symbol/name/identifier
    PTR,   ///< `<ptr:` raw pointer
    CMD,   ///< `<cmd:op>` @ref vm command with @ref Op
};

/// @brief `:V>` value union (tagged by @ref T)
union V {
    bool b;
    int n;
    float f;
    char c;
    char *s;
    void *p;  ///< @ref T::PTR
};

/// @brief typed data cell on @ref D stack
struct Cell {
    T t;  ///< @ref
    V v;  ///<
};

/// @name @ref vm config
/// @{
/// @brief @ref D size
#define Dsz 0x10
/// @brief @ref R size
#define Rsz 0x100
/// @brief @ref M size
#define Msz 0x1000
/// @}

/// @name @ref VM memory
/// @{
extern Cell D[Dsz];  ///< @brief data stack
extern uint Dp;      ///< @brief data stack pointer
extern uint R[Rsz];  ///< @brief return stack
extern uint Rp;      ///< @brief return stack pointer
extern byte M[Msz];  ///< @brief main memory, preallocated raw bytes block
extern uint Cp;      ///< @brief compiler pointer
extern uint Ip;      ///< @brief instruction pointer
/// @}

/// @name @ref VM operations
/// @{

/// @brief push preformed @ref Cell
extern void push(Cell c);
/// @brief `( -- int:n )`
extern void push(int n);
/// @brief `( -- num:n )`
extern void push(float f);
/// @brief `( -- char:c )` @ref T::CHAR
extern void push(char c);
/// @brief `( -- str:s )`
extern void push(char *c);

extern Cell pop();

/// @}

/// @}

/// @defgroup cmd cmd
/// @ingroup vm
/// @brief commands
/// @{

/// @brief @ref cmd opcode
enum class Op : byte {
    nop = 0x00,   ///< @ref nop
    halt = 0xFF,  ///< @ref halt
};

/// @name flow control
/// @{
extern void nop();   ///> @brief `( -- )` no operation
extern void halt();  ///> @brief `( -- )` stop system
/// @}

/// @name debug
/// @{
extern void dump();  ///> @brief  `( -- )` print @ref VM state
/// @}

/// @}
