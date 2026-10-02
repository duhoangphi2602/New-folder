/**
 * @file stack_demo.cpp
 * @brief Demonstrates the LIFO nature of the Stack and downward growth.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

void function_C() {
    int var_C = 30;
    std::cout << "  Inside function_C. Address of var_C: " << &var_C << "\n";
}

void function_B() {
    int var_B = 20;
    std::cout << " Inside function_B.  Address of var_B: " << &var_B << "\n";
    function_C();
}

void function_A() {
    int var_A = 10;
    std::cout << "Inside function_A.   Address of var_A: " << &var_A << "\n";
    function_B();
}

int main() {
    std::cout << "--- The Call Stack ---\n\n";
    
    // 1. Notice how the memory addresses decrease as we go deeper!
    // This proves the stack is growing downwards in RAM.
    function_A();

    // 2. The Dangling Pointer Trap
    // NEVER RETURN A POINTER TO A STACK VARIABLE!
    /*
    int* bad_function() {
        int temp = 42;
        return &temp; // FATAL: When this returns, 'temp' is destroyed!
    }
    */

    return 0;
}
