# Interview Questions: Endianness

## 1. What is the difference between Big Endian and Little Endian?
**Answer:** They define the order in which multi-byte data types (like 32-bit integers) are stored in memory. Big Endian stores the Most Significant Byte (MSB) at the lowest memory address (reading left to right). Little Endian stores the Least Significant Byte (LSB) at the lowest memory address (reading right to left). 

## 2. If almost all modern processors (x86, ARM Cortex-M) are Little Endian, why do we still care about Big Endian?
**Answer:** Because the entire internet is Big Endian. The TCP/IP standard explicitly defines "Network Byte Order" as Big Endian. If an IoT device sends an IP packet header or multi-byte payload, it must swap its internal Little Endian representation to Big Endian before pushing it over the network, otherwise the receiving server will misinterpret the numbers.

## 3. How do you write a C function to detect whether the CPU is Little or Big Endian at runtime?
**Answer:** You can use a `union` to overlay a 32-bit integer and a byte array.
```c
int is_little_endian() {
    union { uint32_t i; uint8_t c[4]; } test = {0x01020304};
    return test.c[0] == 0x04; // If the smallest byte is at index 0, it's Little Endian.
}
```
*(Alternatively, you can cast a pointer: `uint32_t i = 1; return *(uint8_t*)&i == 1;`)*
