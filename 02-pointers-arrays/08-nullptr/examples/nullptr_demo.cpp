/**
 * @file nullptr_demo.cpp
 * @brief Demonstrates the overloading bug caused by NULL and fixed by nullptr.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// Overload 1: Takes an integer
void configure_peripheral(int value) {
    std::cout << "[Integer Overload] Peripheral configured with raw value: " << value << "\n";
}

// Overload 2: Takes a pointer to a config struct
void configure_peripheral(int* config_ptr) {
    if (config_ptr == nullptr) {
        std::cout << "[Pointer Overload] Peripheral disabled (nullptr passed).\n";
    } else {
        std::cout << "[Pointer Overload] Peripheral configured using struct.\n";
    }
}

int main() {
    std::cout << "--- The NULL Trap ---\n\n";

    // 1. Passing the integer 0
    std::cout << "Calling configure_peripheral(0):\n";
    configure_peripheral(0); // Expected: Integer overload

    // 2. Passing NULL (The Trap!)
    std::cout << "\nCalling configure_peripheral(NULL):\n";
    configure_peripheral(NULL); // Expected: Pointer overload? WRONG!

    // 3. Passing nullptr (The Fix)
    std::cout << "\nCalling configure_peripheral(nullptr):\n";
    configure_peripheral(nullptr); // Expected: Pointer overload. CORRECT!

    return 0;
}
