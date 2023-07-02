/**
 * @file logging.h
 * @author Carlos Salguero
 * @brief Defines the logging functions
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LOGGING_H
#define LOGGING_H

// C++ Standard Library
#include <iostream>
#include <string>

// Classes
/**
 * @class Logging
 * @brief Defines the logging functions
 */
class Logging
{
public:
    // Public Methods
    void log(const std::string &) const;
    void log(const std::string &, const std::string &) const;

    // Public Static Methods
    static Logging &get_instance();

    // Public Static Attributes
    static const std::string INFO;
    static const std::string WARNING;
    static const std::string ERROR;

private:
    // Attributes
    static Logging *instance;

    // Constructors
    Logging() = default;
};

#endif //! LOGGING_H