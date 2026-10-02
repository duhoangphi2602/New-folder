/**
 * @file race_condition_demo.cpp
 * @brief Simulates a Race Condition occurring at the assembly instruction level.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

int global_counter = 0;

// Simulate the 3 steps of assembly: LDR, ADD, STR
void simulated_assembly_increment(const std::string& task_name) {
    std::cout << "[" << task_name << "] Step 1: LDR (Read from RAM)\n";
    int R0 = global_counter; // Load
    
    // SIMULATING A CONTEXT SWITCH PREEMPTION!
    // We intentionally sleep here to force the OS to switch to the other thread.
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    std::cout << "[" << task_name << "] Step 2: ADD (Modify in Register)\n";
    R0 = R0 + 1; // Add
    
    std::cout << "[" << task_name << "] Step 3: STR (Write back to RAM)\n";
    global_counter = R0; // Store
}

int main() {
    std::cout << "--- Race Condition (Assembly Level Simulation) ---\n\n";
    
    std::cout << "Initial Value: " << global_counter << "\n\n";

    // Launch two threads trying to increment the exact same variable
    std::thread t1(simulated_assembly_increment, "Task A");
    std::thread t2(simulated_assembly_increment, "Task B");

    t1.join();
    t2.join();

    std::cout << "\nExpected Final Value: 2\n";
    std::cout << "ACTUAL Final Value:   " << global_counter << "  <-- DATA CORRUPTION!\n";

    return 0;
}
