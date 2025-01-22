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
};

/// @}
