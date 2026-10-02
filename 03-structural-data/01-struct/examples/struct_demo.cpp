/**
 * @file struct_demo.cpp
 * @brief Demonstrates basic struct declaration and initialization.
 * 
 * Target: PC
 * Standard: C++20 (for designated initializers)
 */

#include <iostream>
#include <cstdint>

// 1. Define the blueprint
struct GpsCoordinate {
    float latitude;
    float longitude;
    float altitude;
};

// Function taking the grouped data
void print_location(const GpsCoordinate& coord) {
    std::cout << "Lat: " << coord.latitude 
              << ", Lon: " << coord.longitude 
              << ", Alt: " << coord.altitude << "m\n";
}

int main() {
    std::cout << "--- Struct Basics ---\n\n";

    // 2. Uninitialized (bad practice)
    GpsCoordinate loc1;
    loc1.latitude = 37.7749f;
    loc1.longitude = -122.4194f;
    loc1.altitude = 15.0f;
    std::cout << "Location 1:\n";
    print_location(loc1);

    // 3. C++11 Uniform Initialization (order matters)
    GpsCoordinate loc2{40.7128f, -74.0060f, 10.0f};
    std::cout << "\nLocation 2:\n";
    print_location(loc2);

    // 4. C++20 Designated Initializers (Safest, most readable)
    GpsCoordinate loc3{
        .latitude = 51.5074f,
        .longitude = -0.1278f,
        .altitude = 24.0f
    };
    std::cout << "\nLocation 3:\n";
    print_location(loc3);

    return 0;
}
