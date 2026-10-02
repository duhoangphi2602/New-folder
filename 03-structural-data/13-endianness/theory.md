# Endianness

## 1. Concept
Imagine the 32-bit hexadecimal number `0x1A2B3C4D`. It is composed of 4 bytes:
- The **Most Significant Byte (MSB)** is `0x1A` (the "biggest" part, like the thousands digit in a decimal number).
- The **Least Significant Byte (LSB)** is `0x4D` (the "smallest" part).

When saving this to RAM starting at address `0x1000`:
- **Big Endian:** Stores the MSB first. `[0x1A, 0x2B, 0x3C, 0x4D]`. (Reads left-to-right, like English).
- **Little Endian:** Stores the LSB first. `[0x4D, 0x3C, 0x2B, 0x1A]`. (Reads backwards).

## 2. Why
Historically, different CPU manufacturers chose different designs to optimize their internal silicon logic. Today, almost all modern desktop (x86/x64) and embedded (ARM Cortex-M, RISC-V) processors are Little Endian. 
However, **Network Byte Order** (the standard for sending data over TCP/IP internet) is explicitly defined as **Big Endian**. 

## 3. Example
*(See `examples/` for runnable code demonstrating how to detect Endianness using a union).*

## 4. Embedded usage (Network Byte Swapping)
When an embedded device sends a 32-bit integer over Wi-Fi or Ethernet, it must convert its internal Little Endian data into Big Endian before transmission.

```cpp
#include <cstdint>

// A manual byte-swapping function using Bit-Masks
uint32_t swap_bytes_32(uint32_t value) {
    return ((value & 0x000000FF) << 24) |
           ((value & 0x0000FF00) << 8)  |
           ((value & 0x00FF0000) >> 8)  |
           ((value & 0xFF000000) >> 24);
}

void send_over_network(uint32_t sensor_data) {
    // 1. Convert to Network Byte Order (Big Endian)
    uint32_t safe_data = swap_bytes_32(sensor_data);
    
    // 2. Transmit the bytes
    tcp_send(reinterpret_cast<uint8_t*>(&safe_data), 4);
}
```
*(Note: Most systems provide built-in macros like `htonl()` (Host TO Network Long) which use hardware-accelerated CPU instructions like `REV` on ARM to swap bytes in a single clock cycle, instead of doing it manually).*

## 5. Endianness and Bit-Fields
Endianness affects how **Bit-Fields** are packed inside a single byte. 
- A Little Endian compiler packs bit-fields starting from the LSB (Bit 0).
- A Big Endian compiler packs bit-fields starting from the MSB (Bit 7).
This is the fundamental reason why Bit-Field structs are strictly banned when defining cross-platform network packets or cross-platform hardware drivers.

## 6. Trade-offs (Performance vs Portability)
Writing portable serialization code (using bit-shifts) takes slightly more typing and might seem slower than just using `std::memcpy` or casting a struct pointer over a byte array. However, compiler optimization today is so advanced that portable bit-shifting code is usually optimized directly into a single hardware read instruction, giving you the best of both worlds: 100% portability and 100% performance.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
