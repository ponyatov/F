#pragma once

#include <stddef.h>
#include <string>

/// @defgroup object object
/// @ingroup core
/// @{

class Object {
    /// @ingroup gc
    /// @{
    size_t ref;
    /// @}
    /// @name `<T:V>`
    /// @{
    std::string value;
    /// @}
   public:
    /// @name constructor / destructor
    /// @{
    Object();
    Object(char *literal);
    virtual ~Object();
    /// @}
    /// @name dump / stringify
    /// @{
    /// @brief type/class tag
    virtual std::string tag();
    /// @brief @ref value in string format
    virtual std::string val();
    /// @brief `<T:V>` header
    virtual std::string head();
    /// @brief full text tree dump
    virtual std::string dump();
    /// @}
};

/// @}
