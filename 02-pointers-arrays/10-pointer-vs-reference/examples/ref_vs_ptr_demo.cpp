/**
 * @file ref_vs_ptr_demo.cpp
 * @brief Demonstrates passing objects by pointer vs reference.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>

struct LargeConfig {
    int id;
    int data[100]; // Assume this is a heavy object
};

// 1. Pass by Reference (Mandatory)
// Use this when the function REQUIRES the object to function.
void print_id(const LargeConfig& config) {
    std::cout << "Config ID (via reference): " << config.id << "\n";
}

// 2. Pass by Pointer (Optional)
// Use this when the function can still do something useful even if the object is missing.
void print_id_optional(const LargeConfig* config_ptr) {
    if (config_ptr == nullptr) {
        std::cout << "No config provided, using default ID: 0\n";
    } else {
        std::cout << "Config ID (via pointer)  : " << config_ptr->id << "\n";
    }
}

int main() {
    std::cout << "--- Reference vs Pointer APIs ---\n\n";

    LargeConfig my_cfg;
    my_cfg.id = 42;

    // Passing to reference API
    print_id(my_cfg);

    // Passing to pointer API
    print_id_optional(&my_cfg);

    // Passing null to pointer API
    std::cout << "\nAttempting optional call:\n";
    print_id_optional(nullptr);

    // print_id(nullptr); // COMPILE ERROR: Cannot pass null to a reference!

    return 0;
}
