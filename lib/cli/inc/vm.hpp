#pragma once

/// @defgroup vm vm
/// @brief Virtual Machine
/// @ingroup core
/// @{

typedef unsigned int uint;   ///< generic insigned int
typedef unsigned char byte;  ///< byte alias

/// @brief `<T:` type tag
enum T : int { NIL, BOOL, INT, FLOAT, CHAR, STRING, ID };

/// @brief `:V>` value union
union V {
    bool b;
    int n;
    float f;
    char c;
    char *s;
    char *id;
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

/// @}

// #include "object.hpp"

// /// @brief Virtual Machine
// class VM : public Object {
//    public:
//     VM();
//     std::string val() const;
//     /// @name stack operations
//     /// @{
//     /// @brief `( -- o)`
//     void push(Object* o);
//     /// @brief `( o -- )`
//     Object* pop();
//     /// @brief `( ... -- )`
//     void clean();
//     /// @}

//    private:
//     /// @brief @ref D size
//     static const size_t Dsz = 0x10;
//     /// @brief data stack
//     Object* D[Dsz];
//     /// @brief @ref D pointer
//     uint8_t Dp;
// };

// /// @brief global main @ref VM
// extern VM vm;

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
