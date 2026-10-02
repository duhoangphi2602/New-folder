# Solutions: Memory Padding

## Solution 1: Calculate the Padding
**Answer:**
1. **Memory Map (Original):**
   - Bytes 0-1: `id` (2 bytes)
   - Bytes 2-3: *Padding* (2 bytes, so `timestamp` aligns to 4)
   - Bytes 4-7: `timestamp` (4 bytes)
   - Byte 8: `is_active` (1 byte)
   - Bytes 9-11: *Padding* (3 bytes, so `next_node` aligns to 4)
   - Bytes 12-15: `next_node` (4 bytes)
2. **Total Size:** 16 bytes.
3. **Rewritten (Largest to Smallest):**
   ```cpp
   struct SensorNode {
       uint32_t timestamp;  // 4 bytes
       void*    next_node;  // 4 bytes
       uint16_t id;         // 2 bytes
       uint8_t  is_active;  // 1 byte
       // Trailing Padding  // 1 byte (Total must be multiple of 4)
   };
   ```
   **New Total Size:** 12 bytes.

## Solution 2: The `alignas` Keyword
**Answer:** Hardware subsystems operate on chunks of memory. A CPU Cache often loads RAM in 16-byte or 32-byte "Cache Lines". A DMA (Direct Memory Access) controller might require memory buffers to be strictly aligned to 32-byte boundaries so it can burst-read the data efficiently over the hardware bus. Using `alignas(32)` forces the compiler to inject padding before the struct so that it lands perfectly on the boundary required by that specific silicon hardware.
