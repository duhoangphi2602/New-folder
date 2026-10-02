# Solutions: Software Timers

## Solution 1: The Frozen Timers
**Answer:** The architectural mistake is calling a blocking RTOS API (`xSemaphoreTake` with a 1000ms timeout) inside a Timer Callback.
All software timer callbacks are executed by the exact same hidden RTOS task: the **Timer Service Task (Daemon Task)**. 
When Timer 3 expires, the Daemon Task executes `Sensor_Callback`. Because the I2C bus is locked, `xSemaphoreTake` puts the Daemon Task to sleep (moves it to the Blocked List) for up to 1000ms.
Because the Daemon Task is asleep, it physically cannot execute the callbacks for Timer 1 or Timer 2 when their times expire! All software timers in the entire OS are instantly frozen until the Daemon task wakes up.
**The Fix:** A Timer Callback must never block. If reading the sensor requires waiting for a Mutex, the Timer Callback should simply use `xSemaphoreGive()` or `xQueueSend()` to wake up a *separate, dedicated Sensor Task* which is legally allowed to block and wait for the I2C bus.

## Solution 2: Timer ID and Callback Sharing
**Answer:** When calling `xTimerCreate` for the 8 timers, you assign a unique Integer to the `pvTimerID` parameter for each one (e.g., Belt 1 gets ID `1`, Belt 2 gets ID `2`). You assign all 8 timers to the exact same callback function: `Generic_Belt_Callback`.
When a timer expires, the RTOS passes the `TimerHandle_t` of the expired timer into the callback as an argument.
Inside the callback, you query the ID using `pvTimerGetTimerID(xTimer)`.
```cpp
void Generic_Belt_Callback(TimerHandle_t xTimer) {
    // Cast the void pointer ID back to an integer
    int belt_id = (int) pvTimerGetTimerID(xTimer);
    
    // Now you know exactly which belt timed out!
    stop_motor(belt_id);
    trigger_alarm(belt_id);
}
```
