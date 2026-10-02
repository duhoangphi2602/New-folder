# Exercises: Memory Ordering

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Relaxed Counter
You have an RTOS system with 5 identical Worker Tasks. Whenever a task successfully processes a network packet, it increments a global statistic counter:
`total_packets_processed.fetch_add(1, std::memory_order_relaxed);`
A completely separate UI Task occasionally wakes up, reads `total_packets_processed`, and prints it to an LCD screen.
**Task:** Is it safe to use `memory_order_relaxed` here? What is the absolute worst-case scenario of using `relaxed` in this specific context?

## Exercise 2: Why not just volatile?
A developer is confused by `memory_order_release`. They say: *"Why do we need this complicated memory ordering stuff? Why don't we just declare the payload data and the flag as `volatile`? Doesn't `volatile` force the compiler to write to RAM in the exact order the code is written?"*
**Task:** Identify the fundamental flaw in the developer's logic regarding modern CPU hardware architecture.
