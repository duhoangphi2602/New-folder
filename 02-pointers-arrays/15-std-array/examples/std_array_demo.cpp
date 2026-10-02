/**
 * @file std_array_demo.cpp
 * @brief Demonstrates passing std::array without decay.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <array>
#include <cstdint>

// 1. C-Style (Dangerous: Array decayed to pointer)
void process_c_style(uint8_t* buf) {
    // We have no idea how big buf is!
    std::cout << "[C-Style] Received pointer of size: " << sizeof(buf) << " bytes (decayed)\n";
}

// 2. C++ Style (Safe: Pass by const reference)
// The size (5) is enforced at compile time.
void process_cpp_style(const std::array<uint8_t, 5>& buf) {
    std::cout << "[C++-Style] Received array of size: " << buf.size() << " elements\n";
    
    // We can safely iterate using range-based for
    std::cout << "Data: ";
    for (uint8_t val : buf) {
        std::cout << (int)val << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "--- std::array vs C-array ---\n\n";

    uint8_t c_array[5] = {10, 20, 30, 40, 50};
    std::array<uint8_t, 5> cpp_array = {10, 20, 30, 40, 50};

    process_c_style(c_array);
    process_cpp_style(cpp_array);

    return 0;
}
