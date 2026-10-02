# Exercises: Task Scheduling

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Idle Task
In FreeRTOS, when you call `vTaskStartScheduler()`, the OS silently creates a hidden task called the `Idle Task` with Priority 0. It is literally just an empty `while(1)` loop.
**Task:** Why is it absolutely mathematically required for the RTOS to create this Idle Task? What would physically happen to the CPU if all user-created tasks (WiFi, Sensor, UI) called `vTaskDelay()` at the exact same time, and the Idle Task did not exist?

## Exercise 2: Blocking vs Polling
Developer A writes a task to wait for a GPIO button press:
```cpp
void vTaskButton(void *pvParams) {
    while(1) {
        if (HAL_GPIO_ReadPin(GPIOA, PIN_0) == 1) { 
            fire_missile(); 
        }
    }
}
```
Developer B writes a task to do the same thing, but uses an RTOS Semaphore (which we will learn later):
```cpp
void vTaskButton(void *pvParams) {
    while(1) {
        // This function tells the OS: "Put me to sleep until the Button ISR gives me the Semaphore"
        xSemaphoreTake(button_sem, portMAX_DELAY);
        fire_missile();
    }
}
```
**Task:** Developer A assigns their task Priority 3. Developer B assigns their task Priority 3. Assume no other tasks have Priority 3.
Explain how the RTOS Scheduler will treat Developer A's task versus Developer B's task during the 10 hours before the user finally presses the button. Which design is correct?
