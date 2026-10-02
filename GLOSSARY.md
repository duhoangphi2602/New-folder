# Embedded C/C++ Glossary

## A
- **ABI (Application Binary Interface):** The low-level interface between an application and the operating system or between compiled modules.
- **Alignment:** The requirement that data types be placed in memory at addresses that are multiples of specific values (e.g., 4-byte boundaries).
- **Atomic Operation:** An operation that runs completely independently of any other processes or interrupts, appearing instantaneous to the rest of the system.

## B
- **Bare-metal:** Programming a microcontroller directly without an operating system or RTOS.
- **Bit-field:** A data structure (often inside a `struct`) that allows integer members to be packed into memory spaces smaller than the standard integer size.
- **Bit-mask:** A binary number used with bitwise operations (AND, OR, XOR) to isolate, set, or clear specific bits in a register.
- **BSS (.bss):** Block Started by Symbol. A memory segment containing statically allocated variables that are initialized to zero.
- **BSP (Board Support Package):** Code that implements hardware-specific operations for a given OS or RTOS to run on a specific board.

## C
- **Context Switch:** The process of saving the state of a currently running task/thread and restoring the state of the next task/thread.
- **Critical Section:** A block of code that must not be interrupted by other tasks or interrupts, often protected by disabling interrupts or using a mutex.
- **Cross-compilation:** Compiling code on one architecture (Host) that is intended to run on a different architecture (Target).

## D
- **Deadlock:** A state where two or more tasks are blocked forever, each waiting for a resource held by another.
- **Determinism:** The ability to guarantee that an operation will complete within a known, predictable amount of time.
- **DMA (Direct Memory Access):** A hardware feature allowing peripherals to transfer data directly to/from RAM without CPU intervention.

## E
- **Endianness:** The order in which bytes are arranged in memory. (Little-endian: least significant byte first. Big-endian: most significant byte first).
- **ELF (Executable and Linkable Format):** The standard binary file format for objects and executables.

## H
- **HAL (Hardware Abstraction Layer):** A software layer that hides the specific details of the hardware, providing a consistent API to higher layers.
- **Heap:** A memory segment used for dynamic memory allocation (`malloc`/`new`). Often restricted or avoided in critical embedded systems.

## I
- **ISR (Interrupt Service Routine):** A software routine that hardware invokes in response to an interrupt.

## M
- **MMIO (Memory-Mapped I/O):** A method of performing I/O where hardware registers are mapped into the same address space as RAM.
- **Mutex:** A synchronization primitive used to prevent concurrent access to a shared resource (Mutual Exclusion).

## P
- **Padding:** Extra bytes inserted by the compiler into structs to satisfy alignment requirements.
- **Priority Inversion:** A scenario in scheduling where a high-priority task is indirectly preempted by a lower-priority task holding a shared resource.

## R
- **RAII (Resource Acquisition Is Initialization):** A C++ programming technique where resource management (memory, locks, files) is tied to object lifetime (constructor/destructor).
- **RTOS (Real-Time Operating System):** An OS intended to serve real-time applications that process data as it comes in, typically without buffering delays.

## S
- **Semaphore:** A synchronization primitive used to signal events or manage a pool of resources.
- **Stack:** A LIFO memory segment used for local variables, function arguments, and return addresses.
- **Startup Code:** Assembly or C code that runs immediately after a microcontroller resets, initializing memory (RAM) before calling `main()`.

## V
- **Volatile:** A C/C++ keyword telling the compiler that a variable's value may change at any time without any action being taken by the code the compiler finds nearby, preventing optimization.
- **Vector Table:** An array of addresses (pointers) to the ISRs, typically located at the very beginning of the memory map.
