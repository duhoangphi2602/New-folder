# Solutions: The Startup Code

## Solution 1: Global Pointers
**Answer:** Because the global pointer is uninitialized, the compiler places it in the `.bss` segment. During the Startup Code, the `.bss` segment is completely filled with zeros. Therefore, when `main()` starts, `hw_register` will perfectly hold the value `0x00000000` (A Null Pointer). 
If you try to write to it (`*hw_register = 5;`), the CPU will attempt to write the number 5 to address `0x00000000`. On an ARM Cortex-M, address `0x00` is in the Flash (Read-Only) memory region, causing an immediate Hard Fault crash.

## Solution 2: Global Constructors
**Answer:** The C++ standard dictates that all global object constructors must execute *before* `main()` is called. The Startup Code will execute `__libc_init_array`, which calls the `Logger` constructor. The constructor will try to write data to the UART peripheral. However, because `main()` hasn't run yet, the UART hardware clock hasn't been turned on! Writing to a disabled hardware peripheral often causes a bus error (Hard Fault), crashing the system before it even reaches `main()`. *(This is called the "Static Initialization Order Fiasco" and is why complex global C++ objects are heavily discouraged in embedded systems).*
