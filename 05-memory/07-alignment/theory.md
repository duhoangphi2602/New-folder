# Memory Alignment

## 1. Concept
Memory Alignment is the rule that variables must be stored in memory addresses that are integer multiples of their size. 
- A 1-byte `char` can live at any address (`0x...0`, `0x...1`, `0x...2`).
- A 2-byte `short` must live at an even address (`0x...0`, `0x...2`, `0x...4`).
- A 4-byte `int` or `float` must live at an address perfectly divisible by 4 (`0x...0`, `0x...4`, `0x...8`, `0x...C`).

This rule is called **Natural Alignment**.

## 2. Why
Efficiency and Hardware Limitations. 
A 32-bit CPU reads memory in 4-byte chunks. If a 4-byte integer starts at address `0x00000000`, the CPU reads all 4 bytes in a single clock cycle.
If the 4-byte integer starts at `0x00000001`, the integer is split across two separate 4-byte chunks. To read it, the CPU would have to do two separate memory reads, shift the bits, and combine them. To save silicon complexity, early ARM designers simply banned this. If you try it, the CPU throws an "Unaligned Access Exception".

## 3. Syntax (Checking Alignment in C++)

Modern C++ provides the `alignof` operator to query the hardware's strict alignment requirement for any type.

```cpp
#include <iostream>

int main() {
    std::cout << alignof(char) << "\n";  // Prints 1
    std::cout << alignof(short) << "\n"; // Prints 2
    std::cout << alignof(int) << "\n";   // Prints 4
}
```
*Note: The compiler automatically aligns all variables you declare. You only encounter alignment bugs when you manually cast pointers.*

## 4. Example
*(See `examples/` for runnable code demonstrating standard alignment boundaries).*

## 5. Embedded usage (The Network Casting Crash)

The most common alignment crash happens when parsing an incoming byte array from a network or UART:

```cpp
// We receive 5 bytes: [Type] [Data0] [Data1] [Data2] [Data3]
uint8_t raw_buffer[5] = { 0x01, 0xDE, 0xAD, 0xBE, 0xEF };

// The developer wants to read the 4 data bytes as a 32-bit integer.
// They take the address of index 1 (which is an ODD address) 
// and cast it to a 32-bit pointer.
uint32_t* ptr = (uint32_t*)(&raw_buffer[1]);

// CRASH! The ARM CPU sees a 32-bit read at an odd address and Hard Faults.
uint32_t value = *ptr; 
```
**The Fix:** You must use manual bit-shifting or `std::memcpy` to safely extract the 32-bit value from an unaligned address.

## 6. Trade-offs (Modern CPUs vs Older CPUs)
Newer ARM processors (like the Cortex-M4 and M7) actually contain hardware to handle unaligned memory access safely! However, it still costs multiple clock cycles, destroying performance. Older CPUs (like Cortex-M0) lack this hardware entirely and will always crash. Writing perfectly aligned code guarantees maximum performance and 100% portability across all CPU generations.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
