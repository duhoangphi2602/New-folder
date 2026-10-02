/**
 * @file vector_demo.cpp
 * @brief Simulates how CPU hardware uses the Vector Table to jump to ISRs.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// --- The Handlers ---
void Reset_Handler() {
    std::cout << "[EXECUTING] Reset_Handler: System is booting up!\n";
}

void HardFault_Handler() {
    std::cout << "[EXECUTING] HardFault_Handler: The system has crashed!\n";
    // while(1);
}

void UART_IRQHandler() {
    std::cout << "[EXECUTING] UART_IRQHandler: Received data over serial.\n";
}

void Default_Handler() {
    std::cout << "[EXECUTING] Default_Handler: Unhandled interrupt caught.\n";
}

// --- The Vector Table ---
// In a real system, this sits exactly at memory address 0x00000000
using ISR_Pointer = void (*)();

ISR_Pointer vector_table[] = {
    (ISR_Pointer)0x20005000, // Index 0: Initial Stack Pointer (Not a function!)
    Reset_Handler,           // Index 1: Reset 
    Default_Handler,         // Index 2: NMI
    HardFault_Handler,       // Index 3: Hard Fault
    Default_Handler,         // Index 4: MemManage
    Default_Handler,         // Index 5: BusFault
    Default_Handler,         // Index 6: UsageFault
    UART_IRQHandler          // Index 7: Custom UART Interrupt (Simplified)
};

// --- CPU Hardware Simulator ---
void simulate_hardware_interrupt(int irq_number) {
    std::cout << "\n[HARDWARE] Interrupt " << irq_number << " fired!\n";
    
    // The CPU uses the IRQ number as an array index!
    ISR_Pointer target_function = vector_table[irq_number];
    
    // Jump to the function
    target_function();
}

int main() {
    std::cout << "--- Vector Table CPU Simulation ---\n";

    // Power applied. Hardware always fires IRQ 1.
    simulate_hardware_interrupt(1);

    // Some time later, a UART packet arrives
    simulate_hardware_interrupt(7);

    // The code tries to divide by zero! Hardware fires IRQ 3.
    simulate_hardware_interrupt(3);

    return 0;
}
