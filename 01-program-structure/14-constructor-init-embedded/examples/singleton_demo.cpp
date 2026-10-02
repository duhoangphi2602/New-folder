/**
 * @file singleton_demo.cpp
 * @brief Demonstrates Meyer's Singleton to solve init order issues.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// --- Simulated Hardware Driver ---
class Uart {
public:
    Uart() {
        std::cout << "[UART] Hardware Initialized.\n";
    }
    void print(const char* msg) {
        std::cout << "[UART TX] " << msg;
    }
};

// --- Singleton Accessor ---
// This guarantees Uart is initialized exactly once, on the first call.
Uart& get_uart() {
    static Uart instance;
    return instance;
}

// --- Dependent Component ---
class Logger {
public:
    Logger() {
        std::cout << "[Logger] Initializing... calling get_uart()\n";
        get_uart().print("Logger booted up successfully.\n");
    }
};

// --- The Global Object ---
// Even though this is global and constructed before main(), 
// the Meyer's Singleton guarantees it gets a valid Uart object!
Logger g_sys_logger;

int main() {
    std::cout << "\n--- Entering main() ---\n";
    get_uart().print("Application running.\n");
    return 0;
}
