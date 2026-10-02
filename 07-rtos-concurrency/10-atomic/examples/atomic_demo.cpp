/**
 * @file atomic_demo.cpp
 * @brief Demonstrates lock-free thread synchronization using std::atomic.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

// No mutexes needed!
std::atomic<bool> is_data_ready{false};
std::atomic<int>  sensor_reading{0};

// Simulates an ISR or High-Priority Task generating data
void ProducerISR() {
    std::cout << "[Producer] Generating reading...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    
    // Write data (Atomic)
    sensor_reading.store(42);
    
    // Set flag (Atomic)
    // The C++ memory model guarantees that 'sensor_reading' will be 
    // fully written to RAM *before* 'is_data_ready' becomes true.
    is_data_ready.store(true);
    
    std::cout << "[Producer] Data ready flag set!\n";
}

// Simulates a background Task waiting for data
void ConsumerTask() {
    std::cout << "[Consumer] Booted. Waiting for data...\n";
    
    // Lock-free spinning (Note: In a real RTOS, you'd use a Semaphore 
    // to avoid wasting CPU, but Atomics are perfect for ultra-low latency).
    while (!is_data_ready.load()) {
        // Spin...
    }
    
    std::cout << "[Consumer] Flag detected! Reading data safely: " 
              << sensor_reading.load() << "\n";
}

int main() {
    std::cout << "--- std::atomic Lock-Free Demo ---\n\n";

    std::thread consumer(ConsumerTask);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Ensure consumer starts first
    std::thread producer(ProducerISR);

    consumer.join();
    producer.join();

    return 0;
}
