/**
 * @file new_delete_demo.cpp
 * @brief Demonstrates the difference between malloc and new.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdlib>

class Engine {
public:
    Engine()  { std::cout << "  [Engine Constructor] Vroom!\n"; }
    ~Engine() { std::cout << "  [Engine Destructor] Shutting down...\n"; }
};

int main() {
    std::cout << "--- malloc() vs new ---\n\n";

    std::cout << "1. Using malloc() and free():\n";
    Engine* e1 = (Engine*)malloc(sizeof(Engine));
    // Notice: Nothing prints. The Constructor never ran!
    free(e1);
    // Notice: Nothing prints. The Destructor never ran!

    std::cout << "\n2. Using new and delete:\n";
    Engine* e2 = new Engine();
    // Notice: The Constructor runs!
    delete e2;
    // Notice: The Destructor runs!

    std::cout << "\n3. Using arrays:\n";
    Engine* e_array = new Engine[3];
    // Notice: The Constructor runs 3 times!
    delete[] e_array; 
    // Notice: The Destructor runs 3 times!

    return 0;
}
