# Mutex vs Semaphore vs Atomic

## 1. The Decision Matrix

When faced with a concurrency problem, use the following rules to choose the correct tool.

### Rule 1: Are you inside a Hardware Interrupt (ISR)?
If **YES**:
- **NEVER use a Mutex.** (ISRs cannot own Mutexes. It will crash).
- To signal a Task: Use a **Binary/Counting Semaphore** (`FromISR` API).
- To share a small variable (int, bool) with a Task: Use `std::atomic`.
- To share a large buffer with a Task: Use an RTOS Queue or StreamBuffer.

### Rule 2: Are you sharing a hardware peripheral (e.g., I2C, SPI) between two Tasks?
- **Use a Mutex.** Task A locks the bus, finishes the transaction, and unlocks it. Task B will safely sleep while Task A is working.

### Rule 3: Are you modifying a global struct/array between two Tasks?
- **Use a Mutex.** It is the safest way to protect large data blocks.

### Rule 4: Are you modifying a single primitive variable (e.g., counter, state flag) between two Tasks?
- **Use `std::atomic`.** It is drastically faster than a Mutex and doesn't require involving the RTOS Scheduler.

### Rule 5: Do you need to run a block of code with absolute zero chance of ANY interruption?
- **Use a Critical Section.** (e.g., `taskENTER_CRITICAL()`). 
- *Warning:* This disables all hardware interrupts. Only use this for operations taking less than 10 microseconds.

## 2. Summary Table

| Tool | Primary Purpose | ISR Safe? | Blocks (Sleeps) the Task? | Ownership? | Priority Inheritance? |
| :--- | :--- | :--- | :--- | :--- | :--- |
| **Mutex** | Protection (Mutual Exclusion) | **NO! (CRASH)** | YES | YES | YES |
| **Binary Semaphore** | Synchronization (Signaling) | YES (`FromISR`) | YES | NO | NO |
| **std::atomic** | Lock-Free Primitive Protection | YES | NO (Spins) | NO | NO |
| **Critical Section** | Absolute Preemption Prevention | YES | NO (Disables HW) | N/A | N/A |

## 3. The Golden Rule of Semaphores
Never use a Semaphore to protect shared data. 
If Task A takes a Semaphore to access data, and a higher priority Task B attempts to take it, Task B will block. However, because Semaphores do NOT have Priority Inheritance (Topic 13), Task A can be preempted by a medium priority Task C. Task B is now stuck waiting for Task C, causing a catastrophic **Priority Inversion**. Always use a Mutex for data protection.

## 4. Exercises
Please proceed to the `exercises/` folder.

## 5. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
