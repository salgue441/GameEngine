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
#include "core/engine.h"

int main()
{
    Engine engine(800, 600, "Game Engine");
    engine.run();

    return EXIT_SUCCESS;
}