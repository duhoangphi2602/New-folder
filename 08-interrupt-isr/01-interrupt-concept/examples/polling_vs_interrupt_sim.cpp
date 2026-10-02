/**
 * @file polling_vs_interrupt_sim.cpp
 * @brief Simulates the architectural difference between Polling and Interrupts.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <thread>
#include <chrono>

bool hardware_button_pressed = false;

// ---------------------------------------------------------
// BAD ARCHITECTURE: Polling
// ---------------------------------------------------------
void bad_polling_main() {
    std::cout << "[Polling] Starting main loop. Wasting CPU cycles...\n";
    int cycles_wasted = 0;
    
    // The CPU is trapped in this loop, burning 100% power
    while (!hardware_button_pressed) {
        cycles_wasted++;
        // Cannot do any other work here!
    }
    
    std::cout << "[Polling] Button detected! Wasted " << cycles_wasted << " checks.\n\n";
}


// ---------------------------------------------------------
// GOOD ARCHITECTURE: Interrupts (Simulated)
// ---------------------------------------------------------

// This is the ISR. It is only called when the hardware triggers it.
void button_isr() {
    std::cout << "\n  >> [ISR] HARDWARE INTERRUPT FIRED! Button pressed! <<\n";
    // Clear the hardware flag, set a software flag, or wake a task
}

void good_interrupt_main() {
    std::cout << "[Interrupts] Starting main loop. CPU is free to do heavy math!\n";
    
    int math_progress = 0;
    while (!hardware_button_pressed) {
        // The CPU is doing useful work!
        math_progress++;
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate work
        std::cout << "[Interrupts] Processing math... " << math_progress << "%\n";
    }
}

// ---------------------------------------------------------
// Hardware Simulator
// ---------------------------------------------------------
void simulate_hardware_user() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    hardware_button_pressed = true;
    button_isr(); // Hardware forces the CPU to jump to the ISR
}


int main() {
    std::cout << "--- Interrupt Architecture Simulation ---\n\n";

    // Simulate Bad Polling
    std::thread hw1([](){ 
        std::this_thread::sleep_for(std::chrono::microseconds(10));
        hardware_button_pressed = true; 
    });
    bad_polling_main();
    hw1.join();

    hardware_button_pressed = false;

    // Simulate Good Interrupts
    std::thread hw2(simulate_hardware_user);
    good_interrupt_main();
    hw2.join();

    return 0;
}
