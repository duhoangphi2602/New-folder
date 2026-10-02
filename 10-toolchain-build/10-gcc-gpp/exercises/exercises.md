# Exercises: gcc vs g++

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The C-Only Project
You are working on a legacy embedded project that consists entirely of 15 `.c` files. There is absolutely no C++ code.
You accidentally configure your Makefile to use `g++` to build the project instead of `gcc`.
**Task:** Will the project successfully compile and link? If yes, will the final executable be exactly the same size, larger, or smaller than if you had used `gcc`? Why?

## Exercise 2: Forcing the Compiler
You have a file named `driver.c`. However, inside this file, someone wrote a C++ class:
```cpp
class Sensor { 
    public: int get_data() { return 5; } 
};
```
If you run `gcc driver.c` or `g++ driver.c`, they will both fail during compilation (Stage 2) with syntax errors, because both compilers look at the `.c` extension and enforce strict C rules. C does not understand the `class` keyword.
**Task:** Without renaming the file to `.cpp`, how can you use a command-line flag with `g++` to force it to treat `driver.c` as C++ code? (You may need to research the `-x` flag).
