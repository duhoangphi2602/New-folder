# Interview Questions: The Stack

## 1. How does the CPU allocate and deallocate memory on the Stack, and why is it so fast?
**Answer:** The CPU manages the Stack using a dedicated hardware register called the Stack Pointer (SP). To allocate memory, the CPU executes a single arithmetic instruction to subtract the required size from the SP (moving the pointer downwards). To deallocate, it simply adds the size back to the SP. There is no searching for free blocks or updating memory management tables, making allocation/deallocation take exactly 1 clock cycle.

## 2. Why does returning a pointer to a local variable cause undefined behavior?
**Answer:** Local variables are stored on the Stack Frame of the currently executing function. When the function returns, its Stack Frame is "popped", meaning the memory is marked as available. If you return a pointer to that variable, the caller receives an address pointing to memory that is no longer protected. The very next function call or interrupt will overwrite that exact memory location, turning your pointer into a "Dangling Pointer" that reads corrupted garbage data.

## 3. What is the fundamental danger of allocating a large array (e.g., `uint8_t buffer[2048]`) inside a function on a microcontroller?
**Answer:** Stack Overflow. Microcontrollers have very limited SRAM, and the linker script allocates only a fraction of that SRAM (e.g., 1KB or 2KB) specifically for the Stack. If you declare a 2048-byte array as a local variable, the Stack Pointer will drop straight through the bottom of the designated Stack region and begin blindly overwriting the `.data` or `.bss` segments, silently destroying your system's global variables and state machines.
