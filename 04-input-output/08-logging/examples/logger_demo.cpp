/**
 * @file logger_demo.cpp
 * @brief Demonstrates level-based macro logging.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdio>

// --- Configuration ---
// Change this to 1 to simulate a Production Build!
#define ACTIVE_LOG_LEVEL 2 

// --- Macro Definitions ---
#if ACTIVE_LOG_LEVEL >= 1
    #define LOG_ERROR(fmt, ...) std::printf("[ERROR] %s:%d - " fmt "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#else
    #define LOG_ERROR(fmt, ...)
#endif

#if ACTIVE_LOG_LEVEL >= 2
    #define LOG_DEBUG(fmt, ...) std::printf("[DEBUG] " fmt "\n", ##__VA_ARGS__)
#else
    #define LOG_DEBUG(fmt, ...)
#endif

int main() {
    std::cout << "--- Professional Logging Demo ---\n\n";
    std::cout << "Active Log Level: " << ACTIVE_LOG_LEVEL << "\n\n";

    int temp = 25;
    int max_temp = 80;

    // This is a DEBUG log. It will print if ACTIVE_LOG_LEVEL is 2.
    // If ACTIVE_LOG_LEVEL is 1, the compiler literally deletes this line!
    LOG_DEBUG("Starting temperature read. Current: %d", temp);

    temp = 95;

    if (temp > max_temp) {
        // This is an ERROR log. It always prints, and automatically 
        // injects the file name and line number!
        LOG_ERROR("Temperature critically high! Read: %d", temp);
    }

    return 0;
}
