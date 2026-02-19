# Dynamic Bitset (C++)

## Overview

This project implements a custom dynamic `BITSET` class in C++ that stores and manipulates a large number of Boolean values (0 or 1) using bitwise operations.

Instead of using `std::bitset`, this implementation manually manages bits inside a dynamically growing `std::vector<int>`, where each integer stores 32 bits.

The program includes a simple command-line interface allowing interactive bit manipulation.



## Features

- Dynamically grows to support arbitrarily large bit indices
- Efficient bit storage using bitwise operators
- Automatic shrinking when high-order sets become zero
- Interactive command-line control
- Binary set visualization grouped in 4-bit chunks



## Implementation Details

Each element in the internal vector stores 32 bits:

- `bit_index / 32` → selects which integer (set)
- `bit_index % 32` → selects which bit within that integer

Bitwise operators used:

- `|` (OR) → Set a bit
- `^` (XOR) → Clear a bit
- `>>` (Right shift) → Test a bit
- `&` (AND) → Extract bit value
- `<<` (Left shift) → Position bit mask



## File Structure

```
bitset.cpp
README.md
```



## Build

Compile with:

```bash
g++ bitset.cpp -o bitset
```



## Run

```bash
./bitset
```



## Interactive Commands

The program continuously prompts for commands:

```
t <bit>  - Test a bit (prints 1 or 0)
s <bit>  - Set a bit to 1
c <bit>  - Clear a bit to 0
p <set>  - Print 32-bit binary representation of a set
q        - Quit program
```



## Example Session

```
s 5
t 5
1
p 0
0000 0000 0000 0000 0000 0000 0010 0000
```



## Design Highlights

- Automatically expands storage when setting high bit indices
- Automatically shrinks storage when clearing trailing sets
- Maintains at least one set at all times
- Efficient memory usage compared to naive Boolean arrays



## Educational Concepts Demonstrated

- Bitwise manipulation
- Dynamic memory management
- Vector resizing
- CLI parsing with `scanf`
- Binary formatting
- Low-level data representation



## Notes

- Bits are grouped in 4-bit chunks for readability.
- Each “set” represents 32 bits.
- Clearing a bit may reduce storage size if upper sets become zero.
- This implementation uses `int` (32-bit) storage blocks.

