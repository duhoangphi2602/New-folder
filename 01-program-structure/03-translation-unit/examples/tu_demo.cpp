/**
 * @file tu_demo.cpp
 * @brief Demonstrates viewing a translation unit.
 * 
 * Target: PC
 * Standard: C++17
 * 
 * How to run:
 * Run `g++ -E tu_demo.cpp > preprocessed.txt`
 * Open `preprocessed.txt` to see what the compiler actually compiles!
 */

#define SYSTEM_READY 1
#define MAX_RETRIES 5

#ifdef SYSTEM_READY
    int get_status() { return 1; }
#else
    int get_status() { return 0; }
#endif

int main() {
    int retries = MAX_RETRIES;
    return get_status();
}
