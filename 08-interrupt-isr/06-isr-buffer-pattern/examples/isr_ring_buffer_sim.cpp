/**
 * @file isr_ring_buffer_sim.cpp
 * @brief Simulates a fast lock-free Ring Buffer passing data from an ISR to a Task.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>

// --- The Lock-Free Ring Buffer ---
const int BUFFER_SIZE = 256;
std::array<char, BUFFER_SIZE> ring_buffer;

// Atomics are used because ISR and Task both access these indices
std::atomic<int> head_idx{0}; // Written by ISR
std::atomic<int> tail_idx{0}; // Written by Task

// Mock Semaphore
std::condition_variable packet_semaphore;
std::mutex mtx;
bool packet_ready = false;

// ---------------------------------------------------------
// 1. The Hardware ISR (Producer)
// ---------------------------------------------------------
void UART_ISR_Sim(const std::string& simulated_data) {
    for (char c : simulated_data) {
        // FAST PATH: Copy byte and increment head (wrapping around)
        int current_head = head_idx.load(std::memory_order_relaxed);
        ring_buffer[current_head] = c;
        head_idx.store((current_head + 1) % BUFFER_SIZE, std::memory_order_release);
        
        // TRIGGER PATH: If we see a newline, fire the Semaphore!
        if (c == '\n') {
            std::cout << "[ISR] Newline detected. Firing Semaphore!\n";
            {
                std::lock_guard<std::mutex> lock(mtx);
                packet_ready = true;
            }
            packet_semaphore.notify_one();
        }
    }
}

// ---------------------------------------------------------
// 2. The RTOS Task (Consumer)
// ---------------------------------------------------------
void ProcessingTask() {
    std::cout << "[Task] Booted. Waiting for Semaphore...\n\n";
    
    while (true) {
        // Sleep until ISR fires the Semaphore
        std::unique_lock<std::mutex> lock(mtx);
        packet_semaphore.wait(lock, []{ return packet_ready; });
        packet_ready = false;
        lock.unlock();
        
        std::cout << "  [Task] AWAKE! Processing buffer...\n";
        
        // Read data until tail catches up to head
        std::string processed_packet = "";
        int current_tail = tail_idx.load(std::memory_order_relaxed);
        int current_head = head_idx.load(std::memory_order_acquire);
        
        while (current_tail != current_head) {
            processed_packet += ring_buffer[current_tail];
            current_tail = (current_tail + 1) % BUFFER_SIZE;
        }
        
        // Update tail globally
        tail_idx.store(current_tail, std::memory_order_release);
        
        std::cout << "  [Task] Packet Parsed: " << processed_packet;
    }
}


int main() {
    std::cout << "--- ISR to Task Ring Buffer Pattern ---\n\n";

    std::thread t1(ProcessingTask);
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    // Hardware receives bytes over time
    std::cout << "[Hardware] Receiving 'H'...\n"; UART_ISR_Sim("H");
    std::cout << "[Hardware] Receiving 'e'...\n"; UART_ISR_Sim("e");
    std::cout << "[Hardware] Receiving 'l'...\n"; UART_ISR_Sim("l");
    std::cout << "[Hardware] Receiving 'l'...\n"; UART_ISR_Sim("l");
    std::cout << "[Hardware] Receiving 'o'...\n"; UART_ISR_Sim("o");
    
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "[Hardware] Receiving '\\n'...\n"; UART_ISR_Sim("\n");

    std::this_thread::sleep_for(std::chrono::seconds(1));
    t1.detach();

    return 0;
}
