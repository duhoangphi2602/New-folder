# Solutions: Enum Class

## Solution 1: Implicit Conversion Trap
**Answer:** `enum class` does not implicitly convert to an integer. Array indices require an integer. To use an `enum class` as an array index, you must explicitly cast it.
```cpp
int val = readings[static_cast<int>(target)]; 
```
*(Note: While verbose, this prevents accidentally using a completely unrelated enum to index the array).*

## Solution 2: Struct Packing
**Answer:** 
First, force the `enum class` to be 1 byte using `: uint8_t`.
Second, reorder the struct so the 4-byte `payload` comes *first*. If `PacketType` (1 byte) is first, the compiler will inject 3 bytes of padding before `payload`.
```cpp
enum class PacketType : uint8_t { PING, DATA, ACK };

// Optimal layout: 4 bytes + 1 byte = 5 bytes total.
struct NetworkPacket {
    uint32_t payload;
    PacketType type; 
};
```
