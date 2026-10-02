/**
 * @file enum_class_demo.cpp
 * @brief Demonstrates scoping, type safety, and memory sizing of enum class.
 * 
 * Target: PC
 * Standard: C++11
 */

#include <iostream>
#include <cstdint>

// 1. Scoping prevents collisions
enum class TrafficLight { GREEN, YELLOW, RED };
enum class NetworkConnection { DISCONNECTED, CONNECTING, GREEN }; // Both have 'GREEN'!

// 2. Memory optimization (Forced to 1 byte)
enum class SmallEnum : uint8_t {
    STATE_A,
    STATE_B
};

int main() {
    std::cout << "--- Enum Class (C++11) ---\n\n";

    TrafficLight light = TrafficLight::GREEN;
    NetworkConnection conn = NetworkConnection::GREEN;

    // 3. Strict Type Safety
    // if (light == conn) { ... } // ERROR: Cannot compare different enum classes!
    // int x = light + 5;         // ERROR: No implicit integer conversion!

    if (light == TrafficLight::GREEN) {
        std::cout << "Light is GREEN.\n";
    }

    std::cout << "Size of normal enum class : " << sizeof(TrafficLight) << " bytes\n";
    std::cout << "Size of optimized enum class: " << sizeof(SmallEnum) << " bytes\n";

    // 4. Explicit cast when needed
    int raw_value = static_cast<int>(light);
    std::cout << "Raw integer value of light: " << raw_value << "\n";

    return 0;
}
