# Smart Pointers

## What is this topic?
This topic introduces C++11 **Smart Pointers**, specifically `std::unique_ptr`, which applies the safety of RAII to Dynamic Memory Allocation (the Heap).

## Why is it important?
While the Heap is heavily discouraged in highly critical embedded systems (due to fragmentation), many standard embedded systems (like IoT devices running Embedded Linux or FreeRTOS) *do* use the Heap to handle variable-length network packets or dynamic JSON parsing. If you must use the Heap, using raw `new` and `delete` is considered gross malpractice in modern C++. Smart pointers guarantee that memory leaks are impossible.

## Prerequisites
- [03-raii](../03-raii/README.md)
- [04-ownership-lifetime](../04-ownership-lifetime/README.md)
- [03-heap](../../05-memory/03-heap/README.md)

## Learning Outcomes
1. Understand how `std::unique_ptr` wraps a raw pointer.
2. Learn how to allocate memory safely using `std::make_unique`.
3. Understand why `std::shared_ptr` is generally avoided in bare-metal embedded.
