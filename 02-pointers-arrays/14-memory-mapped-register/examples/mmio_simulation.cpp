/**
 * @file mmio_simulation.cpp
 * @brief Simulates Memory-Mapped I/O on a PC.
 * 
 * Target: PC Simulation
 * Standard: C++17
 * 
 * How to compile & run:
 * g++ -std=c++17 mmio_simulation.cpp -o mmio_sim
 * ./mmio_sim
 */

#include <iostream>
#include <cstdint>
#include <iomanip>

// --- HARDWARE SIMULATION ---
// On a real MCU, this memory physically exists at a fixed address (e.g., 0x40020014).
// On a PC, we simulate it by allocating an integer on the heap/stack.
std::uint32_t simulated_hardware_register = 0x00000000;

// --- FIRMWARE CODE ---

// 1. We get the memory address of our simulated hardware
// (In firmware, this would be a hardcoded hex value from the datasheet)
const std::uintptr_t HARDWARE_ADDR = reinterpret_cast<std::uintptr_t>(&simulated_hardware_register);

// 2. We define our Memory-Mapped Pointer
// - `volatile`: The hardware can change this value without the CPU knowing.
// - `* const`: The pointer itself cannot be repointed to another address.
auto* const GPIO_OUTPUT_REG = reinterpret_cast<volatile std::uint32_t*>(HARDWARE_ADDR);

void toggle_pin(int pin_number) {
    // Read-Modify-Write using the pointer
    *GPIO_OUTPUT_REG = (*GPIO_OUTPUT_REG) ^ (1 << pin_number);
}

void print_register() {
    std::cout << "Register State: 0x" 
              << std::hex << std::setw(8) << std::setfill('0') 
              << simulated_hardware_register << '\n';
}

int main() {
    std::cout << "Initial state:\n";
    print_register();

    std::cout << "\nToggling Pin 5 (turning LED ON)...\n";
    toggle_pin(5);
    print_register(); // Should be 0x00000020

    std::cout << "\nToggling Pin 5 (turning LED OFF)...\n";
    toggle_pin(5);
    print_register(); // Should be 0x00000000

    std::cout << "\nSetting Pin 13...\n";
    *GPIO_OUTPUT_REG |= (1 << 13);
    print_register(); // Should be 0x00002000

    return 0;
}
