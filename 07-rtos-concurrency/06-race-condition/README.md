# Race Conditions

## What is this topic?
This topic introduces the **Race Condition**, the most notorious and difficult-to-debug software bug in multithreaded and RTOS environments.

## Why is it important?
In a Bare-Metal Super Loop, tasks run sequentially. Task A completely finishes before Task B starts. In an RTOS, the Scheduler can preempt Task A right in the middle of a mathematical calculation to run Task B. If both tasks share the same global variable, they will overwrite each other's data, causing silent, unpredictable data corruption.

## Prerequisites
- [04-scheduler](../04-scheduler/README.md)
- [05-context-switch](../05-context-switch/README.md)

## Learning Outcomes
1. Mechanically define a Race Condition at the Assembly level.
2. Identify non-atomic C/C++ operations.
3. Recognize the symptoms of Race Conditions in embedded software.
