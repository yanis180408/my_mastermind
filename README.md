# Welcome to My Mastermind
***

## Task
The goal of this project is to implement the Mastermind board game as a command line program in C.
The program generates a secret code made of 4 distinct pieces chosen among 9 (`0` to `8`), and the player has a limited number of attempts to find it.
After each guess, the game reports the number of **well-placed pieces** (right piece, right position) and **misplaced pieces** (right piece, wrong position).
The challenge lies in writing the whole game logic (input handling, validation, scoring) with a restricted list of allowed functions and without relying on the standard library for string handling or line reading.

## Description
I solved this problem by splitting the game into small, single-purpose modules:
- **Code Generation** : `generate_code` builds a random secret code of 4 distinct pieces, seeded with `srand`, and returns it as a dynamically allocated string.
- **Input Validation** : `is_valid_code` checks that a guess has exactly 4 pieces, that each is between `0` and `8`, and that there are no duplicates.
- **Scoring** : `placements` compares the guess to the secret code and returns a `t_result` structure holding the number of well-placed and misplaced pieces.
- **Custom Utilities** : `my_readline` reads the player's input from standard input using `read`, and `my_strlen` replaces the standard string length function.
- **Game Loop** : `main` parses the options, runs the rounds, and ends the game when the code is found or the attempts run out.
- **Error Handling** : Invalid guesses are rejected with a "Wrong input!" message without consuming an attempt, and the game continues.
- **Memory Safety** : Every allocated secret code is freed before the program exits, including when the player quits with `Ctrl+D`.

## Installation
The project includes a Makefile for easy compilation.
1. Compile the project :
```bash
make
```

2. Recompile (clean and build) :
```bash
make re
```

3. Clean object files :
```bash
make clean
```

4. Clean everything (executable and objects) :
```bash
make fclean
```

## Usage
The program is launched from the command line. By default, the secret code is random and the player has 10 attempts.

**Syntax :**
```bash
./my_mastermind [-c CODE] [-t ATTEMPTS]
```

**Options :**
- `-c [CODE]` : use a specific secret code instead of a random one (4 distinct digits between `0` and `8`).
- `-t [ATTEMPTS]` : set the number of attempts (default: 10).

**Examples:**
- **Start a game with a random code and 10 attempts :**
```bash
./my_mastermind
```

- **Start a game with a chosen secret code :**
```bash
./my_mastermind -c "0123"
```

- **Start a game with 5 attempts :**
```bash
./my_mastermind -t 5
```

- **Combine both options :**
```bash
./my_mastermind -c "0123" -t 12
```

**Example of a game :**
---
Round 0
>1234
Well placed pieces: 1
Misplaced pieces: 2
---
Round 1
>0123
Congratz! You did it!


### The Core Team


<span><i>Made at <a href='https://qwasar.io'>Qwasar SV -- Software Engineering School</a></i></span>
<span><img alt='Qwasar SV -- Software Engineering School's Logo' src='https://storage.googleapis.com/qwasar-public/qwasar-logo_50x50.png' width='20px' /></span>
