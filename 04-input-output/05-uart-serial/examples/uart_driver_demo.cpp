/**
 * @file uart_driver_demo.cpp
 * @brief Simulates a bare-metal blocking UART string transmission.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <string_view>
#include <thread>
#include <chrono>

// --- Simulated Hardware Registers ---
bool hardware_ready_flag = true; 

// Simulated hardware TX register
void hardware_write_dr(char c) {
    // In reality, this shifts the bit out of a physical pin.
    // We will just print it to the PC screen to simulate it arriving at the terminal.
    std::cout << c << std::flush;
    
    // Simulate the time it takes to send 1 byte over a slow 9600 baud connection (approx 1ms)
    hardware_ready_flag = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    hardware_ready_flag = true;
}

// --- The Bare-Metal Driver ---

void uart_send_char(char c) {
    // Polling Loop: Wait for the hardware to finish the previous byte
    while (!hardware_ready_flag) {
        // CPU is blocked here!
    }
    
    // Write to the Data Register
    hardware_write_dr(c);
}

void uart_send_string(std::string_view str) {
    for (char c : str) {
        uart_send_char(c);
    }
}

int main() {
    std::cout << "--- UART Driver Simulation ---\n\n";

    std::cout << "Sending a string via Simulated Polling UART:\n";
    std::cout << ">> ";
    
    uart_send_string("Hello Embedded World!\n");

    std::cout << "\nNotice the slight delay? At 9600 baud, the CPU spends 99% of its time trapped in the while() loop waiting for the hardware to catch up.\n";

    return 0;
}
