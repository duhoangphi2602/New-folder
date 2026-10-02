# Embedded C/C++17 Learning Repository

Welcome to the definitive learning repository for Embedded C/C++ and Modern C++ (C++17). This repository is designed to bridge the gap between Desktop C++ learning and production-ready Embedded Software Engineering.

## Goal

This repository transforms theoretical C++ knowledge into practical embedded firmware development skills. After completing this repository, you will be able to:
1. Read, write, and debug Embedded C/C++17 code.
2. Understand memory, compilers, linkers, startup routines, peripherals, interrupts, RTOS, and concurrency.
3. Apply C++17 features safely in resource-constrained systems.

## Repository Structure

The repository is structured into 17 main phases. See [ROADMAP.md](./ROADMAP.md) for a comprehensive overview of the curriculum.

- **00-getting-started**: Setup and environment
- **01-program-structure**: Source files, translation units, compilation pipeline, startup
- **02-pointers-arrays**: Addresses, memory-mapped I/O, `std::string_view`
- **03-structural-data**: Structs, enums, bit-fields, bit-masks, padding
- **04-input-output**: Standard I/O vs Embedded I/O, UART redirect
- **05-memory**: Stack, heap, `.data`, `.bss`, linker script, vector table
- **06-resource-management**: RAII, allocators, fragmentation
- **07-rtos-concurrency**: Tasks, schedulers, mutexes, semaphores, deadlocks
- **08-interrupt-isr**: ISR rules, latency, shared data
- **09-volatile-atomic-ordering**: `volatile`, `std::atomic`, memory ordering
- **10-toolchain-build**: Cross-compilation, CMake, flags
- **11-embedded-peripherals**: Registers, GPIO, UART, DMA, Bootloaders
- **12-cpp-vs-c-vs-cpp17**: Feature comparisons, STL strategies for embedded
- **13-practical-projects**: Real-world integrated projects
- **14-interview**: Interview question bank
- **15-exercises**: Multilevel exercises
- **16-reference**: Cheat sheets, checklists, guides

## How to Navigate

- [LEARNING_ORDER.md](./LEARNING_ORDER.md) - Recommended sequence for studying topics.
- [REPOSITORY_MAP.md](./REPOSITORY_MAP.md) - Map of where everything is located.
- [SELF_ASSESSMENT.md](./SELF_ASSESSMENT.md) - Evaluate your skills level by level.
- [GLOSSARY.md](./GLOSSARY.md) - Definitions of terms used.
- [CONTRIBUTING.md](./CONTRIBUTING.md) - Guidelines for repository consistency.

## Topic Structure

Every topic folder is structured consistently:
- `README.md` / `theory.md` (What, why, how, Embedded context)
- `examples/` (Runnable C/C++/C++17/Embedded examples)
- `exercises/` (Practice problems)
- `solutions/` (Answers)
- `interview.md` (Common interview questions)

## Building the Examples

Most examples use CMake. A top-level `CMakeLists.txt` is provided to build everything.

```bash
mkdir build
cd build
cmake ..
cmake --build .
```
