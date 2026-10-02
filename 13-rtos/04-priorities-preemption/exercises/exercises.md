# Exercises: Priorities & Preemption

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Greedy Math Task
Task A (Priority 1) executes a massive matrix multiplication that takes 5 full seconds. It contains no `vTaskDelay`.
Task B (Priority 3) checks a button every 10ms.
```cpp
void TaskB() {
    while(1) {
        if (button_pressed()) { fire_laser(); }
        vTaskDelay(10 / portTICK_PERIOD_MS); // Sleep for 10ms
    }
}
```
**Task:** Will Task A's 5-second calculation cause the system to miss the button press? Detail exactly what happens to Task A when the 10ms delay in Task B expires.

## Exercise 2: Same Priority Collision
You create `Task_RedLED` and `Task_BlueLED`. Both have `while(1)` loops that just turn their respective LED on, do some math, and turn it off. 
Neither task contains a `vTaskDelay` blocking call.
You assign BOTH tasks **Priority 2**.
**Task:** What will the RTOS Scheduler do? Will one task starve the other, or will both LEDs blink? What is the specific RTOS term for this scheduling behavior?
