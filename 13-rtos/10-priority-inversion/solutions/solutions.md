# Solutions: Priority Inversion

## Solution 1: Semaphore vs Mutex
**Answer:** You must use `xSemaphoreCreateMutex()`. 
While both act as a lock, only a **Mutex** includes the **Priority Inheritance** mechanism. 
If you use a Binary Semaphore, it has no concept of "Ownership". The RTOS does not track which task took it. Therefore, if the High Priority task blocks on the Binary Semaphore, the RTOS has no idea that the Low Priority task is the one holding it up, so the RTOS cannot boost the Low Priority task. You will be completely vulnerable to a Priority Inversion crash. Mutexes track ownership specifically to execute the Priority Inheritance algorithm.

## Solution 2: The Priority Ceiling
**Answer:**
- **Advantage:** It is much faster and simpler for the RTOS Kernel to execute. The OS doesn't have to dynamically calculate who is waiting and who owns what; it just blindly boosts the priority the instant the lock is taken. It prevents Priority Inversion before it even starts.
- **Disadvantage:** It destroys system efficiency and Real-Time responsiveness. If a Low Priority task takes the lock, it is instantly boosted to Priority 3. It will now needlessly preempt and block Priority 2 tasks, even if the actual Priority 3 task is currently asleep and doesn't even want the lock! Priority Inheritance is superior because it only boosts priorities *reactively*, strictly when a collision actually occurs.
