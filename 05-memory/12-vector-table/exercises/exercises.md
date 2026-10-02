# Exercises: The Vector Table

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Initial Stack Pointer
Look closely at the `vector_table` array in the `examples/` code. 
Indexes 1 through 7 contain function pointers (e.g., `Reset_Handler`). 
Index 0 contains `0x20005000`, which is cast to an `ISR_Pointer` just to make the compiler happy. It is *not* a function.
**Task:** Why does the ARM architecture force the Initial Stack Pointer to be stored at Index 0 of the Vector Table, rather than just having the `Reset_Handler` configure the Stack Pointer dynamically when it boots?

## Exercise 2: Infinite Loops
A junior developer is confused by the `Default_Handler()` provided in the startup code:
```c
void Default_Handler() {
    while(1) {
        // Do nothing
    }
}
```
**Task:** If an unused interrupt accidentally fires, it jumps to this `Default_Handler`. Why is it safer to trap the CPU in an infinite `while(1)` loop rather than simply letting the function `return` and allowing the CPU to go back to what it was doing?
