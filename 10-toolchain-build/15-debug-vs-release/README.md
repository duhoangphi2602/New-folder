# Debug vs Release

## What is this topic?
This topic compares the two standard "Build Profiles" used universally in software engineering: Debug and Release.

## Why is it important?
Code that works perfectly on your desk might crash instantly in the field. 99% of the time, this happens because the code was developed in Debug mode, but deployed in Release mode. Understanding exactly which compiler flags change between these two profiles is crucial for preventing deployment disasters.

## Prerequisites
- [06-elf](../06-elf/README.md)
- [14-optimization](../14-optimization/README.md)

## Learning Outcomes
1. Define the compiler flags associated with Debug mode.
2. Define the compiler flags associated with Release mode.
3. Understand how `#ifdef NDEBUG` controls `assert()` behavior.
