/**
 * @file semihosting_demo.cpp
 * @brief Demonstrates the initialization required for ARM Semihosting.
 * 
 * Target: ARM Cortex-M
 * Standard: C++17
 */

#include <iostream>
#include <cstdio>

// This function is provided by the rdimon library
extern "C" void initialise_monitor_handles(void);

int main() {
    // 1. MUST CALL THIS FIRST!
    // This tells the C library to route standard I/O to the debugger interface.
    // If you don't call this, printf will do nothing.
    initialise_monitor_handles();

    std::cout << "--- ARM Semihosting Demo ---\n\n";

    // 2. Standard printf now magically appears in your IDE console!
    std::printf("Hello from the Microcontroller!\n");
    std::printf("I have no UART connected, but you can still read this.\n");

    // 3. The Danger
    std::printf("WARNING: The CPU was completely halted by the debugger for ~5ms to print this.\n");
    
    // If you unplugged the debugger before powering on the board, 
    // the system would have permanently frozen at line 21.

    return 0;
}
