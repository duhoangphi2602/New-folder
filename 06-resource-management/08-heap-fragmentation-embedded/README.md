# Heap Fragmentation

## What is this topic?
This topic dissects **Heap Fragmentation**, the invisible killer of long-running embedded systems. It explains the mechanics of how memory becomes "swiss cheese" over time, ultimately leading to system crashes even when the device theoretically has enough total RAM available.

## Why is it important?
A smart home thermostat might run perfectly on the developer's desk for 2 weeks. But after 3 months in a customer's house, it randomly reboots. The most common cause of these "time-bomb" bugs in IoT devices is Heap Fragmentation. Understanding this phenomenon is what separates desktop programmers from embedded engineers.

## Prerequisites
- [01-malloc-free](../01-malloc-free/README.md)
- [07-pool-allocation](../07-pool-allocation/README.md)

## Learning Outcomes
1. Understand the mechanics of memory fragmentation.
2. Differentiate between total free memory and contiguous free memory.
3. Understand why Desktop OSs survive fragmentation while RTOSs do not.
