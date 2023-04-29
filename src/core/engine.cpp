/**
 * @file engine.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Engine class
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "engine.h"

// Constructors
/**
 * @brief
 * Construct a new Engine:: Engine object
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
 */
Engine::Engine(std::uint32_t width, std::uint32_t height, const char *title) noexcept
    : m_window(width, height, title)
{
}

// Methods
/**
 * @brief
 * Run the engine
 */
void Engine::run()
{
    try
    {
        m_window.init();

        while (m_window.is_running())
        {
            m_window.update();
            m_window.render();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}