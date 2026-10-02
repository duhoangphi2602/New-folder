/**
 * @file alignment_demo.cpp
 * @brief Demonstrates the 'alignof' operator and address alignment.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// A struct combining different types
struct MixedData {
    char a;      // 1 byte
    uint32_t b;  // 4 bytes
    double c;    // 8 bytes
};

int main() {
    std::cout << "--- Memory Alignment (Natural Alignment) ---\n\n";

    std::cout << "Required Alignment for char     : " << alignof(char) << " byte\n";
    std::cout << "Required Alignment for uint32_t : " << alignof(uint32_t) << " bytes\n";
    std::cout << "Required Alignment for double   : " << alignof(double) << " bytes\n";
    std::cout << "Required Alignment for struct   : " << alignof(MixedData) << " bytes\n\n";

    // Let's prove the compiler follows these rules:
    MixedData data;
    
    // Cast pointers to integers so we can do modulo math on the addresses
    uintptr_t addr_a = reinterpret_cast<uintptr_t>(&data.a);
    uintptr_t addr_b = reinterpret_cast<uintptr_t>(&data.b);
    uintptr_t addr_c = reinterpret_cast<uintptr_t>(&data.c);

    std::cout << "Address of a (char)    : 0x" << std::hex << addr_a << "\n";
    std::cout << "Address of b (uint32_t): 0x" << std::hex << addr_b << " (Divisible by 4? " << (addr_b % 4 == 0 ? "YES" : "NO") << ")\n";
    std::cout << "Address of c (double)  : 0x" << std::hex << addr_c << " (Divisible by 8? " << (addr_c % 8 == 0 ? "YES" : "NO") << ")\n";

    return 0;
}
