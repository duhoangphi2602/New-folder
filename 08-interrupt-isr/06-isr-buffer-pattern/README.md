# The ISR Buffer Pattern

## What is this topic?
This topic presents the **ISR to Task Communication Pattern**, the architectural gold standard for safely moving massive amounts of data from hardware peripherals (like UART, SPI, or ADCs) into the RTOS software environment.

## Why is it important?
If you read hardware data slowly inside an ISR, you crash the system. If you try to pass pointers to raw hardware memory directly to Tasks, the hardware will overwrite the data before the Task can read it. Mastering the Double Buffer and Ring Buffer patterns is how professional firmware guarantees zero data loss at extreme speeds.

## Prerequisites
- [09-semaphore](../../07-rtos-concurrency/09-semaphore/README.md)
- [05-rtos-isr-api](../05-rtos-isr-api/README.md)

## Learning Outcomes
1. Implement the Producer-Consumer pattern across the Hardware/Software boundary.
2. Understand why RTOS Queues are too slow for high-bandwidth data.
3. Architect a Ring Buffer (Circular Buffer) protected by a Binary Semaphore.
