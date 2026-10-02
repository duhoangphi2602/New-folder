# Exercises: Translation Unit

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Viewing the Translation Unit
Create a simple `test.cpp` file:
```cpp
#define MAX_SIZE 128
int main() {
    int buffer[MAX_SIZE];
    return 0;
}
```
**Task:** Run the GCC command `g++ -E test.cpp`. What does `-E` do? What is the exact output printed to the terminal?

## Exercise 2: Internal Linkage
Developer A writes `motor.cpp` and defines:
```cpp
int speed = 0;
```
Developer B writes `pump.cpp` and defines:
```cpp
int speed = 50;
```
When compiled, the linker throws a "multiple definition of `speed`" error. 
**Task:** Using your knowledge of translation units, explain the simplest way to fix this *without* renaming the variables, assuming `speed` is only meant to be used internally within each respective `.cpp` file.

## Exercise 3: Preprocessor Bloat
You include `<iostream>` in a 5-line `main.cpp` file. 
**Task:** Use `g++ -E main.cpp > out.txt` and check the number of lines in `out.txt` (using `wc -l out.txt` on Linux/Mac, or opening it in an editor on Windows). Approximately how many lines is the final translation unit? What does this tell you about `#include` overhead?
