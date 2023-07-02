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
#include "../../lib/stb_image.h"

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

// /**
//  * @brief
//  * Draws a texture on the screen
//  * @param texture_path Path to the texture
//  * @param x X coordinate of the texture
//  * @param y Y coordinate of the texture
//  */
// void Renderer::draw_texture(const std::string &texture_path, float x, float y)
// {
//     // Load the texture
//     GLuint texture_id;
//     glGenTextures(1, &texture_id);
//     glBindTexture(GL_TEXTURE_2D, texture_id);

//     // Set the texture wrapping/filtering options (on the currently bound texture object)
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
//                     GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,
//                     GL_REPEAT);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
//                     GL_LINEAR);
//     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
//                     GL_LINEAR);

//     // Load image, create texture and generate mipmaps
//     int width, height, nr_channels;

//     stbi_set_flip_vertically_on_load(true);
//     unsigned char *data = stbi_load(texture_path.c_str(),
//                                     &width, &height,
//                                     &nr_channels,
//                                     0);

//     if (data)
//     {
//         glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
//                      width, height, 0, GL_RGB,
//                      GL_UNSIGNED_BYTE, data);

//         // glGenerateMipmap(GL_TEXTURE_2D);
//     }
//     else
//         throw std::runtime_error("Failed to load texture");

//     stbi_image_free(data);

//     // Render the texture
//     glBindTexture(GL_TEXTURE_2D, texture_id);
//     glBegin(GL_QUADS);

//     glTexCoord2f(0.0f, 0.0f);
//     glVertex2f(x, y);

//     glTexCoord2f(1.0f, 0.0f);
//     glVertex2f(x + width, y);

//     glTexCoord2f(1.0f, 1.0f);
//     glVertex2f(x + width, y + height);

//     glTexCoord2f(0.0f, 1.0f);
//     glVertex2f(x, y + height);

//     glEnd();
//     glDeleteTextures(1, &texture_id);
// }