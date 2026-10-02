# Solutions: Memory-Mapped Registers

## Solution 1: C-Style Macro Definition

```c
#include <stdint.h>

// Cast the hex address to a pointer to volatile uint32_t, then dereference it.
#define SPI1_CR1 (*(volatile uint32_t*)0x40013000)

// Usage:
// SPI1_CR1 = 0x01;
```
**Why:** The cast `(volatile uint32_t*)` tells the compiler the memory address holds a 32-bit unsigned integer that can change independently of the program flow. The leading `*` dereferences it so the macro acts like a variable.

## Solution 2: C++17 Type-Safe Pointer

```cpp
#include <cstdint>

// The pointer itself is const (we will never move the pointer to a new address).
// The data it points to is volatile (the hardware can change it).
auto* const uart2_dr = reinterpret_cast<volatile std::uint32_t*>(0x40004404);

// Usage:
// *uart2_dr = 'A';
```
**Why:** `reinterpret_cast` is the C++ standard way to cast an integer literal to a pointer. Using `auto* const` enforces that the pointer's destination address cannot be accidentally reassigned.

## Solution 3: Bug Hunt

**The Bug:** The pointer `status_reg` is missing the `volatile` keyword.
In an optimized build (Release mode, `-O2` or `-O3`), the compiler looks at the `while` loop and thinks: *"I already read `status_reg` once, and inside the loop, the software doesn't change it. Therefore, it will never change. I will cache the value in a CPU register and create an infinite loop."*

The program will freeze forever because it only reads the hardware address exactly once.

**Corrected Code:**
```cpp
void wait_for_tx() {
    // ADDED volatile keyword!
    volatile uint32_t* status_reg = (volatile uint32_t*)0x50000018;
    
    while ((*status_reg & 0x80) == 0) {
        // Now the compiler is forced to fetch from memory on EVERY iteration
    }
}
```
