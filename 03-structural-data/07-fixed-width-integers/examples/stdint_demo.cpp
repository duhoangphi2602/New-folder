/**
 * @file stdint_demo.cpp
 * @brief Demonstrates exactly why fixed-width integers are strictly required.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "--- Native Types vs Fixed-Width Types ---\n\n";

    std::cout << "1. Native Types (Unpredictable across CPUs):\n";
    std::cout << "   sizeof(int)   = " << sizeof(int) << " bytes\n";
    std::cout << "   sizeof(long)  = " << sizeof(long) << " bytes (Can be 4 or 8!)\n";

    std::cout << "\n2. Fixed-Width Types (Guaranteed everywhere):\n";
    std::cout << "   sizeof(uint8_t)  = " << sizeof(uint8_t)  << " byte\n";
    std::cout << "   sizeof(uint16_t) = " << sizeof(uint16_t) << " bytes\n";
    std::cout << "   sizeof(uint32_t) = " << sizeof(uint32_t) << " bytes\n";
    std::cout << "   sizeof(uint64_t) = " << sizeof(uint64_t) << " bytes\n";

    return 0;
}
