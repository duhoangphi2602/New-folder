/**
 * @file smart_pointer_demo.cpp
 * @brief Demonstrates std::unique_ptr and zero-overhead memory safety.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <memory>

class Sensor {
public:
    Sensor()  { std::cout << "  [Sensor Constructed on Heap]\n"; }
    ~Sensor() { std::cout << "  [Sensor Destroyed. Heap memory freed.]\n"; }
    void read() { std::cout << "  Reading data...\n"; }
};

void unsafe_raw_pointer() {
    Sensor* ptr = new Sensor();
    
    // Imagine an error happens here
    std::cout << "  [!] Error! Returning early...\n";
    return; // FATAL: delete is never called. Memory leak!
    
    delete ptr;
}

void safe_smart_pointer() {
    // std::make_unique is the modern C++ way to allocate memory safely
    std::unique_ptr<Sensor> ptr = std::make_unique<Sensor>();
    
    ptr->read(); // Use the -> operator just like a normal pointer
    
    std::cout << "  [!] Error! Returning early...\n";
    return; // SAFE: C++ automatically calls ptr's destructor here!
}

int main() {
    std::cout << "--- Smart Pointers Demo ---\n\n";

    std::cout << "1. Unsafe Raw Pointer:\n";
    unsafe_raw_pointer();

    std::cout << "\n2. Safe std::unique_ptr:\n";
    safe_smart_pointer();

    return 0;
}
