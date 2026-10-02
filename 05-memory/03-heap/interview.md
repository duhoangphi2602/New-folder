# Interview Questions: The Heap

## 1. What is Heap Fragmentation, and why does it make dynamic allocation dangerous for long-running embedded systems?
**Answer:** Heap Fragmentation occurs when memory chunks of varying sizes are allocated and freed over time, leaving many small, non-contiguous "holes" of free memory scattered throughout the Heap. Eventually, the system might have plenty of total free RAM, but no single hole is large enough to satisfy a new contiguous memory request. `malloc` will fail, crashing the system. Because microcontrollers must often run 24/7 for years without rebooting, fragmentation is mathematically inevitable if `malloc`/`free` are used continuously.

## 2. In modern C++, what should you use instead of raw `new` and `delete` to prevent memory leaks?
**Answer:** You should use **Smart Pointers** (`std::unique_ptr` and `std::shared_ptr`). Smart pointers wrap the raw pointer inside a stack-allocated object. When the stack object goes out of scope (e.g., the function ends or an exception is thrown), its destructor automatically calls `delete` on the underlying Heap memory, guaranteeing that a memory leak can never occur. (However, smart pointers do not solve fragmentation).

## 3. How do safety-critical standards (like MISRA C++) handle the Heap?
**Answer:** They outright ban it. In highly reliable systems, all dynamic allocation (`malloc`, `new`) is forbidden after the initial boot sequence. All required memory must be statically allocated at compile time (Global Arrays or Memory Pools). This guarantees the memory footprint is 100% deterministic, eliminating both memory leaks and fragmentation.
