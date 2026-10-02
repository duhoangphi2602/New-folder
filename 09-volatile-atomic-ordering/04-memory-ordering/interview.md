# Interview Questions: Memory Ordering

## 1. What does `std::memory_order_seq_cst` do, and why is it the default in C++?
**Answer:** `seq_cst` stands for Sequential Consistency. It is the strictest memory ordering available. It establishes a massive, global synchronization barrier, ensuring that all threads in the system observe all memory operations in the exact same chronological order. It is the default in C++ because it provides the most intuitive, "least surprising" behavior for developers, making multithreaded code behave exactly as one would logically expect. The downside is that it is the most computationally expensive ordering, often inserting heavy hardware barriers that degrade pipeline performance.

## 2. Explain the "Release-Acquire" pairing. What specific concurrency pattern is it designed for?
**Answer:** The Release-Acquire pairing is specifically designed for the Producer-Consumer pattern, where one thread prepares data and then sets a flag to notify another thread. 
- The Producer uses `memory_order_release` when setting the flag. This acts as a barrier preventing any previous memory writes (the payload data) from being reordered *after* the flag is set. 
- The Consumer uses `memory_order_acquire` when reading the flag. This prevents any subsequent memory reads (reading the payload data) from being reordered to happen *before* the flag check. 
Together, they guarantee that when the Consumer sees the flag change, the payload data is mathematically guaranteed to be fully written and visible in memory.

## 3. If `std::memory_order_relaxed` provides absolutely no synchronization or ordering guarantees, what is its purpose?
**Answer:** Its purpose is pure performance for isolated atomic operations. While it provides no ordering relative to *other* variables, it still guarantees that the operation on *that specific variable* is completely atomic (free from Race Conditions). This is perfect for simple statistics counters (e.g., `error_count++`). We don't care if the CPU increments the error count before or after writing some text to a UART buffer, we just need to guarantee that if two tasks increment the error count simultaneously, no counts are lost. `relaxed` achieves this with exactly zero barrier overhead.
