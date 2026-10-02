# Interview Questions: Compiler Flags

## 1. What does the `-c` flag do, and why is it used in large Makefiles?
**Answer:** The `-c` flag tells the compiler to take the source file, run the Preprocessor, the Compiler, and the Assembler to generate a binary Object file (`.o`), and then completely halt execution. It explicitly prevents the toolchain from invoking the Linker. In a large project with hundreds of files, Makefiles use the `-c` flag to compile every single `.cpp` file independently into `.o` files. Only after all `.o` files are successfully built does the Makefile issue one final command (without the `-c` flag) to link them all together.

## 2. You want to change the target hardware from an STM32F1 (Cortex-M3) to an STM32F4 (Cortex-M4). What compiler flags must be updated?
**Answer:** The architecture and FPU flags must be updated. 
- The CPU flag must change from `-mcpu=cortex-m3` to `-mcpu=cortex-m4`. 
- Because the Cortex-M4 has a hardware Floating Point Unit (which the M3 lacks), you must add the `-mfloat-abi=hard` flag and the specific `-mfpu=fpv4-sp-d16` flag to instruct the compiler to generate hardware math instructions instead of software simulations.
- You would also likely need to update a Preprocessor definition (e.g., changing `-DSTM32F103xB` to `-DSTM32F411xE`) to alert the HAL libraries of the hardware change.

## 3. What is the difference between `-I` and `-L` flags?
**Answer:** 
- `-I` (capital i) is for the **Preprocessor**. It specifies directories where the toolchain should search for Header files (`.h` / `.hpp`) during the `#include` resolution phase.
- `-L` (capital L) is for the **Linker**. It specifies directories where the toolchain should search for pre-compiled Static Libraries (`.a` / `.so`) during the Symbol Resolution phase.
