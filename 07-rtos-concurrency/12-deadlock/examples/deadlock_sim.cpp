/**
 * @file deadlock_sim.cpp
 * @brief Demonstrates how Strict Lock Ordering prevents Deadlocks.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mutex_A; // UART
std::mutex mutex_B; // SD Card

// BAD PATTERN: Task 1 takes A then B. Task 2 takes B then A.
// (Commented out to prevent the test from freezing forever)
/*
void bad_task1() {
    std::lock_guard<std::mutex> lockA(mutex_A);
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Force context switch
    std::lock_guard<std::mutex> lockB(mutex_B); // DEADLOCK HAPPENS HERE
}
void bad_task2() {
    std::lock_guard<std::mutex> lockB(mutex_B);
    std::this_thread::sleep_for(std::chrono::milliseconds(10)); // Force context switch
    std::lock_guard<std::mutex> lockA(mutex_A); // DEADLOCK HAPPENS HERE
}
*/

// GOOD PATTERN: Strict Lock Ordering. 
// ALL tasks MUST take Mutex A before Mutex B.

void good_task1() {
    std::cout << "[Task 1] Attempting to lock A...\n";
    std::lock_guard<std::mutex> lockA(mutex_A);
    std::cout << "[Task 1] Locked A. Working...\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50)); // Simulated context switch
    
    std::cout << "[Task 1] Attempting to lock B...\n";
    std::lock_guard<std::mutex> lockB(mutex_B);
    std::cout << "[Task 1] Locked A and B! Work complete.\n";
} // Locks auto-release here

void good_task2() {
    // Even though Task 2 wants to use resource B first, 
    // the company architecture RULES dictate it MUST lock A first!
    std::cout << "[Task 2] Attempting to lock A...\n";
    std::lock_guard<std::mutex> lockA(mutex_A);
    std::cout << "[Task 2] Locked A. Working...\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    
    std::cout << "[Task 2] Attempting to lock B...\n";
    std::lock_guard<std::mutex> lockB(mutex_B);
    std::cout << "[Task 2] Locked A and B! Work complete.\n";
} // Locks auto-release here

int main() {
    std::cout << "--- Deadlock Prevention (Lock Ordering) ---\n\n";

    // Because both tasks follow the A->B order, Task 2 will simply 
    // block at lockA until Task 1 is completely finished. No Deadlock!
    std::thread t1(good_task1);
    std::thread t2(good_task2);

    t1.join();
    t2.join();

    std::cout << "\nSystem executed successfully without freezing!\n";

    return 0;
}
