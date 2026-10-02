/**
 * @file startup_demo.cpp
 * @brief Simulates the logic of a bare-metal Startup File (Reset_Handler).
 * 
 * Target: ARM Cortex-M (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <vector>

// --- Simulated Linker Symbols ---
// In a real system, these addresses are provided by the linker script.
uint8_t simulated_flash[1024];
uint8_t simulated_ram[1024];

uint32_t _sidata = 0;   // Start of .data in Flash
uint32_t _sdata  = 0;   // Start of .data in RAM
uint32_t _edata  = 100; // End of .data in RAM

uint32_t _sbss = 100;   // Start of .bss in RAM
uint32_t _ebss = 200;   // End of .bss in RAM

// --- Simulated User Code ---
int main_function() {
    std::cout << "[MAIN] The C/C++ environment is fully initialized!\n";
    return 0;
}

// --- The Startup Code (Reset Handler) ---
void Reset_Handler() {
    std::cout << "[STARTUP] CPU Booting. Executing Reset_Handler...\n";

    // 1. Copy .data from Flash to RAM
    std::cout << "[STARTUP] Copying .data segment from Flash to RAM...\n";
    uint32_t data_size = _edata - _sdata;
    for (uint32_t i = 0; i < data_size; i++) {
        simulated_ram[_sdata + i] = simulated_flash[_sidata + i];
    }

    // 2. Zero out the .bss segment in RAM
    std::cout << "[STARTUP] Zeroing out .bss segment in RAM...\n";
    uint32_t bss_size = _ebss - _sbss;
    for (uint32_t i = 0; i < bss_size; i++) {
        simulated_ram[_sbss + i] = 0;
    }

    // 3. Call C++ Global Constructors (Skipped in this C-simulation)
    std::cout << "[STARTUP] (Skipping C++ __libc_init_array)...\n";

    // 4. Jump to main()
    std::cout << "[STARTUP] Branching to main()...\n\n";
    main_function();
}

int main() {
    // Simulate the hardware triggering the Reset Handler on power-up
    Reset_Handler();
    return 0;
}
