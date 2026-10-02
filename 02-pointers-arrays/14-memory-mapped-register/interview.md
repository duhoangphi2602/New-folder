# Interview Questions: Memory-Mapped I/O

## 1. What does the `volatile` keyword do, and why is it mandatory for MMIO?
**Answer:** `volatile` tells the compiler that a variable's value can change at any time, independently of the code executing nearby (e.g., changed by hardware or an ISR). It prevents the compiler from optimizing out read/write operations and forces it to fetch the value directly from RAM/hardware on every access, rather than caching it in a CPU register. If omitted in MMIO, polling loops will become infinite loops in optimized builds.

## 2. Given the physical address `0x40021000` for a 32-bit hardware register, how would you write a value of `0x55` to it in C?
**Answer:**
```c
#define REG (*(volatile uint32_t*)0x40021000)
REG = 0x55;
```

## 3. What is the difference between `volatile uint32_t *ptr` and `uint32_t * volatile ptr`?
**Answer:**
- `volatile uint32_t *ptr`: The **data** pointed to is volatile. You use this for hardware registers. The compiler won't optimize reads/writes to the data.
- `uint32_t * volatile ptr`: The **pointer itself** is volatile. The data is normal. This is rare, but used if an interrupt service routine might change the address the pointer is pointing to.
- `volatile uint32_t * volatile ptr`: Both the pointer and the data are volatile.

## 4. Why might an experienced C++ embedded developer prefer `reinterpret_cast` over C-style macros for hardware registers?
**Answer:**
1. **Type Safety:** C++ casts restrict invalid conversions and are easily searchable in a codebase.
2. **Scoping/Namespaces:** C-style macros `#define` ignore C++ namespaces, leading to global namespace pollution. A pointer declared as `constexpr auto*` inside a `namespace STM32 { ... }` respects scope.
3. **Debugging:** Macros are expanded by the preprocessor, making them opaque to some debuggers. Typed pointers are actual symbols the debugger can inspect.
