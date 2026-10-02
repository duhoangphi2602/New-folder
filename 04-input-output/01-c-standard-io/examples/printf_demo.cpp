/**
 * @file printf_demo.cpp
 * @brief Demonstrates C-style formatted output.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdio>
#include <cstdint>

int main() {
    std::cout << "--- C Standard I/O (printf) ---\n\n";

    int temp = 25;
    uint32_t memory_addr = 0x200055AA;
    float battery = 4.21f;

    // 1. Basic formatting
    std::printf("Temperature: %d C\n", temp);

    // 2. Hexadecimal formatting (crucial for embedded)
    std::printf("Base Address (Lower): %x\n", memory_addr);
    std::printf("Base Address (Upper): %X\n", memory_addr);
    
    // The Professional Embedded Way: Prepend 0x and pad to 8 zeroes
    std::printf("Hardware Register   : 0x%08X\n", memory_addr);

    // 3. Float precision
    std::printf("Battery Voltage     : %.2f V\n", battery);

    // 4. The Embedded Float Hack (If %f is disabled to save ROM)
    int whole = (int)battery;
    int decimal = (int)(battery * 100) % 100;
    std::printf("Battery (No Float)  : %d.%02d V\n", whole, decimal);

    return 0;
}
