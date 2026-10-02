/**
 * @file rtos_task_sim.cpp
 * @brief Demonstrates the structure of RTOS tasks using standard C++ threads.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

// Mock RTOS Delay function (simulates vTaskDelay)
void vTaskDelay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// ---------------------------------------------
// TASK 1: Sensor Reading (High Frequency)
// ---------------------------------------------
void SensorTask(void* params) {
    int task_id = *(int*)params;
    std::cout << "[SensorTask] Booted. ID: " << task_id << "\n";
    
    // Infinite RTOS Loop
    while (true) {
        std::cout << "  [SensorTask] Reading I2C Sensor...\n";
        
        // CRITICAL: We must sleep to let the CPU run other tasks!
        vTaskDelay(500); 
    }
}

// ---------------------------------------------
// TASK 2: Network Reporting (Low Frequency)
// ---------------------------------------------
void NetworkTask(void* params) {
    std::cout << "[NetworkTask] Booted.\n";
    
    // Infinite RTOS Loop
    while (true) {
        std::cout << "  [NetworkTask] Sending Data to Cloud...\n";
        
        // Sleep for 2 seconds
        vTaskDelay(2000); 
    }
}

int main() {
    std::cout << "--- RTOS Task Structure Simulation ---\n\n";

    int sensor_id = 42;

    // Simulating xTaskCreate
    std::cout << "Starting Scheduler...\n\n";
    std::thread t1(SensorTask, &sensor_id);
    std::thread t2(NetworkTask, nullptr);

    // In a real RTOS, vTaskStartScheduler() is called here and never returns.
    t1.join();
    t2.join();

    return 0;
}
