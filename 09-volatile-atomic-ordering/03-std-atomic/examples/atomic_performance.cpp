/**
 * @file atomic_performance.cpp
 * @brief Demonstrates the ease of use and performance of std::atomic.
 * 
 * Target: PC Simulation
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>

const int ITERATIONS = 1000000;

// Scenario 1: Mutex
int mutex_counter = 0;
std::mutex mtx;

void mutex_task() {
    for (int i = 0; i < ITERATIONS; i++) {
        std::lock_guard<std::mutex> lock(mtx);
        mutex_counter++;
    }
}

// Scenario 2: Atomic
std::atomic<int> atomic_counter = 0;

void atomic_task() {
    for (int i = 0; i < ITERATIONS; i++) {
        atomic_counter++; // No locks!
    }
}

int main() {
    std::cout << "--- Mutex vs std::atomic Performance Simulation ---\n\n";

    // 1. Benchmark Mutex
    auto start = std::chrono::high_resolution_clock::now();
    std::thread t1(mutex_task);
    std::thread t2(mutex_task);
    t1.join(); t2.join();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> mutex_time = end - start;
    
    std::cout << "[Mutex] Final Value: " << mutex_counter << " (Expected: " << ITERATIONS*2 << ")\n";
    std::cout << "[Mutex] Time taken:  " << mutex_time.count() << " ms\n\n";

    // 2. Benchmark Atomic
    start = std::chrono::high_resolution_clock::now();
    std::thread t3(atomic_task);
    std::thread t4(atomic_task);
    t3.join(); t4.join();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> atomic_time = end - start;

    std::cout << "[Atomic] Final Value: " << atomic_counter << " (Expected: " << ITERATIONS*2 << ")\n";
    std::cout << "[Atomic] Time taken:  " << atomic_time.count() << " ms\n\n";

    std::cout << "Conclusion: std::atomic is perfectly safe AND significantly faster!\n";

    return 0;
}
