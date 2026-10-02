# Exercises: Heap Fragmentation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The O(N) Latency Problem
Aside from crashing due to lack of contiguous space, fragmentation causes a severe performance penalty known as non-deterministic execution time. 
**Task:** Explain mechanistically why `malloc(50)` takes much longer to execute on a heavily fragmented heap compared to a fresh, newly booted heap. 

## Exercise 2: Desktop Illusion
A Python developer joins your embedded team. They argue: *"My Python scripts run on Linux servers for years, creating and destroying millions of objects of different sizes, and they never crash from fragmentation. Why can't we just do that in C++ on this Cortex-M4?"*
**Task:** Identify the hardware component that Linux servers have, but the Cortex-M4 lacks, that completely eliminates the symptom of physical fragmentation. How does it work?
