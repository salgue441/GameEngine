#!/bin/zsh

# Build directory
BUILD_DIR="build"

# Creating the directory 
mkdir -p $BUILD_DIR

# Change to build direcotry
cd $BUILD_DIR

# Cmake
cmake ..

# Build the project
make

# Run the executable
./bin/GameEngine

# Clean up
make clean
cd ..

