/**
 * @file padding_demo.cpp
 * @brief Demonstrates how compiler padding wastes memory and how to pack it.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <cstddef>

// Default struct with invisible padding
struct Unpacked {
    uint8_t  id;    // 1 byte
    uint32_t value; // 4 bytes
    uint8_t  flag;  // 1 byte
};

// Reordered struct to minimize padding
struct Reordered {
    uint32_t value; // 4 bytes
    uint8_t  id;    // 1 byte
    uint8_t  flag;  // 1 byte
};

// Packed struct (No padding allowed)
struct __attribute__((packed)) Packed {
    uint8_t  id;    // 1 byte
    uint32_t value; // 4 bytes
    uint8_t  flag;  // 1 byte
};

int main() {
    std::cout << "--- Struct Padding & Alignment ---\n\n";

    std::cout << "Size of Unpacked  : " << sizeof(Unpacked) << " bytes\n";
    std::cout << " -> Offset of value : " << offsetof(Unpacked, value) << " (3 bytes of padding!)\n\n";

    std::cout << "Size of Reordered : " << sizeof(Reordered) << " bytes\n";
    std::cout << " -> Notice how reordering saved 4 bytes of RAM per struct!\n\n";

    std::cout << "Size of Packed    : " << sizeof(Packed) << " bytes\n";
    std::cout << " -> Exact size. Perfect for network transmission.\n";
    std::cout << " -> Offset of value : " << offsetof(Packed, value) << " (Unaligned memory access!)\n";

    return 0;
}
