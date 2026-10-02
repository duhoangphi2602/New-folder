/**
 * @file critical_section_demo.cpp
 * @brief Demonstrates using Modern C++ RAII to safely manage Critical Sections.
 * 
 * Target: Simulated RTOS (PC)
 * Standard: C++17
 */

#include <iostream>

// Mocking FreeRTOS Macros
void taskENTER_CRITICAL() { std::cout << "  [HARDWARE] Interrupts DISABLED (SysTick Paused)\n"; }
void taskEXIT_CRITICAL()  { std::cout << "  [HARDWARE] Interrupts ENABLED  (SysTick Resumed)\n"; }

// C++17 RAII Wrapper for Critical Sections
class CriticalGuard {
public:
    CriticalGuard() {
        taskENTER_CRITICAL();
    }
    ~CriticalGuard() {
        taskEXIT_CRITICAL();
    }
    
    // Prevent copying! We don't want multiple exits.
    CriticalGuard(const CriticalGuard&) = delete;
    CriticalGuard& operator=(const CriticalGuard&) = delete;
};

// Global resource
int sensor_raw_value = 0;

void read_sensor_safe(bool trigger_error) {
    std::cout << "Starting Sensor Read Task...\n";
    
    // We enter the critical section safely using RAII
    CriticalGuard guard;
    
    sensor_raw_value++; // Safe from all preemption
    
    if (trigger_error) {
        std::cout << "  [!] Sensor Error! Returning early!\n";
        return; // DANGER in C! But in C++, the Destructor runs automatically!
    }
    
    std::cout << "  Sensor read complete.\n";
} // Destructor runs here naturally

int main() {
    std::cout << "--- RAII Critical Section Demo ---\n\n";

    std::cout << "Scenario 1: Normal Execution\n";
    read_sensor_safe(false);

    std::cout << "\nScenario 2: Error Execution\n";
    read_sensor_safe(true);

    return 0;
}
