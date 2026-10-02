# Linking

## 1. The Inputs
The Linker receives three things:
1. All of your compiled **Object Files** (`main.o`, `sensor.o`, `uart.o`).
2. **Static Libraries** (`.a` files), like the C/C++ Standard Library (`libc.a`, `libm.a`), containing pre-compiled code for functions like `printf()` or `sin()`.
3. A **Linker Script** (`.ld` file), which provides the physical memory blueprint (Flash starts at `0x08000000`, RAM starts at `0x20000000`).

## 2. Phase 1: Symbol Resolution
The Linker looks at the Symbol Tables of all the `.o` files.
- `main.o` says: *"I have an Undefined ('U') requirement for a function called `uart_init`."*
- The Linker searches all other files.
- It finds `uart.o`, which says: *"I have a Defined ('T') function called `uart_init`."*
- The Linker successfully connects them.

**Error 1: Undefined Reference**
If the Linker searches every `.o` file and every `.a` library, and cannot find `uart_init`, it halts and throws an **Undefined Reference** error. (You forgot to compile `uart.cpp`, or you forgot to link the library).

**Error 2: Multiple Definition**
If the Linker searches and finds that BOTH `uart.o` and `debug.o` claim to have a Defined ('T') function named `uart_init`, it halts and throws a **Multiple Definition** error. It doesn't know which one to use. (You forgot to use `static`, or you implemented a function inside a header file).

## 3. Phase 2: Relocation (Assigning Addresses)
Right now, the code in `main.o` and `sensor.o` both think they start at memory address `0x00`. 
The Linker uses the Linker Script to lay out the final memory map.
1. It gathers the `.text` sections from all `.o` files and stacks them back-to-back in Flash Memory.
   - `main.o`'s `.text` goes from `0x08000000` to `0x08000100`.
   - `sensor.o`'s `.text` goes from `0x08000100` to `0x08000200`.
2. It gathers the `.data` sections and stacks them back-to-back in RAM.
3. Now that every variable and function has an absolute physical address (VMA/LMA), the Linker goes back into the machine code and overwrites the blank placeholders with the true physical addresses.

## 4. The Output: Executable (ELF)
The output is a single, massive binary file (usually an `.elf` or `.out` file). This file contains the perfectly linked machine code, the assigned memory addresses, and (optionally) debugging symbols so your debugger knows which line of C++ corresponds to which memory address.

## 5. Example
*(See `examples/` for a simulated view of the Relocation process).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
