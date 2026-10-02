# Solutions: Struct Basics

## Solution 1: The Semicolon Trap
**Answer:** A struct declaration **must** end with a semicolon (`;`). Because the semicolon was missing, the compiler thought the programmer was trying to declare a variable of type `I2C_Config` immediately after defining it, and the error bled over into `main.cpp`. This is a classic C/C++ compilation trap.

## Solution 2: Object Copying
**Answer:** No, you do not have to copy members manually. Structs can be assigned directly using the `=` operator. The compiler will perform a shallow byte-copy of the entire memory block.
```cpp
p2 = p1; // Perfectly valid and highly efficient.
```

## Solution 3: Default Member Initialization
**Answer:** In C++11, you can assign default values directly in the struct definition:
```cpp
struct Point { 
    int x = 0; 
    int y = 0; 
};
// Now, Point p3; is guaranteed to be (0, 0).
```
