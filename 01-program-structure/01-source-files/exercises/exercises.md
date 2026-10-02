# Exercises: Source Files

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Include Guard Conversion
You inherit a legacy C codebase for an 8-bit MCU. The header file `display.h` looks like this:
```c
#ifndef DISPLAY_H
#define DISPLAY_H

void display_init(void);
void display_print(const char* msg);

#endif
```
**Task:** Convert this include guard to the modern syntax supported by nearly all modern C/C++ compilers. What is the benefit of the new syntax?

## Exercise 2: The Multiple Definition Bug
A developer creates `config.h`:
```cpp
#pragma once
int system_timeout = 1000;
```
They include this header in `main.cpp` and `uart.cpp`. When they build the project, the linker throws a "Multiple definition of `system_timeout`" error.

**Task:** Explain *why* this error occurs based on the C/C++ compilation model, and provide the correct way to declare and define this variable.

## Exercise 3: C/C++ Interoperability
You are writing a C++ application, but the vendor provided a pure C hardware driver: `spi_driver.c` and `spi_driver.h`. 
When you include `spi_driver.h` in your `main.cpp` and call `spi_init()`, the code compiles but fails at the linking stage with "Undefined reference to `spi_init()`".

**Task:** How must you modify `spi_driver.h` so it can be safely included in your C++ code?
