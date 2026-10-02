/**
 * @file pool_alloc_demo.cpp
 * @brief Demonstrates overriding 'new' to use a Memory Pool.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <array>
#include <new>

// A highly simplified Memory Pool Manager
class PacketPool {
    static constexpr int POOL_SIZE = 3;
    struct Block {
        uint8_t data[256];
        bool in_use = false;
    };
    std::array<Block, POOL_SIZE> blocks;

public:
    void* allocate() {
        for (auto& b : blocks) {
            if (!b.in_use) {
                b.in_use = true;
                std::cout << "  [POOL] Allocated block at address: " << &b << "\n";
                return &b;
            }
        }
        std::cout << "  [POOL] OUT OF MEMORY!\n";
        throw std::bad_alloc();
    }

    void deallocate(void* ptr) {
        // Simple pointer matching to find the block
        for (auto& b : blocks) {
            if (ptr == &b) {
                b.in_use = false;
                std::cout << "  [POOL] Freed block at address: " << &b << "\n";
                return;
            }
        }
    }
};

// Global Pool Instance
PacketPool global_pool;

class NetworkPacket {
public:
    int id;
    
    // Override 'new' to intercept heap allocations for this specific class!
    void* operator new(size_t size) { return global_pool.allocate(); }
    
    // Override 'delete'
    void operator delete(void* ptr) { global_pool.deallocate(ptr); }
};

int main() {
    std::cout << "--- Memory Pool Custom Allocator Demo ---\n\n";

    // These use our custom pool, NOT the system heap!
    NetworkPacket* p1 = new NetworkPacket();
    NetworkPacket* p2 = new NetworkPacket();
    NetworkPacket* p3 = new NetworkPacket();

    std::cout << "\nAttempting to allocate a 4th packet...\n";
    try {
        NetworkPacket* p4 = new NetworkPacket(); // Will fail!
    } catch (...) {
        std::cout << "  Caught Out of Memory error safely.\n";
    }

    std::cout << "\nFreeing p2...\n";
    delete p2;

    std::cout << "\nAllocating again...\n";
    NetworkPacket* p5 = new NetworkPacket(); // Takes the spot freed by p2

    return 0;
}
