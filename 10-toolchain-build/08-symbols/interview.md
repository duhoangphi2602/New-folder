# Interview Questions: Symbols

## 1. What does the `nm` tool do, and what do the letters 'T', 'D', and 'B' stand for in its output?
**Answer:** The `nm` tool parses an Object file (`.o`) or an ELF file (`.elf`) and prints its Symbol Table, which is the list of all variables and functions and their memory addresses.
- **T (Text):** The symbol is located in the `.text` section (Executable code / Functions, usually in Flash).
- **D (Data):** The symbol is located in the `.data` section (Initialized global variables, usually in RAM).
- **B (BSS):** The symbol is located in the `.bss` section (Zero-initialized global variables, usually in RAM).

## 2. Why does C++ mangle function names, but C does not?
**Answer:** C++ supports Function Overloading (having multiple functions with the exact same name but different parameters). The Linker, however, only understands flat, unique string identifiers; it doesn't understand parameter types. To allow the Linker to differentiate between `add(int, int)` and `add(float, float)`, the C++ compiler "mangles" the names by appending characters representing the parameter types (e.g., `_Z3addii` vs `_Z3addff`). C does not support function overloading, so a function named `add` will always be the only `add` in the program, making name mangling unnecessary.

## 3. You are analyzing a Hard Fault on a Cortex-M. The Program Counter (PC) was at `0x08002B4A`. How can you use the `nm` tool to find the function that crashed?
**Answer:** I would run `arm-none-eabi-nm -n firmware.elf` (the `-n` flag sorts the output numerically by address). I would then scroll through the output and look for the 'T' (Text/Function) symbols around the `0x08002B00` range. By finding the function whose start address is just below `0x08002B4A`, and verifying that the *next* function in the list starts after `0x08002B4A`, I can mathematically prove exactly which C++ function contains the crashing instruction.
