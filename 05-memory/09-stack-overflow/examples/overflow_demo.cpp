/**
 * @file overflow_demo.cpp
 * @brief Simulates how a Stack Overflow corrupts Global Memory.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <cstring>

// 1. Simulate the Microcontroller's 10KB RAM Memory Map
uint8_t simulated_ram[10000];

// The "Global Variable" is located at the bottom of RAM (Index 100)
uint32_t* global_system_state = (uint32_t*)&simulated_ram[100];

// The "Stack Pointer" starts at the top of RAM (Index 10000)
int simulated_stack_pointer = 10000;

void bad_function() {
    std::cout << "[Function] Allocating 9500 bytes on the Stack...\n";
    
    // Simulate the Stack Pointer moving down
    simulated_stack_pointer -= 9500;
    
    // We are now at index 500. It's close to the globals (Index 100), but safe.
    
    // Uh oh, the developer needs a temporary buffer inside this function!
    std::cout << "[Function] Allocating another 500 bytes on the Stack...\n";
    simulated_stack_pointer -= 500;
    
    // We are now at index 0. The Stack Pointer has overlapped the globals!
    
    // When the function writes to its local buffer, it destroys the global state.
    uint32_t* local_buffer = (uint32_t*)&simulated_ram[simulated_stack_pointer];
    *local_buffer = 0xFFFFFFFF; // Corrupt!
}

int main() {
    std::cout << "--- Stack Overflow Simulation ---\n\n";

    // Set the global state to a healthy value (1 = OK)
    *global_system_state = 1;
    std::cout << "Before Call: System State = " << *global_system_state << "\n";

    bad_function();

    // The system doesn't know it crashed. It reads the corrupted global variable.
    std::cout << "After Call : System State = " << *global_system_state << "\n\n";
    
    if (*global_system_state != 1) {
        std::cout << "FATAL: The global system state was silently destroyed by a Stack Overflow!\n";
    }

    return 0;
}
