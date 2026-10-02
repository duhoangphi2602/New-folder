/**
 * @file union_demo.cpp
 * @brief Demonstrates memory overlap in unions.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

struct NormalStruct {
    uint32_t a;
    uint32_t b;
};

union OverlappedUnion {
    uint32_t a;
    uint32_t b;
};

int main() {
    std::cout << "--- Union vs Struct ---\n\n";

    std::cout << "Size of NormalStruct    : " << sizeof(NormalStruct) << " bytes\n";
    std::cout << "Size of OverlappedUnion : " << sizeof(OverlappedUnion) << " bytes\n\n";

    OverlappedUnion u;
    
    // Write to member 'a'
    u.a = 0xDEADBEEF;
    std::cout << "Wrote 0xDEADBEEF to u.a\n";

    // Read from member 'b' (Type Punning / Overlap)
    // In C, this is completely legal. In strict C++, it is technically UB, 
    // but practically supported by GCC/Clang.
    std::cout << "Read from u.b           : 0x" << std::hex << u.b << "\n";

    // Notice that a and b are the EXACT SAME memory address
    if (&u.a == &u.b) {
        std::cout << "\nMemory addresses of u.a and u.b are identical!\n";
    }

    return 0;
}
