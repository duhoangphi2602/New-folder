/**
 * @file volatile_sim.cpp
 * @brief Conceptually simulates how a compiler optimizes away memory reads.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

// 1. Without volatile (Simulating optimized behavior)
bool hardware_flag_optimized = false;

// 2. With volatile
volatile bool hardware_flag_volatile = false;

// Simulates the CPU reading from a Register Cache instead of RAM
void bad_optimized_loop() {
    std::cout << "[Bad Loop] Reading hardware_flag_optimized into CPU Cache (Register)...\n";
    bool cached_register = hardware_flag_optimized; 
    
    std::cout << "[Bad Loop] Spinning... checking cached register only.\n";
    
    int timeout = 0;
    // The compiler turns the loop into this: checking the cache, not RAM!
    while (cached_register == false) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        timeout++;
        if (timeout > 20) {
            std::cout << "  [Bad Loop] FATAL: Stuck in infinite loop! Never read RAM!\n";
            break;
        }
    }
}

// Simulates the CPU being forced to read from RAM every time
void good_volatile_loop() {
    std::cout << "[Good Loop] Spinning... forcing physical RAM read every iteration.\n";
    
    while (hardware_flag_volatile == false) {
        // Actually reading RAM
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    std::cout << "  [Good Loop] SUCCESS! Detected flag change in RAM.\n";
}

void hardware_isr() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "\n  >> [ISR] Updating RAM flags to TRUE <<\n\n";
    
    // Update both physical RAM locations
    hardware_flag_optimized = true;
    hardware_flag_volatile = true;
}

int main() {
    std::cout << "--- Compiler Optimization Simulation (Volatile) ---\n\n";

    std::thread isr_thread(hardware_isr);

    // Run the bad loop (Simulates a release build crash)
    bad_optimized_loop();
    
    // Run the good loop
    good_volatile_loop();

    isr_thread.join();
    return 0;
}
