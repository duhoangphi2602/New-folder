/**
 * @file mutex_demo.cpp
 * @brief Demonstrates Mutex protection using C++ std::mutex and std::lock_guard.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Shared Hardware Resource
class I2CBus {
    std::mutex bus_mutex;
public:
    void send_data(const std::string& task_name, const std::string& data) {
        // Automatically take the mutex. Blocks if another task has it.
        std::lock_guard<std::mutex> guard(bus_mutex);
        
        std::cout << "[" << task_name << "] Acquired I2C Mutex. Sending: " << data << "...\n";
        
        // Simulate a slow hardware transmission
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        
        std::cout << "[" << task_name << "] Transmission complete. Releasing Mutex.\n";
    } // guard goes out of scope here -> Mutex automatically given back!
};

I2CBus shared_i2c;

void sensor_task() {
    shared_i2c.send_data("Sensor Task", "TEMP=25C");
}

void display_task() {
    // This task will start, try to use the I2C bus, find it locked by the 
    // Sensor Task, and be safely put to sleep by the OS until it is free.
    shared_i2c.send_data("Display Task", "DRAW_CMD");
}

int main() {
    std::cout << "--- Mutex Hardware Protection Demo ---\n\n";

    // Launch both tasks almost simultaneously
    std::thread t1(sensor_task);
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Ensure t1 starts slightly first
    std::thread t2(display_task);

    t1.join();
    t2.join();

    return 0;
}
