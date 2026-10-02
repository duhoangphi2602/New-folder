/**
 * @file static_demo.cpp
 * @brief Demonstrates the lifetime of static variables inside functions.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

void normal_function() {
    // Allocated on the Stack. Destroyed when function ends.
    int count = 0; 
    count++;
    std::cout << "Normal Count: " << count << "\n";
}

void static_function() {
    // Allocated in Static Storage. Initialized only ONCE at boot.
    // Retains its value permanently.
    static int count = 0; 
    count++;
    std::cout << "Static Count: " << count << "\n";
}

int main() {
    std::cout << "--- Static Storage Duration ---\n\n";

    std::cout << "Calling Normal Function 3 times:\n";
    normal_function(); // Prints 1
    normal_function(); // Prints 1
    normal_function(); // Prints 1

    std::cout << "\nCalling Static Function 3 times:\n";
    static_function(); // Prints 1
    static_function(); // Prints 2
    static_function(); // Prints 3

    return 0;
}
