# Exercises: Struct Basics

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Semicolon Trap
A beginner C++ programmer writes this code in `config.h`:
```cpp
struct I2C_Config {
    int speed;
    int address;
} // <-- End of file
```
Then they `#include "config.h"` in their `main.cpp`. The compiler throws a massive, completely confusing error on the very first line of `main.cpp`. 
**Task:** Why did this happen? What is missing?

## Exercise 2: Object Copying
You have two struct variables:
```cpp
struct Point { int x; int y; };
Point p1{10, 20};
Point p2;
```
**Task:** How do you copy the contents of `p1` into `p2`? Do you have to write `p2.x = p1.x; p2.y = p1.y;` manually?

## Exercise 3: Default Member Initialization
In modern C++ (C++11 and later), you can ensure that a struct is *never* accidentally left uninitialized with garbage data, right at the point of declaration.
**Task:** Rewrite the `Point` struct so that if a user creates `Point p3;`, `x` and `y` will automatically default to `0`.
