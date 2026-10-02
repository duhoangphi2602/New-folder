# Self-Assessment Guide

Use this document to evaluate your progress. Rate yourself from Level 0 to Level 5 for each topic.

## Level Definitions
- **Level 0 (Unaware):** I don't know what this is.
- **Level 1 (Familiar):** I know the concept but can't write code for it without help.
- **Level 2 (Competent):** I can write standard C/C++ code using this feature.
- **Level 3 (Embedded Aware):** I can use this in an embedded context and know its memory/CPU impact.
- **Level 4 (Advanced):** I can explain the trade-offs (e.g., `vector` vs `array`, `volatile` vs `atomic`) and debug complex issues.
- **Level 5 (Master):** I could design a firmware architecture utilizing this efficiently and teach it to others.

---

## 01. Program Structure & Basics
- [ ] Translation Units and `#include`
- [ ] Preprocessing and Compilation Pipeline
- [ ] Functions and `inline`
- [ ] Scope, `static`, and `extern`
- [ ] `main()` and Embedded Startup Routine

## 02. Pointers and Memory Access
- [ ] Pointer Basics & Arithmetic
- [ ] Pointers vs Arrays & Array Decay
- [ ] Const Correctness (Pointers)
- [ ] Memory-Mapped Registers (MMIO)
- [ ] `std::string_view` (C++17)

## 03. Structural Data
- [ ] `struct` Memory Layout & Padding
- [ ] `typedef` and `using`
- [ ] `enum` vs `enum class`
- [ ] `union` and Strict Aliasing
- [ ] Bit-fields vs Bit-masks
- [ ] Serialization & Endianness

## 04. Input / Output
- [ ] C Standard I/O vs C++ I/O
- [ ] Retargeting `printf` to UART
- [ ] Polling vs Interrupt-based I/O

## 05. Memory
- [ ] Stack vs Heap
- [ ] Data, BSS, Text, RoData segments
- [ ] Linker Scripts
- [ ] Vector Table placement
- [ ] Stack Overflow prevention

## 06. Resource Management
- [ ] `malloc` / `new` dangers in Embedded
- [ ] RAII concept and implementation
- [ ] Static vs Pool Allocation

## 07. RTOS & Concurrency
- [ ] Task vs ISR
- [ ] Context Switching
- [ ] Mutex vs Semaphore
- [ ] Race Conditions & Critical Sections
- [ ] Priority Inversion & Deadlock

## 08. Interrupts
- [ ] ISR Constraints (No blocking, minimal execution)
- [ ] ISR-to-Task Communication (Buffer/Queue)
- [ ] Shared Data (Main vs ISR)

## 09. Volatile & Atomic
- [ ] When to use `volatile`
- [ ] When `volatile` fails (Race conditions)
- [ ] `std::atomic` and Memory Ordering

## 10. Toolchain
- [ ] Cross-compilation (Host vs Target)
- [ ] Compiler Flags (`-O`, `-W`)
- [ ] CMake for Embedded
- [ ] ELF analysis (`nm`, `readelf`, `objdump`)

## 11. Peripherals
- [ ] GPIO Configuration
- [ ] UART Driver Implementation
- [ ] DMA Concept
- [ ] HAL (Hardware Abstraction Layer) Design

## 12. C++17 for Embedded
- [ ] `constexpr` and `if constexpr`
- [ ] `std::optional`
- [ ] `std::variant`
- [ ] Move semantics and Copy Elision
- [ ] Safely using STL

## 13. Practical Design
- [ ] C Driver to C++ Wrapper Pattern
- [ ] Finite State Machine (C++17 `variant`)
- [ ] Ring Buffer (Template + Static Array)
