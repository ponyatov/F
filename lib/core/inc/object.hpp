#pragma once

#include <stddef.h>
#include <string>

/// @defgroup gc gc
/// @brief garbage collection
/// @ingroup core

/// @defgroup object object
/// @brief core @ref Object
/// @ingroup core
/// @{

/// @brief core @ref Object
/// @details provides common behaviour like @ref gc etc
class Object {
    /// @ingroup gc
    /// @{
    size_t ref;  ///< reference counter
    /// @}

    /// @name `<T:V>`
    /// @{
    std::string value;  ///< object name / literal value

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
