# Exercises: Enum Class

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Implicit Conversion Trap
A developer wants to use an enum to index into an array:
```cpp
enum class SensorPort { TEMP, HUMIDITY, PRESSURE };

int readings[3] = {25, 60, 1000};
SensorPort target = SensorPort::HUMIDITY;

// int val = readings[target]; // This line fails to compile!
```
**Task:** Why does `readings[target]` fail to compile in C++11, even though it works perfectly fine with a C-style enum? How do you fix it?

## Exercise 2: Struct Packing
You are designing a network packet that must be exactly 5 bytes long.
```cpp
enum class PacketType { PING, DATA, ACK };

struct NetworkPacket {
    PacketType type;
    uint32_t payload;
};
```
**Task:** Without using `__attribute__((packed))`, rewrite the `PacketType` definition so that `sizeof(NetworkPacket)` is exactly 5 bytes without any padding. *(Assume natural alignment for `uint32_t` is 4).*
Wait, look at the struct closely. If `PacketType` is 1 byte, where will `payload` be placed?
*(Actually, just fix `PacketType` to be 1 byte, and realize you might have to swap the struct member order to avoid internal padding!).* Write the fully optimized solution.
