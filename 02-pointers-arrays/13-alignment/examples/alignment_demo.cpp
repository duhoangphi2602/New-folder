/**
 * @file alignment_demo.cpp
 * @brief Demonstrates alignof and alignas keywords.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "--- Alignment Requirements ---\n";
    
    std::cout << "alignof(uint8_t)  : " << alignof(uint8_t) << " byte\n";
    std::cout << "alignof(uint16_t) : " << alignof(uint16_t) << " bytes\n";
    std::cout << "alignof(uint32_t) : " << alignof(uint32_t) << " bytes\n";
    std::cout << "alignof(double)   : " << alignof(double) << " bytes\n";

    std::cout << "\n--- Custom Alignment ---\n";

    // Standard alignment for an array of bytes is 1
    uint8_t normal_buffer[10];
    
    // Forced alignment to 64 bytes (often used for CPU cache lines)
    alignas(64) uint8_t strict_buffer[10];

    std::cout << "Address of normal_buffer : " << static_cast<void*>(normal_buffer) << "\n";
    std::cout << "Address of strict_buffer : " << static_cast<void*>(strict_buffer) << "\n";
    
    // Verify the math
    uintptr_t addr = reinterpret_cast<uintptr_t>(strict_buffer);
    if (addr % 64 == 0) {
        std::cout << "-> strict_buffer is mathematically perfectly aligned to 64 bytes!\n";
    }

    return 0;
}
