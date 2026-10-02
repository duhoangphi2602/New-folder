# The Vector Table

## 1. Concept
The Vector Table is simply a C-style array of Function Pointers (`void (*)(void)`).
On an ARM Cortex-M, this array is rigidly defined by the hardware architecture and must be placed at the absolute beginning of memory (Address `0x00000000`).
When an event happens, the hardware uses the event's ID number as an index into this array, reads the memory address stored there, and jumps the Program Counter to that address.

## 2. The Hardcoded Addresses
The first 16 entries in the table are reserved by ARM for the CPU core itself.
- **Index 0 (`0x00000000`):** The Initial Stack Pointer value. (Not a function!).
- **Index 1 (`0x00000004`):** The Reset Handler. (The function to run on power-up).
- **Index 2 (`0x00000008`):** The NMI (Non-Maskable Interrupt) Handler.
- **Index 3 (`0x0000000C`):** The Hard Fault Handler. (The function to run when the CPU crashes).

Everything from Index 16 onwards is vendor-specific (Interrupts for UART, GPIO, Timers, etc.).

## 3. Syntax (Creating the Table in C)

```c
// Define the startup function
extern void Reset_Handler(void);
// Define a default crash function
void HardFault_Handler(void) { while(1); }
// Define a default dummy function for unused interrupts
void Default_Handler(void) { while(1); }

// The actual Vector Table Array
// We use a GCC attribute to tell the linker to put this in a special ".isr_vector" section
__attribute__((section(".isr_vector"))) 
void (*const g_pfnVectors[])(void) = {
    (void (*)(void))(&_estack), // 0: The Initial Stack Pointer (provided by linker)
    Reset_Handler,              // 1: The Reset Handler (Startup Code)
    Default_Handler,            // 2: NMI
    HardFault_Handler,          // 3: Hard Fault
    // ... 
    Default_Handler,            // 16: External Interrupt 0
    // ...
};
```

## 4. Example
*(See `examples/` for a simulated demonstration of the hardware indexing the table).*

## 5. Embedded usage (Weak Aliases)
What happens if UART fires an interrupt, but you haven't written a `UART_IRQHandler` function yet? The system shouldn't crash.
To solve this, the startup file populates the Vector Table with "Weak" function aliases that all point to a `Default_Handler` (an infinite `while(1)` loop).

```c
// If the user doesn't write UART_IRQHandler, make it point to Default_Handler
void UART_IRQHandler() __attribute__((weak, alias("Default_Handler")));
```

When you write your own `void UART_IRQHandler() { ... }` in your `main.cpp`, the compiler sees it, drops the weak alias, and automatically updates the Vector Table to point to your new function.

## 6. Trade-offs (RAM vs Flash Vector Tables)
By default, the Vector Table is stored in Flash (ROM) at `0x08000000` (aliased to `0x00000000`). This is extremely safe, but you cannot change the function pointers at runtime.
Some advanced RTOS systems or Bootloaders copy the Vector Table into SRAM and tell the CPU core (via the VTOR register) to look in RAM instead. This allows the software to dynamically swap out interrupt handlers on the fly, but it risks memory corruption if the Stack overflows into the RAM Vector Table.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
