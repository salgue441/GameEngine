cmake_minimum_required(VERSION 3.21)
project(GameEngine)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Source files
file(GLOB_RECURSE SOURCES
    "src/*.cpp"
    "src/*.h"
)

# Directories
include_directories(src)

# Executable
add_executable(GameEngine ${SOURCES})

# Target Properties
target_include_directories(GameEngine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_compile_options(GameEngine PRIVATE -Wall -Wextra -pedantic)

# Required libraries
find_package(OpenGL REQUIRED)

# Set GLEW directories manually
set(GLEW_INCLUDE_DIRS "/usr/include")
set(GLEW_LIBRARIES "/usr/lib/x86_64-linux-gnu/libGLEW.so")

target_include_directories(GameEngine PRIVATE ${GLEW_INCLUDE_DIRS})
target_link_libraries(GameEngine PRIVATE
    OpenGL::GL
    ${GLEW_LIBRARIES}
    glfw
)

# Additional libraries & Dependencies
# target_link_libraries(GameEngine PRIVATE)

# Output Directory
set_target_properties(GameEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Any additional compiler flags
# target_compile_options(GameEngine PRIVATE -O3)
