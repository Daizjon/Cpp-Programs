# Stream Stats & Caesar Shift CLI (C++)

## Overview

This folder contains three small C++ command-line programs:

- `stream-minmax-sum.cpp` — reads integers from `stdin` and prints count, sum, min, and max.
- `stats-class-minmax.cpp` — same functionality as above, implemented using a `stats` class.
- `caesar-shift-cli.cpp` — encodes or decodes ASCII text using a simple Caesar-style letter shift.

These programs demonstrate:

- Stream-based input (`stdin`)
- Aggregation logic (min/max/sum/count)
- Basic object-oriented design
- Command-line argument parsing
- Character arithmetic and cyclic mapping



## Files

- `stream-minmax-sum.cpp`
- `stats-class-minmax.cpp`
- `caesar-shift-cli.cpp`
- `README.md`



## Build

Compile using `g++`:

```bash
g++ -std=c++11 -O2 -Wall -Wextra -o stream-minmax-sum stream-minmax-sum.cpp
g++ -std=c++11 -O2 -Wall -Wextra -o stats-class-minmax stats-class-minmax.cpp
g++ -std=c++11 -O2 -Wall -Wextra -o caesar-shift-cli caesar-shift-cli.cpp
```



## 1. stream-minmax-sum

### Description

Reads integers from standard input until EOF and prints:

- `N`   — number of integers read
- `sum` — total sum
- `min` — smallest value
- `max` — largest value

### Example

```bash
echo "5 2 9 -1 3" | ./stream-minmax-sum
```

Output:

```
N = 5
sum = 18
min = -1
max = 9
```


## 2. stats-class-minmax

### Description

Same functionality as `stream-minmax-sum`, but implemented using a `stats` class with:

- `push(int)` — processes an integer
- `print()` — prints summary statistics

### Example

```bash
echo "5 2 9 -1 3" | ./stats-class-minmax
```

Output format is identical to `stream-minmax-sum`.



## 3. caesar-shift-cli

### Description

Encodes or decodes ASCII text using a Caesar-style shift.

- Only letters (`A–Z`, `a–z`) are shifted.
- Case is preserved.
- Wrap-around is enforced:
  - `Z + 1 -> A`
  - `z + 1 -> a`
  - `A - 1 -> Z`
- Non-letter characters (digits, punctuation, whitespace) are unchanged.
- Shift value must be an integer between `0` and `9`.

### Usage

```bash
./caesar-shift-cli -encode <shift>
./caesar-shift-cli -decode <shift>
```

### Encode Example

```bash
echo "Hello World" | ./caesar-shift-cli -encode 3
```

### Decode Example

```bash
echo "Khoor Zruog" | ./caesar-shift-cli -decode 3
```



## Notes

- These programs are CLI utilities designed for practice with:
  - Input streams
  - Basic aggregation logic
  - Class structure
  - Character arithmetic
- Compiled binaries are not included in this repository.
