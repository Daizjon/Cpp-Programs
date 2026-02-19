# PGM Manipulation (P2 ASCII)

This folder contains C++ programs for generating, inspecting, and transforming **P2 (ASCII) PGM grayscale images**.

All programs use standard input/output and perform validation on PGM structure where applicable.



## What is a P2 PGM?

A P2 PGM file is a plain-text grayscale image format with this structure:

```
P2
<columns> <rows>
255
<pixel values...>
```

- `P2` → ASCII grayscale format
- `<columns> <rows>` → image dimensions
- `255` → maximum pixel value
- Followed by `rows × columns` pixel values in range `0–255`



## Files

- `pgminfo.cpp` — validate and print image statistics
- `bigwhite.cpp` — generate an all-white PGM
- `neg.cpp` — output the negative of a PGM
- `hflip.cpp` — output a horizontal reflection of a PGM
- `Makefile` (if present)



## Build

Using g++:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o pgminfo pgminfo.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o bigwhite bigwhite.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o neg neg.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o hflip hflip.cpp
```

Or if a Makefile exists:

```bash
make
```



## 1. pgminfo

Reads a P2 PGM from `stdin`, validates it, and prints:

- Number of rows
- Number of columns
- Total pixel count
- Average pixel value (3 decimal places)

### Usage

```bash
./pgminfo < image.pgm
```

### Example Output

```
# Rows:        20
# Columns:     10
# Pixels:      200
Avg Pixel:    127.350
```

### Validation Checks

- First token must be `P2`
- Columns and rows must be integers ≥ 1
- Max value must be `255`
- Exactly `rows × columns` pixels must follow
- Each pixel must be between `0` and `255`
- No extra tokens allowed after pixel data

Errors are printed to `stderr`.



## 2. bigwhite

Generates an all-white P2 image (pixel value `255`).

### Usage

```bash
./bigwhite <rows> <cols> > output.pgm
```

### Example

```bash
./bigwhite 20 10 > white.pgm
```

Produces a 20×10 white image.

### Notes

- Requires exactly 2 arguments
- Both must be integers ≥ 1
- On invalid input, prints:
  ```
  usage: bigwhite rows cols
  ```
  to `stderr`



## 3. neg

Reads a P2 PGM from `stdin` and prints its **negative** to `stdout`.

Negative transformation:
```
new_pixel = 255 - original_pixel
```

### Usage

```bash
./neg < image.pgm > negative.pgm
```

Validation rules are the same as `pgminfo`.



## 4. hflip

Reads a P2 PGM from `stdin` and prints a **horizontal reflection** (left ↔ right).

Each row’s pixels are reversed before printing.

### Usage

```bash
./hflip < image.pgm > flipped.pgm
```

Validation rules are the same as `pgminfo`.



## Example Workflow

```bash
# Generate white image
./bigwhite 5 5 > white.pgm

# Inspect image
./pgminfo < white.pgm

# Create negative
./neg < white.pgm > black.pgm

# Flip image
./hflip < white.pgm > flipped.pgm
```



## Summary

These programs demonstrate:

- Structured file parsing
- Input validation with error reporting
- Vector-based pixel storage
- Image transformations (negative, horizontal reflection)
- Command-line utilities using stdin/stdout
