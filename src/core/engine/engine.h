/**
 * @file engine.h
 * @author Carlos Salguero
 * @brief Declaration of the Engine class
 * @version 0.1
 * @date 2023-04-29
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef ENGINE_H
#define ENGINE_H

#pragma once

// Standard libraries
#include <iostream>
#include <memory>

// Project headers
#include "../window/window.h"
#include "../../resource/resource_manager.h"
#include "../../graphics/renderer/renderer.h"
#include "../../utils/logging/logging.h"

/**
 * @brief
 * Class that handles the engine
 */
class Engine
{
public:
    // Constructor
    Engine() = default;
    explicit Engine(std::uint32_t, std::uint32_t, const char *) noexcept;

    // Destructor
    ~Engine() = default;

    // Methods
    void run();

private:
    std::unique_ptr<Window> m_window;
    std::unique_ptr<ResourceManager> m_resource_manager;
    std::unique_ptr<Renderer> m_renderer;
    std::unique_ptr<Logging> m_logging;

    // Methods
    void update();
    void render();
};

#endif //! ENGINE_H