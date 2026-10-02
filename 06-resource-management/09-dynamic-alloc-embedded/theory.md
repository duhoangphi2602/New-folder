# Dynamic Allocation in Embedded Systems

## 1. Concept
While Hard Real-Time Systems strictly ban the Heap, Soft Real-Time Systems (IoT, UI displays, network gateways) often use it. However, they do not use it casually like a Desktop PC. They follow strict architectural patterns to contain the danger.

## 2. When is the Heap Necessary?
You *must* use the Heap when the size of the data is completely unknowable at Compile-Time, and the "Worst-Case Scenario" is too large to fit in static RAM.
- **Parsing JSON/XML:** A cloud server might send a 50-byte response or a 5,000-byte response. You cannot statically allocate a 5,000-byte buffer for every possible network socket, or you would run out of RAM instantly.
- **TLS/SSL Certificates:** Cryptographic handshakes require massive temporary buffers that are only needed for a few seconds during connection setup. 
- **Dynamic GUIs:** Creating UI elements (buttons, menus) on a touchscreen where the user can open/close complex windows.

## 3. The 3 Safe Patterns

### Pattern 1: Allocate Once, Run Forever
During the boot sequence (`main()` before the RTOS starts), you read configuration data from an EEPROM to determine how many sensors are attached. You then dynamically allocate the exact number of objects needed. 
Once the system enters the main loop, you **never** call `malloc` or `new` again, and you **never** call `free` or `delete`. 
**Why it's safe:** Zero fragmentation (because you never free), and zero latency during the actual mission loop.

### Pattern 2: The Monolithic Temporary Buffer
When a TLS connection is initiated, you dynamically allocate a massive 16KB buffer on the Heap. The TLS handshake takes 3 seconds. Once the handshake is complete, you immediately `free` the entire 16KB block.
**Why it's safe:** You are allocating one giant block and immediately freeing it. You are not mixing tiny allocations and frees, which minimizes fragmentation risk.

### Pattern 3: Custom Allocators (FreeRTOS `heap_4.c`)
Standard C `malloc` is not thread-safe and fragments easily. RTOSs provide custom implementations. For example, FreeRTOS `heap_4.c` is thread-safe and includes a "Coalescing" algorithm. If you free two 100-byte blocks that happen to be next to each other physically, `heap_4.c` mathematically merges them back into a 200-byte block, actively fighting fragmentation.

## 4. Modern C++ Rule (Never use Raw New/Delete)
If you apply one of the safe patterns above, you **must** use C++11 Smart Pointers (`std::unique_ptr`). In the TLS Temporary Buffer example, if the handshake fails on step 3 out of 10, the function will `return` early. If you used raw `malloc`, that 16KB is leaked forever. `std::unique_ptr` guarantees the temporary buffer is freed even on failure.

## 5. Example
*(See `examples/` for an architecture simulation of Pattern 1).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
