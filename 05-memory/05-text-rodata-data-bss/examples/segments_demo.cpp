/**
 * @file segments_demo.cpp
 * @brief Demonstrates where variables belong in the memory segments.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// 1. .data segment (Global, initialized to non-zero)
int global_status = 42; 

// 2. .bss segment (Global, uninitialized)
// The C Standard guarantees this will be zeroed out at boot!
int global_counter; 

// 3. .rodata segment (Global, constant)
const float pi = 3.14159f;

// 4. .text segment (The machine code instructions for this function)
void some_function() {
    // 5. STACK segment (Local variables are NOT in .data or .bss!)
    int local_var = 10;
    
    // 6. .rodata segment (The string literal is stored in ROM)
    std::cout << "Local var: " << local_var << "\n";
}

int main() {
    std::cout << "--- Memory Segments (.text, .rodata, .data, .bss) ---\n\n";

    std::cout << "global_status (should be 42) : " << global_status << "\n";
    std::cout << "global_counter (MUST be 0)   : " << global_counter << "\n";

    some_function();

    return 0;
}
