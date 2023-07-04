/**
 * @file renderer.cpp
 * @author Carlos Salguero
 * @brief Implementation of the Renderer class
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */
// C++ Standard Library
#include <GL/gl.h>

// Project Headers
#include "renderer.h"

// Access Methods
/**
 * @brief
 * Get the resource path
 * @return const std::string& Path to the resources folder
 */
const std::string &Renderer::get_resource_path() const
{
    return m_resource_path;
}

// Methods
/**
 * @brief
 * Clear the screen
 */
void Renderer::clear()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

/**
 * @brief
 * Render the screen
 */
void Renderer::render()
{
    m_window->swap_buffers();
}

/**
 * @brief
 * Draw a triangle
 * @param x1 X coordinate of the first vertex
 * @param y1 Y coordinate of the first vertex
 * @param x2 X coordinate of the second vertex
 * @param y2 Y coordinate of the second vertex
 * @param x3 X coordinate of the third vertex
 * @param y3 Y coordinate of the third vertex
 */
void Renderer::draw_triangle(float x1, float y1, float x2,
                             float y2, float x3, float y3)
{
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

/**
 * @brief
 * Draw a rectangle
 * @param x X coordinate of the rectangle
 * @param y Y coordinate of the rectangle
 * @param width Width of the rectangle
 * @param height Height of the rectangle
 */
void Renderer::draw_rectangle(float x, float y, float width, float height)
{
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

/**
 * @brief
 * Draw a texture on the screen
 * @param texture_name Name of the texture
 * @param x X coordinate of the texture
 * @param y Y coordinate of the texture
 */
void Renderer::draw_texture(const std::string &texture_name,
                            float x, float y)
{
    m_resource_manager->load_resource(texture_name, m_resource_path);

    auto texture = m_resource_manager->get_texture(texture_name);
}