# Exercises: Volatile

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Disappearing Code
You want to write a simple software delay to pause the microcontroller for a few milliseconds.
You write this function:
```c
void delay_us(uint32_t count) {
    for (uint32_t i = 0; i < count; i++) {
        // Do nothing, just waste CPU cycles
    }
}
```
In Debug mode (`-O0`), this delay works perfectly. When you build for Release (`-O3`), the delay completely disappears and your LEDs blink instantly!
**Task:** Why did the compiler delete your delay loop? How can you use the `volatile` keyword to force the compiler to keep the delay loop in the final binary?

## Exercise 2: Pointer Syntax
The placement of the `volatile` keyword changes its meaning, just like `const`.
Explain the difference between the following two declarations:
1. `volatile uint32_t * reg_ptr;`
2. `uint32_t * volatile ptr_reg;`
Which one is used for defining a hardware register in embedded systems?
