/**
 * @file static_demo.cpp
 * @brief Demonstrates the various uses of static and inline.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

// 1. File-scope static (Internal Linkage)
// This variable cannot be accessed by any other .cpp file using 'extern'
static int hardware_status = 0;

// 2. C++17 inline variable
inline constexpr int MAX_RETRIES = 3;

// 3. Function-scope static
void process_data() {
    // This variable is initialized ONCE. It lives in .bss/.data, not the stack.
    static int call_count = 0;
    
    call_count++;
    std::cout << "Function called " << call_count << " times.\n";
}

// 4. Class static
class Sensor {
public:
    static int active_sensors; // Shared across all instances
    Sensor() { active_sensors++; }
    ~Sensor() { active_sensors--; }
};

// Definition of the class static variable
int Sensor::active_sensors = 0;

int main() {
    process_data(); // prints 1
    process_data(); // prints 2
    process_data(); // prints 3

    std::cout << "\nSensor Count: " << Sensor::active_sensors << "\n";
    {
        Sensor s1;
        Sensor s2;
        std::cout << "Sensor Count: " << Sensor::active_sensors << "\n";
    } // s1 and s2 destroyed here
    
    std::cout << "Sensor Count: " << Sensor::active_sensors << "\n";

    return 0;
}
