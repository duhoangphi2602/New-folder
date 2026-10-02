# Exercises: Preprocessing

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Spot the Macro Bug
A developer wrote this macro to clear a specific bit in a register:
```c
#define CLEAR_BIT(reg, bit) reg &= ~(1 << bit)
```
Later, they use it in an `if` statement without curly braces (poor practice, but common):
```c
if (condition)
    CLEAR_BIT(STATUS_REG, 3);
else
    do_something_else();
```
**Task:** This code will fail to compile. Why? What is the standard C macro trick to fix this?

## Exercise 2: C++17 Replacement
You are porting an old C library to modern C++17. You find the following:
```c
#define PI 3.14159f
#define SECONDS_IN_HOUR (60 * 60)
```
**Task:** Rewrite both of these using modern C++17 features to provide type safety and respect scope.

## Exercise 3: Cross-Platform Abstraction
You have a function `void delay_ms(int ms);`.
On an STM32 MCU, this function should call `HAL_Delay(ms);`.
On an ESP32 MCU, this function should call `vTaskDelay(ms / portTICK_PERIOD_MS);`.
**Task:** Write a `.cpp` implementation of `delay_ms` that uses preprocessor directives to conditionally compile the correct function body depending on whether `TARGET_STM32` or `TARGET_ESP32` is defined.
