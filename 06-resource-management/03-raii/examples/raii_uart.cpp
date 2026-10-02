/**
 * @file raii_uart.cpp
 * @brief Demonstrates using RAII to temporarily enable a hardware peripheral.
 * 
 * Target: PC (Simulated Embedded)
 * Standard: C++17
 */

#include <iostream>

// Simulated Hardware registers
void enable_uart_clock()  { std::cout << "[HARDWARE] UART Clock ENABLED\n"; }
void disable_uart_clock() { std::cout << "[HARDWARE] UART Clock DISABLED\n"; }

// The RAII Class
class UartPowerGuard {
public:
    UartPowerGuard() {
        std::cout << "  (UartPowerGuard Created)\n";
        enable_uart_clock();
    }
    ~UartPowerGuard() {
        std::cout << "  (UartPowerGuard Destroyed)\n";
        disable_uart_clock();
    }
    
    // Prevent copying
    UartPowerGuard(const UartPowerGuard&) = delete;
    UartPowerGuard& operator=(const UartPowerGuard&) = delete;
};

void transmit_data(bool trigger_error) {
    std::cout << "Entering transmit function...\n";
    
    // 1. Acquire Resource. Clock turns on automatically!
    UartPowerGuard power_manager; 

    if (trigger_error) {
        std::cout << "  [!] Hardware Error! Bailing out early...\n";
        // 2. C++ automatically calls Destructor right here! Clock turns off!
        return; 
    }

    std::cout << "  Transmitting 1024 bytes...\n";
    // 3. C++ automatically calls Destructor right here! Clock turns off!
}

int main() {
    std::cout << "--- RAII UART Power Manager ---\n\n";

    std::cout << "TEST 1: Normal Execution\n";
    transmit_data(false);
    
    std::cout << "\nTEST 2: Early Error Return\n";
    transmit_data(true);

    return 0;
}
