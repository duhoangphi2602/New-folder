# Solutions: Translation Unit

## Solution 1: Viewing the Translation Unit
**Answer:** The `-E` flag tells the GCC compiler to **stop after the preprocessing stage**. It outputs the raw translation unit without actually compiling it to machine code.
The exact output will be:
```cpp
# 1 "test.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "test.cpp"

int main() {
    int buffer[128];
    return 0;
}
```
Notice how `MAX_SIZE` has been textually replaced with `128`, and the `#define` directive itself is removed.

## Solution 2: Internal Linkage
**Answer:** Mark both variables as `static`.
In `motor.cpp`:
```cpp
static int speed = 0;
```
In `pump.cpp`:
```cpp
static int speed = 50;
```
**Why:** The `static` keyword applied to global variables gives them **internal linkage**. This confines the variable to the translation unit in which it is defined. When the linker combines `motor.o` and `pump.o`, it hides these symbols from each other, preventing the conflict.

## Solution 3: Preprocessor Bloat
**Answer:** The final translation unit will likely be between **30,000 and 50,000 lines** long (depending on the compiler version). 
**Why:** `<iostream>` includes dozens of other internal headers (`<string>`, `<memory>`, `<locale>`, etc.). The preprocessor recursively copies the text of every single header into your translation unit. This demonstrates why heavy `#include` usage drastically slows down C++ compilation times.
