# Exercises: Struct Memory Layout

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Address Calculation
Given the following struct:
```cpp
struct RgbColor {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};
```
If an instance of this struct `RgbColor pixel;` is allocated at memory address `0x20001000`:
1. What is the memory address of `pixel.red`?
2. What is the memory address of `pixel.green`?
3. What is the memory address of `pixel.blue`?

## Exercise 2: C++ `offsetof` Macro
In C/C++, there is a standard macro to find out exactly where a compiler placed a member inside a struct (its byte offset from the start).
**Task:** Research the `<cstddef>` header. Write a small snippet of code that uses the standard macro to print the byte offset of the `blue` member in the `RgbColor` struct above.
