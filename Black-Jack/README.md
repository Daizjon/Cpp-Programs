# Blackjack (C++ CLI Game)

## Overview

This project is a terminal-based implementation of the card game **Blackjack**, written in C++.  
A player competes against a dealer with the goal of reaching a value as close to 21 as possible without going over.

This project reinforces:

- C++ class design
- Dynamic memory management
- Copy constructor / assignment operator / destructor (Rule of Three)
- Basic game loop control
- Randomization and shuffling
- User input handling



## File Structure

```
CardDeck.h      // CardDeck class definition
CardDeck.cpp    // CardDeck class implementation
main.cpp        // Interactive Blackjack game logic
makefile        // Build script (if included)
README.md
```



## How the Game Works

- The deck contains numeric values:
  - 2–11
  - Face cards (J, Q, K) are treated as 10
  - Ace is treated as 11
- The player chooses:
  - `h` → hit (draw another card)
  - `s` → stay (end turn)
- The dealer:
  - Draws until reaching 17 or higher
- If either side exceeds 21 → they bust
- If neither busts → higher total wins
- Ties are awarded to the player (as implemented)

Win totals are tracked across rounds.



## CardDeck Class Design

The `CardDeck` class:

- Stores cards in a dynamically allocated array (`int* deck`)
- Implements:
  - Constructor
  - Copy constructor
  - Assignment operator
  - Destructor
- Provides:
  - `shuffle()` — shuffles deck using `std::random_shuffle`
  - `deal()` — removes and returns the top card
  - `getSize()` — returns remaining card count

When the deck size reaches 15 cards, the game refreshes the deck and reshuffles.



## Build

### Option 1 — Using makefile
```bash
make
```

### Option 2 — Compile manually
```bash
g++ -std=c++11 -O2 -Wall -Wextra -o blackjack main.cpp CardDeck.cpp
```



## Run

```bash
./blackjack
```



## Example Gameplay

```
Time to play BlackJack!

Size of deck is 52

Okay first deal, here's your card 7
type h for hit or s for stay
```



## Educational Concepts Demonstrated

- Rule of Three (constructor, copy constructor, destructor)
- Operator overloading (assignment operator)
- Pointer-based dynamic arrays
- Vector usage for temporary storage
- Random number seeding
- Game state management
- Control flow using loops and conditionals



## Notes

- This is a simplified Blackjack implementation.
- Ace always counts as 11 (no soft/hard handling).
- `std::random_shuffle` is deprecated in modern C++ (can be replaced with `std::shuffle`).
- Compiled artifacts (e.g., `*.o`, `blackjack`) should not be committed to GitHub.

Example `.gitignore` entries:

```
*.o
blackjack
a.out
```
