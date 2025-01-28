#pragma once

#include <stddef.h>
#include <string>

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
    Object(char *literal);
    virtual ~Object();
    /// @}

    /// @name dump / stringify
    /// @{
    /// @brief type/class tag
    virtual std::string tag() const;
    /// @brief @ref value in string format
    virtual std::string val() const;
    /// @brief `<T:V>` header
    virtual std::string head(std::string prefix = "") const;
    /// @brief full text tree dump
    virtual std::string dump() const;
    /// @}

    /// @name exec/compile
    /// @{
    /// @brief execute in @ref vm context
    virtual void exec();
    /// @brief compile in @ref vm context
    virtual void comp();
    /// @}

   protected:
    /// @name `<T:V>`
    /// @{
    std::string value;  ///< object name / literal value
                        /// @}
   private:
    /// @ingroup gc
    /// @{
    size_t ref;  ///< reference counter
    /// @}
};

/// @}
