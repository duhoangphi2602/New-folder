# Exercises: Event Groups

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Multiple Semaphore Trap
A junior developer doesn't know what Event Groups are. They need the Main Task to wait for both the WiFi and the GPS to initialize.
They create two Binary Semaphores: `wifi_sem` and `gps_sem`.
They write the Main Task like this:
```cpp
void vTaskMain() {
    // Wait for WiFi
    xSemaphoreTake(wifi_sem, portMAX_DELAY);
    
    // Once WiFi is done, wait for GPS
    xSemaphoreTake(gps_sem, portMAX_DELAY);
    
    start_app();
}
```
**Task:** This actually works for a simple initialization sequence. However, in a continuous `while(1)` loop where both WiFi and GPS can disconnect and reconnect randomly, taking multiple Semaphores sequentially like this is mathematically proven to cause catastrophic system Deadlocks. Explain the architectural flaw. (Hint: What happens if GPS reconnects first, but WiFi doesn't?)

## Exercise 2: The Timeout Mechanism
Look at this code for a drone waiting to arm its motors:
```cpp
EventBits_t result = xEventGroupWaitBits(
    flight_group, 
    (IMU_READY | BATTERY_GOOD), 
    pdFALSE, 
    pdTRUE, 
    5000 / portTICK_PERIOD_MS // 5-second timeout
);
```
If the 5 seconds expire, the function wakes up the task anyway and returns the current state of the bits.
**Task:** Assume the IMU initialized successfully (bit 1 is set), but the battery is dead (bit 0 is 0). When the task wakes up after 5 seconds, what exact integer value will the `result` variable hold? Write a C++ `if` statement to check if the timeout occurred.
