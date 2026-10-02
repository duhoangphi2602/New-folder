# Master Learning Path

This is the comprehensive roadmap for the Embedded C/C++17 curriculum.

## PART A — C/C++ Program Structure
Covered in: `01-program-structure/`
- Source File Structure
- Translation Unit
- Preprocessing
- Compilation Pipeline (Compile → Assemble → Link)
- Functions, Function Pointers, Lambda
- `inline`, `static`, `extern`
- `main()` and Embedded Startup
- Runtime Initialization

## PART B — Pointer / Array
Covered in: `02-pointers-arrays/`
- Variables, Addresses, Dereferencing
- Pointer Arithmetic, Arrays, Decay
- Pointer to Pointer, `void*`, `nullptr`
- Const Correctness (Pointer to const vs Const pointer)
- Memory Safety, Alignment
- Memory-Mapped Registers
- `std::array`, `std::string_view`

## PART C — Structural Data
Covered in: `03-structural-data/`
- Structs, Memory Layout, Padding, Alignment
- Nested Structs, Pointer to Struct
- `typedef` vs `using`
- Fixed-width integers (`<cstdint>`)
- Enums, `enum class`
- Unions, Type Punning
- Bit-fields, Bit-masks
- Endianness, Packet Serialization

## PART D — Input and Output
Covered in: `04-input-output/`
- Standard C/C++ I/O (`printf`, `iostream`)
- Embedded I/O Concepts
- UART Serial Communication
- Redirecting `printf` (retargeting)
- Semihosting, Logging Overhead
- Blocking vs Non-blocking I/O

## PART E — Memory Fundamentals
Covered in: `05-memory/`
- Process vs Embedded Memory Model
- Stack, Heap, Static Storage
- `.text`, `.rodata`, `.data`, `.bss`
- Memory Maps, Alignment, Padding
- Stack Overflow, Heap Fragmentation
- Startup Code, Vector Table, Linker Script

## PART F — Resource Management
Covered in: `06-resource-management/`
- `malloc/free`, `new/delete`
- RAII, Object Lifetime, Ownership
- Smart Pointers in Embedded
- Static Allocation, Pool Allocation
- Managing Heap Fragmentation

## PART G & H — RTOS, Concurrency & Synchronization
Covered in: `07-rtos-concurrency/`
- Tasks, Threads, Processes
- Scheduler, Context Switch
- Race Conditions, Critical Sections
- Mutex, Semaphores (Binary/Counting)
- Deadlocks, Priority Inversion
- Atomic Operations

## PART I — Interrupt / ISR
Covered in: `08-interrupt-isr/`
- Interrupt Concept, ISR Rules
- Latency, Nesting
- ISR-to-Task Communication (Buffer Pattern)
- Shared Data (ISR and Main)

## PART J — Volatile / Atomic / Memory Ordering
Covered in: `09-volatile-atomic-ordering/`
- `volatile` (Uses and Limitations)
- `volatile` vs `std::atomic`
- Memory Ordering (Acquire, Release, Sequential Consistency)

## PART K — Compiler / Linker / Build
Covered in: `10-toolchain-build/`
- Toolchain, Cross-Compiler, GCC/G++
- Compiler Flags, Optimization, Warnings
- Object Files, ELF, BIN/HEX, Symbols
- Linker Scripts
- Make, CMake

## PART L — Embedded-Specific C/C++ (Hardware Bridge)
Covered in: `11-embedded-peripherals/`
- MMIO, Registers, Bit Manipulation
- GPIO, UART, SPI, I2C, ADC, PWM, Timer
- DMA, Watchdog, Bootloader
- HAL, Driver, BSP Patterns

## PART M & N — C vs C++ vs C++17
Covered in: `12-cpp-vs-c-vs-cpp17/`
- Language Comparisons
- C++17 Features (`constexpr`, `optional`, `variant`, etc.)
- Exceptions and RTTI
- Move Semantics, Templates
- Standard Library Strategy for Embedded

## PART O — Practical Examples
Covered in: `13-practical-projects/`
- GPIO Abstraction
- UART Driver
- Packet Parser
- Ring Buffer
- State Machine
- Integrated Mini System

## PART P, Q, R, S, T, U, V
Covered in: `14-interview/`, `15-exercises/`, `16-reference/`, `SELF_ASSESSMENT.md`, `LEARNING_ORDER.md`
