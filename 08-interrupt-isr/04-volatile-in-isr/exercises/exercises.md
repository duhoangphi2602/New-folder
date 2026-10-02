# Exercises: The Volatile Keyword

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Bug
A developer writes the following delay function for a bare-metal microcontroller:
```c
void delay_ms(uint32_t ms) {
    uint32_t count = ms * 10000; // Calibrated for CPU speed
    while(count > 0) {
        count--; // Useless math to burn time
    }
}
```
When compiled with `-O0` (No Optimization), the delay works perfectly (e.g., it delays for 1 second). 
When compiled with `-O3` (Max Optimization) for the final release, the delay completely vanishes, taking 0.00001 seconds! 
**Task:** Why did the compiler delete the delay loop? How can you fix this using `volatile`?

## Exercise 2: Volatile Pointers
Look closely at this syntax:
1. `volatile uint8_t * ptr;`
2. `uint8_t * volatile ptr;`
**Task:** What is the difference between these two declarations? If you are mapping a pointer to a hardware register whose *value* changes automatically, which one do you use?
