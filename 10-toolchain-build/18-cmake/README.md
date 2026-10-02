# CMake

## What is this topic?
This topic introduces **CMake**, the modern, industry-standard Meta-Build System that generates Makefiles for you.

## Why is it important?
Writing Makefiles by hand for a project with 300 files across Windows, Mac, and Linux developers is a nightmare. CMake abstracts the build process into a human-readable language, automatically generating the perfect `Makefile` (or Visual Studio project) for whatever OS you happen to be on. If you want a job in C/C++, you must know CMake.

## Prerequisites
- [17-make](../17-make/README.md)

## Learning Outcomes
1. Understand that CMake is a "Meta-Build System", not a compiler.
2. Read and write a basic `CMakeLists.txt` file.
3. Understand the two-step CMake workflow (`cmake` then `make`).
