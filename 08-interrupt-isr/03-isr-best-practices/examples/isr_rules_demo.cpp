/**
 * @file isr_rules_demo.cpp
 * @brief Demonstrates the catastrophic failure caused by breaking ISR rules.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

// Mock Hardware Registers
bool uart_data_ready_flag = false;

// ---------------------------------------------------------
// BAD ISR: Too long, blocking, forgets to clear flag
// ---------------------------------------------------------
void bad_uart_isr() {
    std::cout << "\n  >> [BAD ISR] Entered.\n";
    
    // MISTAKE 1: Using printf (std::cout) in an ISR is horribly slow!
    // MISTAKE 2: Blocking delay!
    std::cout << "  >> [BAD ISR] Processing massive data packet... (Blocking CPU for 2 seconds)\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    
    // MISTAKE 3: Forgot to clear the 'uart_data_ready_flag'!
    // When this ISR exits, the hardware will immediately re-trigger it.
    std::cout << "  >> [BAD ISR] Exiting.\n";
}

// ---------------------------------------------------------
// GOOD ISR: Short, fast, clears flag, defers work
// ---------------------------------------------------------
void good_uart_isr() {
    // 1. Clear the hardware flag immediately to prevent infinite loops
    uart_data_ready_flag = false;
    
    // 2. Copy data to a buffer (fast)
    // 3. Give a Semaphore to wake a RTOS Task (fast)
    
    // std::cout is used here just for the simulation, but in real life, 
    // this entire function should contain NO prints and take < 2 microseconds.
    std::cout << "\n  >> [GOOD ISR] Data copied. Flag cleared. Semaphore Given. Exiting instantly.\n";
}

int main() {
    std::cout << "--- ISR Best Practices Demo ---\n\n";

    std::cout << "[Main] Normal operations running...\n";
    
    // Simulate hardware event
    uart_data_ready_flag = true;
    
    if (uart_data_ready_flag) {
        std::cout << "[Hardware] Triggering GOOD ISR...\n";
        good_uart_isr();
    }
    
    std::cout << "[Main] Resumed instantly! No lag.\n\n";
    
    // Simulate hardware event
    uart_data_ready_flag = true;
    
    if (uart_data_ready_flag) {
        std::cout << "[Hardware] Triggering BAD ISR...\n";
        bad_uart_isr();
        
        // Simulating the infinite loop consequence of forgetting to clear the flag
        if (uart_data_ready_flag) {
            std::cout << "[Hardware] Flag is STILL true! Re-triggering ISR! (INFINITE LOOP)\n";
        }
    }

    return 0;
}
