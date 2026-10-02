/**
 * @file namespace_demo.cpp
 * @brief Demonstrates C++ namespaces preventing naming collisions.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// Driver 1: Custom HAL
namespace hal {
    void delay(int ms) {
        std::cout << "HAL Delay for " << ms << " ms\n";
    }
}

// Driver 2: RTOS
namespace rtos {
    void delay(int ms) {
        std::cout << "RTOS Task Delay (yielding) for " << ms << " ms\n";
    }
}

// Anonymous namespace (Internal linkage)
namespace {
    void hidden_helper() {
        std::cout << "This function cannot be called from other .cpp files!\n";
    }
}

int main() {
    // Both functions have the exact same name, but don't collide
    hal::delay(10);
    rtos::delay(50);
    
    hidden_helper();

    // Using a specific symbol
    using rtos::delay;
    delay(100); // Resolves specifically to rtos::delay

    return 0;
}
