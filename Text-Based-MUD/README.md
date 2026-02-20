# Text-Based MUD (CLI Adventure Engine)

A simple text-based Multi-User Dungeon (MUD) engine written in C++.

The program loads a room map from a file and allows the player to navigate using single-letter commands.



## Files

- `text-mud-cli.cpp` — main game engine
- `rooms.txt` — room map data file
- `README.md`



## Build

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o mud text-mud-cli.cpp
```



## Run

```bash
./mud rooms.txt
```



## Game Controls

| Command | Action |
|----------|--------|
| `l` | Look at the current room |
| `n` | Move north |
| `s` | Move south |
| `e` | Move east |
| `w` | Move west |
| `q` | Quit the game |

If a direction does not exist from the current room, an error message is displayed.



## How the Room File Works

The room file (`rooms.txt`) uses the following structure:

```
Room Title
~
Room description text...
~
<direction> <room_index>
<direction> <room_index>
~
```

### Format Rules

- `~` marks section boundaries.
- Each room contains:
  1. Title
  2. Description (can span multiple lines)
  3. Exit definitions
- Exit format:
  ```
  n 3
  s 5
  e 2
  w 0
  ```
- The number corresponds to the index of the room in the file (starting at 0).



## Example Gameplay

```
> l
Room #0

You are at the start. Your journey begins..

Exits: s

> s
> l
Room #5

You're near the start.

Exits: e n
```



## Implementation Overview

- Uses a `Room` struct containing:
  - title
  - description
  - pointers to adjacent rooms (`n`, `s`, `e`, `w`)
- Dynamically builds a graph of connected rooms from the input file
- Maintains a pointer to the current room
- Command loop continues until user enters `q`



## Concepts Demonstrated

- File parsing with `fgets`
- Dynamic memory allocation
- Pointer-based graph structure
- Command-driven CLI interface
- Simple game loop design



## Notes

- Input file must follow the exact format.
- Invalid command-line usage will produce an error.
- Designed as a minimal text adventure engine.



## Possible Extensions

- Add items and inventory
- Add room events
- Add win conditions
- Add command parsing for full words (e.g., "north")
- Save/load game state
