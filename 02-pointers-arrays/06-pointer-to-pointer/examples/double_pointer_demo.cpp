/**
 * @file double_pointer_demo.cpp
 * @brief Demonstrates C-style vs C++-style pointer modification.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

// Simulated hardware buffers
uint32_t buffer_A[5] = {1, 1, 1, 1, 1};
uint32_t buffer_B[5] = {2, 2, 2, 2, 2};

// --- The C Way (Double Pointers) ---
void switch_buffer_c(uint32_t** active_buffer_ptr) {
    if (active_buffer_ptr != nullptr) {
        // Dereference once to access the caller's pointer, then change its value
        *active_buffer_ptr = buffer_B;
    }
}

// --- The Modern C++ Way (Pointer References) ---
void switch_buffer_cpp(uint32_t*& active_buffer_ref) {
    // Treat active_buffer_ref just like a normal pointer
    active_buffer_ref = buffer_A;
}

int main() {
    std::cout << "--- Pointer Modification ---\n";

    uint32_t* my_current_buffer = buffer_A;
    std::cout << "Currently pointing to: " << my_current_buffer[0] << "\n";

    // 1. C-style: We must pass the address of our pointer
    switch_buffer_c(&my_current_buffer);
    std::cout << "After C function:      " << my_current_buffer[0] << "\n";

    // 2. C++-style: We just pass the pointer itself (passed by reference under the hood)
    switch_buffer_cpp(my_current_buffer);
    std::cout << "After C++ function:    " << my_current_buffer[0] << "\n";

    return 0;
}
