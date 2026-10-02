# Interview Questions: Static Allocation

## 1. Why do safety-critical coding standards like MISRA-C or NASA's "Power of 10" rules mandate that all memory must be statically allocated?
**Answer:** To guarantee absolute determinism. If a program uses dynamic memory (`malloc`/`new`), it might run perfectly for 6 months, but eventually fail when the Heap becomes fragmented or exhausted due to an unexpected burst of data. By requiring all memory to be allocated statically, the compiler calculates the exact byte-count required at compile-time. If the binary fits in the microcontroller's RAM during the build process, it is mathematically proven that the software will never crash due to an "Out of Memory" error in flight.

## 2. In modern C++, why is `std::array` preferred over C-style arrays (`int buf[10]`) for static allocation?
**Answer:** `std::array` is a zero-overhead wrapper around a C-style array. It provides bounds-checking capabilities (via `.at()`), knows its own size (via `.size()`), and crucially, it does not automatically "decay" into a raw pointer when passed to functions, preserving strict type safety. It compiles down to the exact same memory footprint as a C array.

## 3. What is the fundamental disadvantage of using Static Allocation for a system that connects to the Internet?
**Answer:** Internet traffic is inherently highly variable and unpredictable (bursty). You might have 0 connections, or a sudden spike of 50 connections. If you use Static Allocation, you must reserve maximum RAM for 50 connections permanently. This wastes massive amounts of RAM during idle times, making it very expensive (in terms of hardware costs) to build highly scalable networking systems purely with static memory.
