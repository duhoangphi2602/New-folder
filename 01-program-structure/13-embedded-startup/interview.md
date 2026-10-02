# Interview Questions: Embedded Startup

## 1. What happens between CPU reset and `main()` on a bare-metal MCU?
**Answer:** The hardware reads the Vector Table to set the Stack Pointer and jump to the `Reset_Handler`. The `Reset_Handler` (startup code) executes: it copies `.data` (initialized global variables) from Flash to RAM, it zero-fills `.bss` (uninitialized global variables) in RAM, it configures system clocks via a `SystemInit()` call, it executes global C++ constructors by iterating over the `.init_array`, and finally, it calls `main()`.

## 2. Why is `.data` copied from Flash to RAM?
**Answer:** Because variables in `.data` are initialized with specific, non-zero values (like `int x = 42;`). These initial values must be permanently stored in non-volatile memory (Flash) so they aren't lost on power-off. However, because they are standard variables, the program must be able to modify them at runtime. Therefore, they must reside in writable memory (RAM). The startup code copies the initial values from Flash into their permanent runtime locations in RAM.

## 3. What are `_sidata`, `_sdata`, and `_sbss`? Where do they come from?
**Answer:** They are memory address symbols used by the startup code to know where memory sections begin and end. `_sidata` is the Start of Initial Data (in Flash). `_sdata` is the Start of Data (in RAM). `_sbss` is the Start of BSS (in RAM). These symbols are not defined in C code; they are dynamically calculated and exported by the **Linker Script** during the final build stage.

## 4. What happens if the startup code fails to zero-fill the `.bss` section?
**Answer:** Any global or static variables that are supposed to be default-initialized to zero will instead contain random garbage (whatever electrical state the RAM happened to wake up in). This leads to extremely unpredictable and non-deterministic bugs, especially with pointers or boolean flags.
