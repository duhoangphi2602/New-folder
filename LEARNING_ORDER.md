# Learning Order

This document proposes a logical, phased approach to learning the material in this repository. Instead of going purely alphabetically by folder, follow these stages to build concepts progressively.

## Phase 1: Foundation
*Establish basic C/C++ syntax and program anatomy.*
- `01-program-structure/`: Understand translation units, compilation, and `main()`.
- `02-pointers-arrays/`: Master pointers, addresses, and arithmetic.

## Phase 2: Data Structures & Layout
*Learn how data is grouped and represented in memory.*
- `03-structural-data/`: Focus on `struct`, `typedef`, alignment, padding, and bit manipulation.

## Phase 3: Memory & Hardware Interaction
*Connect software to hardware limits and execution context.*
- `05-memory/`: Understand `.text`, `.data`, `.bss`, linker scripts, and firmware startup.
- `11-embedded-peripherals/`: Apply pointers and bit-masks to Memory-Mapped I/O (MMIO) and registers.

## Phase 4: Modern C++ Features
*Upgrade your C/C++ knowledge to modern, safe paradigms.*
- `12-cpp-vs-c-vs-cpp17/` (Part 1): Focus on `constexpr`, `optional`, `variant`, and language differences.

## Phase 5: Resource Management
*Learn to manage limited RAM safely.*
- `06-resource-management/`: Study RAII, static allocation, memory pools, and why dynamic allocation is dangerous.

## Phase 6: Embedded I/O
*Understand how data enters and leaves the MCU.*
- `04-input-output/`: Focus on UART, retargeting `printf`, and logging.

## Phase 7: Interrupts & Shared State
*Handle asynchronous hardware events.*
- `08-interrupt-isr/`: Learn ISR constraints and ISR-to-task patterns.
- `09-volatile-atomic-ordering/`: Master `volatile` vs `std::atomic` for shared state.

## Phase 8: Concurrency & RTOS
*Scale up to multi-tasking systems.*
- `07-rtos-concurrency/`: Learn tasks, mutexes, semaphores, race conditions, and priority inversion.

## Phase 9: Toolchain & Build Systems
*Understand how the code becomes a binary.*
- `10-toolchain-build/`: Deep dive into cross-compilation, CMake, flags, and ELF files.

## Phase 10: Practical Convergence
*Put it all together.*
- `13-practical-projects/`: Build the Ring Buffer, State Machine, and the Mini Embedded System.

## Phase 11: Validation
*Test your knowledge.*
- `15-exercises/`: Work through the multi-level exercises.
- `14-interview/`: Practice answering beginner to advanced interview questions.

## Phase 12: Assessment
*Evaluate your readiness.*
- `SELF_ASSESSMENT.md`: Check off competencies.
