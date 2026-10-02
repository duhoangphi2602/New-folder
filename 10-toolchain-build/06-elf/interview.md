# Interview Questions: ELF Format

## 1. What role does the ELF file play in hardware debugging?
**Answer:** The ELF file is the absolute source of truth for the debugger (like GDB). When you hit a physical hardware breakpoint in the microcontroller, the chip only knows its Program Counter (e.g., it stopped at memory address `0x08001044`). The debugger on your PC reads the massive DWARF Debugging Metadata embedded inside the ELF file. It acts as a reverse-dictionary, allowing the debugger to translate `0x08001044` back into "Line 42 of `sensor.cpp`", allowing the developer to step through human-readable source code while the physical chip is executing raw machine code.

## 2. Why can't you just take an ELF file and drag-and-drop it into a raw Flash memory chip using a standard EEPROM programmer?
**Answer:** Because an ELF file is not a raw memory image. It is a structured database container. If you burn an ELF file directly into Flash byte-for-byte, the microcontroller will try to execute the ELF Header text (`7F 45 4C 46`) as if it were ARM assembly instructions, instantly crashing with a Hard Fault. To program a raw memory chip, you must first extract the pure machine code payload from the ELF file and convert it into a flat `.bin` or `.hex` file.

## 3. What is the `.bss` section's size inside the physical ELF file vs its size in RAM?
**Answer:** This is a classic trick question. Inside the ELF file on your hard drive, the `.bss` section takes up exactly zero bytes (it is marked as `NOBITS`). The ELF file only contains a Section Header that says, "When the program boots, please allocate 1024 bytes in RAM at address `0x20000000`". The physical zeros are generated dynamically at runtime by the Assembly Startup Code (Reset Handler), keeping the ELF file and Flash memory footprint small.
