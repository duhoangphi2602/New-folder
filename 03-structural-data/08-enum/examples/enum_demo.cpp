/**
 * @file enum_demo.cpp
 * @brief Demonstrates C-style enums and their implicit integer conversions.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// C-style enum
enum Direction {
    NORTH, // 0
    EAST,  // 1
    SOUTH, // 2
    WEST   // 3
};

int main() {
    std::cout << "--- Legacy C-Style Enums ---\n\n";

    Direction heading = EAST;
    
    // 1. Implicit conversion to integer
    std::cout << "Heading value: " << heading << "\n"; // Prints 1

    // 2. Dangerous Math (Compiles without warnings)
    int nonsense = heading + 100;
    std::cout << "Nonsense math: " << nonsense << "\n"; // Prints 101

    // 3. Namespace Pollution Check
    // If you uncomment the following line, the code will fail to compile
    // because 'NORTH' already exists in the global scope!
    // int NORTH = 99; 

    return 0;
}
