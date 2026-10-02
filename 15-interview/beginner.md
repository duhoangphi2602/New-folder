# 14 — Interview Preparation

## Beginner Questions

1. **What is a pointer?**
   A variable that stores the memory address of another object.

2. **What is the difference between stack and heap?**
   Stack: automatic, LIFO, fixed size, fast. Heap: dynamic, manual allocation/deallocation, fragmentation risk.

3. **What is a `struct`?**
   A composite type grouping variables of different types. In C++, `struct` defaults to public access, `class` defaults to private.

4. **What is `const`?**
   A qualifier indicating the variable/parameter should not be modified. In embedded, used for read-only registers and API contracts.

5. **What is `static`?**
   File scope: internal linkage. Function scope: persistent local variable. Class scope: shared member.

6. **What are `enum` and `enum class`?**
   `enum`: unscoped, implicitly converts to int. `enum class` (C++11): scoped, no implicit conversion, type-safe.

7. **What is `sizeof`?**
   Compile-time operator returning the size in bytes. For structs, includes padding.

8. **What is the difference between C and C++?**
   C: procedural, manual memory, macros. C++: OOP, RAII, templates, type safety, STL.

---

## Intermediate Questions

9. **What is RAII?**
   Resource Acquisition Is Initialization. Resources are acquired in constructors and released in destructors, tying resource lifetime to object scope.

10. **What is `volatile`?**
    Prevents compiler from optimizing away memory accesses. Used for hardware registers and ISR-shared flags. Does NOT provide atomicity or thread-safety.

11. **What is `std::atomic`?**
    Provides atomic operations with memory ordering guarantees. Used for lock-free shared state between tasks/ISR.

12. **What is a mutex?**
    Mutual exclusion primitive with ownership. The task that locks must unlock. Supports priority inheritance on most RTOS.

13. **What is a semaphore?**
    Signaling primitive without ownership. Binary semaphore: ISR→task signaling. Counting semaphore: resource/event counting.

14. **What is the difference between `const int*` and `int* const`?**
    `const int*`: pointer to const data (can't modify data). `int* const`: const pointer (can't change pointer address).

15. **What is a linker script?**
    Defines how code/data sections are placed in Flash/RAM. Maps `.text`, `.data`, `.bss` to physical memory.

16. **Why is `printf` expensive in embedded?**
    Uses significant Flash (formatting code), RAM (buffer), and CPU cycles. Blocks on UART TX. Must never be called from ISR.

---

## Advanced Questions

17. **What is priority inversion?**
    A high-priority task is blocked by a low-priority task holding a mutex, while a medium-priority task runs. Solved by priority inheritance.

18. **What is the Static Initialization Order Fiasco?**
    Global C++ object construction order across translation units is undefined. If objects depend on each other, use function-local static (Construct on First Use).

19. **What happens before `main()` on a bare-metal MCU?**
    CPU loads SP from vector table[0], jumps to Reset_Handler from vector table[1]. Startup copies `.data` from Flash→RAM, zeros `.bss`, calls SystemInit, runs global constructors, then calls `main()`.

20. **Why is dynamic allocation dangerous in embedded?**
    Fragmentation after many alloc/free cycles. Non-deterministic latency. Allocation failure with no recovery path. Prefer static allocation or memory pools.

21. **When would you use `std::variant` in embedded?**
    For type-safe state machines, discriminated unions, or representing alternative result types. Zero dynamic allocation, compile-time type checking.

22. **What C++17 features are most useful in embedded?**
    `constexpr` (compile-time computation), `if constexpr` (compile-time branching), `std::optional` (typed optional results), `std::variant` (type-safe unions), `std::string_view` (zero-copy string views), `[[nodiscard]]` (API misuse prevention).
