/**
 * @file window.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Window class
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "window.h"

// Constructors
/**
 * @brief
 * Construct a new Window:: Window object
 * @param width Width of the window
 * @param height Height of the window
 * @param title Title of the window
 */
Window::Window(std::uint32_t width, std::uint32_t height, const char *title) noexcept
    : m_width(width), m_height(height), m_title(title)
{
}

// Access Methods
/**
 * @brief
 * Get the width of the window
 * @return std::uint32_t Width of the window
 */
std::uint32_t Window::get_width() const noexcept
{
    return m_width;
}

/**
 * @brief
 * Get the height of the window
 * @return std::uint32_t Height of the window
 */
std::uint32_t Window::get_height() const noexcept
{
    return m_height;
}

/**
 * @brief
 * Get the GLFWwindow object
 * @return GLFWwindow* GLFWwindow object
 */
GLFWwindow *Window::get_window() const noexcept
{
    return m_window;
}

/**
 * @brief
 * Get the title of the window
 * @return const char* Title of the window
 */
const char *Window::get_title() const noexcept
{
    return m_title;
}

// Methods
/**
 * @brief
 * Initialize the window
 */
void Window::init()
{
    if (!glfwInit())
    {
        std::runtime_error("Error initializing GLFW");
        std::exit(EXIT_FAILURE);
    }

    m_window = glfwCreateWindow(m_width, m_height, m_title,
                                nullptr, nullptr);

    if (!m_window)
    {
        std::runtime_error("Error creating the window");
        std::exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(m_window);
}

/**
 * @brief
 * Run the window
 */
void Window::run()
{
    while (!glfwWindowShouldClose(m_window))
    {
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

/**
 * @brief
 * Terminate the window
 */
void Window::terminate()
{
    glfwTerminate();
}