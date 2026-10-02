# Interview Questions: Assembly

## 1. What is the difference between a Compiler and an Assembler?
**Answer:** The Compiler (Stage 2) is a high-level logical translator. It takes human-readable C/C++ syntax, performs type checking, highly optimizes the logic (deleting dead code, unrolling loops), and generates human-readable Assembly text (`.s`). It is a lossy, many-to-many translation.
The Assembler (Stage 3) is a low-level mechanical translator. It takes the Assembly text and performs a strict 1-to-1 dictionary lookup, converting mnemonics (like `ADD`) into the raw binary machine code (like `0100 0100`) required by the specific silicon Instruction Set Architecture (ISA). It outputs a binary Object (`.o`) file.

## 2. Why do we need a "Cross-Compiler" (like `arm-none-eabi-gcc`) for embedded development?
**Answer:** Compilers and Assemblers default to generating machine code for the host system they are running on. If you run standard `gcc` on a Windows Intel PC, it generates x86_64 machine instructions. An STM32 microcontroller uses an ARM Cortex-M architecture, which uses a completely different set of physical silicon instructions (Thumb-2 ISA). A cross-compiler is a toolchain that runs on your Intel PC but is configured to use the ARM dictionary, outputting ARM machine code that the microcontroller can actually understand.

## 3. What does "Disassembly" mean, and why is it useful?
**Answer:** Disassembly is the process of reversing the Assembler's job: taking raw binary machine code and translating it back into human-readable Assembly mnemonics. Because the Assembler uses a 1-to-1 lookup table, disassembly is highly accurate. It is incredibly useful for debugging hard faults (e.g., checking exactly which assembly instruction the Program Counter crashed on) or verifying that the Compiler's `-O3` optimizer didn't aggressively delete critical `volatile` hardware reads.
