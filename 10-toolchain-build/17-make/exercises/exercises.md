# Exercises: Makefiles

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Hidden Header Bug
Look at the rule for `main.o` in the `Makefile` example:
```make
main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp -o main.o
```
Assume `main.cpp` has a line: `#include "config.h"`. You run `make` and build the project successfully. 
Later, you open `config.h` and change a `#define BAUDRATE 9600` to `115200`. You save the file and run `make` again in the terminal.
`make` prints: `make: 'firmware.elf' is up to date.` It does nothing.
**Task:** Why did `make` refuse to rebuild the project even though you changed the baudrate? How do you fix the rule in the Makefile?

## Exercise 2: The `clean` Target
In the example `Makefile`, there is a rule named `clean`. It deletes all `.o` and `.elf` files. 
You run `make clean` in the terminal, and it successfully deletes the files.
However, one day, you accidentally create a blank text file in your project folder and name it exactly `clean`.
You type `make clean` in the terminal. `make` prints: `make: 'clean' is up to date.` and refuses to delete anything.
**Task:** Why did creating a file named `clean` break the Makefile command? How does the `.PHONY` keyword solve this problem?
