/**
 * @file macro_dangers.cpp
 * @brief Demonstrates why C++17 constexpr is superior to C macros.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// 1. The C-style Macro
#define MAX_MACRO(a, b) ((a) > (b) ? (a) : (b))

// 2. The C++17 constexpr Template
template<typename T>
constexpr T max_safe(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    int x = 5;
    int y = 10;
    
    // Normal usage seems fine
    std::cout << "Macro: " << MAX_MACRO(x, y) << "\n";
    std::cout << "Safe:  " << max_safe(x, y) << "\n";

    // The Danger Zone
    int i = 5;
    int j = 10;
    
    std::cout << "\n--- Danger Zone ---\n";
    
    // We expect j to be returned (10), and then incremented to 11.
    // Let's see what max_safe does:
    int safe_result = max_safe(i++, j++); 
    std::cout << "Safe result: " << safe_result << " (i=" << i << ", j=" << j << ")\n";
    
    // Reset
    i = 5; j = 10;
    
    // Let's see what the macro does:
    // It expands to: ((i++) > (j++) ? (i++) : (j++))
    // j++ evaluates to 10 (and increments j to 11). 
    // The condition (5 > 10) is false.
    // It returns (j++). Wait, j is now 11, so it returns 11 and increments j to 12!
    int macro_result = MAX_MACRO(i++, j++);
    std::cout << "Macro result: " << macro_result << " (i=" << i << ", j=" << j << ")\n";
    std::cout << "Notice how j was incremented TWICE by the macro!\n";

    return 0;
}
