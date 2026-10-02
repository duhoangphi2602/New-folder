/**
 * @file pointer_demo.cpp
 * @brief Demonstrates declaration, dereferencing, and modifying via pointers.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

int main() {
    std::cout << "--- Pointer Basics ---\n";
    
    int score = 50;
    int* ptr_score = &score; // ptr_score holds the address of score

    std::cout << "Original score: " << score << "\n";
    std::cout << "Address of score: " << ptr_score << "\n";

    // Dereferencing to read
    int read_value = *ptr_score;
    std::cout << "Read via pointer: " << read_value << "\n";

    // Dereferencing to write
    *ptr_score = 99;
    std::cout << "Score after writing through pointer: " << score << "\n";

    std::cout << "\n--- Nullptr Safety ---\n";
    
    // In modern C++, ALWAYS initialize pointers to nullptr if they don't point to anything yet.
    // Do NOT use NULL or 0.
    int* safe_ptr = nullptr;

    // Always check for nullptr before dereferencing!
    if (safe_ptr != nullptr) {
        *safe_ptr = 100;
    } else {
        std::cout << "Caught a nullptr! Safely skipped dereferencing.\n";
    }

    return 0;
}
