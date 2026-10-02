# Interview Questions: Compilation Pipeline

## 1. Walk me through the steps of compiling a C++ program.
**Answer:** 
1. **Preprocessor:** Expands macros, resolves `#include` files, and strips comments to create a translation unit.
2. **Compiler:** Parses the C++ syntax and translates it into hardware-specific Assembly language.
3. **Assembler:** Converts the assembly instructions into machine code (binary), producing an Object file (`.o`).
4. **Linker:** Combines all object files, resolves undefined symbols (matching function calls to their definitions), and assigns final memory addresses to produce the Executable (`.elf`).

## 2. What is the difference between a compiler error and a linker error?
**Answer:** A compiler error means your code violates C++ syntax or typing rules (e.g., missing semicolon, passing a string to a function expecting an int). A linker error means the C++ syntax was perfectly fine, but a symbol (like a function or global variable) that was declared and used could not be found anywhere in the provided object files (or was defined multiple times).

## 3. What does `arm-none-eabi-objcopy -O binary` do?
**Answer:** It takes an ELF file (which contains machine code mixed with debugging metadata) and extracts only the raw binary instructions (`.text`, `.data`, `.rodata`). This creates a pure binary file (`.bin`) that can be flashed directly to a microcontroller's ROM/Flash memory.

## 4. Why does embedded firmware need a custom linker script (`.ld`) but desktop programs don't?
**Answer:** On a desktop, the OS loader manages memory dynamically using virtual memory. In a bare-metal embedded system, memory addresses are strictly physical and fixed by the silicon hardware (e.g., Flash starts exactly at `0x08000000`, RAM at `0x20000000`). The linker script explicitly tells the linker where these regions exist so it can assign the correct physical addresses to functions and variables during the link stage.
