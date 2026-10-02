# RTOS Task

## 1. Concept
An RTOS Task is a function that contains an infinite loop, exactly like a bare-metal `main()` function. 
However, an RTOS allows you to have *dozens* of these infinite loops. The RTOS secretly pauses one loop, saves its exact state, and resumes another loop so fast that it gives the illusion of parallel execution.

## 2. Anatomy of a Task Function
An RTOS Task is just a standard C function that takes a `void*` argument and never returns.
```cpp
void SensorTask(void *pvParameters) {
    // 1. Initialization code (runs once)
    setup_sensor();
    
    // 2. The Infinite Loop (The Task's life)
    while(1) {
        read_sensor();
        // 3. MUST block or sleep! (Do not use raw while-loop delays)
        vTaskDelay(pdMS_TO_TICKS(10)); 
    }
}
```

## 3. Creating a Task
To tell the RTOS about your function, you must "Create" the task. In FreeRTOS, this is `xTaskCreate`.
You must provide the RTOS with 4 critical pieces of information:
1. **The Function Pointer:** The name of the function to execute (`SensorTask`).
2. **The Stack Size:** How many bytes of RAM this specific task needs for its local variables.
3. **The Parameters:** An optional `void*` to pass data into the task when it boots.
4. **The Priority:** A number dictating how important this task is compared to others. (Higher number = Higher priority in FreeRTOS).

## 4. The Task Control Block (TCB)
When you call `xTaskCreate`, the RTOS allocates a small C `struct` in RAM called the **TCB (Task Control Block)**. The TCB holds:
- The Task's Priority.
- The Task's current State (Running, Sleeping, Suspended).
- A pointer to the top of the Task's private Stack.

## 5. Example
*(See `examples/` for a C++ simulated RTOS task creation structure).*

## 6. The "Sleep" Requirement
In bare-metal, a `while(1)` loop spins as fast as the CPU allows. 
In an RTOS, if a Task spins in a `while(1)` loop without sleeping, it will consume 100% of the CPU. If its priority is high, it will permanently starve all lower-priority tasks (they will never execute). 
**Rule:** Every RTOS task must eventually call a blocking API (like `vTaskDelay`, or waiting on a Queue) to yield the CPU to other tasks.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
