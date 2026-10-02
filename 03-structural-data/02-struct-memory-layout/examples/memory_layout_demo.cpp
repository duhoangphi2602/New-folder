/**
 * @file memory_layout_demo.cpp
 * @brief Demonstrates the sequential memory layout of struct members.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdint>

struct OrderedData {
    uint32_t first;
    uint32_t second;
    uint32_t third;
};

int main() {
    std::cout << "--- Struct Memory Layout ---\n\n";

    OrderedData data;
    
    // Calculate the byte offsets of each member from the start of the struct
    uintptr_t base_addr = reinterpret_cast<uintptr_t>(&data);
    uintptr_t addr1     = reinterpret_cast<uintptr_t>(&data.first);
    uintptr_t addr2     = reinterpret_cast<uintptr_t>(&data.second);
    uintptr_t addr3     = reinterpret_cast<uintptr_t>(&data.third);

    std::cout << "Base address of struct : " << &data << "\n";
    std::cout << "Offset of 'first'      : " << (addr1 - base_addr) << " bytes\n";
    std::cout << "Offset of 'second'     : " << (addr2 - base_addr) << " bytes\n";
    std::cout << "Offset of 'third'      : " << (addr3 - base_addr) << " bytes\n";

    std::cout << "\nNotice how the members are laid out strictly sequentially in memory!\n";

    return 0;
}
