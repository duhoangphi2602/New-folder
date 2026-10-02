# Priority Inversion

## 1. The Setup
You have three tasks and one Mutex protecting the I2C bus:
- **Task HIGH (Priority 3):** Needs the I2C bus to read critical sensors.
- **Task MED (Priority 2):** Does a long, 500ms math calculation. Doesn't care about I2C.
- **Task LOW (Priority 1):** Needs the I2C bus to read non-critical sensors.

## 2. The Inversion Sequence (The Disaster)
1. **Task LOW** wakes up, calls `xSemaphoreTake(I2C_Mutex)`, and starts using the I2C bus.
2. *PREEMPTION!* **Task HIGH** wakes up. It needs the I2C bus. It calls `xSemaphoreTake(I2C_Mutex)`. 
3. Because Task LOW holds the lock, the RTOS puts Task HIGH to sleep (Blocked).
4. Task LOW resumes to finish its I2C work so it can return the lock.
5. *PREEMPTION!* **Task MED** wakes up to do its 500ms math calculation.
6. The RTOS sees two Ready tasks: Task MED (Prio 2) and Task LOW (Prio 1). Task HIGH (Prio 3) is still Blocked.
7. The RTOS gives the CPU to **Task MED**.

## 3. The Result
**Task MED** runs for 500ms. 
Because Task MED is running, **Task LOW** is preempted and frozen. 
Because Task LOW is frozen, it cannot release the Mutex.
Because the Mutex is not released, **Task HIGH** is permanently blocked.

*The logical priority of the system has inverted!* 
Task MED (Priority 2) is currently holding up Task HIGH (Priority 3). The highest priority task in the system is being starved by a medium priority task.

## 4. The Solution: Priority Inheritance
FreeRTOS Mutexes have a built-in feature called **Priority Inheritance** to fix this.
When Task HIGH tries to take the Mutex and sees that Task LOW holds it, the RTOS Kernel intervenes:
1. The RTOS temporarily "boosts" Task LOW's priority up to Priority 3 (inheriting Task HIGH's priority).
2. Task LOW resumes.
3. When Task MED wakes up (Prio 2), the RTOS says: *"No, Task LOW is currently Prio 3."* Task MED is denied the CPU.
4. Task LOW finishes the I2C transaction rapidly and gives the Mutex back.
5. The RTOS instantly drops Task LOW back down to Priority 1.
6. The RTOS wakes up Task HIGH, gives it the Mutex, and normal execution resumes!

## 5. Example
*(See `examples/` for a timeline visualization).*

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
