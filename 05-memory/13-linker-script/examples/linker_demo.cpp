/**
 * @file linker_demo.cpp
 * @brief Demonstrates how C++ code interacts with Linker Script symbols.
 * 
 * Target: ARM Cortex-M
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// These variables are NOT defined in C++. 
// They are defined in the .ld Linker Script!
// We use 'extern' to tell the C++ compiler: "Trust me, the Linker will provide these later."
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

int main() {
    std::cout << "--- Linker Script Symbol Demo ---\n\n";

    // We don't care about the *value* of the variables.
    // We only care about their memory ADDRESSES, because the Linker 
    // assigned their addresses based on the memory map!
    
    uintptr_t data_start = reinterpret_cast<uintptr_t>(&_sdata);
    uintptr_t data_end   = reinterpret_cast<uintptr_t>(&_edata);
    uintptr_t bss_start  = reinterpret_cast<uintptr_t>(&_sbss);
    uintptr_t bss_end    = reinterpret_cast<uintptr_t>(&_ebss);

    // In a real embedded system, this would print something like:
    // .data starts at 0x20000000 and ends at 0x20000400 (Size: 1024 bytes)
    // .bss starts at 0x20000400 and ends at 0x20001400 (Size: 4096 bytes)
    
    /*
    std::cout << ".data Start: 0x" << std::hex << data_start << "\n";
    std::cout << ".data End  : 0x" << std::hex << data_end << "\n";
    std::cout << ".data Size : " << std::dec << (data_end - data_start) << " bytes\n\n";
    */

    std::cout << "By accessing these symbols, the Startup Code can write loops\n";
    std::cout << "to initialize RAM dynamically, regardless of how much code\n";
    std::cout << "the developer actually wrote!\n";

    return 0;
}
