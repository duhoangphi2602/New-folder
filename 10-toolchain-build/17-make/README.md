# Make and Makefiles

## What is this topic?
This topic introduces `make`, the classic build automation tool. It explains how to write a `Makefile` to automate the complex GCC commands we learned in previous topics.

## Why is it important?
Typing `arm-none-eabi-g++ -c main.cpp -mcpu=cortex-m4 ...` manually in the terminal is impossible for a project with 100 source files. A `Makefile` orchestrates the entire toolchain, manages dependencies, and performs Incremental Builds (only compiling files that changed), turning a 5-minute manual process into a 1-second automated click.

## Prerequisites
- [04-object-files](../04-object-files/README.md)
- [13-compiler-flags](../13-compiler-flags/README.md)

## Learning Outcomes
1. Understand the syntax of a Makefile (Targets, Prerequisites, Recipes).
2. Explain the concept of Incremental Compilation based on file timestamps.
3. Write a simple Makefile to compile an executable.
