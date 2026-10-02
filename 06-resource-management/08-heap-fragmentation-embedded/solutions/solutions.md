# Solutions: Heap Fragmentation

## Solution 1: The O(N) Latency Problem
**Answer:** `malloc` operates by walking a Linked List of "Free Blocks". On a fresh heap, the list only has 1 giant item, so `malloc` finds it instantly (O(1)). On a fragmented heap, the list might contain 10,000 tiny blocks. If you ask for 50 bytes, `malloc` has to loop through the linked list, checking the size of every single hole. If it checks 9,999 holes before finding one big enough, that loop burns thousands of CPU cycles. This unpredictable execution time violates the core requirement of Hard Real-Time Systems.

## Solution 2: Desktop Illusion
**Answer:** The Linux server has an **MMU (Memory Management Unit)**. The Cortex-M4 does not. 
The MMU creates a layer of "Virtual Memory" between the software and the physical RAM chip. If physical RAM is heavily fragmented (e.g., 50 holes of 10 bytes), the OS configures the MMU to map those physically scattered holes into a perfectly contiguous 500-byte block in Virtual Memory space. The Python script never sees the physical fragmentation. Because the Cortex-M4 lacks an MMU, physical fragmentation is inescapable.
