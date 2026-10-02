# Solutions: Heap Fragmentation

## Solution 1: The Root Cause
**Answer:** **Developer B is right.** External fragmentation is caused by the interleaved allocation and deallocation of randomly sized chunks over time, creating a Swiss-cheese effect in the Heap. Developer A is describing a **Memory Leak**. While memory leaks will also cause `malloc` to fail, they are a logical bug (forgetting to free memory), whereas fragmentation is an architectural flaw (the memory is perfectly freed, but mechanically unusable).

## Solution 2: Internal vs External
**Answer:**
1. When you request a block for a 10-byte command, you are forced to take a 128-byte block. **118 bytes of RAM are wasted.** This is **Internal Fragmentation** (wasted space *inside* the allocated block).
2. It is acceptable because it is **100% deterministic**. The aerospace engineer knows exactly how many 128-byte blocks exist in the pool. They know the system will *never* crash unpredictably due to external holes. The system trades RAM efficiency (wasting 118 bytes) for the absolute guarantee of long-term mechanical stability.
