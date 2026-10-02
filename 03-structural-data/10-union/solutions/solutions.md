# Solutions: Union

## Solution 1: Memory Footprint
**Answer:** The size is **16 bytes**.
**Why:** A union's size is determined by its *largest* single member. 
- `small_flag` is 1 byte.
- `precise_value` is 8 bytes.
- `id_array` is an array of four 4-byte integers, totaling 16 bytes.
Therefore, the compiler allocates exactly 16 bytes. All three variables start at offset 0 and overlap inside those 16 bytes.

## Solution 2: The Modern C++ Way
**Answer:** You should use `std::memcpy`.
```cpp
#include <cstring>
#include <cstdint>

uint32_t raw_data = 0x41C80000;
float result;

// Copies the raw binary bits directly into the float variable
std::memcpy(&result, &raw_data, sizeof(float));
```
*(Note: Do not worry about performance. The C++ compiler completely optimizes `std::memcpy` away, emitting the exact same instantaneous register-transfer assembly instructions as the union approach, but without the Undefined Behavior risks).*
