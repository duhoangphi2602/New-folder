# Constructor Initialization in Embedded

## What is this topic?
This topic addresses a specific, notorious pitfall in C++ programming: **Global Object Constructors**. It explains how global objects are initialized before `main()` and the severe dangers of relying on them.

## Why is it important?
When you declare a global class object (e.g., `Logger g_logger;`), its constructor runs before `main()`. This seems convenient, but it leads to the "Static Initialization Order Fiasco"—a classic C++ bug where two global objects depend on each other, causing the program to crash unpredictably at boot. In embedded systems, executing large amounts of code before `main()` is also dangerous because hardware peripherals might not be fully configured yet.

## Prerequisites
- [10-class-object-basics](../10-class-object-basics/README.md)
- [13-embedded-startup](../13-embedded-startup/README.md)

## Learning Outcomes
1. Understand how the startup code calls global constructors via the `.init_array`.
2. Understand and avoid the Static Initialization Order Fiasco.
3. Learn modern C++17 solutions (`constexpr`) and best practices for global singletons.
