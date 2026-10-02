# Exercises: Software Timers

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Frozen Timers
You have three Auto-Reload Software Timers running:
- Timer 1: Blinks a Red LED every 100ms.
- Timer 2: Blinks a Blue LED every 200ms.
- Timer 3: Checks an I2C sensor every 500ms.
Inside the Callback for Timer 3, you write this code:
```cpp
void Sensor_Callback(TimerHandle_t xTimer) {
    // Wait for the I2C Bus to be free (Timeout 1000ms)
    xSemaphoreTake(i2c_mutex, pdMS_TO_TICKS(1000));
    read_sensor();
    xSemaphoreGive(i2c_mutex);
}
```
**Task:** When the system runs, the Red and Blue LEDs blink perfectly for a few seconds. Suddenly, another task locks the I2C bus for 500ms. Instantly, the Red and Blue LEDs completely freeze and stop blinking. Why? Explain the architectural mistake made in `Sensor_Callback`.

## Exercise 2: Timer ID and Callback Sharing
You are building an industrial controller with **8 identical conveyor belts**. You want a timeout timer for each belt.
Instead of writing 8 separate callback functions (`Belt1_Callback`, `Belt2_Callback`, etc.), you want to write exactly ONE callback function that handles all 8 timers.
**Task:** Look at the `xTimerCreate` API in the example file. How can you use the "Timer ID" parameter to achieve this? How does the single callback function know *which* of the 8 timers expired?
