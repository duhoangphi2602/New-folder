/**
 * @file release_acquire_sim.cpp
 * @brief Demonstrates the correct use of Memory Ordering for Producer-Consumer.
 * 
 * Target: PC Simulation
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <cassert>

int payload_data = 0;
std::atomic<bool> payload_ready = false;

void producer_task() {
    // 1. Prepare the payload (Non-atomic, normal memory write)
    payload_data = 42; 

    // 2. Set the flag using memory_order_release.
    // The CPU/Compiler is FORBIDDEN from moving the 'payload_data = 42' 
    // write to after this line. It guarantees that when the flag becomes 
    // true, the payload is physically in RAM.
    std::cout << "[Producer] Data prepared. Setting flag (Release)...\n";
    payload_ready.store(true, std::memory_order_release);
}

void consumer_task() {
    // 1. Wait for the flag using memory_order_acquire.
    // The CPU/Compiler is FORBIDDEN from moving the 'read payload_data' 
    // to before this line (no speculative pre-fetching allowed).
    while (!payload_ready.load(std::memory_order_acquire)) {
        // Spin and wait
    }

    // 2. Safely read the payload
    std::cout << "[Consumer] Flag detected (Acquire). Reading data...\n";
    std::cout << "[Consumer] Data is: " << payload_data << "\n";
    
    // We are mathematically guaranteed that payload_data is 42.
    assert(payload_data == 42); 
}

int main() {
    std::cout << "--- Memory Ordering (Release-Acquire) Simulation ---\n\n";

    std::thread t2(consumer_task);
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Ensure consumer waits
    std::thread t1(producer_task);

    t1.join();
    t2.join();

    return 0;
}
