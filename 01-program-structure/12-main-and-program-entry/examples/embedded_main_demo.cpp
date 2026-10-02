/**
 * @file embedded_main_demo.cpp
 * @brief Demonstrates the structure of a bare-metal embedded main() function.
 * 
 * Target: PC (Simulating Embedded Structure)
 * Standard: C++17
 */

#include <iostream>

// --- Simulated Hardware Functions ---
void system_clock_init() { std::cout << "[INIT] Clocks configured to 48MHz\n"; }
void gpio_init()         { std::cout << "[INIT] GPIO pins configured\n"; }
bool read_button()       { static int c=0; return (++c % 3 == 0); } // Simulates a button press occasionally
void toggle_led()        { std::cout << "       * LED Toggled! *\n"; }

int main(void) {
    std::cout << "--- CPU Reset. Startup code finished. Entering main() ---\n\n";

    // 1. One-time setup
    system_clock_init();
    gpio_init();

    std::cout << "\n--- Entering Super Loop ---\n";
    
    // 2. The Super Loop
    int loop_counter = 0;
    while (true) {
        loop_counter++;
        
        // Simulating the MCU doing work...
        if (read_button()) {
            std::cout << "Loop " << loop_counter << ": Button pressed!\n";
            toggle_led();
        }

        // Artificial exit condition just so the PC simulation doesn't run forever.
        // In a real MCU, this 'break' would never exist!
        if (loop_counter >= 5) {
            std::cout << "Simulated power loss. Shutting down.\n";
            break;
        }
    }

    // 3. Unreachable Code (in a real embedded system)
    std::cout << "\nFATAL: main() returned!\n";
    return 0;
}
