#pragma once

#include "hw.hpp"
#include "os.hpp"

/// @defgroup cvm cvm
/// @brief /c Virtual Machine
/// @details CLI / compact / microControlller / C
/// - minimized / bytecode
/// - minimal class wrappers (only for code readability)
/// @ingroup cli
/// @{

/// @brief @ref cmd opcode
/// @ingroup cmd
enum class Op : byte {
    nop = 0x00,   ///< @ref nop
    halt = 0xFF,  ///< @ref halt
                  //
    dup = 0x10,   ///< @ref dup
    drop = 0x11,  ///< @ref drop
    swap = 0x12,  ///< @ref swap
    over = 0x13,  ///< @ref over
                  //
    add = 0x20,   ///< @ref add
    sub = 0x21,   ///< @ref sub
    mul = 0x22,   ///< @ref mul
    div = 0x23,   ///< @ref div
                  //
    dump = 0x30,  ///< @ref dump
    key = 0x31,   ///< @ref key
    emit = 0x32,  ///< @ref emit
};

extern const char *op_dump(Op op);

/// @brief `<T:` type tag
enum class T : int {
    NIL,   ///< `<nil:` null
    BOOL,  ///< `<bool:` boolean
    BYTE,  ///< `<byte:>` single byte
    INT,   ///< `<int:` integer
    HEX,   ///< `<hex:` hexadecimal
    OCT,   ///< `<hex:` octal
    BIN,   ///< `<hex:` binary
    NUM,   ///< `<num: floating point
    CHAR,  ///< `<char:` single character
    STR,   ///< `<str:` ASCII string
    ID,    ///< `<id:` symbol/name/identifier
    PTR,   ///< `<ptr:` raw pointer
    CMD,   ///< `<cmd:op>` @ref vm command with @ref Op

};

/// @brief dump @ref T in string representation
extern const char *t_dump(T t);

/// @brief `:V>` value union (tagged by @ref T)
union V {
    bool b;
    int n;
    float f;
    char c;
    char *s;
    void *p;  ///< @ref T::PTR
    Op op;    /// @ref Op
};

/// @brief typed data cell on @ref D stack
struct Cell {
    T t;  ///< @ref
    V v;  ///<
};

/// @name VM config
/// @{

/// @brief @ref D size
#define Dsz 0x10
/// @brief @ref R size
#define Rsz 0x100
/// @brief @ref M size
#define Msz 0x100
/// @}

/// @name VM memory
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

/// @brief `( o -- )` pop @ref Cell into C(++) code
extern Cell pop();

/// @}

/// @}

/// @defgroup cmd cmd
/// @ingroup cvm
/// @brief commands
/// @{

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
