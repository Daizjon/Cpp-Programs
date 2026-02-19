# Bitmatrix (GF(2) Matrix Library + CLI Editor)

## Overview

Bitmatrix is a C++ implementation of a binary matrix library operating over **GF(2)** (modulo 2 arithmetic). Each matrix entry is either `0` or `1`, and all arithmetic operations (sum, product, row addition) are performed using mod-2 logic (XOR behavior).

The project includes:

- A reusable `Bitmatrix` class
- Matrix operations such as sum and product
- Row operations for linear algebra over GF(2)
- File I/O support
- PGM image export
- A hash table for storing matrices by key
- An interactive command-line editor for creating and manipulating matrices



## Files

- `bitmatrix.hpp` — Class definitions for `Bitmatrix`, GF(2) operations, and `BM_Hash`.
- `bitmatrix.cpp` — Implementation of matrix functionality and hash table logic.
- `bitmatrix_editor.cpp` — Interactive CLI program for building, modifying, and testing matrices.



## Core Features

### Matrix Construction

- `Bitmatrix(rows, cols)` — Creates an empty matrix of size `rows × cols`.
- `Bitmatrix(filename)` — Loads a matrix from a text file containing only `0`, `1`, and whitespace.
- `Copy()` — Returns a deep copy of the matrix.

### Matrix Access & Modification

- `Rows()` / `Cols()` — Returns matrix dimensions.
- `Val(row, col)` — Returns `'0'` or `'1'`. Returns `'x'` if indices are invalid.
- `Set(row, col, val)` — Sets entry to `0` or `1`.
- `Swap_Rows(r1, r2)` — Swaps two rows.
- `R1_Plus_Equals_R2(r1, r2)` — Performs row addition (XOR):  
  `row[r1] = row[r1] + row[r2] (mod 2)`



## File Output & Visualization

- `Write(filename)` — Writes matrix to file (one row per line).
- `Print(w)` — Prints matrix to stdout with optional grouping every `w` columns/rows.
- `PGM(filename, pixels, border)` — Exports matrix to a grayscale PGM image:
  - `0` values → white
  - `1` values → gray
  - Optional border spacing



## Matrix Operations (GF(2))

- `Sum(a1, a2)` — Element-wise addition mod 2.
- `Product(a1, a2)` — Matrix multiplication mod 2.
- `Sub_Matrix(a1, rows)` — Creates a new matrix using selected row indices.
- `Inverse(m)` — Declared but not implemented (returns `NULL`).



## Hash Table Support

Matrices can be stored and retrieved by string key using `BM_Hash`.

- `Store(key, matrix)`
- `Recall(key)`
- `All()`

Uses `djb_hash` with separate chaining.



## Build

Using g++:

```bash
g++ -std=c++11 -O2 -o bitmatrix_editor bitmatrix.cpp bitmatrix_editor.cpp
```

Or use the provided Makefile:

```bash
make
```



## Run

```bash
./bitmatrix_editor
```

Optional custom prompt:

```bash
./bitmatrix_editor "bm>"
```



## Interactive Commands

Type `?` inside the program to print help.

Supported commands:

- `EMPTY rows cols`
- `READ filename`
- `SET row col val`
- `VAL row col`
- `SWAP r1 r2`
- `+= r1 r2`
- `WRITE filename`
- `PRINT [w]`
- `PGM filename pixels border`
- `STORE key`
- `RECALL key`
- `ALL`
- `SUM key1 key2`
- `PRODUCT key1 key2`
- `SUB r1 r2 ...`
- `INVERT`
- `QUIT`



## Input File Format

Matrix files must contain:

- Only `0` and `1`
- Optional spaces
- One row per line

Invalid characters trigger `"Bad file format"`.



## Notes

- All arithmetic is performed in GF(2).
- `Inverse()` is currently not implemented.
- Compiled object files (`*.o`) should not be committed to the repository.
- This project demonstrates matrix manipulation, file parsing, modular arithmetic, hashing, and CLI command parsing in C++.

