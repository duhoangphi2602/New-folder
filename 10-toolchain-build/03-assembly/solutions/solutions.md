# Solutions: Assembly

## Solution 1: Cross-Compilation
**Answer:** The standard `g++` command uses an Assembler that translates code into the x86 Instruction Set (the dictionary for Intel/AMD processors). The STM32 silicon has an ARM architecture. It cannot read x86 binary code.
**The Fix:** The developer must use a **Cross-Compiler**. This is a toolchain running on an x86 PC, but designed to output ARM binary code. Specifically, they must use `arm-none-eabi-g++` instead of `g++`.

## Solution 2: Disassembly
**Answer:** 
- **Can you reconstruct the Assembly?** YES. Because the Assembler is a strict 1-to-1 dictionary, a Disassembler tool can take `0x200C` and perfectly translate it back into `MOV R0, #12`.
- **Can you reconstruct the C++?** NO. The Compiler (Stage 2) is a lossy process. Variable names (`int user_age`), `for` loop structures, and classes are completely destroyed and optimized away into raw registers (`R0`, `R1`) and relative jumps. You can decompile it into *some* C code, but it will be an unreadable mess of generic pointers and `goto` statements, completely lacking the original architecture.
