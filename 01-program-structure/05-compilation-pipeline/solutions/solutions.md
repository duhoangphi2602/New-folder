# Solutions: Compilation Pipeline

## Solution 1: Identify the Stage
**Answer:** The **Linker** stage failed.
**How you know:** The error prefix `/usr/bin/ld:` explicitly points to `ld`, which is the GNU Linker. Furthermore, "undefined reference" is the classic linker error.
**Likely cause:** The developer included `uart.h` and called `uart_init()`, so the compiler was happy. But they forgot to provide `uart.cpp` to the linker (e.g., they didn't add it to their CMakeLists.txt or Makefile), so the linker couldn't find the actual machine code for that function.

## Solution 2: Object Files
**Answer:** 
Only `sensor.cpp` is recompiled. The build system will:
1. Run the Preprocessor, Compiler, and Assembler **only** on `sensor.cpp`, producing a new `sensor.o`.
2. `main.cpp` and `display.cpp` are completely ignored (their old `.o` files are reused).
3. The Linker runs, combining the *new* `sensor.o` with the *existing* `main.o` and `display.o` to produce the final executable.
This is the core concept of **incremental compilation**.

## Solution 3: Embedded Specifics
**Answer:** An ELF (Executable and Linkable Format) file contains the actual machine code, but it is heavily wrapped in metadata for operating systems and debuggers (e.g., section tables, symbol names, DWARF debug info). 
A bare-metal MCU has no operating system to parse an ELF file; it just wants raw instructions to execute at address `0x08000000`.
**The Fix:** You must use the `objcopy` tool to extract the raw binary sections (like `.text` and `.data`).
Example command: `arm-none-eabi-objcopy -O binary firmware.elf firmware.bin`
