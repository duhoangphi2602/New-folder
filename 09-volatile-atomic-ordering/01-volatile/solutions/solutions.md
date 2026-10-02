# Solutions: Volatile

## Solution 1: The Disappearing Code
**Answer:** The compiler analyzed the `for` loop, realized that the variable `i` is never used for any meaningful calculation, and concluded that the entire loop is "Dead Code" (it has no observable side effects). To optimize execution time, the compiler completely deleted the loop from the generated Assembly.
**The Fix:** You must make the loop counter `volatile`:
```c
void delay_us(uint32_t count) {
    for (volatile uint32_t i = 0; i < count; i++) { }
}
```
Because `i` is now `volatile`, the compiler is legally forbidden from optimizing it away. It MUST execute the `LDR`, `ADD`, and `STR` instructions to physical RAM for every single iteration, effectively wasting CPU cycles and creating the desired delay.

## Solution 2: Pointer Syntax
**Answer:**
1. `volatile uint32_t * reg_ptr;` 
   This means "Pointer to a volatile uint32_t". The data being pointed to (the hardware register) is volatile and can change unpredictably. The pointer itself (the address) is just a normal variable. **This is the correct syntax for hardware registers.**
2. `uint32_t * volatile ptr_reg;` 
   This means "Volatile pointer to a normal uint32_t". The data being pointed to is normal RAM. But the pointer *itself* (the memory address it holds) can change unpredictably (e.g., an ISR might change where the pointer is pointing). This is extremely rare.
