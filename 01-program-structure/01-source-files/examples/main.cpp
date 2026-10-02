/*
 * Language: C++17
 * Target: PC
 * Build: g++ -std=c++17 main.cpp implementation.cpp -o source_demo
 * Run: ./source_demo
 * Expected output:
 *   Temp: 2500 Hum: 6000
 * What to learn: How header/source file separation works
 */

#include "header_example.hpp"
#include <iostream>

int main() {
    SensorData data = read_sensor();
    print_data(data);
    return 0;
}
