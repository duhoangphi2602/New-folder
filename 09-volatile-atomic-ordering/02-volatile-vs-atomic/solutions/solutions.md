# Solutions: Volatile vs Atomic

## Solution 1: The Boolean Flag Exception
**Answer:** A Race Condition requires a Read-Modify-Write sequence (like `x = x + 1`). 
Setting a boolean flag (`is_pressed = true`) is a direct, singular Write operation (`STR` instruction). In a 32-bit architecture, writing an 8-bit, 16-bit, or 32-bit value to an aligned memory address happens in exactly one hardware clock cycle. It is physically indivisible. Since the hardware inherently writes it atomically, and the compiler reads it atomically, a Race Condition is physically impossible. `volatile` is all that is needed to ensure the compiler doesn't cache it.

## Solution 2: Selecting the right tool
**Answer:**
1. **Hardware Register:** `volatile`. The memory address represents hardware, so the compiler must be forced to read/write it directly. (No RTOS tasks are fighting over it in this context).
2. **ISR/Task Shared Counter:** `volatile std::atomic<uint32_t>`. Because it is modified by an ISR and read by a Task, it needs `volatile` to stop compiler caching. Because it is being incremented (Read-Modify-Write), it needs `atomic` to prevent the hardware from interrupting the addition process.
3. **Large Struct:** `Mutex`. You cannot make a 1024-byte struct `atomic` because the CPU cannot process 1024 bytes in a single clock cycle. You must use an RTOS Mutex to lock the struct, allowing one task to finish reading/writing it before another task can access it. (No `volatile` is needed here because RTOS Mutex APIs inherently act as memory barriers for the compiler).
