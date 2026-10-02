/**
 * @file lifecycle_demo.cpp
 * @brief A conceptual checklist of the Embedded Memory Architecture.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// Test your knowledge! Mentally trace where these go:

const int config_value = 100;     // 1. Where does this live? (Flash / .rodata)
int system_state = 1;             // 2. Where does this live? (RAM / .data)
int error_counts;                 // 3. Where does this live? (RAM / .bss)

int main() {
    int local_temp = 50;          // 4. Where does this live? (RAM / Stack)
    
    // 5. If I call 'new', where does it live? (RAM / Heap - BANNED!)
    // int* leak = new int(5); 

    std::cout << "--- Firmware Memory Lifecycle Complete ---\n\n";
    std::cout << "If you correctly identified the memory segments above,\n";
    std::cout << "you have successfully mastered Chapter 05.\n";

    return 0;
}
