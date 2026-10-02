# Solutions: Atomic Operations

## Solution 1: Finding the Limit
**Answer:** No, it will not. The `TempData` struct contains 5 integers (20 bytes total). A 32-bit Cortex-M4 CPU can only move a maximum of 32 bits (4 bytes) over its memory bus in a single hardware cycle. It is physically impossible for the hardware to atomically read or write 20 bytes simultaneously. 
When you compile this code, the C++ compiler will secretly inject a Mutex (or a Critical Section) around all accesses to `my_data`. The developer thinks they wrote lock-free code, but they actually created a hidden software lock. (You can check this in code by calling `my_data.is_lock_free()`).

## Solution 2: Compare-and-Swap
**Answer:** If you use a standard `if` statement, a Context Switch can happen *exactly* between the Check and the Set. 
Example: 
1. Task A checks `if(var == 0)`. It is true!
2. **Context Switch!** 
3. Task B runs, changes `var` to 100.
4. **Context Switch!** 
5. Task A resumes. It already passed the `if` check, so it executes `var = 1`. 
Task B's data (100) is illegally overwritten. The atomic `compare_exchange` guarantees that the Check and the Set happen in a single, unbreakable hardware motion, preventing this exact failure.
