# Checkerboard Generator (C++)

## Overview

This program generates a generalized checkerboard pattern and prints it to standard output.

A generalized checkerboard is defined by five parameters:

- **R** — Number of rows
- **C** — Number of columns
- **SC** — Starting character
- **CS** — Cycle size (number of characters to cycle through)
- **W** — Width/height of each cell

Each element in row `r` and column `c` is:

SC + ((r + c) % CS)

Each element is printed as a `W x W` square.



## File Structure

```
checkerboard.cpp
README.md
```



## Build

Compile using g++:

```bash
g++ -std=c++11 -O2 -Wall -Wextra -o checkerboard checkerboard.cpp
```



## Run

The program reads five values from standard input in this order:

```
R C SC CS W
```

### Example

```bash
echo "5 6 a 4 1" | ./checkerboard
```

This means:

- R = 5 rows
- C = 6 columns
- SC = 'a'
- CS = 4 (cycle through a, b, c, d)
- W = 1 (each cell is 1×1)



## Output Behavior

- Prints `R * W` total lines
- Each printed line contains `C * W` characters
- Each cell in the logical grid is printed as a `W x W` block
- Characters cycle according to the formula:

```
char(SC + ((row + column) % CS))
```



## Input Validation

The program exits silently (prints nothing) if:

- `R <= 0`
- `C <= 0`
- `CS <= 0`
- `W <= 0`
- `SC + CS > 127`

If input parsing fails, it prints:

```
usage: checkerboard - stdin should contain R, C, SC, CS, and W
```



## Concepts Demonstrated

- Nested loop grid construction
- Modular arithmetic for pattern generation
- ASCII character manipulation
- Input validation using `cin`
- Deterministic pattern generation
