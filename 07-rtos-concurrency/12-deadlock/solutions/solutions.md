# Solutions: Deadlock

## Solution 1: The Watchdog Timer
**Answer:** A Watchdog Timer is usually "kicked" (reset) by a low-priority task (or the Idle Task) to prove that the RTOS Scheduler is still running and that no tasks are starving. 
If Task A and Task B deadlock, their states change from RUNNING to BLOCKED. The RTOS Scheduler is perfectly healthy; it simply bypasses A and B, and gives 100% of the CPU to the Idle Task (and the Watchdog Kicker task). Because the Watchdog task is running perfectly, it continuously resets the timer. The device will **never** reboot, even though the mission-critical A and B tasks are permanently frozen. (This is why advanced RTOS designs require *every* task to check in with a central software watchdog manager).

## Solution 2: C++11 std::lock
**Answer:** `std::lock(m1, m2)` breaks the "Hold and Wait" condition. 
Internally, it tries to lock `m1`. If successful, it tries to lock `m2` using a non-blocking `try_lock()`. If `m2` is currently owned by someone else, `std::lock` does NOT go to sleep while holding `m1`. Instead, it immediately **releases `m1`**, yields the CPU, and then tries the whole process again later. Because it never stubbornly "Holds" one mutex while "Waiting" for another, deadlocks are mathematically avoided.
