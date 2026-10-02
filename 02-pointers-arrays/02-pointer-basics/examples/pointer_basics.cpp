/*
 * Language: C++17
 * Target: PC
 * Build: g++ -std=c++17 pointer_basics.cpp -o pointer_basics
 * Run: ./pointer_basics
 * Expected output:
 *   value = 42
 *   Address of value: 0x...
 *   ptr holds address: 0x...
 *   Dereferenced: *ptr = 42
 *   After *ptr = 100: value = 100
 *   sizeof(arr) = 20
 *   sizeof(ptr) = 8  (or 4 on 32-bit)
 * What to learn: Fundamental pointer operations — address-of, dereference, sizeof trap
 */

#include <cstdint>
#include <cstdio>

int main() {
    // --- Basic pointer operations ---
    int value = 42;
    int* ptr = &value;  // ptr stores the address of value

    std::printf("value = %d\n", value);
    std::printf("Address of value: %p\n", static_cast<void*>(&value));
    std::printf("ptr holds address: %p\n", static_cast<void*>(ptr));
    std::printf("Dereferenced: *ptr = %d\n", *ptr);

    // Write through pointer
    *ptr = 100;
    std::printf("After *ptr = 100: value = %d\n", value);

    // --- sizeof trap ---
    int arr[5] = {1, 2, 3, 4, 5};
    int* arr_ptr = arr;  // array decays to pointer

    std::printf("sizeof(arr) = %zu\n", sizeof(arr));       // Total array size
    std::printf("sizeof(ptr) = %zu\n", sizeof(arr_ptr));   // Pointer size only!

    return 0;
}
