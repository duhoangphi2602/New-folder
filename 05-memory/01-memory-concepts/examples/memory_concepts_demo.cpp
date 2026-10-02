/**
 * @file memory_concepts_demo.cpp
 * @brief Demonstrates how 'const' affects memory addresses (simulated).
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// 1. Normal variable (RAM)
int ram_variable = 42;

// 2. Const variable (ROM/Flash in Embedded, Read-Only Data segment in PC)
const int rom_variable = 99;

int main() {
    std::cout << "--- RAM vs ROM (Simulated Memory Map) ---\n\n";

    // Print the addresses of the two variables
    std::cout << "Address of ram_variable : " << &ram_variable << "\n";
    std::cout << "Address of rom_variable : " << &rom_variable << "\n\n";

    // Notice that the addresses are drastically different!
    // On a PC, the OS separates writable data (RAM) from read-only data.
    // On an STM32 microcontroller:
    // - ram_variable would be at ~0x20000000 (SRAM Base Address)
    // - rom_variable would be at ~0x08000000 (Flash Base Address)

    // ram_variable = 43; // Legal. It's in RAM.
    // rom_variable = 100; // ILLEGAL. Compiler error. It's in ROM!

    return 0;
}
