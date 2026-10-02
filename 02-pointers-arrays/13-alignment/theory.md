# Memory Alignment

## 1. Concept
Most CPUs read memory in chunks (e.g., 32 bits / 4 bytes at a time). Because of how the silicon bus is wired, they prefer—or strictly require—that data structures start at addresses that are multiples of their size. This is called **natural alignment**.

- `uint8_t` (1 byte) can live anywhere (address 0, 1, 2, 3...).
- `uint16_t` (2 bytes) must live on even addresses (0, 2, 4, 6...).
- `uint32_t` (4 bytes) must live on addresses divisible by 4 (0, 4, 8, 12...).

## 2. Why
If a 32-bit CPU tries to read a 32-bit integer that starts at address `0x1001`, the integer straddles two different physical memory chunks.
- **x86 / Cortex-M4**: The CPU does two separate reads under the hood and stitches the data together. This is slow.
- **Cortex-M0 / RISC-V**: The CPU throws its hands up and triggers a **Hardware Fault** (crash).

## 3. Syntax (C++11 Keywords)

C++11 introduced two keywords to manage alignment:

**`alignof`**: Query the alignment requirement of a type.
```cpp
size_t a = alignof(uint32_t); // Returns 4
```

**`alignas`**: Force a variable to be aligned to a stricter boundary.
```cpp
// Forces the array to start at a memory address divisible by 32
alignas(32) uint8_t dma_buffer[256];
```

## 4. Example
*(See `examples/` for runnable code demonstrating alignment requirements and pointer cast dangers).*

## 5. Embedded usage (DMA and Network Parsing)

### 1. Pointer Casting Danger (Network Packets)
When parsing incoming UART or Ethernet packets, developers often cast a raw byte array to a `uint32_t*` to read a 4-byte header.
```cpp
uint8_t rx_buffer[10] = { /* ... */ };

// DANGER! &rx_buffer[1] is an odd address!
uint32_t* header_ptr = reinterpret_cast<uint32_t*>(&rx_buffer[1]);

// HARD FAULT on Cortex-M0!
uint32_t header = *header_ptr; 
```
**The Safe Solution:** Use `std::memcpy`. Modern C++ compilers optimize `memcpy` for small fixed sizes into the exact safe assembly instructions needed for the target architecture.
```cpp
uint32_t header;
std::memcpy(&header, &rx_buffer[1], sizeof(header)); // 100% Safe
```

### 2. DMA Buffers
When using a DMA controller to transfer data to a peripheral, the hardware manual often requires the buffer to be aligned to the cache line size (e.g., 32 bytes) so that cache invalidation operations don't accidentally wipe out adjacent variables. You enforce this using `alignas(32)`.

## 6. Trade-offs (Padding)

When you group variables together in a `struct`, the compiler automatically inserts hidden "padding" bytes between them to satisfy alignment rules. (This will be covered in deep detail in Chapter 03).
The trade-off of alignment is **wasted RAM**.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
