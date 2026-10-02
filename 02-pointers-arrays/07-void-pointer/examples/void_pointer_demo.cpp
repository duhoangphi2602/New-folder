/**
 * @file void_pointer_demo.cpp
 * @brief Demonstrates generic functions using void pointers.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <iomanip>

// A generic function that can print the hex bytes of ANY data type
void print_memory_hex(const void* mem_ptr, size_t num_bytes) {
    // We cannot dereference mem_ptr, nor can we do arithmetic on it.
    // We MUST cast it to a 1-byte pointer (uint8_t*) to parse it byte-by-byte.
    
    const uint8_t* byte_ptr = static_cast<const uint8_t*>(mem_ptr);
    
    std::cout << "Memory Dump (" << num_bytes << " bytes): ";
    for (size_t i = 0; i < num_bytes; i++) {
        // Now pointer arithmetic and dereferencing works!
        std::cout << std::hex << std::setfill('0') << std::setw(2) 
                  << (int)*(byte_ptr + i) << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "--- Generic void* Functions ---\n\n";

    uint32_t val_32 = 0xAABBCCDD;
    double   val_double = 3.14159;

    std::cout << "Dumping a uint32_t:\n";
    // Implicitly casts &val_32 to void*
    print_memory_hex(&val_32, sizeof(val_32)); 

    std::cout << "\nDumping a double:\n";
    // Implicitly casts &val_double to void*
    print_memory_hex(&val_double, sizeof(val_double));

    return 0;
}
