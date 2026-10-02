/**
 * @file memory_safety_demo.cpp
 * @brief Demonstrates C++17 defensive paradigms vs C-style risks.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <array>
#include <cstdint>
#include <stdexcept>

// C-style processing (Unsafe)
void process_c_style(uint32_t* buffer, size_t length) {
    // If the caller passes the wrong length, we will overflow!
    for(size_t i = 0; i < length; i++) {
        buffer[i] = 0xFF; 
    }
}

// C++-style processing (Safe)
template <size_t N>
void process_cpp_style(std::array<uint32_t, N>& buffer) {
    // We physically cannot loop out of bounds because N is known
    for(size_t i = 0; i < buffer.size(); i++) {
        buffer[i] = 0xFF; 
    }
}

int main() {
    std::cout << "--- Memory Safety: Arrays ---\n\n";

    // 1. Universal Initialization
    int* safe_ptr{}; // Safely initialized to nullptr
    if (safe_ptr == nullptr) {
        std::cout << "safe_ptr was initialized securely to nullptr.\n";
    }

    // 2. Buffer bounds checking
    std::array<uint32_t, 3> my_data{}; // Zero initialized
    
    std::cout << "\nAttempting out-of-bounds access using .at():\n";
    try {
        // This will safely throw an exception, preventing memory corruption
        my_data.at(5) = 100; 
    } catch (const std::out_of_range& e) {
        std::cout << "Caught Exception: " << e.what() << "\n";
        std::cout << "-> C++ std::array prevented a buffer overflow!\n";
    }

    // 3. Passing to functions
    uint32_t raw_array[3] = {0,0,0};
    
    // Dangerous: Passing mismatched length
    // process_c_style(raw_array, 100); // This WILL corrupt memory!

    // Safe: Length is automatically deduced
    process_cpp_style(my_data); 

    return 0;
}
