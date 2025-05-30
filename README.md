# Symphony of Symbols: A C++ Console Match-Three Puzzle Game

This repository contains "Symphony of Symbols," a classic **Match-Three puzzle game** implemented in **C++** for the console. Developed as an academic project, it offers a fundamental understanding of game logic, console I/O, and basic game state management.

## Project Overview

"Symphony of Symbols" challenges players to strategically swap adjacent symbols on a 10x10 board to create horizontal or vertical matches of three or more identical symbols. The game features cascading matches, score tracking, and unique "trap" symbols to add depth to the gameplay.

## Features

* **Classic Match-Three Gameplay:** Swap adjacent symbols (`!`, `@`, `#`, `$`, `%`) to form horizontal or vertical lines of three or more identical symbols.
* **10x10 Game Board:** A standard grid size for engaging puzzle play.
* **Cascading Matches:** When a match is cleared, symbols above fall to fill the empty spaces, potentially creating new matches automatically. New random symbols fill the top rows.
* **Score Tracking:** Points are awarded for successful matches.
* **Life System:** Players have a limited number of lives, which can be lost by hitting certain "trap" symbols.
* **Special "Trap" Symbols:** Beyond standard matching symbols, a 'D' (red) symbol acts as a trap, reducing the player's lives upon being matched.
* **Visual Feedback:** Matched symbols are temporarily replaced with `'-'` to highlight cleared areas before new symbols fall into place.
* **Save/Load Game:** Players can save their current game progress to a text file (`SymphonyOfSymbols.txt`) and load it later to resume playing.
* **Windows Console Specific:** Utilizes `windows.h` for console-specific features like `Sleep()` for pauses and `system("CLS")` for screen clearing.

## How to Play

1.  The game board is displayed with a 10x10 grid of symbols.
2.  **Input Coordinates:** Enter the **ROW** and **COLUMN** numbers (0-9) of the symbol you wish to move.
3.  **Choose Swap Direction:** Enter `W` (Up), `S` (Down), `D` (Right), or `A` (Left) to swap your chosen symbol with an adjacent one.
4.  **Match for Points:** If your swap creates a match of 3 or more symbols, those symbols will disappear, new symbols will fall, and you'll earn points. Swaps that do not create an immediate match will be reverted, and you will lose 10 points.
5.  **Special Symbol 'D':** Matching the 'D' symbol will result in losing a life.
6.  **Continue or Quit:**
    * Press `<Y>` to continue playing.
    * Press `<X>` to stop the game.
    * Press `<S>` to save your current game to `SymphonyOfSymbols.txt`.
    * Press `<L>` to load a previously saved game.

## Code Structure

The program is organized into several distinct functions, each responsible for a specific aspect of the game:

* **`main()`:** The entry point of the program, initializes the board, starts the game loop, and displays the final message.
* **`create_board(char Board[][10])`:** Initializes the 10x10 game board with random symbols. It includes a call to `check_board` to ensure the starting board contains no immediate matches.
* **`get_random_shape()`:** Generates a random symbol (`!`, `@`, `#`, `$`, `%`) for the board.
* **`swapping(char Board[][10])`:** Contains the main game loop. It handles user input for swaps, performs the swap, checks for matches, updates the score, and manages save/load/quit options.
* **`check_board(char Board[][10], bool show_cin)`:** This is the core match-detection and board-refill logic.
    * It iterates through the board to find horizontal and vertical matches of 3 or more.
    * If `show_cin` is `true` (called from `swapping`), it visually highlights matches by replacing them with `'-'` temporarily.
    * It then "drops" symbols down to fill empty spaces and generates new random symbols for the top row.
    * Crucially, it **recursively calls itself** to detect and clear any new matches formed by cascading symbols, ensuring all chain reactions are resolved.
    * It returns a boolean indicating whether the last swap *did not* result in a match (used to revert the swap in `swapping`).
* **`refresh_board(char Board[][10])`:** Clears the console screen and prints the current state of the game board.
* **`Save_Game(char Board[][10])`:** Writes the current board state to `SymphonyOfSymbols.txt`.
* **`Load_Game(char Board[][10])`:** Reads a board state from `SymphonyOfSymbols.txt` and updates the game board.
