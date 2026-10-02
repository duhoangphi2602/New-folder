# Process, Thread, and Task

## What is this topic?
This topic breaks down the fundamental units of execution across different operating systems. It compares the heavy "Processes" of Linux/Windows to the lightweight "Threads" and embedded "Tasks."

## Why is it important?
When transitioning from Desktop C++ to Embedded C++, developers often bring misconceptions about how concurrency works. Trying to spawn a standard `std::thread` on a bare-metal microcontroller will result in a compilation error. Understanding the terminology and architectural differences between a Process, a Thread, and an RTOS Task is the first step to mastering Real-Time Systems.

## Prerequisites
- [05-text-rodata-data-bss](../../05-memory/05-text-rodata-data-bss/README.md)
- [02-stack](../../05-memory/02-stack/README.md)

## Learning Outcomes
1. Define a Process (Virtual Memory, isolation) vs a Thread (Shared Memory).
2. Understand why Microcontrollers (without an MMU) cannot run Linux Processes.
3. Understand the definition of an RTOS Task (effectively a lightweight Thread).
