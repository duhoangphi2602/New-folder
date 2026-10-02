# Solutions: Packet Data Representation

## Solution 1: Serialization Logic
**Answer:**
```cpp
uint16_t temp = 0x1234;
uint8_t msb = (temp >> 8) & 0xFF; // Shifts 0x12 down, masks it. Result: 0x12
uint8_t lsb = (temp >> 0) & 0xFF; // Shifts 0, masks bottom byte. Result: 0x34
```
*(Note: `& 0xFF` is mathematically redundant when assigning to a `uint8_t` because the truncation happens automatically, but it is considered best practice to include it for explicit clarity).*

## Solution 2: Deserialization Logic
**Answer:**
Because `byte0` is the LSB, it stays at the bottom (shift by 0). Because `byte1` is the MSB, it must be shifted up by 8 bits to form the top half of the 16-bit integer.
```cpp
uint16_t voltage = (byte1 << 8) | (byte0 << 0);
// Result: 0x05AA
```
