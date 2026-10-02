/**
 * @file blocking_demo.cpp
 * @brief Simulates the catastrophic CPU waste of Blocking I/O.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

int simulated_cpu_cycles_wasted = 0;

// Simulate a hardware peripheral that takes 100ms to finish a task
bool is_hardware_ready() {
    static int calls = 0;
    calls++;
    simulated_cpu_cycles_wasted++;
    
    // Simulate a slow peripheral (e.g., waiting for UART to send)
    std::this_thread::sleep_for(std::chrono::microseconds(100));
    
    if (calls > 100) {
        calls = 0;
        return true;
    }
    return false;
}

int main() {
    std::cout << "--- Blocking I/O CPU Waste Simulation ---\n\n";

    std::cout << "CPU wants to send 1 byte using Blocking I/O...\n";

    auto start = std::chrono::high_resolution_clock::now();

    // THE BLOCKING LOOP (POLLING)
    // The CPU is completely trapped here!
    while (!is_hardware_ready()) {
        // CPU does absolutely nothing but ask "Are you ready?"
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "\nByte Sent successfully!\n";
    std::cout << "Time elapsed: " << duration.count() << " ms\n";
    
    // This is the tragedy of polling:
    std::cout << "The CPU asked 'Are you ready?' " << simulated_cpu_cycles_wasted << " times.\n";
    std::cout << "If we used Interrupts, the CPU could have done " << simulated_cpu_cycles_wasted << " calculations instead!\n";

    return 0;
}
