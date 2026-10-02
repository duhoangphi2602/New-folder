/**
 * @file startup_simulation.cpp
 * @brief Simulates the logic of an MCU Reset_Handler in C++.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstring>
#include <vector>

// --- Simulated Hardware Memory ---
// Flash memory containing the initial values
std::vector<uint32_t> simulated_flash_sidata = {0xAA, 0xBB, 0xCC};

// RAM blocks
uint32_t simulated_ram_data[3]; 
uint32_t simulated_ram_bss[5];

// --- Simulated Linker Symbols ---
uint32_t* _sidata = simulated_flash_sidata.data();
uint32_t* _sdata  = simulated_ram_data;
uint32_t* _edata  = simulated_ram_data + 3;

uint32_t* _sbss   = simulated_ram_bss;
uint32_t* _ebss   = simulated_ram_bss + 5;


// --- Simulated Application ---
void main_app() {
    std::cout << "\n[App] main() executing...\n";
    std::cout << "[App] .data[0] is: 0x" << std::hex << simulated_ram_data[0] << "\n";
    std::cout << "[App] .bss[0] is: 0x" << std::hex << simulated_ram_bss[0] << "\n";
}

// --- The Startup Sequence ---
void Reset_Handler() {
    std::cout << "[Startup] CPU Reset!\n";

    // 1. Copy .data from Flash to RAM
    std::cout << "[Startup] Copying .data from Flash to RAM...\n";
    uint32_t* src = _sidata;
    uint32_t* dst = _sdata;
    while (dst < _edata) {
        *dst++ = *src++;
    }

    // 2. Zero-fill .bss in RAM
    std::cout << "[Startup] Zero-filling .bss in RAM...\n";
    // Simulate RAM having garbage data at power-on
    for(int i=0; i<5; i++) simulated_ram_bss[i] = 0xDEADBEEF; 
    
    dst = _sbss;
    while (dst < _ebss) {
        *dst++ = 0;
    }

    // 3. (Simulated) Call C++ constructors
    std::cout << "[Startup] Calling C++ global constructors...\n";

    // 4. Enter Application
    main_app();
}

int main() {
    // Kick off the simulation
    Reset_Handler();
    return 0;
}
