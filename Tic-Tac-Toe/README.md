# Tic-Tac-Toe (CLI)

An interactive terminal-based Tic-Tac-Toe game written in C++.

Supports variable board sizes (NxN). Two players take turns entering coordinates to place `X` and `O` until one wins or the game ends in a tie.



## Files

- `tic-tac-toe-cli.cpp` — Main interactive game
- `tic-tac-toe-checker.cpp` — Board evaluation/checking utility
- `Makefile`
- `README.md`



## Build

### Using g++

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o tic tac-toe-cli.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o ticcheck tic-tac-toe-checker.cpp
```

### Using Make (if Makefile is present)

```bash
make
```



## Run

### Play the game

```bash
./tic
```

(Or whatever executable name you chose when compiling.)



## Gameplay Instructions

1. Enter grid size when prompted (e.g., `3` for 3x3).
2. Players take turns entering:
   ```
   row column
   ```
   Example:
   ```
   1 2
   ```
   This places the player's marker in row 1, column 2.

3. The board updates after every move.
4. Game ends when:
   - A player completes a row, column, or diagonal.
   - The board fills (Tie).



## Features

- Custom board size (2x2 up to 5x5 tested)
- Turn-based two-player system
- Input validation for:
  - Out-of-range coordinates
  - Occupied cells
- Win detection:
  - Rows
  - Columns
  - Diagonals
- Tie detection



## Example Output

```
Enter grid size:
3
_ _ _
_ _ _
_ _ _

Player 1 (X) pick cell:
1 1

X _ _
_ _ _
_ _ _
```



## Concepts Demonstrated

- 2D arrays
- Input validation
- Game loop logic
- Conditional win checking
- Dynamic board sizing
- CLI interaction
