# Command Line Calculator (C++)

## Overview

This program performs arithmetic operations using command line arguments.

It accepts:

```
<left> <operator> <right>
```

Example:

```
./calculator 12 + 8
```

Output:

```
12 + 8 = 20
```



## File Structure

```
string-arithmetic-cli.cpp
README.md
```



## Supported Operators

| Operator | Description        |
|----------|-------------------|
| +        | Addition           |
| -        | Subtraction        |
| x        | Multiplication     |
| /        | Division           |
| %        | Modulus            |



## Build

```bash
g++ -std=c++11 -O2 -Wall -Wextra -o calculator string-arithmetic-cli.cpp
```



## Run

```bash
./calculator <left> <op> <right>
```

Example:

```bash
./calculator 15 x 4
```

Output:

```
15 x 4 = 60
```



## Implementation Details

This program **does not use built-in string-to-integer conversion functions**.

Instead, it manually implements:

- `CharToInt()`
- `IntToChar()`
- `StringToInt()`
- `IntToString()`

### StringToInt

- Parses character digits manually
- Handles negative numbers
- Uses positional multiplication (base 10)

### IntToString

- Converts integer digits using modulus and division
- Builds string manually
- Handles negative numbers
- Returns `"0"` for input `0`



## Program Flow

1. Validate argument count
2. Convert left operand (argv[1]) using `StringToInt`
3. Read operator (argv[2][0])
4. Convert right operand (argv[3])
5. Perform operation
6. Convert result using `IntToString`
7. Print using `printf` (required)



## Constraints

- Must use `printf` for output
- No use of `stoi`, `to_string`, or standard conversion utilities
- Input must be passed via command line arguments



## Concepts Demonstrated

- Command line argument parsing (`argc`, `argv`)
- Manual numeric parsing
- ASCII arithmetic
- Integer-to-string conversion
- Switch-based operator dispatch
- C-style formatted output

