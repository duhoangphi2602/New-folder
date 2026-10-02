/**
 * @file address_demo.cpp
 * @brief Demonstrates viewing the memory addresses of different variables.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    uint8_t  var_8bit  = 0xAA;
    uint32_t var_32bit = 0xAABBCCDD;

    // We must cast the uint8_t address to a void* so cout prints the 
    // address instead of trying to print it as a char/string.
    std::cout << "Address of 8-bit var:  " << (void*)&var_8bit << "\n";
    std::cout << "Address of 32-bit var: " << &var_32bit << "\n";

    // Let's prove that the 32-bit variable takes 4 bytes.
    // We will cast its address to a 1-byte pointer and inspect each byte.
    uint8_t* byte_ptr = (uint8_t*)&var_32bit;
    
    std::cout << "\nInspecting the 4 bytes of var_32bit:\n";
    for(int i = 0; i < 4; i++) {
        std::cout << "Byte " << i << " at address " << (void*)(byte_ptr + i) 
                  << " contains: 0x" << std::hex << (int)*(byte_ptr + i) << "\n";
    }

    return 0;
}
