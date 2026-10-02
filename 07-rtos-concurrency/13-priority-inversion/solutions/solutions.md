# Solutions: Priority Inversion

## Solution 1: The Mars Pathfinder Fix
**Answer:** They enabled the **Priority Inheritance** flag on the Mutex that protected the data bus. The VxWorks OS used on Pathfinder had Priority Inheritance built-in, but it was disabled by default to save CPU cycles (since managing dynamic priorities takes a bit of extra overhead). Once NASA enabled Priority Inheritance, the Low priority task was successfully boosted, preventing the Medium priority tasks from blocking it, and the High priority task was able to meet its deadlines.

## Solution 2: Binary Semaphores
**Answer:** The RTOS cannot apply Priority Inheritance because **Semaphores do not track Ownership**. When Task L takes the Semaphore, the Semaphore's count just drops from 1 to 0. The RTOS has no idea *which* task caused the count to drop. When Task H comes along and gets blocked, the RTOS looks at the Semaphore but has no way of knowing that Task L is the one holding it. Because it doesn't know who holds it, it cannot boost their priority. A Mutex explicitly records a pointer to Task L's Task Control Block (TCB) inside the Mutex struct, which is why it can boost it.
