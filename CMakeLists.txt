# Cmake
cmake_minimum_required(VERSION 3.21)
project(GameEngine)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set source files
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.h"
)

# Directories
include_directories(src)

# Add executable
add_executable(GameEngine ${SOURCES})

# Link libraries
target_compile_definitions(GameEngine PRIVATE -DGLFW_INCLUDE_NONE)
target_compile_options(GameEngine PRIVATE -Wall -Wextra -pedantic)  

# Required libraries
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# Link libraries
target_link_libraries(GameEngine PRIVATE 
    OpenGL::GL
    glfw
    GLEW::GLEW
    ${CMAKE_DL_LIBS}
)

# Output Directory
set_target_properties(GameEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)