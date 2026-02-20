# Prime Number Primer (C++)

This folder contains two programs that read integers from standard input and determine whether each number is prime.

Both programs continue reading integers until EOF (Ctrl+D on macOS/Linux).



## Files

- `prime1.cpp`
- `prime2.cpp`
- `README.md`



## Build

Using g++:

```bash
g++ -std=c++17 -O2 -Wall -Wextra -o prime1 prime1.cpp
g++ -std=c++17 -O2 -Wall -Wextra -o prime2 prime2.cpp
```



## prime1

### Description

- Uses a simple trial division algorithm.
- Checks divisibility from `2` to `x - 1`.
- Prints a message only if the number is prime.
- Skips `0` and `1`.

### Example

```bash
echo "1 2 3 4 5 6 7 8 9 10" | ./prime1
```

### Example Output

```
2 is a prime number
3 is a prime number
5 is a prime number
7 is a prime number
```



## prime2

### Description

- Implements a callable class `isprime`.
- Stores previously discovered prime numbers in a vector.
- Expands the list of primes as needed using a `grow()` function.
- Uses `sqrt(n)` for more efficient primality checks.
- Prints a message only if the number is prime.

### Example

```bash
echo "1 2 3 4 5 6 7 8 9 10" | ./prime2
```

Output is identical in format to `prime1`.



## How It Works

### prime1
- For each input `x`:
  - Checks if any number from `2` to `x - 1` divides `x`.
  - If none do, it is prime.

### prime2
- Maintains a growing list of prime numbers.
- If a number larger than the current largest known prime is tested,
  it generates primes up to that number.
- Determines primality by checking membership in the stored list.



## Notes

- Input is read from `stdin`.
- Output is written to `stdout`.
- Programs terminate when EOF is reached.
- Designed to demonstrate:
  - Basic function-based design (`prime1`)
  - Class-based function objects and caching (`prime2`)
  - Simple algorithmic optimization
