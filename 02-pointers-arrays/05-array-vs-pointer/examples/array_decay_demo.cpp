/**
 * @file array_decay_demo.cpp
 * @brief Demonstrates the sizeof trap caused by array decay.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// Notice that we explicitly ask for an array of size 10 in the signature.
// The compiler ignores the '10' completely. It decays to 'uint32_t* buffer'
void process_buffer(uint32_t buffer[10]) {
    std::cout << "[Inside function]\n";
    std::cout << "  Size of 'buffer' argument: " << sizeof(buffer) << " bytes\n";
    
    // This will calculate incorrectly!
    size_t length = sizeof(buffer) / sizeof(buffer[0]);
    std::cout << "  Calculated length: " << length << " elements (WRONG!)\n";
}

int main() {
    std::cout << "--- The Array Decay Trap ---\n\n";

    uint32_t data[10] = {0};

    std::cout << "[Inside main]\n";
    std::cout << "  Size of 'data' array: " << sizeof(data) << " bytes\n";
    
    size_t length = sizeof(data) / sizeof(data[0]);
    std::cout << "  Calculated length: " << length << " elements (CORRECT!)\n\n";

    // Pass the array to the function (triggers decay)
    process_buffer(data);

    return 0;
}
