/**
 * @file logging.cpp
 * @author Carlos Salguero
 * @brief Implements the logging functions
 * @version 0.1
 * @date 2023-07-03
 *
 * @copyright Copyright (c) 2023
 *
 */

// C++ Standard Library
#include <iostream>

// Project files
#include "logging.h"

// static attributes
Logging *Logging::instance = nullptr;

// Public Methods
/**
 * @brief
 * Logs a message
 * @param message The message to log
 */
void Logging::log(const std::string &message) const
{
    std::cout << message << std::endl;
}

/**
 * @brief
 * Logs a message with a tag
 * @param tag The tag to use
 * @param message The message to log
 */
void Logging::log(const std::string &tag, const std::string &message) const
{
    std::cout << tag << ": " << message << std::endl;
}

// Public Static Methods
/**
 * @brief
 * Gets the instance of the class
 * @return Logging& The instance of the class
 */
Logging &Logging::get_instance()
{
    if (instance == nullptr)
        instance = new Logging();

    return *instance;
}
