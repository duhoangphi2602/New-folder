/**
 * @file typedef_using_demo.cpp
 * @brief Demonstrates the clarity of 'using' over 'typedef' for function pointers.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// A dummy hardware function we want to pass around
void handle_sensor_data(int sensor_id, float value) {
    std::cout << "Sensor " << sensor_id << " reads " << value << "\n";
}

// ---------------------------------------------------------
// 1. The C Way (typedef)
// ---------------------------------------------------------
// Syntax: typedef ReturnType (*AliasName)(ParamTypes...);
typedef void (*LegacyCallback_t)(int, float);

void register_callback_legacy(LegacyCallback_t cb) {
    std::cout << "[Legacy] Executing callback...\n";
    cb(1, 25.5f);
}

// ---------------------------------------------------------
// 2. The Modern C++ Way (using)
// ---------------------------------------------------------
// Syntax: using AliasName = ReturnType (*)(ParamTypes...);
using ModernCallback_t = void (*)(int, float);

void register_callback_modern(ModernCallback_t cb) {
    std::cout << "[Modern] Executing callback...\n";
    cb(2, 42.0f);
}

int main() {
    std::cout << "--- typedef vs using ---\n\n";

    // Both aliases mathematically represent the exact same function pointer type.
    
    register_callback_legacy(handle_sensor_data);
    
    std::cout << "\n";

    register_callback_modern(handle_sensor_data);

    return 0;
}
