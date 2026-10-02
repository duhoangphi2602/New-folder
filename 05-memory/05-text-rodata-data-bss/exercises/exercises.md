# Exercises: Memory Segments

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Categorization
You write the following code in an embedded project:
```cpp
const int max_retries = 5;
int current_retries = 3;
char network_buffer[1024];

void reset_network() {
    int error_code = 0;
}
```
**Task:** Identify exactly which memory segment (`.text`, `.rodata`, `.data`, `.bss`, or `Stack`) each of the four variables belongs to.

## Exercise 2: Firmware Size Optimization
Your microcontroller has exactly 32KB of Flash and 8KB of RAM.
You compile your firmware, and GCC gives you this output:
```
   text    data     bss     dec     hex filename
  30000    3000    6000   39000    9858 firmware.elf
```
**Task:** 
1. Will this firmware successfully flash to the microcontroller? (Calculate total Flash usage).
2. Will this firmware successfully run on the microcontroller? (Calculate total static RAM usage).
