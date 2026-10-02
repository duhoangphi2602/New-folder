/**
 * @file io_overview_demo.cpp
 * @brief Pseudo-code demonstrating how MMIO relates to physical pins.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// Simulate a hardware register that directly controls physical pins
uint32_t SIMULATED_GPIO_PORT_A = 0;

void set_pin_high(int pin_number) {
    SIMULATED_GPIO_PORT_A |= (1 << pin_number);
    std::cout << "[Hardware] Pin A" << pin_number << " voltage is now 3.3V (HIGH)\n";
}

void set_pin_low(int pin_number) {
    SIMULATED_GPIO_PORT_A &= ~(1 << pin_number);
    std::cout << "[Hardware] Pin A" << pin_number << " voltage is now 0.0V (LOW)\n";
}

int main() {
    std::cout << "--- Embedded I/O Simulation ---\n\n";

    std::cout << "1. Simple GPIO (Blinking an LED on Pin 5):\n";
    set_pin_high(5); // LED ON
    // delay(500);
    set_pin_low(5);  // LED OFF

    std::cout << "\n2. Serial I/O Concept (Sending character 'H' = 0x48 over Pin 2):\n";
    std::cout << "Target character: 'H' (Binary: 01001000)\n";
    
    uint8_t char_H = 0x48;
    
    // To send this over a single pin (UART TX), the hardware automatically 
    // pulses the pin high/low for each bit based on a clock timer.
    for (int bit = 0; bit < 8; bit++) {
        if (char_H & (1 << bit)) {
            set_pin_high(2);
        } else {
            set_pin_low(2);
        }
        // In real hardware, a baud-rate timer controls the delay between these pulses.
    }
    
    std::cout << "\nNote: In a real MCU, you don't toggle serial pins manually (Bit-Banging).\n";
    std::cout << "You just write to a UART Data Register, and the silicon hardware toggles the pins for you!\n";

    return 0;
}
