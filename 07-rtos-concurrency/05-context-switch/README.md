# Context Switching

## What is this topic?
This topic explains the mechanical process of a **Context Switch**: the exact sequence of assembly instructions the CPU must execute to pause one task and resume another. 

## Why is it important?
A Context Switch is not free. It costs CPU time (Overhead). If you configure your RTOS incorrectly (e.g., setting the SysTick timer to tick 100,000 times a second), the CPU will spend all its time executing Context Switches and no time actually running your application. Understanding the mechanics allows you to tune your RTOS for maximum throughput.

## Prerequisites
- [04-scheduler](../04-scheduler/README.md)
- [02-stack](../../05-memory/02-stack/README.md)

## Learning Outcomes
1. Define the "Context" of a CPU (Registers + Program Counter).
2. Trace the step-by-step mechanical sequence of a Context Switch.
3. Calculate Context Switch overhead and optimize SysTick rates.
