/**
 * @file malloc_demo.cpp
 * @brief Demonstrates malloc, free, and dangling pointers.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdlib>

void dangling_pointer_demo() {
    std::cout << "[Demo] Dangling Pointer\n";
    
    int* ptr = (int*)malloc(sizeof(int));
    if (!ptr) return;
    
    *ptr = 42;
    std::cout << "  Value: " << *ptr << "\n";
    
    free(ptr); // Memory is returned to the system!
    
    // BUG: ptr still holds the address! It is a "Dangling Pointer".
    // If we write to it now, we corrupt random memory.
    // *ptr = 99; // CRASH!
    
    // BEST PRACTICE:
    ptr = nullptr; 
    std::cout << "  Pointer safely nullified.\n";
}

int main() {
    std::cout << "--- malloc() and free() ---\n\n";
    dangling_pointer_demo();
    return 0;
}
