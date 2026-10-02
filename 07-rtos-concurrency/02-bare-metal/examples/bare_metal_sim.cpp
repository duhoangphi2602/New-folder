/**
 * @file bare_metal_sim.cpp
 * @brief Demonstrates a Non-Blocking Bare-Metal Super Loop.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <chrono>
#include <thread>

// Simulate a hardware timer (returns milliseconds since boot)
uint64_t get_system_ticks() {
    auto now = std::chrono::steady_clock::now();
    auto duration = now.time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}

// Non-blocking Task 1: Blink an LED every 500ms
void process_led() {
    static uint64_t last_toggle_time = 0;
    static bool led_state = false;
    
    uint64_t current_time = get_system_ticks();
    
    // Quick Check: Has 500ms passed?
    if (current_time - last_toggle_time >= 500) {
        led_state = !led_state;
        std::cout << "[LED] State changed to: " << (led_state ? "ON" : "OFF") << "\n";
        last_toggle_time = current_time;
    }
    // If not, we instantly return! (Zero blocking)
}

// Non-blocking Task 2: Check for a button press (simulated)
void process_button() {
    static int loop_counter = 0;
    loop_counter++;
    
    // Simulate a button press exactly every 15,000,000 loop iterations
    if (loop_counter == 15000000) {
        std::cout << "  [BUTTON] User clicked the button!\n";
        loop_counter = 0;
    }
}

int main() {
    std::cout << "--- Bare-Metal Super Loop Simulation ---\n";
    std::cout << "Running... (Press Ctrl+C to stop)\n\n";

    // THE SUPER LOOP
    // This loop spins millions of times per second.
    while (true) {
        process_led();      // Returns almost instantly
        process_button();   // Returns almost instantly
        
        // (Optional: In a real system, you might put the CPU to sleep here 
        // until the next interrupt occurs to save power).
    }

    return 0;
}
