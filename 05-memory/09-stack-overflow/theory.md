# Stack Overflow

## 1. Concept
The Stack is usually placed at the very top of SRAM and grows downwards. The Global Variables (`.data` and `.bss`) are usually placed at the bottom of SRAM and grow upwards.
If a function allocates a massive array on the Stack, the Stack Pointer (SP) moves so far down that it crosses the invisible boundary and plunges into the `.bss` section.

## 2. The Anatomy of the Crash
```
RAM ADDRESSES
0x20002000 |-------------------| <-- Top of RAM
           | Stack (Grows V)   |
0x20001800 |-------------------| <-- Stack Pointer (Current)
           |                   |
           |    FREE RAM       |
           |                   |
0x20000400 |-------------------|
           | .bss (Zeros)      |
0x20000100 |-------------------|
           | .data (Globals)   |
0x20000000 |-------------------| <-- Bottom of RAM
```
If you call `void parse() { uint8_t buf[6000]; }`, the CPU subtracts 6000 bytes from the Stack Pointer. The SP is now `0x20000090`. 
When the function writes data to `buf[0]`, it is physically writing to address `0x20000090`, completely destroying the global variables stored in the `.data` segment!

## 3. Causes
1. **Massive Local Variables:** Creating huge arrays or structs inside a function.
2. **Deep Call Chains:** Function A calls B, which calls C, which calls D... every call pushes a new Stack Frame.
3. **Recursion:** A function calling itself infinitely.
4. **Interrupts:** When a hardware interrupt fires, the CPU saves its current state to the Stack. If the Stack is already 99% full, the interrupt itself will push it over the edge.

## 4. Example
*(See `examples/` for a simulated demonstration of Stack Overflow corruption).*

## 5. Embedded usage (Detection Techniques)
Because bare-metal systems lack an OS to catch the overflow, engineers must build software traps.

**The "Canary" (Watermarking):**
During boot, the startup script fills the entire FREE RAM region with a recognizable "magic number" (e.g., `0xDEADBEEF`).
A background task runs every second and checks the memory address right at the boundary of the Stack limit. If that address still holds `0xDEADBEEF`, the Stack is safe. If the address holds anything else, it means the Stack grew down and overwrote the Canary. The system immediately triggers a safe shutdown and logs a fatal error.

**Hardware MPU (Memory Protection Unit):**
Advanced Cortex-M chips contain an MPU. You can configure the MPU to mark the boundary address as "No Access". If the Stack Pointer ever tries to write to that boundary, the MPU fires a hardware exception (MemManage Fault) *before* the global variables are corrupted.

## 6. Trade-offs (Stack Size Allocation)
How big should you make your Stack? 
- If you make it too large (e.g., 30KB out of 32KB RAM), you have no room for global variables or RTOS tasks.
- If you make it too small, you risk an overflow.
*Static Analysis Tools* can read your compiled code and calculate the theoretical "Maximum Stack Depth" by tracing every possible function call path. However, they struggle with function pointers and recursive calls, which is why recursion is banned.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
