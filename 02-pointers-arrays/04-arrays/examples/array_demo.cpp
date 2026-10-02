/**
 * @file array_demo.cpp
 * @brief Demonstrates array initialization and contiguous memory layout.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "--- Array Memory Layout ---\n";
    
    // Auto-sized array
    uint16_t data[] = {0x1111, 0x2222, 0x3333, 0x4444};
    
    // Calculate size of array
    size_t num_elements = sizeof(data) / sizeof(data[0]);
    std::cout << "Number of elements: " << num_elements << "\n\n";

    // Print addresses to prove contiguous allocation
    for (size_t i = 0; i < num_elements; ++i) {
        std::cout << "Element " << i 
                  << " | Value: 0x" << std::hex << data[i]
                  << " | Address: " << &data[i] << "\n";
    }

    std::cout << "\nNotice that the addresses increase by exactly 2 bytes (sizeof(uint16_t)).\n";

    return 0;
}
