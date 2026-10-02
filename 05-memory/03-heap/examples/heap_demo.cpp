/**
 * @file heap_demo.cpp
 * @brief Demonstrates C++ dynamic allocation and the danger of memory leaks.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

void process_data_safe() {
    // 1. Allocate on the Heap
    int* data = new int[100]; 
    
    data[0] = 42;
    
    // 2. Safely return it to the OS
    delete[] data; 
}

void process_data_leak() {
    int* leak = new int[100];
    leak[0] = 99;
    
    // FATAL: The function ends without calling delete[].
    // The pointer 'leak' is destroyed (it was on the stack), 
    // but the 400 bytes it pointed to on the Heap are lost forever.
}

int main() {
    std::cout << "--- The Heap ---\n\n";

    std::cout << "Calling safe function...\n";
    process_data_safe();
    
    std::cout << "Calling leaking function...\n";
    process_data_leak();
    std::cout << "[!] 400 bytes of RAM were just permanently lost.\n";

    // In a microcontroller that loops millions of times:
    /*
    while(1) {
        process_data_leak(); // System will crash in about 0.05 seconds.
    }
    */

    return 0;
}
