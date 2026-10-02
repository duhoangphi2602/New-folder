/**
 * @file nvic_simulation.cpp
 * @brief Conceptually simulates the NVIC's hardware interrupt nesting behavior.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <string>

// Simulating CPU Execution Stack
int current_hardware_priority = 255; // 255 means no ISR is running (Main Thread)

// Simulate an ISR Execution
void execute_isr(const std::string& name, int priority) {
    int previous_priority = current_hardware_priority;
    current_hardware_priority = priority;
    
    std::cout << "  [" << name << " ISR] Started. (Priority: " << priority << ")\n";
    
    // Simulate a nested interrupt happening in the middle of this ISR!
    if (name == "UART") {
        std::cout << "  [" << name << " ISR] Processing data... \n";
        
        std::cout << "    >> [HARDWARE] Motor Timer Interrupt Fires! (Priority: 2) <<\n";
        if (2 < current_hardware_priority) { // Lower number is higher priority in ARM!
            std::cout << "    [NVIC] Motor Timer preempts UART!\n";
            execute_isr("Motor Timer", 2); // Nested call!
        } else {
            std::cout << "    [NVIC] Motor Timer is pending...\n";
        }
        
        std::cout << "  [" << name << " ISR] Resumed processing data...\n";
    }

    std::cout << "  [" << name << " ISR] Finished. Exiting.\n";
    current_hardware_priority = previous_priority; // Restore priority
}

int main() {
    std::cout << "--- NVIC Nested Interrupt Simulation ---\n\n";

    std::cout << "[Main Loop] Executing normal background tasks...\n";
    std::cout << "[Main Loop] Current Hardware Priority: " << current_hardware_priority << " (None)\n\n";

    std::cout << ">> [HARDWARE] UART Interrupt Fires! (Priority: 5) <<\n";
    std::cout << "[NVIC] Halting Main Loop. Jumping to UART ISR.\n";
    
    execute_isr("UART", 5);

    std::cout << "\n[Main Loop] Resumed normal background tasks.\n";

    return 0;
}
