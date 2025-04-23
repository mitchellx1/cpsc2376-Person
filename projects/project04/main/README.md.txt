# Project 04 – AmazeGame

## 🎮 Description

AmazeGame is a single-player puzzle game built in C++ using SDL2. The objective is to move the player across a grid, painting all available walkable tiles. The player moves in a straight line in the chosen direction until hitting a wall.

This version includes a graphical interface using SDL2, a level progression system, and on-screen text for the current level, timer, and basic instructions.

## 🕹️ Controls

- Arrow Keys: Move the player
- Enter: Start the game (from the menu) or restart from win screen
- ESC: Exit the game

## ✅ Features

- Level progression from Level 1 to 3
- No manual level selection required
- Simple GUI with colored tiles representing player, walls, empty, and painted cells
- Text-based UI using SDL_ttf for timer, level info, and instructions
- Menu screen before starting
- Win screen after completing all levels

## 🧪 Build Instructions

1. Ensure SDL2 and SDL_ttf are installed via vcpkg:
    ```
    vcpkg install sdl2 sdl2-ttf:x64-windows
    ```

2. Link SDL2 and SDL_ttf in your Visual Studio project:
    - Add `SDL2.lib` and `SDL2_ttf.lib` to linker input
    - Add appropriate include and lib directories to VC++ directories

3. Copy a `.ttf` font to your working directory, e.g., `C:\\Windows\\Fonts\\arial.ttf`, or adjust the font path in `main.cpp`.

4. Compile and run the project in Visual Studio (x64, Debug or Release)

## 📷 Screenshot

![Screenshot](screenshot.png)


## 🧠 Notes

This project was built as a class assignment to demonstrate SDL2 integration, event handling, and level design logic in a C++ application.
