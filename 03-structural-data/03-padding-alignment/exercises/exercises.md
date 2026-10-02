# Exercises: Struct Padding and Alignment

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Calculate the Size
Without writing any code, calculate the `sizeof` the following struct on a standard 32-bit architecture. Draw a memory map showing where the padding bytes are injected.
```cpp
struct NetworkHeader {
    uint16_t port;
    uint32_t ip_address;
    uint8_t  protocol;
};
```

## Exercise 2: End Padding
Calculate the `sizeof` this struct:
```cpp
struct DataPoint {
    uint32_t timestamp;
    uint16_t value;
};
```
Why isn't it 6 bytes? What would happen if you created an array `DataPoint buffer[2];` if the size was exactly 6 bytes?
