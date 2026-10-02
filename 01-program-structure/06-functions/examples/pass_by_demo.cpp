/**
 * @file pass_by_demo.cpp
 * @brief Demonstrates the difference between passing by value, pointer, and reference.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

struct LargeData {
    int id;
    double values[100]; // 800 bytes
};

// 1. Pass by Value (Makes a copy of the 804-byte struct!)
void process_value(LargeData data) {
    data.id = 99; // Modifies local copy
}

// 2. Pass by Pointer (Passes an 8-byte address)
void process_ptr(LargeData* data) {
    if (data != nullptr) {
        data->id = 99; // Modifies original
    }
}

// 3. Pass by Reference (Passes an 8-byte address under the hood)
void process_ref(LargeData& data) {
    data.id = 99; // Modifies original
}

int main() {
    LargeData my_data;
    my_data.id = 1;

    std::cout << "Initial ID: " << my_data.id << "\n";

    process_value(my_data);
    std::cout << "After pass by value: " << my_data.id << " (Unchanged)\n";

    process_ptr(&my_data);
    std::cout << "After pass by ptr: " << my_data.id << " (Changed)\n";

    my_data.id = 1; // reset

    process_ref(my_data);
    std::cout << "After pass by ref: " << my_data.id << " (Changed)\n";

    return 0;
}
