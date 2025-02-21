#pragma once

#include "hw.hpp"

// #include <stddef.h>
// #include <string>
// #include <stdexcept>

/// @defgroup gc gc
/// @brief garbage collection
/// @ingroup core

/// @defgroup object object
/// @brief @ref ograph elements
/// @ingroup core
/// @{

/// @brief core @ref Object
/// @details provides common behaviour like @ref gc etc
class Object {
   public:
    /// @name constructor / destructor
    /// @{
    Object();
    // Object(char* literal);
    // virtual ~Object();
    // /// @}

    //     /// @name dump / stringify
    //     /// @{
    //     /// @brief type/class tag
    //     virtual std::string tag() const;
    //     /// @brief @ref value in string format
    //     virtual std::string val() const;
    //     /// @brief `<T:V>` header
    //     virtual std::string head(std::string prefix = "") const;
    //     /// @brief full text tree dump
    //     virtual std::string dump() const;
    //     /// @}

    //     /// @name exec/compile
    //     /// @{
    //     virtual void exec();  ///< @brief execute in @ref vm context
    //     virtual void comp();  ///< @brief compile in @ref vm context

    //     /// @}

    //     /// @name unimplemented stubs
    //     /// @brief methods not applicable for some types
    //     /// @{
    //     /// @ref Add
    //     virtual Object* add(Object*) const { throw
    //     std::invalid_argument("::add"); }
    //     /// @ref Sub
    //     virtual Object* sub(Object*) const { throw
    //     std::invalid_argument("::sub"); }
    //     /// @ref Mul
    //     virtual Object* mul(Object*) const { throw
    //     std::invalid_argument("::mul"); }
    //     /// @ref Div
    //     virtual Object* div(Object*) const { throw
    //     std::invalid_argument("::div"); }

    //     /// @}

    //    protected:
    //     /// @name <T:V>
    //     /// @{
    //     std::string value;  ///< object name / literal value
    //                         ///< @details `string` is the most univeral data
    //                         type

    //     /// @}

   private:
    /// @ingroup gc
    /// @{
    uint ref = 0;         ///< reference counter
    static Object* pool;  ///< global object pool (linked list)
    static void gc();     ///< garbage collection
    /// @}
};

/// @}

// /// @defgroup object object
// /// @ingroup cli
// /// @{

// /// @brief core Object model
// class Object {
//    public:

// /// @}
