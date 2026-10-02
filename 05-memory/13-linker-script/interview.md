# Interview Questions: The Linker Script

## 1. What is the primary purpose of a Linker Script (`.ld` file) in a bare-metal embedded project?
**Answer:** The Linker Script maps the software's logical memory segments (`.text`, `.data`, `.bss`) to the physical memory regions of the specific microcontroller hardware. It defines the starting addresses and sizes of the Flash and RAM, ensuring the generated `.bin` or `.elf` file perfectly aligns with the silicon architecture and preventing the compiler from allocating more memory than the chip physically possesses.

## 2. In a Linker Script, what does the `KEEP(*(.isr_vector))` command do, and why is it critical?
**Answer:** Modern compilers use extreme optimization techniques (like Link-Time Optimization or Dead Code Elimination). Because the Vector Table is an array of function pointers that is *never explicitly called by your C++ code* (it is only used by the hardware), the compiler might assume the array is useless "dead code" and delete it to save space! The `KEEP` keyword explicitly forces the linker to include the Vector Table in the final binary, preventing a catastrophic boot failure.

## 3. How do the Linker Script and the Startup Code work together to initialize the `.bss` segment?
**Answer:** The Linker Script cannot execute code; it only calculates addresses. Inside the Linker Script, the `.bss` section is defined, and two symbols are generated using the location counter (`.`): `_sbss` (Start of BSS) and `_ebss` (End of BSS). The Startup Code (usually an Assembly or C file) imports these two symbols as memory addresses. It then runs a simple `while` loop from `_sbss` to `_ebss`, writing `0x00` to every address, effectively zeroing out the RAM before `main()` begins.
