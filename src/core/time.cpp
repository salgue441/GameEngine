/**
 * @file time.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Time class
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "time.h"

// Constructors
/**
 * @brief
 * Construct a new Time:: Time object
 */
Time::Time() : m_delta_time(0.0)
{
    this->m_start_time = std::chrono::high_resolution_clock::now();
    this->m_previous_frame_time = m_start_time;
}

// Access Methods
/**
 * @brief
 * Get the elapsed time since the start of the application
 * @return float Elapsed time since the start of the application
 */
float Time::get_elapsed_time() const noexcept
{
    auto current_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration<float, std::chrono::seconds::period>(current_time - m_start_time).count();

    return elapsed_time;
}

/**
 * @brief
 * Get the delta time between frames
 * @return float Delta time between frames
 */
float Time::get_delta_time() const noexcept
{
    return m_delta_time;
}

// Functions
/**
 * @brief
 * Update the time
 */
void Time::update()
{
    auto current_time =
        std::chrono::high_resolution_clock::now();

    m_delta_time =
        std::chrono::duration<float, std::chrono::seconds::period>(
            current_time - m_previous_frame_time)
            .count();

    m_previous_frame_time = current_time;
}