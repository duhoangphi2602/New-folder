# Priorities & Preemption

## 1. The Golden Rule of Priorities
In FreeRTOS, a higher number means a higher priority. (Priority 3 > Priority 1).
**The Golden Rule:** *The RTOS Scheduler will ALWAYS, unconditionally, execute the highest-priority Ready task. A lower-priority task will NEVER execute if a higher-priority task is in the Ready state.*

## 2. Preemption
Preemption is the act of forcefully taking the CPU away from one task to give it to another.
Imagine Task A (Priority 1) is running a massive 500ms `for` loop to calculate a fractal.
Suddenly, a hardware interrupt fires indicating a UART byte arrived. The ISR wakes up Task B (Priority 3). 
When the ISR finishes, the RTOS Scheduler sees that Task B (Prio 3) is now Ready. It instantly preempts Task A (saves its context) and runs Task B. Task A is frozen mid-calculation. When Task B finishes and goes back to sleep, the OS restores Task A.
**Preemption guarantees Real-Time responsiveness.** Task B doesn't have to wait 500ms for Task A to finish its math.

## 3. Task Starvation
Preemption is a double-edged sword. 
If Task B (Priority 3) is a poorly written task that contains a `while(1)` loop without *any* blocking calls (like `vTaskDelay`), it will permanently remain in the Ready/Running state.
Because of the Golden Rule, the RTOS will give Task B 100% of the CPU. Task A (Priority 1) will be permanently frozen. This is called **Task Starvation**. 
*Rule of thumb: High-priority tasks must do their job extremely fast and then immediately Block (sleep) to let lower-priority tasks run.*

## 4. How to Assign Priorities (Rate Monotonic Scheduling)
Beginners often assign Priorities based on "Human Importance". (e.g., "The WiFi is the most important feature of this product, so it gets Priority 5! The LED blink is dumb, so it gets Priority 1").
This is fundamentally wrong and will crash your system.
Priorities should be assigned based on **Timing Deadlines** (Rate Monotonic Scheduling):
- **Shortest Deadline = Highest Priority:** The motor control loop MUST run exactly every 1ms, or the drone crashes. It gets Priority 5.
- **Longest Deadline = Lowest Priority:** The WiFi task takes 2 seconds to upload data. It can be preempted a hundred times, and nobody will notice if it takes 2.1 seconds instead. It gets Priority 1.

## 5. Example
*(See `examples/` for a priority assignment architecture).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
