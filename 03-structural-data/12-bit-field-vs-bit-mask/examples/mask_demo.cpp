/**
 * @file mask_demo.cpp
 * @brief Demonstrates manual multi-bit masking vs Bit-Fields.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <bitset>

int main() {
    std::cout << "--- Bit-Masking ---\n\n";

    // Simulate an 8-bit hardware register (all 0s)
    uint8_t hardware_register = 0b00000000;
    
    // We want to set bits 2, 3, and 4 to the value 5 (binary 101)
    uint8_t value = 5; 
    
    // Step 1: The Mask (111 in binary is 7)
    uint8_t mask = (7 << 2); // 0b00011100
    
    // Step 2: Clear the target bits
    hardware_register &= ~mask; 
    
    // Step 3: Insert the new value
    hardware_register |= (value << 2);
    
    // Print the result using std::bitset to see the binary!
    std::cout << "Resulting Register: " << std::bitset<8>(hardware_register) << "\n";
    // Expected output: 00010100

    return 0;
}
