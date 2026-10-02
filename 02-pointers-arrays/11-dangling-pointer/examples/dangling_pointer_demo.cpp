/**
 * @file dangling_pointer_demo.cpp
 * @brief Demonstrates the silent corruption caused by stack-based dangling pointers.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// 1. This function creates a variable and wrongly returns its address
int* generate_secret_code() {
    int secret = 12345;
    return &secret; // WARNING: Returning address of local variable!
}

// 2. This function does something completely unrelated
void do_unrelated_work() {
    int temporary_data = 99999;
    // This variable reuses the exact same stack memory that 'secret' just used!
}

int main() {
    std::cout << "--- Dangling Pointer (Stack Corruption) ---\n\n";

    // Get the dangling pointer
    int* bad_ptr = generate_secret_code();
    
    // It MIGHT look like it works immediately because the memory hasn't been overwritten yet.
    std::cout << "Value immediately after return: " << *bad_ptr << "\n";

    // Call a completely unrelated function. This overwrites the stack memory.
    do_unrelated_work();

    // Now look at the value!
    std::cout << "Value after unrelated work:   " << *bad_ptr << "\n";
    std::cout << "-> The data was silently corrupted because the pointer was dangling!\n";

    return 0;
}
