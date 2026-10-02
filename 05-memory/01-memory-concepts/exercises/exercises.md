# Exercises: Memory Concepts (RAM vs ROM)

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Out-of-Memory Bug
You are programming a microcontroller with 32KB of RAM and 256KB of Flash. 
You declare an array to hold an image for an LCD screen:
```cpp
uint8_t splash_screen_image[40000] = {0xAA, 0xBB, 0xCC, /*... thousands of bytes ...*/};
```
When you compile the code, the linker throws a fatal error: `region 'RAM' overflowed by 8000 bytes`.
**Task:** Explain why this error occurred, and how to fix it by adding a single keyword.

## Exercise 2: Harvard vs Von Neumann
Modern desktop PCs use the Von Neumann architecture, while ARM Cortex-M microcontrollers use a modified Harvard architecture.
**Task:** Research or deduce the primary difference between these two architectures regarding how the CPU connects to RAM and ROM. Why does the microcontroller's architecture allow it to run faster at the same clock speed?
