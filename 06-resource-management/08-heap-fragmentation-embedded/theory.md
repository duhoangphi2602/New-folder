# Heap Fragmentation

## 1. Concept
When you `malloc` memory, the OS finds a contiguous block. When you `free` memory, that block becomes a "hole". Over time, as thousands of variable-sized blocks are allocated and freed at different times, the Heap becomes fragmented—like swiss cheese.

Imagine a Heap with 1,000 bytes of free space.
You request: `malloc(500)`.
**Result:** FATAL ERROR (Out of Memory).
**Why?** Because those 1,000 bytes of free space are split into 10 separate holes of 100 bytes each. You have enough *total* memory, but you do not have enough *contiguous* memory.

## 2. The Mechanics (Visualized)

```text
1. INITIAL STATE (10KB Free)
[---------------------- 10KB FREE ----------------------]

2. ALLOCATE 3 BLOCKS (3KB, 4KB, 3KB)
[  3KB (A)  ][    4KB (B)    ][  3KB (C)  ]

3. FREE BLOCK B
[  3KB (A)  ][---- 4KB FREE ----][  3KB (C)  ]

4. ALLOCATE 2KB (D). (It goes into the 4KB hole)
[  3KB (A)  ][ 2KB (D) ][- 2KB FREE -][  3KB (C)  ]

5. ATTEMPT TO ALLOCATE 3KB (E)
Total Free RAM = 2KB. 
Request = 3KB. 
FAIL! (Standard Out of Memory)

6. (Alternative) FREE BLOCK A
[--- 3KB FREE ---][ 2KB (D) ][- 2KB FREE -][  3KB (C)  ]
Total Free RAM = 5KB.
Request = 4KB.
FAIL! (Fragmentation! We have 5KB free, but the biggest hole is only 3KB).
```

## 3. Why Desktop OSs Survive
If fragmentation is so bad, why doesn't Google Chrome crash your Windows PC every 10 minutes?
Because Desktop processors have an **MMU (Memory Management Unit)**. Windows can take those fragmented 100-byte physical holes, map them through the MMU, and present them to Chrome as a perfectly contiguous 500-byte block of *Virtual Memory*. 
Most Microcontrollers (Cortex-M) do **NOT** have an MMU. Physical memory is Virtual memory. If it's fragmented physically, it is fragmented permanently.

## 4. Example
*(See `examples/` for a C++ simulation of heap fragmentation over time).*

## 5. Mitigation Strategies
If you must use the Heap in a bare-metal or RTOS environment, you must actively fight fragmentation:
1. **Never allocate/free in a tight loop.** Allocate once at startup and reuse.
2. **Use Memory Pools.** As discussed in Topic 07, fixed-size blocks can never suffer from fragmentation.
3. **Reboot Scheduling.** (The dirty secret of the IoT industry). Some devices intentionally reboot themselves every Sunday at 3:00 AM to completely wipe and defragment the RAM.

## 6. Exercises
Please proceed to the `exercises/` folder.

## 7. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
