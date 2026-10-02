# Variables and Addresses

## What is this topic?
This topic introduces the absolute foundational concept of memory mapping in C/C++: how variables are stored in a computer's physical memory and how to find their exact location (their address).

## Why is it important?
In high-level languages like Python or JavaScript, memory is hidden from you. In C/C++, particularly in embedded systems, memory is your primary working environment. You must understand that every variable is just a sequence of bytes at a specific hardware address. This is the prerequisite for understanding pointers.

## Prerequisites
- [05-compilation-pipeline](../../01-program-structure/05-compilation-pipeline/README.md)

## Learning Outcomes
1. Understand the mental model of memory as an array of bytes.
2. Use the address-of operator (`&`) to find a variable's address.
3. Understand why a 32-bit integer has a single address despite occupying 4 bytes.
