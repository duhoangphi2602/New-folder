/**
 * @file pointer_struct_demo.cpp
 * @brief Demonstrates the Arrow operator and C++ References for structs.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <string_view>

struct Player {
    int health;
    int ammo;
    float x_pos;
    float y_pos;
};

// 1. C-Style Pointer (Uses arrow operator, requires null check)
void heal_player_ptr(Player* p) {
    if (p != nullptr) {
        p->health = 100; // Arrow operator
    }
}

// 2. C++ Style Reference (Uses dot operator, null-safe)
void heal_player_ref(Player& p) {
    p.health = 100; // Dot operator
}

int main() {
    std::cout << "--- Pointer to Struct ---\n\n";

    Player p1 = {.health = 10, .ammo = 50, .x_pos = 0.0f, .y_pos = 0.0f};

    std::cout << "Initial health: " << p1.health << "\n";

    // Call using pointer (must pass address)
    heal_player_ptr(&p1);
    std::cout << "After heal (ptr): " << p1.health << "\n";

    p1.health = 20; // Take damage

    // Call using reference (just pass the variable)
    heal_player_ref(p1);
    std::cout << "After heal (ref): " << p1.health << "\n";

    return 0;
}
