#include "header_example.hpp"
#include <iostream>

// Function definitions (implementations)
SensorData read_sensor() {
    // In real embedded code, this would read from hardware registers.
    // Here we return mock data for demonstration.
    return SensorData{2500, 6000};
}

void print_data(const SensorData& data) {
    std::cout << "Temp: " << data.temperature
              << " Hum: " << data.humidity << '\n';
}
