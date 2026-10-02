# Heap Fragmentation

## 1. Concept
When you call `malloc(size)`, the allocator searches the Heap for a **contiguous** (unbroken) block of free RAM that is at least `size` bytes long.
If you constantly allocate and free chunks of *varying sizes*, the free RAM becomes split into hundreds of tiny, disconnected "holes" sandwiched between active allocations. This is called **External Fragmentation**.

## 2. Why
If you have 10KB of total free RAM, but it is fragmented into 1,000 tiny holes of 10 bytes each, a call to `malloc(20)` will FAIL! The allocator needs 20 *contiguous* bytes, and the largest hole is only 10 bytes. 
On a PC, the OS can pause your game, move the memory around to merge the holes (Defragmentation), and resume. On a bare-metal microcontroller, memory cannot be moved because pointers would become invalid, and moving memory takes too much CPU time for a real-time system.

## 3. The Fragmentation Lifecycle

Imagine a 10-byte Heap: `[ F F F F F F F F F F ]` (F = Free)
1. `A = malloc(3);` -> `[ A A A F F F F F F F ]`
2. `B = malloc(4);` -> `[ A A A B B B B F F F ]`
3. `C = malloc(3);` -> `[ A A A B B B B C C C ]`
4. `free(B);`       -> `[ A A A F F F F C C C ]`

**The Crisis:**
You currently have **4 bytes** of free RAM. 
If you now call `D = malloc(5);`, what happens? 
The system crashes. The memory is there, but the hole isn't big enough.

## 4. Example
*(See `examples/` for a programmatic simulation of a fragmentation failure).*

## 5. Embedded usage (The Memory Pool Solution)
How do we get the flexibility of dynamic allocation without the fragmentation? We use a **Memory Pool** (often provided by an RTOS like FreeRTOS).
Instead of allowing random sizes, a Memory Pool divides a large static array into exactly equal-sized blocks (e.g., exactly 64-byte blocks).
- Need 10 bytes? You get a 64-byte block.
- Need 60 bytes? You get a 64-byte block.
Because every block is exactly the same size, any freed block perfectly fits any new request. **External Fragmentation is mathematically eliminated.**

## 6. Trade-offs (Internal vs External Fragmentation)
The Memory Pool solves *External* Fragmentation (wasting space between blocks) but introduces *Internal* Fragmentation (wasting space inside the block). 
If you request 10 bytes from a 64-byte Memory Pool block, 54 bytes inside that block are wasted. However, in safety-critical engineering, we gladly accept a known, deterministic waste of RAM (Internal) to completely eliminate the unpredictable, system-crashing threat of External Fragmentation.

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
