/**
 * @file endian_demo.cpp
 * @brief Demonstrates how to detect Endianness using Type Punning.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <cstring>

// The classic C-way to check endianness using a union
bool is_little_endian() {
    union {
        uint32_t value;
        uint8_t bytes[4];
    } test;

    test.value = 0x00000001;
    // If the 1 was stored in the very first byte (lowest address), 
    // it is Little Endian.
    return test.bytes[0] == 1;
}

int main() {
    std::cout << "--- Endianness Detection ---\n\n";

    if (is_little_endian()) {
        std::cout << "System Architecture: LITTLE ENDIAN\n";
    } else {
        std::cout << "System Architecture: BIG ENDIAN\n";
    }

    std::cout << "\nMemory Layout of 0x1A2B3C4D:\n";
    
    uint32_t data = 0x1A2B3C4D;
    uint8_t raw_memory[4];
    
    // Safely copy the integer into a byte array
    std::memcpy(raw_memory, &data, 4);

    for (int i = 0; i < 4; i++) {
        std::cout << "Address Offset +" << i << ": 0x" << std::hex << (int)raw_memory[i] << "\n";
    }
    
    // On a PC, you will see output 0x4D, 0x3C, 0x2B, 0x1A (Backwards!)

    return 0;
}
