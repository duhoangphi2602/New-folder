# Solutions: Mutexes

## Solution 1: The Missing Key
**Answer:** If the sensor wire unplugs, `read_i2c_hardware()` returns an error. The `if` statement executes, prints the error, and hits the `continue` keyword. 
The `continue` keyword instantly forces the `while(1)` loop to jump back to the top, completely skipping the `xSemaphoreGive(i2c_mutex)` line. 
The task never returned the key! On the next loop, it calls `xSemaphoreTake()` again. Because the task already holds the key (and didn't give it back), the OS puts the task to sleep infinitely waiting for the key. Any other task that needs the I2C bus will also be put to sleep infinitely. The entire I2C subsystem permanently deadlocks.
**The Fix:** You must *always* give the mutex back on all error/exit paths.
```cpp
if (error) { 
    xSemaphoreGive(i2c_mutex); // MUST GIVE IT BACK
    continue; 
}
```

## Solution 2: Timeouts
**Answer:** Passing `0` means **"Try to get the lock, but if it's busy, do NOT go to sleep. Immediately return failure and let me keep executing."**
**Scenario:** You have a low-priority task that updates a blinking Status LED, but it also wants to occasionally print "I'm alive" to the UART console. You don't want the LED blinking to freeze just because the UART is busy.
```cpp
// Pass 0. Don't block.
if (xSemaphoreTake(uart_mutex, 0) == pdTRUE) {
    printf("Alive");
    xSemaphoreGive(uart_mutex);
} else {
    // UART is busy. Oh well, skip printing this time.
}
blink_led(); // LED always blinks smoothly.
```
