# Snake Game

A classic implementation of the Snake game developed in C++ using the SFML library[cite: 11, 12].

## Project Overview
This project follows a clean architectural pattern, separating the game logic from the user interface and input handling[cite: 11]. It is designed to be built using CMake with strict compiler standards[cite: 12].

## Architecture
* **SNAKEBoard**: Manages the game state, grid logic, and collision detection[cite: 11].
* **SNAKEController**: Handles user input and interactions[cite: 11].
* **SNAKEView**: Responsible for rendering the game assets and graphics[cite: 11].
* **main.cpp**: The primary entry point for the application[cite: 11].

## Prerequisites
* **C++ Compiler**: Supports C++17 or higher[cite: 12].
* **SFML**: Version 2.5.1[cite: 12].
* **CMake**: Version 3.26 or higher[cite: 12].

## Build Instructions
1. Open the project folder in **VS Code**[cite: 12].
2. Ensure the **CMake Tools** extension is installed[cite: 12].
3. If using Windows, verify that the `CMakeLists.txt` path matches your local SFML installation (`C:/lib/SFML-2.5.1/`)[cite: 12].
4. Build the project using the CMake build button in the bottom status bar[cite: 12].
5. The executable `SNAKE` will be generated in the build directory[cite: 12].

## Troubleshooting
* If the game fails to start, ensure the `assets` are in the same folder as the `SNAKE` executable[cite: 11].
* If you encounter compilation errors, double-check that your `CMakeLists.txt` is correctly linked to your SFML library directory[cite: 12].