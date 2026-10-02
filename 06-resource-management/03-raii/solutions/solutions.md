# Solutions: RAII

## Solution 1: Finding the Bug
**Answer:** The code disables hardware interrupts at the very beginning. If `data == NULL`, the function returns early. If the checksum fails, the function returns early. In both of these failure cases, `enable_interrupts()` is completely bypassed! The microcontroller will continue running forever with all hardware interrupts disabled. The RTOS scheduler will stop, timers will stop, and the system will essentially freeze. 

## Solution 2: Implementing RAII
**Answer:**
```cpp
// The RAII Class
class InterruptGuard {
public:
    InterruptGuard()  { disable_interrupts(); }
    ~InterruptGuard() { enable_interrupts(); }
    // Best practice: delete copy constructor
    InterruptGuard(const InterruptGuard&) = delete;
};

// The safe function
void flash_firmware(uint8_t* data) {
    InterruptGuard guard; // Interrupts disabled automatically!
    
    if (data == nullptr) {
        return; // Safe! guard's destructor is called, interrupts re-enabled.
    }
    
    if (check_checksum(data) == false) {
        return; // Safe! guard's destructor is called, interrupts re-enabled.
    }
    
    write_to_flash(data);
    
} // Safe! guard's destructor is called, interrupts re-enabled.
```
