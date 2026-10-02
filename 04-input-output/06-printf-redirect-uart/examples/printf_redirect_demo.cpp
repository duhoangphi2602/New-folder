/**
 * @file printf_redirect_demo.cpp
 * @brief Simulates overriding a C library syscall to redirect output.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdio>
#include <string>

// 1. Simulate the hardware UART driver
void my_hardware_uart_transmit(char c) {
    // In reality, this writes to a hardware register.
    // For this simulation, we use std::cout to prove we intercepted the data.
    std::cout << "[UART TX] " << c << "\n";
}

// 2. Simulate the GCC Newlib _write syscall
// Note: On a real PC, overriding _write will conflict with the OS.
// We use a custom named function here to simulate the embedded behavior.
int simulated_write(const char *ptr, int len) {
    int characters_sent = 0;
    
    for (int i = 0; i < len; i++) {
        // Catch newlines and inject Carriage Returns for Serial Terminals
        if (ptr[i] == '\n') {
            my_hardware_uart_transmit('\r');
        }
        
        my_hardware_uart_transmit(ptr[i]);
        characters_sent++;
    }
    
    return characters_sent;
}

// 3. Simulate the internals of printf
void simulated_printf(const std::string& formatted_string) {
    // printf does the heavy formatting, then hands the raw buffer to _write
    simulated_write(formatted_string.c_str(), formatted_string.length());
}

int main() {
    std::cout << "--- Printf UART Redirection Simulation ---\n\n";

    // When the user calls printf...
    simulated_printf("Hello\n");

    // The output will show that 'Hello' was broken down character by character
    // and routed to our custom hardware driver, with a '\r' injected before the '\n'.

    return 0;
}
