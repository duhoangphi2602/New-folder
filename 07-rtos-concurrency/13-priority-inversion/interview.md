# Interview Questions: Priority Inversion

## 1. What is Priority Inversion, and what three tasks are required to cause it?
**Answer:** Priority Inversion is a concurrency bug where a high-priority task is indirectly blocked from executing by a medium-priority task. It requires:
1. A Low-Priority Task holding a shared resource.
2. A High-Priority Task blocked waiting for that resource.
3. A Medium-Priority Task (that doesn't need the resource) preempting the Low-Priority task. 
Because the Medium task preempts the Low task, the Low task cannot release the resource, leaving the High task permanently blocked. 

## 2. Explain Priority Inheritance. Does it solve Priority Inversion permanently?
**Answer:** Priority Inheritance is an RTOS algorithm where a Low-Priority task temporarily "inherits" (is boosted to) the priority of the highest-priority task that is waiting for a Mutex it currently holds. This prevents Medium-priority tasks from preempting the Low-priority task. Once the Mutex is released, the Low task's priority returns to normal. It mathematically prevents Priority Inversion, but it adds processing overhead to the OS Scheduler.

## 3. Why shouldn't you use a Semaphore to protect a shared variable?
**Answer:** Because Semaphores are signaling mechanisms, not protection mechanisms. Crucially, Semaphores do not track "Ownership" (the RTOS does not record which task "took" the Semaphore). Because ownership is unknown, the RTOS cannot apply Priority Inheritance. Using a Semaphore to protect shared data leaves the system completely vulnerable to Priority Inversion crashes. Always use a Mutex.
