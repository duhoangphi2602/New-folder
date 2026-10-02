/**
 * @file padding_demo.cpp
 * @brief Demonstrates how struct member ordering affects total size.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

struct Unoptimized {
    uint8_t a;  // 1 byte
    double b;   // 8 bytes
    uint32_t c; // 4 bytes
};

struct Optimized {
    double b;   // 8 bytes
    uint32_t c; // 4 bytes
    uint8_t a;  // 1 byte
};

struct __attribute__((packed)) Packed {
    uint8_t a;  // 1 byte
    double b;   // 8 bytes
    uint32_t c; // 4 bytes
};

int main() {
    std::cout << "--- Memory Padding & Struct Optimization ---\n\n";

    std::cout << "Sum of raw variables: 1 + 8 + 4 = 13 bytes.\n\n";

    std::cout << "Size of Unoptimized : " << sizeof(Unoptimized) << " bytes\n";
    std::cout << "Size of Optimized   : " << sizeof(Optimized) << " bytes\n";
    std::cout << "Size of Packed      : " << sizeof(Packed) << " bytes\n\n";

    // Why is Unoptimized 24 bytes?
    // a (1) + padding (7) = 8
    // b (8) = 8
    // c (4) + trailing padding (4) = 8
    // Total = 24.
    
    // Why is Optimized 16 bytes?
    // b (8) = 8
    // c (4) + a (1) + trailing padding (3) = 8
    // Total = 16.

    return 0;
}
