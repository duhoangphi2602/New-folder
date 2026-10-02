# Solutions: The Volatile Keyword

## Solution 1: Finding the Bug
**Answer:** The compiler analyzed the `delay_ms` function. It noticed that `count` is a local variable, it is decremented to 0, and then the function exits *without `count` ever being used for anything else*. The compiler concluded that the entire loop accomplishes nothing mathematically useful. To make the code faster, it completely deleted the loop from the final assembly code.
**The Fix:** You must declare it as `volatile uint32_t count = ms * 10000;`. This forces the compiler to physically perform every single write and read to RAM, preventing it from deleting the loop. *(Note: Using hardware timers is infinitely better than `volatile` software delays).*

## Solution 2: Volatile Pointers
**Answer:** 
1. `volatile uint8_t * ptr;` means the **data being pointed to** is volatile. The pointer itself is a normal variable, but the data it looks at can change at any time (e.g., a hardware register value). This is the correct choice for memory-mapped hardware.
2. `uint8_t * volatile ptr;` means the **pointer itself** is volatile. The data is normal, but the memory address the pointer is holding might change unexpectedly (e.g., if an ISR updates the pointer to look at a new buffer).
