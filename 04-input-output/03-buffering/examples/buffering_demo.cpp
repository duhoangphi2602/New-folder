/**
 * @file buffering_demo.cpp
 * @brief Demonstrates manual buffer flushing and stderr.
 * 
 * Target: PC
 * Standard: C++17
 */

#include <iostream>
#include <cstdio>
#include <thread>
#include <chrono>

void delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int main() {
    std::cout << "--- I/O Buffering ---\n\n";

    // 1. Line Buffering Trap
    // In many terminals, this text won't appear instantly because there's no \n
    std::printf("Processing chunk 1... ");
    
    // We delay to simulate a long task or a potential crash
    delay(1000); 
    
    // Now we force the buffer to dump to the screen manually
    std::fflush(stdout); 
    
    delay(1000);
    std::printf("Done!\n"); // The \n flushes automatically

    // 2. Unbuffered output (stderr)
    // stderr is strictly unbuffered by default. It prints instantly.
    std::fprintf(stderr, "[ERROR] This bypasses the buffer and prints immediately!\n");

    // 3. C++ equivalents
    std::cout << "C++ Line buff trap... ";
    std::cout << std::flush; // Equivalent to fflush(stdout)
    
    std::cerr << "C++ Unbuffered Error\n"; // Equivalent to stderr

    return 0;
}
