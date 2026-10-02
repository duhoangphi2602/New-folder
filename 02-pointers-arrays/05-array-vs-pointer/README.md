# Array vs Pointer (Decay)

## What is this topic?
This topic addresses one of the most common misconceptions in C/C++: that Arrays and Pointers are the same thing. They are not. We will explore the concept of **Array Decay**, where an array converts itself into a pointer, losing critical information in the process.

## Why is it important?
Because arrays decay into pointers when passed into functions, passing an array to a function strips away its size information. If you try to calculate the size of an array inside a function, you will get the size of the pointer instead. This is the root cause of countless out-of-bounds memory errors and buffer overflows in C/C++ firmware.

## Prerequisites
- [04-arrays](../04-arrays/README.md)
- [02-pointer-basics](../02-pointer-basics/README.md)

## Learning Outcomes
1. Understand the fundamental difference between an Array and a Pointer.
2. Understand exactly when and why Array Decay occurs.
3. Learn how to safely pass arrays to functions without losing size information.
