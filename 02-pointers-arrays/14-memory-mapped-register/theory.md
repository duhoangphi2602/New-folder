# Memory-Mapped Register (MMIO)

## 1. Concept
In **Memory-Mapped I/O (MMIO)**, hardware peripherals (like pins, timers, and communication ports) are controlled by reading and writing to specific, hardcoded memory addresses. The CPU treats these hardware registers exactly like standard RAM. When you write a `1` to a specific bit at a specific address, a physical transistor inside the chip changes state.

## 2. Why
Microcontrollers need a fast, standard way to communicate with integrated peripherals. Instead of creating special assembly instructions for every possible peripheral (like x86's `IN` and `OUT` port instructions), ARM Cortex-M maps everything to a single, unified 32-bit address space. This allows developers to use standard C/C++ pointers to control the entire chip.

## 3. Syntax

**C-Style Syntax (Legacy):**
```c
// #define a macro that casts an integer to a volatile pointer, then dereferences it
#define GPIOA_ODR (*(volatile uint32_t*)0x40020014)

// Usage:
GPIOA_ODR = 0x01; // Writes 1 to the register
```

**C++17 Style Syntax (Modern, Type-Safe):**
```cpp
// Use reinterpret_cast to create a pointer to a specific hardware address
inline constexpr auto GPIOA_ODR_ADDR = 0x40020014;
auto* const gpioa_odr = reinterpret_cast<volatile std::uint32_t*>(GPIOA_ODR_ADDR);

// Usage:
*gpioa_odr = 0x01; // Writes 1 to the register
```

## 4. Example
*(See full runnable simulation in `examples/mmio_simulation.cpp`)*

Imagine we want to turn on an LED connected to Pin 5 of GPIO Port A.
1. The datasheet says Port A starts at `0x40020000`.
2. The Output Data Register (ODR) is at offset `0x14`.
3. The absolute address is `0x40020014`.
4. We need to set the 5th bit (value `1 << 5` or `0x20`) of this address.

```cpp
#include <cstdint>

void turn_on_led() {
    auto* const gpioa_odr = reinterpret_cast<volatile std::uint32_t*>(0x40020014);
    
    // Read the current value, modify bit 5, and write it back
    *gpioa_odr = (*gpioa_odr) | (1 << 5); 
}
```

## 5. Embedded Usage (The Rule of Volatile)
In Embedded Systems, you **must** use the `volatile` keyword when accessing MMIO registers.

```cpp
// BAD: Compiler might optimize this out!
auto* const reg = reinterpret_cast<std::uint32_t*>(0x40020000);
*reg = 1;
*reg = 2; // Compiler thinks: "Why write 1 and then 2? I'll just skip writing 1."

// GOOD: Compiler is forced to execute every read/write
auto* const v_reg = reinterpret_cast<volatile std::uint32_t*>(0x40020000);
*v_reg = 1; // Actually happens on hardware
*v_reg = 2; // Actually happens on hardware
```
Without `volatile`, the compiler's optimizer assumes memory only changes when the CPU changes it. Hardware registers change on their own (e.g., a button press changes a memory address). `volatile` tells the compiler: *"Do not optimize or cache this address; always read/write directly to RAM."*

## 6. Trade-offs

| Approach | Advantages | Disadvantages |
|----------|------------|---------------|
| **C-Style Macros (`#define`)** | Standard in vendor HALs (STM32Cube). No memory overhead. | No type safety. Bypasses C++ namespaces. Hard to debug. |
| **C++ `reinterpret_cast` Pointers** | Type-safe. Respects namespaces. Integrates with C++ tooling. | Slightly more verbose. Requires solid pointer understanding. |
| **C++ struct Mapping** | Highly readable (`GPIOA->ODR = 1`). Groups registers perfectly. | Padding issues if not careful. Compiler ABI dependent. |

## 7. Exercises
Please proceed to the `exercises/` folder to test your understanding of defining and manipulating memory-mapped registers.

## 8. Interview
Please proceed to `interview.md` for real-world interview questions related to this topic.
