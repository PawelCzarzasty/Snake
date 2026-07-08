# Snake Game

A classic implementation of the Snake game developed in C++ using the SFML library.

## Project Overview
This project follows a clean architectural pattern, separating the game logic from the user interface and input handling. It is designed to be built using CMake with strict compiler standards.

## Architecture
* **SNAKEBoard**: Manages the game state, grid logic, and collision detection.
* **SNAKEController**: Handles user input and interactions.
* **SNAKEView**: Responsible for rendering the game assets and graphics.
* **main.cpp**: The primary entry point for the application.

## Prerequisites
* **C++ Compiler**: Supports C++17 or higher.
* **SFML**: Version 2.5.1.
* **CMake**: Version 3.26 or higher.

## Build Instructions
1. Open the project folder in **VS Code**.
2. Ensure the **CMake Tools** extension is installed.
3. If using Windows, verify that the `CMakeLists.txt` path matches your local SFML installation (`C:/lib/SFML-2.5.1/`).
4. Build the project using the CMake build button in the bottom status bar.
5. The executable `SNAKE` will be generated in the build directory.

## Troubleshooting
* If the game fails to start, ensure the `assets` are in the same folder as the `SNAKE` executable.
* If you encounter compilation errors, double-check that your `CMakeLists.txt` is correctly linked to your SFML library directory.