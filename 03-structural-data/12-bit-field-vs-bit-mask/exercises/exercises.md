# Exercises: Bit-Field vs Bit-Mask

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Single Bit Operations
Assume you have a variable `uint8_t STATUS = 0b11001010;`.
1. Write the single line of C++ code using bitwise operators to **CLEAR** bit 3.
2. Write the single line of C++ code using bitwise operators to **SET** bit 0.
3. Write the single line of C++ code using bitwise operators to **TOGGLE** bit 7.

## Exercise 2: The Macro Way
In C libraries, you often see macros defined to make this easier:
```c
#define SET_BIT(REG, BIT)     ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))
#define READ_BIT(REG, BIT)    ((REG) & (1 << (BIT)))
```
**Task:** Use these macros mentally. If `uint32_t REG = 0;`, what is the exact value of `REG` after executing `SET_BIT(REG, 4);`? (Give your answer in integer or Hexadecimal).
