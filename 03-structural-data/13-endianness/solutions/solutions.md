# Solutions: Endianness

## Solution 1: Memory Layout
**Answer:**
1. **Little Endian (Stores Smallest Byte First):**
   - Address `0x2000`: `0xCD`
   - Address `0x2001`: `0xAB`
2. **Big Endian (Stores Biggest Byte First):**
   - Address `0x2000`: `0xAB`
   - Address `0x2001`: `0xCD`

## Solution 2: `htons`
**Answer:**
```cpp
uint16_t htons_manual(uint16_t host_short) {
    // Mask the bottom byte and shift it to the top OR
    // Mask the top byte and shift it to the bottom
    return ((host_short & 0x00FF) << 8) | 
           ((host_short & 0xFF00) >> 8);
}
```
*(Note: If the `host` processor is already Big Endian, a true `htons` function does absolutely nothing and just returns the original value. This manual logic assumes the host is Little Endian).*
