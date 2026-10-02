# Cross-Compilation

## What is this topic?
This topic formalizes the concept of **Cross-Compilation**, a foundational principle of all embedded systems development.

## Why is it important?
You are writing code on a laptop (Windows/Mac/Linux) with an Intel or Apple Silicon processor, 16 GB of RAM, and a full OS. You are deploying that code to a microcontroller with an ARM processor, 64 KB of RAM, and no OS. Understanding how the Host and Target ecosystems are strictly separated prevents catastrophic architectural mistakes.

## Prerequisites
- [03-assembly](../03-assembly/README.md)
- [11-arm-none-eabi](../11-arm-none-eabi/README.md)

## Learning Outcomes
1. Define Host vs Target architectures.
2. Explain why you cannot compile code directly *on* a microcontroller.
3. Understand how cross-compilers provide custom, stripped-down Standard Libraries (like `newlib-nano`).
