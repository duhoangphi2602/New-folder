# Exercises: Priority Inversion

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Semaphore vs Mutex
You are designing an RTOS system. You need to protect an SPI bus shared between a Low Priority task and a High Priority task.
You read the FreeRTOS documentation and see that you can use `xSemaphoreCreateBinary()` or `xSemaphoreCreateMutex()` to create the lock. Both use the exact same `xSemaphoreTake()` and `xSemaphoreGive()` API functions to lock and unlock.
**Task:** Why must you strictly use the Mutex variant instead of the Binary Semaphore to protect this SPI bus? What critical RTOS feature does the Mutex have that the Binary Semaphore lacks?

## Exercise 2: The Priority Ceiling
Priority Inheritance dynamically changes task priorities at runtime. 
There is an alternative, older method to solve Priority Inversion called the **Priority Ceiling Protocol**. 
In this method, when a Mutex is created, it is statically assigned a "Ceiling Priority" (e.g., Priority 3). 
Whenever *any* task takes the Mutex, that task's priority is instantly boosted to Priority 3, even if no other tasks are currently waiting for it.
**Task:** What is one advantage of Priority Ceiling over Priority Inheritance, and what is one massive disadvantage?
