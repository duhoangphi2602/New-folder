/**
 * @file volatile_failure_sim.cpp
 * @brief Demonstrates that volatile does NOT prevent Race Conditions.
 * 
 * Target: PC Simulation
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <vector>

// Even though it is volatile, it is NOT thread-safe!
volatile int shared_counter = 0;

void increment_task() {
    for (int i = 0; i < 100000; i++) {
        // This is a Read-Modify-Write operation.
        // It takes 3 Assembly instructions (LDR, ADD, STR).
        // It WILL be interrupted by the OS scheduler.
        shared_counter++; 
    }
}

int main() {
    std::cout << "--- Volatile vs Atomic Simulation ---\n\n";

    std::cout << "Starting 10 threads to increment a VOLATILE counter 100,000 times each...\n";
    std::cout << "Expected Final Value: 1000000\n";

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.push_back(std::thread(increment_task));
    }

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "\nActual Final Value:   " << shared_counter << "\n";
    
    if (shared_counter != 1000000) {
        std::cout << ">> MASSIVE DATA LOSS DETECTED! <<\n";
        std::cout << "Volatile completely failed to prevent the Race Condition!\n";
    }

    return 0;
}
