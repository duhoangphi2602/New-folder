# Class & Object Basics

## What is this topic?
This topic introduces Object-Oriented Programming (OOP) concepts in C++: **Classes** and **Objects**. It explains how to bundle data (variables) and behavior (functions) together.

## Why is it important?
In C, a hardware peripheral (like a UART) is typically modeled as a `struct` of data and a set of separate global functions. In C++, you can create a `Uart` class that completely encapsulates the hardware, protecting its state and ensuring it is initialized correctly before use. This makes embedded code drastically safer and easier to use.

## Prerequisites
- [01-source-files](../01-source-files/README.md)
- [02-declaration-vs-definition](../02-declaration-vs-definition/README.md)

## Learning Outcomes
1. Understand the exact difference between `struct` and `class` in C++.
2. Write Constructors and Destructors.
3. Understand how member functions affect memory footprint in embedded systems.
