# Solutions: malloc() and free()

## Solution 1: The Sizeof Bug
**Answer:** `malloc(10)` allocates exactly 10 bytes. An `int` is typically 4 bytes. Therefore, the developer only allocated enough room for 2.5 integers! When they write to `arr[5]`, they are writing 20 bytes past the start of the allocation, corrupting the heap.
It must be written as: `malloc(10 * sizeof(int));`

## Solution 2: The Hidden Leak
**Answer:** If the packet header is `0xFF`, the function prints an error and hits `return;`. It completely skips the `free(decompressed);` line. 1,024 bytes (1KB) of RAM are permanently leaked every single time a bad packet arrives. An attacker sending bad packets could crash the device in seconds.
