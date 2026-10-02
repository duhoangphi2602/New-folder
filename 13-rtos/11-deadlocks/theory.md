# Deadlocks

## 1. The Deadly Embrace
Imagine two tasks: `Task_A` and `Task_B`.
Imagine two Mutexes: `Mutex_X` and `Mutex_Y`.

1. `Task_A` wakes up and successfully takes `Mutex_X`.
2. *PREEMPTION!* `Task_B` wakes up and successfully takes `Mutex_Y`.
3. `Task_B` now needs `Mutex_X` to continue. It calls `Take(Mutex_X)`. Because `Task_A` holds it, the RTOS puts `Task_B` to sleep.
4. `Task_A` resumes execution. It now needs `Mutex_Y` to continue. It calls `Take(Mutex_Y)`. Because `Task_B` holds it, the RTOS puts `Task_A` to sleep.

**The Result:** 
- `Task_A` is sleeping, waiting for `Task_B` to release `Y`.
- `Task_B` is sleeping, waiting for `Task_A` to release `X`.
Both tasks are permanently blocked. They will never wake up. This is a **Deadlock**.

## 2. The Four Coffman Conditions
In computer science, a Deadlock *mathematically cannot occur* unless ALL FOUR of these conditions are true simultaneously:
1. **Mutual Exclusion:** The resource can only be held by one task at a time (e.g., a Mutex).
2. **Hold and Wait:** A task is allowed to hold onto one Mutex while simultaneously going to sleep to wait for a second Mutex.
3. **No Preemption of Locks:** The RTOS cannot forcefully rip `Mutex_X` out of `Task_A`'s hands to give it to `Task_B`. (Task A must willingly give it back).
4. **Circular Wait:** Task A waits for Task B, and Task B waits for Task A.

## 3. How to Prevent Deadlocks
To prevent a Deadlock, you only need to break *one* of the four conditions.

**Strategy 1: Break "Circular Wait" (The Ordered Lock Rule)**
The most common and robust fix. You establish a strict, system-wide rule: *If any task needs both Mutex X and Mutex Y, they MUST ALWAYS be taken in alphabetical order.*
- `Task_A` takes X, then takes Y.
- `Task_B` takes X, then takes Y. (It is forbidden to take Y then X).
If `Task_B` takes X, and `Task_A` wakes up, `Task_A` cannot even get past the first line of code. It goes to sleep. `Task_B` is free to take Y, finish, and release both. Deadlock is mathematically impossible.

**Strategy 2: Break "Hold and Wait" (The Timeout Rule)**
Never use `portMAX_DELAY` (infinite sleep) when taking a second Mutex.
If `Task_A` holds X, and tries to take Y with a timeout of 100ms. If it fails, `Task_A` MUST instantly release X, wait a random amount of time, and try the whole process again from the beginning.

## 4. Example
*(See `examples/` for the Ordered Lock architecture).*

## 5. Exercises
Please proceed to the `exercises/` folder.

## 6. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
