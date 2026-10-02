# Solutions: Event Groups

## Solution 1: The Multiple Semaphore Trap
**Answer:** The flaw is strict sequential blocking. The Main task is forced to wait for WiFi *before* it is even allowed to look at the GPS semaphore. 
If the system is running and the GPS randomly disconnects, the GPS task will try to reset the `gps_sem`. However, if the WiFi is still connected, the Main task is currently sleeping on `wifi_sem`. It is permanently stuck on line 1, completely blind to the fact that the GPS failed on line 2. 
Worse, if you try to take multiple Mutexes in sequence across different tasks (Task A takes X then Y; Task B takes Y then X), you mathematically guarantee a "Deadlock" where both tasks freeze forever waiting for the other. 
An Event Group solves this by letting a task wait for multiple disparate events simultaneously in a single, atomic OS call.

## Solution 2: The Timeout Mechanism
**Answer:** The `result` variable holds the state of the Event Group at the exact moment the function returned. 
If IMU (Bit 1) is `1`, and BATTERY (Bit 0) is `0`, the binary representation is `0000...0010`. The integer value returned is **2**.
To check if the timeout occurred, you must compare the returned bits against the bits you were actually waiting for. If they don't match, a timeout happened:
```cpp
EventBits_t expected_bits = (IMU_READY | BATTERY_GOOD); // Binary 3
if ((result & expected_bits) != expected_bits) {
    // Timeout occurred! Not all bits were set.
    abort_takeoff();
}
```
