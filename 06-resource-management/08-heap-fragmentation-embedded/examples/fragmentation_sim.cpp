/**
 * @file fragmentation_sim.cpp
 * @brief A basic simulation to demonstrate how contiguous memory fails.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <vector>
#include <string>

// Simulating a tiny 20-byte Heap
class TinyHeap {
    std::string memory = "FFFFFFFFFFFFFFFFFFFF"; // 20 'F'ree bytes

public:
    void print() const {
        std::cout << "  Heap: [" << memory << "]\n";
    }

    bool allocate(int id, int size) {
        // Search for a contiguous block of 'size' F's
        std::string target(size, 'F');
        size_t pos = memory.find(target);
        
        if (pos == std::string::npos) {
            std::cout << "  [!] Out of Memory! Failed to allocate " << size << " bytes for ID " << id << ".\n";
            return false;
        }
        
        // Fill it with the ID number
        for (int i = 0; i < size; ++i) {
            memory[pos + i] = std::to_string(id)[0];
        }
        return true;
    }

    void free_block(int id) {
        char target_char = std::to_string(id)[0];
        for (char& c : memory) {
            if (c == target_char) c = 'F';
        }
    }
};

int main() {
    std::cout << "--- Heap Fragmentation Simulation ---\n\n";
    TinyHeap heap;
    heap.print();

    std::cout << "\n1. Allocating 3 blocks (A=5, B=10, C=5)...\n";
    heap.allocate(1, 5);
    heap.allocate(2, 10);
    heap.allocate(3, 5);
    heap.print(); // [11111222222222233333]

    std::cout << "\n2. Freeing block B (10 bytes)...\n";
    heap.free_block(2);
    heap.print(); // [11111FFFFFFFFFF33333]

    std::cout << "\n3. Allocating D=4 bytes and E=4 bytes...\n";
    heap.allocate(4, 4);
    heap.allocate(5, 4);
    heap.print(); // [1111144445555FF33333]

    std::cout << "\n4. Freeing block A and E...\n";
    heap.free_block(1);
    heap.free_block(5);
    heap.print(); // [FFFFF4444FFFFFF33333]

    std::cout << "\n5. ATTEMPTING TO ALLOCATE 10 BYTES...\n";
    // We have 11 'F's total (5 + 6). But the largest contiguous hole is 6!
    heap.allocate(9, 10); 
    heap.print();

    return 0;
}
