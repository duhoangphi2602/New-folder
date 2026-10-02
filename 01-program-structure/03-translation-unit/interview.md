# Interview Questions: Translation Unit

## 1. What is a translation unit in C/C++?
**Answer:** A translation unit is the ultimate input to the compiler. It consists of a single `.c` or `.cpp` source file, plus the contents of all header files included via `#include`, minus any code removed by conditional compilation (`#ifdef`), with all macros expanded. 

## 2. If you declare a global variable `int count;` in two different `.cpp` files, what happens?
**Answer:** Each `.cpp` file (translation unit) will compile successfully because the compiler compiles them completely independently. However, the build will fail during the **linking stage** with a "multiple definition" error, because the linker combines the translation units and sees two global symbols with the same name.

## 3. How do you prevent a function defined in a `.c` file from being called by another `.c` file?
**Answer:** By defining the function with the `static` keyword. This gives the function internal linkage, meaning its symbol is hidden from the linker and is only visible within its own translation unit.

## 4. Why are header guards (`#pragma once` or `#ifndef`) necessary?
**Answer:** Because the preprocessor creates the translation unit via text substitution. If `A.h` includes `B.h`, and `C.c` includes both `A.h` and `B.h`, the preprocessor will copy the contents of `B.h` into the translation unit twice. Header guards prevent this duplicate inclusion, which would otherwise cause redefinition compiler errors.
