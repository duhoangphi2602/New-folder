/**
 * @file deferred_interrupt_sim.cpp
 * @brief Simulates the Deferred Interrupt pattern using C++ std::condition_variable (acting as a Semaphore).
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable binary_semaphore;
bool event_flag = false; // The actual "signal"

// Simulates the RTOS Task waiting for the signal
void DataProcessingTask() {
    std::cout << "[Task] Booted. Going to sleep, waiting for Hardware Interrupt...\n";
    
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Block (sleep) until event_flag becomes true
        binary_semaphore.wait(lock, []{ return event_flag; });
        
        // We received the Semaphore!
        event_flag = false; // Reset the signal
        lock.unlock();
        
        std::cout << "  [Task] AWAKE! Processing heavy data at the Task level...\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Heavy processing
        std::cout << "  [Task] Processing complete. Going back to sleep.\n\n";
    }
}

// Simulates a Hardware Interrupt (ISR)
void Hardware_ISR() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 2 seconds
    
    std::cout << "[ISR] UART Byte Received! (Running in Hardware Context)\n";
    std::cout << "[ISR] Setting Semaphore and exiting instantly!\n";
    
    {
        std::lock_guard<std::mutex> lock(mtx);
        event_flag = true; // "Give" the Semaphore
    }
    binary_semaphore.notify_one(); // Wake the Task
}

int main() {
    std::cout << "--- Deferred Interrupt Simulation ---\n\n";

    std::thread t1(DataProcessingTask);
    
    // Simulate hardware interrupts firing randomly
    std::thread isr1(Hardware_ISR);
    isr1.join();
    
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    std::thread isr2(Hardware_ISR);
    isr2.join();
    
    // Let the task finish processing before exiting
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    t1.detach(); // Allow program to exit

    return 0;
}
