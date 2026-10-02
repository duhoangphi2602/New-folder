# Exercises: Symbols

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Size of an Array
You have a global array in your C++ code: `uint32_t sensor_data[100];`.
You run `nm firmware.elf` and see these two consecutive lines:
`20000400 B sensor_data`
`20000590 B rx_buffer`
**Task:** Without looking at the C++ code, prove mathematically using the Symbol Table addresses that `sensor_data` is exactly an array of 100 `uint32_t` integers.

## Exercise 2: `extern "C"`
A C++ program `#include "legacy_c_driver.h"` and tries to call `init_driver()`. 
The `legacy_c_driver.c` file was compiled with the C compiler (`gcc`), while the main program was compiled with the C++ compiler (`g++`).
The Linker crashes with: `Undefined reference to init_driver()`.
You run `nm` on the driver's object file and see: `00000000 T init_driver`.
**Task:** Why did the Linker fail to find it? How does the `extern "C"` block in C++ fix this exact problem?
