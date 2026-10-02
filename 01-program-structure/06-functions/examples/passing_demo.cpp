/*
 * Language: C++17
 * Target: PC
 * Build: g++ -std=c++17 passing_demo.cpp -o passing_demo
 * Run: ./passing_demo
 * Expected output:
 *   After pass-by-value:     5
 *   After pass-by-pointer:   6
 *   After pass-by-reference: 7
 * What to learn: The difference between the three parameter passing modes
 */

#include <iostream>

// Pass by value — receives a COPY
void by_value(int x) {
    x++;
}

// Pass by pointer — receives the ADDRESS
void by_pointer(int* x) {
    (*x)++;
}

// Pass by reference — receives an ALIAS
void by_reference(int& x) {
    x++;
}

int main() {
    int a = 5;

    by_value(a);
    std::cout << "After pass-by-value:     " << a << '\n';  // Still 5

    by_pointer(&a);
    std::cout << "After pass-by-pointer:   " << a << '\n';  // Now 6

    by_reference(a);
    std::cout << "After pass-by-reference: " << a << '\n';  // Now 7

    return 0;
}
