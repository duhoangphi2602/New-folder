# Exercises: Preprocessing

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Macro Trap
A developer writes a handy macro to square a number:
```c
#define SQUARE(x) x * x

int main() {
    int result = SQUARE(5 + 1);
    return 0;
}
```
The developer expects `result` to be 36 (since 5+1=6, and 6*6=36). 
However, when the code runs, `result` is 11!
**Task:** Manually act as the Preprocessor. Do the literal text replacement for `SQUARE(5 + 1)`. Why does it equal 11 according to standard C++ math rules? How do you fix the macro?

## Exercise 2: Include Guards
File `A.h` contains `#include "B.h"`.
File `B.h` contains `#include "A.h"`.
In `main.cpp`, you `#include "A.h"`.
**Task:** What happens during the Preprocessing stage if neither header file has an Include Guard (`#ifndef`)? 
