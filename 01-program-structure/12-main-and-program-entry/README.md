# main() and Program Entry

## What is this topic?
This topic explains exactly what happens before `main()` is called, and how the program entry point differs drastically between a Desktop operating system and a Bare-metal embedded microcontroller.

## Why is it important?
Many C/C++ developers incorrectly believe that `main()` is the very first code that executes. In embedded systems, if you don't understand the code that runs *before* `main()` (the startup code), you will struggle to debug issues related to uninitialized variables, crashing before `main()` starts, or understanding why firmware must never return from `main()`.

## Prerequisites
- [05-compilation-pipeline](../05-compilation-pipeline/README.md)

## Learning Outcomes
1. Understand the difference between OS-loader startup and bare-metal startup.
2. Know why embedded firmware uses a "Super Loop" (`while(1)`).
3. Understand why returning from `main()` on a microcontroller is undefined behavior.
