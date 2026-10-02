#pragma once

#include <cstdint>

// A simple data structure representing sensor readings
struct SensorData {
    std::uint16_t temperature;
    std::uint16_t humidity;
};

// Function declarations (prototypes)
SensorData read_sensor();
void       print_data(const SensorData& data);
