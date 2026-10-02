# Buffering in I/O

## What is this topic?
This topic explains **Buffering**, the mechanism by which operating systems and standard libraries hold onto I/O data in RAM before physically writing it to hardware (like a screen or a UART port).

## Why is it important?
Writing data to physical hardware is extremely slow compared to CPU speeds. If `printf` talked directly to the hardware for every single character, your system would grind to a halt. Buffering solves this. However, buffering also causes a classic debugging nightmare: you call `printf("Error occurred!");`, the system crashes immediately after, and you *never see the message* because it was trapped in the RAM buffer and never flushed to the screen.

## Prerequisites
- [01-c-standard-io](../01-c-standard-io/README.md)
- [02-cpp-io](../02-cpp-io/README.md)

## Learning Outcomes
1. Understand the difference between Unbuffered, Line Buffered, and Fully Buffered I/O.
2. Learn how to explicitly `fflush()` the output buffer to guarantee data transmission.
3. Understand why a missing `\n` can hide your `printf` logs during a crash.
