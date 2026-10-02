# Solutions: Struct Memory Layout

## Solution 1: Address Calculation
**Answer:** 
Because the members are `uint8_t` (1 byte each), and they are guaranteed to be placed sequentially without padding (since 1-byte variables align anywhere):
1. `pixel.red`: `0x20001000` (The first member always shares the base address of the struct).
2. `pixel.green`: `0x20001001`
3. `pixel.blue`: `0x20001002`

## Solution 2: C++ `offsetof` Macro
**Answer:** The standard macro is `offsetof()`. It is incredibly useful in embedded programming to verify that a hardware struct map perfectly matches the silicon datasheet offsets.
```cpp
#include <iostream>
#include <cstddef>

struct RgbColor {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
};

int main() {
    std::cout << "Offset of blue: " << offsetof(RgbColor, blue) << "\n"; 
    // Outputs: 2
}
```
