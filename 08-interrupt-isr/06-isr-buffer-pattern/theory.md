# The ISR Buffer Pattern

## 1. The Core Problem
Suppose a UART peripheral receives 1 byte every 10 microseconds. It holds this byte in a hardware register (`UART_DATA`). If you do not read that byte within 10us, the next byte arrives and permanently overwrites it (an Overrun Error).
You cannot process the data inside the ISR (it takes too long).
You cannot pass the address of `UART_DATA` to a Task (it will be overwritten before the Task wakes up).
You must copy the data into RAM quickly, and let the Task process the RAM.

## 2. Approach 1: RTOS Queues (The Slow Way)
FreeRTOS provides `xQueueSendFromISR`. The ISR reads the byte and sends it into the Queue. The Task reads from the Queue.
**The Catch:** RTOS Queues are slow. Every time you push 1 byte into a Queue, the RTOS copies the memory, disables interrupts, updates internal linked lists, and checks priorities. Doing this every 10us will consume 80% of your CPU power just managing the Queue. Queues are for low-frequency control messages, NOT high-bandwidth data streams.

## 3. Approach 2: The Ring Buffer (The Fast Way)
Instead of using an RTOS Queue, we use a raw C++ `std::array` acting as a **Ring Buffer** (Circular Buffer), paired with a **Binary Semaphore**.

**The Producer (The ISR):**
1. Byte arrives. ISR fires.
2. ISR copies byte into `std::array[head_index]`.
3. ISR increments `head_index`. (If it reaches the end, it wraps back to 0).
4. ISR exits instantly. (Takes ~10 CPU cycles).
*Note: The ISR does NOT fire a Semaphore for every single byte!*

**The Trigger:**
When a specific event happens (e.g., the UART detects a `\n` newline character, or 100 bytes have been received), the ISR finally calls `xSemaphoreGiveFromISR()`.

**The Consumer (The Task):**
1. The Task is asleep, waiting on the Semaphore.
2. The Semaphore fires. The Task wakes up.
3. The Task enters a `while(tail_index != head_index)` loop.
4. The Task reads bytes out of the `std::array[tail_index]`, incrementing `tail_index`, processing the full packet.

## 4. Why this is the Gold Standard
This pattern provides the absolute lowest possible latency for the hardware (the ISR just copies a byte and increments an integer), while safely batching the heavy processing into a low-priority software Task. The RTOS Scheduler is only invoked once per packet, not once per byte.

## 5. FreeRTOS Stream Buffers
In modern FreeRTOS, they built this exact pattern into the OS! It is called a **Stream Buffer** (or Message Buffer). It uses a lock-free Ring Buffer under the hood and is highly optimized for ISR-to-Task data streams.

## 6. Example
*(See `examples/` for a C++ implementation of an ISR-safe Ring Buffer).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
