/**
 * @file window.h
 * @author Carlos Salguero
 * @brief Declaration of the Window class
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#pragma once

// Standard libraries
#include <cstdint>
#include <stdexcept>

// GLFW libraries
#include <GLFW/glfw3.h>

// Project headers
#include "time.h"

/**
 * @brief
 * Class that handles the window creation and management
 */
class Window
{
public:
    // Constructors
    Window() = default;
    explicit Window(std::uint32_t, std::uint32_t, const char *) noexcept;

    // Destructor
    ~Window() = default;

    // Access Methods
    std::uint32_t get_width() const noexcept;
    std::uint32_t get_height() const noexcept;
    GLFWwindow *get_window() const noexcept;
    const char *get_title() const noexcept;
    bool is_running() const noexcept;

    // Methods
    void init();
    void terminate();
    void update();
    void render();

private:
    std::uint32_t m_width;
    std::uint32_t m_height;
    GLFWwindow *m_window;
    const char *m_title;

    bool m_is_running;
    Time m_time;
};

#endif //! WINDOW_H