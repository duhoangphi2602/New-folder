/**
 * @file cpp_io_demo.cpp
 * @brief Demonstrates C++ streams and operator overloading.
 * 
 * Target: PC / Embedded Linux
 * Standard: C++17
 */

#include <iostream>
#include <iomanip> // Needed for formatting like hex

struct SensorData {
    int id;
    float temp;
};

// The absolute best feature of std::cout: 
// You can teach it how to print your custom structs!
std::ostream& operator<<(std::ostream& os, const SensorData& data) {
    os << "[Sensor " << data.id << "] Temp: " << data.temp << "C";
    return os; // Return stream to allow chaining
}

int main() {
    std::cout << "--- C++ Standard I/O (std::cout) ---\n\n";

    // 1. Automatic Type Safety
    int a = 10;
    double b = 3.14159;
    std::cout << "Integer: " << a << ", Double: " << b << "\n";

    // 2. Formatting requires manipulators (can be verbose)
    int reg_val = 255;
    std::cout << "Hex Register: 0x" 
              << std::hex << std::uppercase << reg_val 
              << std::dec << "\n"; // Must switch back to decimal!

    // 3. Printing Custom Structs seamlessly
    SensorData my_sensor = {42, 28.5f};
    
    // std::cout now magically knows how to print a SensorData object!
    std::cout << "Incoming Data: " << my_sensor << "\n";

    return 0;
}
