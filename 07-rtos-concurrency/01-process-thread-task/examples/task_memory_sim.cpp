/**
 * @file task_memory_sim.cpp
 * @brief Demonstrates how Tasks share global memory but have private Stacks.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread> // Using std::thread to simulate RTOS Tasks on PC
#include <chrono>

// GLOBAL MEMORY (Shared by all Tasks)
int shared_sensor_data = 0;

void task_1() {
    // LOCAL MEMORY (Private to Task 1's Stack)
    int task1_private_counter = 0;
    
    std::cout << "[Task 1] Booted. Updating shared memory...\n";
    shared_sensor_data = 42; // Modifying global state
    
    std::cout << "[Task 1] My private counter is: " << ++task1_private_counter << "\n";
}

void task_2() {
    // LOCAL MEMORY (Private to Task 2's Stack)
    int task2_private_counter = 100;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Wait for Task 1
    
    std::cout << "[Task 2] Booted. Reading shared memory...\n";
    std::cout << "[Task 2] Shared Sensor Data = " << shared_sensor_data << "\n";
    
    std::cout << "[Task 2] My private counter is: " << ++task2_private_counter << "\n";
}

int main() {
    std::cout << "--- RTOS Task Memory Simulation ---\n\n";

    // Simulating spawning two FreeRTOS tasks
    std::thread t1(task_1);
    std::thread t2(task_2);

    t1.join();
    t2.join();

    std::cout << "\n[Main] Simulation complete. Final Shared Data: " << shared_sensor_data << "\n";
    return 0;
}
