# Solutions: Ownership & Lifetime

## Solution 1: Communicating Intent
**Answer:**
1. **Non-Owning (Read-Only Observer):** The function uses a `const` reference. It is just looking at the configuration data and promises not to modify it or destroy it.
2. **Non-Owning (Mutable Observer):** The function uses a raw pointer. It does not own the buffer (it will not call `delete`), but it is allowed to modify the contents of the buffer.
3. **Exclusive Ownership:** The function uses `std::unique_ptr` passed by value. This function is taking absolute control of the Logger. When this function (or the class it stores it in) dies, the Logger will be destroyed.

## Solution 2: The RTOS Trap
**Answer:** `max_retries` is a local variable on the Stack. As soon as `boot_system()` finishes executing, its Stack Frame is destroyed. The RTOS scheduler runs the tasks asynchronously. When `NetworkTask` eventually wakes up and tries to read the pointer to `max_retries`, it will be reading a dead memory address containing garbage data.
**Fix:** To fix it without the Heap, `max_retries` must have a Lifetime that lasts forever. You must declare it as `static int max_retries = 5;` (which moves it into the `.data` segment instead of the Stack), or pass it by value if the RTOS API allows it.
