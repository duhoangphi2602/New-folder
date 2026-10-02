/**
 * @file const_pointer_demo.cpp
 * @brief Demonstrates const correctness in function APIs.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <cstring>

// Read-only API: Guarantees it will not modify the buffer
void transmit_data(const uint8_t* tx_buffer, size_t length) {
    std::cout << "Transmitting: ";
    for (size_t i = 0; i < length; i++) {
        // tx_buffer[i] = 0; // COMPILE ERROR: Cannot modify const data
        std::cout << (int)tx_buffer[i] << " ";
    }
    std::cout << "\n";
}

// Write-only API: Needs to modify the buffer
void receive_data(uint8_t* rx_buffer, size_t length) {
    // Simulate receiving data from hardware
    for (size_t i = 0; i < length; i++) {
        rx_buffer[i] = i * 10; // OK: Data is mutable
    }
}

int main() {
    std::cout << "--- Const Pointer API Rules ---\n\n";

    uint8_t my_data[3] = {1, 2, 3};

    // We can pass mutable data to a function expecting const data.
    // (Implicit conversion from T* to const T*)
    transmit_data(my_data, 3);

    // Receive new data
    receive_data(my_data, 3);
    
    std::cout << "After receive: ";
    transmit_data(my_data, 3);

    return 0;
}
