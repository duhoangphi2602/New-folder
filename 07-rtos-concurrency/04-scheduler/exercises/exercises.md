# Exercises: The Scheduler

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Race
Task A (Priority 10) is currently RUNNING. 
Task B (Priority 5) is READY. 
Task C (Priority 15) is BLOCKED waiting for 100ms. 
**Task:** 
1. The SysTick interrupt fires. Which task will the Scheduler pick to run? 
2. 100ms later, the SysTick interrupt fires again and notices Task C's wait is over. Which task will the Scheduler pick to run now?

## Exercise 2: While(1) vs vTaskDelay
Task A (Priority 2) contains: `while(1) { do_math(); }`
Task B (Priority 2) contains: `while(1) { do_math(); vTaskDelay(10); }`
Task C (Priority 1) contains: `while(1) { do_math(); }`
**Task:** Explain exactly how CPU time is distributed among these three tasks by the FreeRTOS Scheduler. Will Task C ever run?
