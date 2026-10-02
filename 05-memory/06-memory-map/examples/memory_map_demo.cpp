/**
 * @file memory_map_demo.cpp
 * @brief Simulates identifying regions based on standard ARM Memory Maps.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <iomanip>

// A helper function to identify an address region
void identify_region(uint32_t address) {
    std::cout << "Address: 0x" << std::hex << std::uppercase << std::setfill('0') << std::setw(8) << address << " -> ";
    
    // Extract the top 3 bits to identify the region
    uint32_t top_nibble = address >> 28;
    
    switch (top_nibble) {
        case 0x0: 
        case 0x1: std::cout << "CODE / FLASH (ROM)\n"; break;
        case 0x2: 
        case 0x3: std::cout << "SRAM (RAM)\n"; break;
        case 0x4: 
        case 0x5: std::cout << "PERIPHERALS (MMIO)\n"; break;
        case 0xE: 
        case 0xF: std::cout << "SYSTEM / CORTEX-M INTERNAL\n"; break;
        default:  std::cout << "EXTERNAL OR RESERVED\n"; break;
    }
}

int main() {
    std::cout << "--- ARM Cortex-M Memory Map Simulator ---\n\n";

    // 1. Where does the main() function live? (Flash)
    identify_region(0x08001234);

    // 2. Where do local variables (Stack) live? (RAM)
    identify_region(0x20004568);

    // 3. Where is the GPIO Port A control register? (Peripheral)
    identify_region(0x40020000);

    // 4. Where is the SysTick Timer (Inside the CPU core)?
    identify_region(0xE000E010);

    return 0;
}
