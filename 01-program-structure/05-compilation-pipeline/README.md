# Compilation Pipeline

## What is this topic?
This topic breaks down the exact sequence of steps a C/C++ compiler takes to convert raw text files (`.cpp`) into a final, executable binary (`.bin`/`.elf`).

## Why is it important?
When your program fails to build, understanding the pipeline is the only way to know *what* failed. Is it a syntax error (Compiler)? An unresolved symbol (Linker)? A missing file (Preprocessor)? In embedded systems, the final output isn't a `.exe`; it's a `.bin` or `.hex` file, which requires understanding an additional extraction step.

## Prerequisites
- [03-translation-unit](../03-translation-unit/README.md)
- [04-preprocessing](../04-preprocessing/README.md)

## Learning Outcomes
1. Identify the 4 main stages: Preprocess → Compile → Assemble → Link.
2. Understand the Embedded-specific step of binary extraction (`objcopy`).
3. Differentiate between compiler errors and linker errors.
