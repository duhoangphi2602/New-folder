# Exercises: Alignment

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Fault
You are writing a driver for a Cortex-M0 (which does not support unaligned memory access).
```cpp
uint8_t packet[32] = {0}; // Assume this array starts at address 0x20000000

uint16_t a = *reinterpret_cast<uint16_t*>(&packet[0]);
uint32_t b = *reinterpret_cast<uint32_t*>(&packet[2]);
uint32_t c = *reinterpret_cast<uint32_t*>(&packet[5]);
uint16_t d = *reinterpret_cast<uint16_t*>(&packet[8]);
```
**Task:** Which of these four reads (`a`, `b`, `c`, or `d`) will trigger a Hard Fault crash? Explain why.

## Exercise 2: DMA Requirement
You are configuring an Ethernet peripheral. The datasheet says: *"The Transmit Descriptor array must be aligned to an 8-byte boundary."*
**Task:** Write the C++17 declaration for an array named `tx_descriptors` that contains 4 elements of type `uint32_t` and satisfies this hardware requirement.
