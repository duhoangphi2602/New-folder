/**
 * @file pointer_arithmetic_demo.cpp
 * @brief Demonstrates the scaling rule of pointer arithmetic.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "--- Pointer Arithmetic Scaling ---\n";
    
    uint16_t data16[3] = {100, 200, 300};
    uint16_t* p16 = data16;

    std::cout << "Base address (p16)   : " << p16 << " -> Value: " << *p16 << "\n";
    p16++; // Scales by sizeof(uint16_t) = 2 bytes
    std::cout << "After p16++          : " << p16 << " -> Value: " << *p16 << "\n";

    uint32_t data32[3] = {400, 500, 600};
    uint32_t* p32 = data32;

    std::cout << "\nBase address (p32)   : " << p32 << " -> Value: " << *p32 << "\n";
    p32++; // Scales by sizeof(uint32_t) = 4 bytes
    std::cout << "After p32++          : " << p32 << " -> Value: " << *p32 << "\n";

    std::cout << "\n--- Pointer Subtraction ---\n";
    uint32_t* start = &data32[0];
    uint32_t* end   = &data32[2];

    // Subtraction yields the number of elements (ptrdiff_t), not the number of bytes!
    std::ptrdiff_t distance = end - start;
    
    std::cout << "Start address        : " << start << "\n";
    std::cout << "End address          : " << end << "\n";
    std::cout << "Distance (end - start): " << distance << " elements\n";

    return 0;
}
