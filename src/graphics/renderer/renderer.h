/**
 * @file renderer.h
 * @author Carlos Salguero
 * @brief Declaration of the Renderer class
 * @version 0.1
 * @date 2023-07-01
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef RENDERER_H
#define RENDERER_H

// C++ Standard Library
#include <memory>
#include <string>
#include <vector>

// Project Headers
#include "../../core/window/window.h"

// Class
/**
 * @class Renderer
 * @brief Handles the rendering of the game
 */
class Renderer
{
public:
    // Constructors
    Renderer() = default;

    // Deleted Constructors
    Renderer(const Renderer &) = delete;
    Renderer(Renderer &&) = delete;

    // Destructor
    ~Renderer() = default;

    // Access Methods
    const std::string &get_resource_path() const;

    // Deleted Operators
    Renderer &operator=(const Renderer &) = delete;
    Renderer &operator=(Renderer &&) = delete;

    // Methods
    void clear();
    void render();

    void draw_triangle(float, float, float, float, float, float);
    void draw_rectangle(float, float, float, float);
    void draw_texture(const std::string &, float, float);

private:
    std::string m_resource_path;
    std::unique_ptr<Window> &m_window;
};

#endif //! RENDERER_H