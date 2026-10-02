/**
 * @file volatile_isr_flag.cpp
 * @brief Demonstrates the mandatory use of volatile for ISR flags.
 * 
 * Target: Any embedded system
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

// SCENARIO 1: BUGGY (No volatile)
// In a real Release build (-O3), the compiler would cache `buggy_flag` in a register.
// The main loop would NEVER see the ISR change it.
bool buggy_flag = false;

// SCENARIO 2: CORRECT (Volatile)
// The compiler is FORCED to read physical RAM every time.
volatile bool correct_flag = false;

// Simulated Hardware Interrupt
void hardware_isr_simulator() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "[ISR] Hardware event occurred! Setting flags to true...\n";
    buggy_flag = true;
    correct_flag = true;
}

int main() {
    std::cout << "--- Volatile ISR Flag Simulation ---\n\n";

    std::thread isr_thread(hardware_isr_simulator);

    std::cout << "[Main] Waiting for correct_flag to become true...\n";
    
    // In a real embedded system without volatile, this loop would be infinite at -O3.
    while (correct_flag == false) {
        // Spin waiting for ISR
    }
    
    std::cout << "[Main] Detected correct_flag == true! Exiting loop.\n";

    isr_thread.join();
    return 0;
}
