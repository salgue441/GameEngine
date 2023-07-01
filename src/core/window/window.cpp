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
// C++ Standard libraries
#include <iostream>
#include <stdexcept>
#include <GL/glew.h>

// Project headers
#include "window.h"

// Static methods
/**
 * @brief
 * Error callback function for GLFW
 * @param error Error code
 * @param description Description of the error
 */
void Window::error_callback(int error, const char *description) noexcept
{
    std::cerr << "GLFW Error (" << error << "): " << description << std::endl;
}

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

/**
 * @brief
 * Check if the window is running
 * @return true If the window is running
 * @return false If the window is not running
 */
bool Window::is_running() const noexcept
{
    return !glfwWindowShouldClose(m_window);
}

// Methods
/**
 * @brief
 * Initialize the window
 */
void Window::init()
{
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        throw std::runtime_error("Failed to initialize GLFW");

    // OpenGL context hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    m_window = glfwCreateWindow(m_width, m_height, m_title,
                                nullptr, nullptr);

    if (!m_window)
    {
        terminate();
        throw std::runtime_error("Failed to create GLFW window");
    }

    glfwMakeContextCurrent(m_window);

    info();
}

/**
 * @brief
 * Terminate the window
 */
void Window::terminate()
{
    if (m_window)
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }

    m_window = nullptr;
}

/**
 * @brief
 * Update the window
 */
void Window::update()
{
    glfwPollEvents();
}

/**
 * @brief
 * Render the window
 */
void Window::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glfwSwapBuffers(m_window);
}

// Methods (private)
/**
 * @brief
 * Shows the available information about the window (Properties, renderer,
 * OpenGL version, etc.)
 */
void Window::info() const noexcept
{
    std::cout << "Window information:" << std::endl;

    std::cout << "\tVendor: " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "\tRenderer: " << glGetString(GL_RENDERER) << std::endl;
    std::cout << "\tOpenGL version: " << glGetString(GL_VERSION) << std::endl;
    std::cout << "\tGLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION)
              << std::endl;

    std::cout << "\tWidth: " << m_width << std::endl;
    std::cout << "\tHeight: " << m_height << std::endl;
    std::cout << "\tTitle: " << m_title << std::endl;
}