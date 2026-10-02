/**
 * @file fragmentation_demo.cpp
 * @brief Simulates Heap External Fragmentation.
 * 
 * Target: PC (Simulation)
 * Standard: C++17
 */

#include <iostream>
#include <vector>
#include <string>

// Simulate a tiny 20-byte Heap
char heap[20];
bool is_free[20];

void print_heap() {
    std::cout << "[ ";
    for (int i = 0; i < 20; i++) {
        if (is_free[i]) std::cout << "F ";
        else std::cout << heap[i] << " ";
    }
    std::cout << "]\n";
}

int main() {
    // Initialize heap as completely Free
    for (int i = 0; i < 20; i++) is_free[i] = true;

    std::cout << "--- Heap Fragmentation Simulation ---\n\n";
    print_heap();

    std::cout << "\n1. Allocate A (5 bytes), B (8 bytes), C (5 bytes):\n";
    for(int i=0; i<5; i++)  { heap[i] = 'A'; is_free[i] = false; }
    for(int i=5; i<13; i++) { heap[i] = 'B'; is_free[i] = false; }
    for(int i=13; i<18; i++){ heap[i] = 'C'; is_free[i] = false; }
    print_heap();

    std::cout << "\n2. Free B (8 bytes):\n";
    for(int i=5; i<13; i++) { is_free[i] = true; }
    print_heap();
    
    // We now have 10 bytes free in total (8 in the middle, 2 at the end).
    
    std::cout << "\n3. Allocate D (4 bytes) into the hole:\n";
    for(int i=5; i<9; i++) { heap[i] = 'D'; is_free[i] = false; }
    print_heap();
    
    // The crisis
    std::cout << "\n4. We have 6 bytes of free RAM total.\n";
    std::cout << "Let's try to allocate E (5 bytes)...\n";
    
    // Try to find 5 contiguous Fs
    bool success = false;
    // (Logic omitted for brevity, visually it is impossible).
    
    std::cout << "[FATAL ERROR] malloc(5) FAILED! Out Of Memory!\n";
    std::cout << "The heap has 6 bytes free, but the largest contiguous hole is only 4 bytes.\n";

    return 0;
}
