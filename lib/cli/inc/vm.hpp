#pragma once

#include "hw.hpp"

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup core
/// @{

/// @brief `<T:` type tag
enum T : int {
    NIL,     ///< `<nil:` null
    BOOL,    ///< `<bool:` boolean
    INT,     ///< `<int:` integer
    NUM,     ///< `<num: floating poinr
    CHAR,    ///< `<char:` single character
    STRING,  ///< `<str:` ASCII string
    ID,      ///< `<id:` symbol/name/identifier
    PTR,     ///< `<ptr:` raw pointer
};

/// @brief `:V>` value union (tagged by @ref T)
union V {
    bool b;
    int n;
    float f;
    char c;
    char *s;
    char *id;
    void *ptr;
};

/// @brief typed data cell on @ref D
struct Cell {
    T t;
    V v;
};

/// @name @ref VM config
/// @{
/// @ref D size
#define Dsz 0x10
/// @ref R size
#define Rsz 0x100
/// @ref M size
#define Msz 0x1000
/// @}

/// @name @ref VM memory
/// @{
extern Cell D[Dsz];  ///< data stack
extern uint Dp;      ///< data stack pointer
extern uint R[Rsz];  ///< return stack
extern uint Rp;      ///< return stack pointer
extern byte M[Msz];  ///< main memory, preallocated raw bytes block
extern uint Cp;      ///< compiler pointer
extern uint Ip;      ///< instruction pointer
/// @}

/// @name @ref VM operations
/// @{

/// @brief push preformed @ref Cell
extern void push(Cell c);
/// @brief `( -- char:c )`
extern void push(char c);
/// @brief `( -- int:n )`
extern void push(int n);
/// @brief `( -- num:n )`
extern void push(float f);

extern Cell pop();

/// @}

/// @}

/// @defgroup cmd cmd
/// @ingroup vm
/// @brief @ref commands
/// @{

/// @name flow control
/// @{
extern void nop();   ///> `( -- )` no operation
extern void halt();  ///> `( -- )` stop system
/// @}

/// @name debug
/// @{
extern void dump();  ///> `( -- )` print @ref VM state
/// @}

/// @}
