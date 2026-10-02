# Interview Questions: Mutex vs Semaphore vs Atomic

## 1. During a code review, you see a developer using a Binary Semaphore to protect a shared I2C bus between two tasks. What is the danger of this approach?
**Answer:** While it might function mechanically like a Mutex, a Binary Semaphore lacks "Priority Inheritance". If a low-priority task holds the Semaphore, and a high-priority task wants it, a medium-priority task can preempt the low-priority task and run forever. The high-priority task is now indirectly blocked by the medium-priority task. This is called Priority Inversion. A Mutex solves this by temporarily boosting the low-priority task's priority. Semaphores should never be used for resource protection.

## 2. In a Bare-Metal (no RTOS) Super Loop architecture, do you need Mutexes or Semaphores?
**Answer:** No. Mutexes and Semaphores are Operating System constructs; they rely on an RTOS Scheduler to put tasks into a Blocked state. In Bare-Metal, everything runs sequentially in a single `while(1)` loop, so Task-vs-Task Race Conditions are impossible. However, you DO still need Critical Sections or `std::atomic` to protect data shared between the main Super Loop and Hardware ISRs.

## 3. Can `std::atomic` be used to protect a 256-byte data buffer?
**Answer:** Physically, no. The CPU memory bus is usually 32-bit or 64-bit; it cannot read/write 256 bytes in a single indivisible clock cycle. If you declare `std::atomic<MyLargeStruct>`, the C++ compiler will silently inject a software lock (usually a global Mutex) to protect it. This is extremely dangerous in embedded systems, because if an ISR accesses that variable, it will hit the hidden Mutex and crash the system. Atomics should only be used for standard primitive types (`int`, `bool`, pointers).
