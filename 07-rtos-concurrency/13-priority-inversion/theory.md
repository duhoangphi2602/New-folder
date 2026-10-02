# Priority Inversion

## 1. Concept (The Mars Pathfinder Bug)
Priority Inversion requires 3 Tasks: High (H), Medium (M), and Low (L). It also requires one shared resource, protected by a Lock (Mutex or Semaphore).

**The Deadly Sequence:**
1. **Low Task (L)** starts running. It acquires the Lock for the shared Data Bus.
2. *[Context Switch]* - **High Task (H)** wakes up. It needs the Data Bus! It tries to acquire the Lock. Because **L** has the Lock, **H** goes to sleep (Blocked). 
3. *[Context Switch]* - **L** resumes, trying to finish its work to release the Lock.
4. *[Context Switch]* - **Medium Task (M)** wakes up. **M** does *not* need the Data Bus. **M** just wants to do long mathematical calculations. 

**THE INVERSION:**
- The Scheduler looks at the Ready tasks: **M** (Ready) and **L** (Ready). 
- **H** is ignored because it is Blocked.
- The Scheduler picks **M**, because Medium > Low priority.
- **M** runs for 500 milliseconds. 
- While **M** runs, **L** is paused. Because **L** is paused, it cannot release the Lock. 
- Because the Lock is held, **H** remains asleep.

**Result:** A High-Priority task is waiting 500 milliseconds for a Medium-Priority task to finish. The priorities have inverted! If **H** has a strict 50ms deadline, the system crashes.

## 2. The Solution: Priority Inheritance
Modern RTOS Mutexes contain a built-in algorithm called **Priority Inheritance**. 

When **H** tries to acquire the Mutex and sees that **L** holds it, the RTOS does something magical:
**It temporarily boosts L's priority to match H!**

Now, **L** is running with High Priority. When **M** wakes up, the Scheduler compares **L (Boosted to High)** vs **M (Medium)**. The Scheduler tells **M** to go back to sleep. **L** finishes its work, releases the Mutex, and its priority instantly drops back to Low. **H** grabs the Mutex and runs. **M** is forced to wait. The system is saved!

## 3. Mutex vs Semaphore (The Warning)
- A **Mutex** tracks "Ownership". The RTOS knows exactly which task holds the Mutex, so it knows exactly which task to boost.
- A **Semaphore** does NOT track ownership. Therefore, Semaphores **do not have Priority Inheritance**. If you use a Semaphore to protect a shared resource, your system is vulnerable to Priority Inversion.

## 4. Example
*(See `examples/` for a programmatic simulation of the Mars Pathfinder bug).*

## 5. Exercises
Please proceed to the `exercises/` folder.

## 6. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
