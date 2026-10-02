# Software Timers

## What is this topic?
This topic introduces FreeRTOS **Software Timers**, a feature that allows you to execute a function at a set time in the future, without consuming dedicated hardware timers or spawning entire RTOS tasks just to wait.

## Why is it important?
Hardware timers are precious and limited (often only 4-8 on a microcontroller). If you need 20 different timeouts (e.g., turn off LCD backlight after 5s, timeout WiFi after 10s, blink a status LED every 1s), using 20 hardware timers is impossible. Creating 20 separate Tasks just to call `vTaskDelay()` wastes massive amounts of RAM (20 stacks). Software Timers solve this by piggybacking on the RTOS SysTick to manage infinite timers with almost zero overhead.

## Prerequisites
- [07-timers](../../11-embedded-peripherals/07-timers/README.md)
- [02-task-scheduling](../02-task-scheduling/README.md) (The SysTick)

## Learning Outcomes
1. Define a Software Timer and its Callback Function.
2. Differentiate between One-Shot and Auto-Reload software timers.
3. Understand the hidden Daemon Task (`Tmr Svc`) that executes timer callbacks.
