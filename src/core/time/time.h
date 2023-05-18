/**
 * @file time.h
 * @author Carlos Salguero
 * @brief Declaration of the Time class
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef TIME_H
#define TIME_H

#pragma once

// C++ Standard Library
#include <chrono>

/**
 * @brief
 * Class that represents the time of the application
 */
class Time
{
public:
    // Constructors
    Time();

    // Destructor
    ~Time() = default;

    // Access Methods
    float get_elapsed_time() const noexcept;
    float get_delta_time() const noexcept;

    // Functions
    void update();

private:
    std::chrono::high_resolution_clock::time_point m_start_time;
    std::chrono::high_resolution_clock::time_point m_previous_frame_time;
    float m_delta_time;
};

#endif //! TIME_H