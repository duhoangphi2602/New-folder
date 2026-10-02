# Exercises: Compiler Flags

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing `-c` Flag
You run the following command in your terminal to compile a single object file:
`arm-none-eabi-g++ main.cpp -o main.o -mcpu=cortex-m4`
The terminal spits out massive errors:
`undefined reference to 'SystemInit'`
`undefined reference to 'HAL_Init'`
**Task:** Look very closely at the `command_sim.txt` example. What critical flag did you forget in your command? What did the toolchain try to do because that flag was missing?

## Exercise 2: `gnu++17` vs `c++17`
In GCC, you can define an array without a constant size:
```cpp
void process_data(int size) {
    int buffer[size]; // Variable Length Array (VLA)
}
```
If you compile this with `-std=gnu++17`, it compiles perfectly.
If you compile this with `-std=c++17`, the compiler throws an error: `variable-sized object may not be initialized`.
**Task:** Why did one succeed and the other fail? As an embedded developer, which flag should you use, and why?
