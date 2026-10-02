/**
 * @file nested_struct_demo.cpp
 * @brief Demonstrates initialization and memory layout of nested structs.
 * 
 * Target: PC
 * Standard: C++20
 */

#include <iostream>
#include <cstdint>
#include <cstddef>

struct Vector3D {
    float x;
    float y;
    float z;
};

struct DroneTelemetry {
    uint32_t timestamp;
    Vector3D position; // Nested struct
    Vector3D velocity; // Nested struct
    uint8_t  battery_percent;
};

int main() {
    std::cout << "--- Nested Structs ---\n\n";

    // C++20 Designated Initializers with nesting
    DroneTelemetry current_state = {
        .timestamp = 10045,
        .position = {.x = 10.0f, .y = 20.0f, .z = 50.0f},
        .velocity = {.x = 0.0f,  .y = 5.0f,  .z = -1.0f},
        .battery_percent = 85
    };

    std::cout << "Drone Altitude (Z): " << current_state.position.z << " meters\n";

    // Let's look at the memory footprint
    std::cout << "\nMemory Analysis:\n";
    std::cout << "Size of Vector3D       : " << sizeof(Vector3D) << " bytes\n";
    std::cout << "Size of DroneTelemetry : " << sizeof(DroneTelemetry) << " bytes\n";
    
    // 4 (timestamp) + 12 (pos) + 12 (vel) + 1 (battery) = 29 bytes.
    // Why is the size of DroneTelemetry 32 bytes?
    // Because the outer struct needs end-padding to align to 4 bytes!
    
    return 0;
}
