/**
 * @file string_view_demo.cpp
 * @brief Demonstrates fast substrings and passing by value.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <string_view>

// Pass std::string_view by VALUE (it is only 2 registers wide)
void log_message(std::string_view msg) {
    // msg.length() is known instantly without iterating over the string
    std::cout << "[LOG (" << msg.length() << " chars)]: " << msg << "\n";
}

int main() {
    std::cout << "--- std::string_view ---\n\n";

    // 1. Passing a string literal
    // The compiler counts the characters at compile time! Zero runtime overhead.
    log_message("System initializing...");

    // 2. Fast substrings (Zero Allocation!)
    const char raw_buffer[] = "ERROR: Sensor timeout detected on port 3";
    std::string_view view_of_buffer(raw_buffer);
    
    // We want just the "Sensor timeout" part.
    // .substr() does NOT copy the string. It just returns a new view 
    // with an adjusted pointer and length.
    std::string_view substring = view_of_buffer.substr(7, 14);
    
    log_message(substring);

    return 0;
}
