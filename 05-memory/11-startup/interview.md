# Interview Questions: The Startup Code

## 1. Describe the exact sequence of events that occur between a microcontroller receiving power and the execution of the first line of `main()`.
**Answer:** 
1. The hardware loads the Initial Stack Pointer (MSP) from address `0x00000000`.
2. The hardware loads the Program Counter with the address of `Reset_Handler` from `0x00000004`.
3. `Reset_Handler` executes and copies the `.data` segment's initial values from Flash into RAM.
4. It iterates over the `.bss` segment in RAM and initializes it to zero.
5. It executes `__libc_init_array` to call the constructors of all static/global C++ objects.
6. It finally calls `main()`.

## 2. Why must the `.data` segment be copied from Flash to RAM during startup?
**Answer:** The `.data` segment contains global variables that have a specific initial value (e.g., `int state = 5;`), but because they are variables, the code must be able to modify them at runtime. Flash memory is Read-Only, so the variables cannot live there permanently. However, RAM is Volatile and loses its contents on power loss. The only solution is to store a permanent "backup" of the initial values in Flash, and have the Startup Code physically copy those values into the writable RAM before the program starts.

## 3. What happens if you delete the loop in the startup code that zeroes out the `.bss` section?
**Answer:** Any uninitialized global or static variable (e.g., `int counter;`) is assumed by the C Standard to start at `0`. If you delete the `.bss` initialization loop, those variables will instead start with whatever random, corrupted electrical noise happened to exist in the RAM chip when it powered on. Your `counter` might start at `3,194,204`, instantly breaking any logic that relied on it starting at zero.
