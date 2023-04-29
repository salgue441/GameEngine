/**
 * @file main.cpp
 * @author Carlos Salguero
 * @brief Main file of the Game Engine
 * @version 0.1
 * @date 2023-04-28
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

// Project Files
#include "core/window.h"

int main()
{
    std::uint32_t width{800};
    std::uint32_t height{600};

    Window window(width, height, "Game Engine");

    try
    {
        window.init();
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << "Runtime error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    window.run();
}