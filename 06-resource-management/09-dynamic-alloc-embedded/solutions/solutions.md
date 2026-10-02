# Solutions: Safe Dynamic Allocation

## Solution 1: The Wi-Fi Disconnect Bug
**Answer:** The code likely uses raw `malloc` or `new`. When the Wi-Fi router is unplugged, the download function hits a network timeout error and returns early. The developer forgot to put a `free()` statement inside the network timeout error handler. Therefore, every time the Wi-Fi disconnects, the machine permanently leaks 2KB of RAM. After a few disconnects, the machine runs out of memory and crashes.
**The Fix:** Wrap the 2KB buffer in a `std::unique_ptr`. When the Wi-Fi disconnects and the function returns early, the `unique_ptr`'s destructor will automatically run and free the 2KB buffer, making the memory leak impossible.

## Solution 2: Static vs Allocate-Once
**Answer:** `std::array` requires the size to be hardcoded at compile-time. If you build a firmware binary using `std::array<Sensor, 4>`, that binary can *only* ever support 4 sensors. If a customer buys a 5-sensor model, you have to compile a brand new binary for them. 
The "Allocate Once" dynamic pattern allows the company to compile **one single universal binary**. During boot, the binary checks a hardware EEPROM to see if it's running on a 4-sensor model or an 8-sensor model, and dynamically allocates the exact amount needed. Once allocated, it acts exactly like static memory (it is never freed).
