# Exercises: Object Files

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Static Keyword
You have a file called `uart.cpp`. Inside it, you write a helper function:
```cpp
void calculate_baud_rate() { ... }
```
If you run `nm uart.o`, the function shows up as `00000000 T calculate_baud_rate`.
Now, you change the code to:
```cpp
static void calculate_baud_rate() { ... }
```
**Task:** In C/C++, the `static` keyword applied to a global function gives it "Internal Linkage". If you run `nm uart.o` on the modified file, what will happen to the Symbol Table? Why is this useful for large projects?

## Exercise 2: Header Implementations
A beginner developer writes `math_functions.h` and implements a function directly inside it:
```cpp
// math_functions.h
int add(int a, int b) { return a + b; }
```
They `#include "math_functions.h"` in both `main.cpp` and `sensor.cpp`.
**Task:** Describe exactly what exists inside the Symbol Table for `main.o` and `sensor.o`. What will happen when these two object files are handed to the Linker?
