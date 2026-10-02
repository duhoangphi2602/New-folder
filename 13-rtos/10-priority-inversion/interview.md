# Interview Questions: Priority Inversion

## 1. Describe the exact 3-task scenario that causes a Priority Inversion.
**Answer:** A Priority Inversion requires three tasks: High, Medium, and Low priority. 
First, the Low task takes a Mutex to access a shared resource. Second, the High task wakes up, needs the Mutex, and is placed in the Blocked state by the RTOS because the Low task holds it. Third, the Medium task wakes up. Because Medium is a higher priority than Low, the RTOS preempts the Low task and gives the CPU to the Medium task. 
The Medium task is now running freely, while the High task is permanently stuck waiting for the Low task to finish. The system's priority has inverted: Medium is effectively running at a higher priority than High.

## 2. How does "Priority Inheritance" solve Priority Inversion?
**Answer:** Priority Inheritance is an algorithm built into RTOS Mutexes. When the High priority task attempts to take a Mutex that is currently owned by the Low priority task, the RTOS temporarily elevates the Low task's priority to match the High task. Now running at High priority, the Low task cannot be preempted by the Medium task. It swiftly finishes its critical section, releases the Mutex, and is immediately dropped back to its original Low priority. The RTOS then gives the Mutex and the CPU to the High priority task.

## 3. Can a Binary Semaphore experience Priority Inversion? Can it use Priority Inheritance to fix it?
**Answer:** Yes, a system relying on Binary Semaphores for mutual exclusion can absolutely experience Priority Inversion. However, a Binary Semaphore **cannot** use Priority Inheritance to fix it. Priority Inheritance requires the RTOS to know exactly which task currently "owns" the lock so it can boost that specific task's priority. Binary Semaphores do not track ownership; they only track a binary 1/0 state. Therefore, you must strictly use Mutexes (which do track ownership) to protect shared resources in a multi-priority RTOS system.
