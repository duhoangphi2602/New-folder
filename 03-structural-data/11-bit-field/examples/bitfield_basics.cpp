/**
 * @file bitfield_basics.cpp
 * @brief Demonstrates bit-field syntax and memory size.
 * 
 * Target: PC
 * Standard: C++17
 * 
 * How to compile & run:
 * g++ -std=c++17 bitfield_basics.cpp -o bitfield
 * ./bitfield
 */

#include <iostream>
#include <cstdint>

// A struct using standard types
struct NormalStruct {
    bool flag1;         // 1 byte
    bool flag2;         // 1 byte
    std::uint8_t mode;  // 1 byte
}; // Size: 3 bytes (or 4 with padding)

// A struct using bit-fields
struct PackedStruct {
    std::uint8_t flag1 : 1; // 1 bit
    std::uint8_t flag2 : 1; // 1 bit
    std::uint8_t mode  : 3; // 3 bits
                            // Total: 5 bits (fits in 1 byte)
};

int main() {
    std::cout << "Size of NormalStruct: " << sizeof(NormalStruct) << " bytes\n";
    std::cout << "Size of PackedStruct: " << sizeof(PackedStruct) << " bytes\n";

    PackedStruct data = {0};
    
    // Assigning values
    data.flag1 = 1;
    data.mode = 5;

    // Warning: Assigning a value too large for the bit-field causes truncation!
    // mode is 3 bits (max value 7).
    data.mode = 8; // Binary 1000. Truncated to 000 (0).
    
    std::cout << "Mode after assigning 8 to a 3-bit field: " << (int)data.mode << "\n";

    return 0;
}
