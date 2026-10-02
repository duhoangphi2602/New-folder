# Exercises: Mutexes

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Missing Key
Look at this code for an I2C transaction protected by a Mutex:
```cpp
void vTaskReadSensor() {
    while(1) {
        xSemaphoreTake(i2c_mutex, portMAX_DELAY);
        
        if (read_i2c_hardware() == I2C_ERROR_DISCONNECTED) {
            printf("Sensor Failed!\n");
            continue; // Skip the rest of the loop and try again
        }
        
        process_data();
        xSemaphoreGive(i2c_mutex);
        
        vTaskDelay(100);
    }
}
```
**Task:** This code contains a fatal, system-destroying bug. Assume the physical sensor wire accidentally unplugs. What exactly will happen to the entire RTOS system on the next loop cycle, and why?

## Exercise 2: Timeouts
When taking a mutex, you pass a timeout value: `xSemaphoreTake(mutex, timeout)`.
Most examples use `portMAX_DELAY`, which means "wait infinitely".
Alternatively, you can pass `100` (wait for 100 Ticks/ms), or `0`.
**Task:** Describe a real-world scenario where you would pass `0` as the timeout. What does passing `0` instruct the RTOS to do if the Mutex is currently held by someone else?
