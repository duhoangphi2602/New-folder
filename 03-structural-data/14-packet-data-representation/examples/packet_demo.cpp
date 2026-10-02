/**
 * @file packet_demo.cpp
 * @brief Simulates creating, sending, and parsing a binary network packet.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>
#include <vector>

// --- 1. SENDER: Serialization (Host to Network) ---
std::vector<uint8_t> serialize_packet(uint8_t type, uint32_t payload) {
    std::vector<uint8_t> buffer;
    
    // Header
    buffer.push_back(0xAA); // Start byte
    buffer.push_back(type);
    
    // Payload (32-bit, Forced to Big Endian for Network transmission)
    buffer.push_back((payload >> 24) & 0xFF); // MSB
    buffer.push_back((payload >> 16) & 0xFF);
    buffer.push_back((payload >> 8)  & 0xFF);
    buffer.push_back((payload >> 0)  & 0xFF); // LSB
    
    // Footer
    buffer.push_back(0x55); // End byte
    
    return buffer;
}

// --- 2. RECEIVER: Deserialization (Network to Host) ---
void parse_packet(const std::vector<uint8_t>& rx_buffer) {
    // Basic validation
    if (rx_buffer.size() < 7 || rx_buffer[0] != 0xAA || rx_buffer.back() != 0x55) {
        std::cout << "Packet Invalid or Corrupted!\n";
        return;
    }
    
    uint8_t type = rx_buffer[1];
    
    // Reconstruct 32-bit payload safely from Big Endian bytes
    uint32_t payload = (rx_buffer[2] << 24) |
                       (rx_buffer[3] << 16) |
                       (rx_buffer[4] << 8)  |
                       (rx_buffer[5] << 0);
                       
    std::cout << "Parsed Packet - Type: " << (int)type << ", Payload: " << payload << "\n";
}

int main() {
    std::cout << "--- Binary Packet Data Representation ---\n\n";

    // 1. We want to send a sensor reading of 500,000
    uint32_t sensor_reading = 500000;
    
    std::cout << "Sending Sensor Reading: " << sensor_reading << "\n";

    // 2. Serialize it into raw bytes
    std::vector<uint8_t> transmitted_bytes = serialize_packet(1, sensor_reading);
    
    std::cout << "Raw Bytes over Wire: ";
    for (uint8_t b : transmitted_bytes) {
        std::cout << std::hex << (int)b << " ";
    }
    std::cout << std::dec << "\n\n";

    // 3. Receive and parse it
    parse_packet(transmitted_bytes);

    return 0;
}
