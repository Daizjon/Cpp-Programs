# Moonglow Parser (C++)

## Overview

`moonglow.cpp` reads text in **Moonglow format** from standard input and calculates a student's final score.

The program parses words sequentially and interprets them according to specific rules, then prints:

```
<student_name> <final_score>
```



## File

- `moonglow.cpp`



## Build

### macOS / Linux (g++)
```bash
g++ -std=c++11 -O2 -Wall -Wextra -o moonglow moonglow.cpp
```



## Moonglow Format Rules

The input is word-based.

### 1. NAME
If the word is:

```
NAME
```

The **next word** is taken as the student's name.

Example:
```
NAME Alex
```



### 2. Numbers
If a word is a number, it is added directly to the student's score.

Example:
```
10 5 3
```

Adds:
```
10 + 5 + 3
```



### 3. AVERAGE
If the word is:

```
AVERAGE
```

The program reads the following consecutive numbers and:

- Computes their average
- Adds the average to the total score

If no numbers follow `AVERAGE`, it is ignored.

Example:
```
AVERAGE 90 80 70
```

Adds:
```
(90 + 80 + 70) / 3 = 80
```



## Example Input

```txt
NAME Kai
10 5
AVERAGE 90 80 70
3
```



## Example Output

```txt
Kai 98
```

### Explanation

- Normal scores: `10 + 5 + 3 = 18`
- Average block: `(90 + 80 + 70) / 3 = 80`
- Final score: `18 + 80 = 98`



## How to Run

Using a file:

```bash
./moonglow < input.txt
```

Using a pipe:

```bash
echo "NAME Kai 10 AVERAGE 20 30 40" | ./moonglow
```



## Notes

- Input is read from standard input (`stdin`)
- Output is written to standard output (`stdout`)
- Designed as a simple parser using stream input
- Intended for practice with token parsing and conditional logic
