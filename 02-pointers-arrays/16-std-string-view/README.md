# std::string_view (C++17)

## What is this topic?
This topic covers `std::string_view`, introduced in C++17. It is a highly optimized, read-only "window" or reference to an existing sequence of characters (a string). 

## Why is it important?
Passing strings around in C requires finding their length dynamically via `strlen()` (which is slow). Passing `std::string` in older C++ versions often caused hidden, expensive heap allocations (dynamic memory), which is lethal in embedded systems. `std::string_view` completely solves both problems by passing just a pointer and a length, requiring zero allocations and eliminating the need to calculate length at runtime.

## Prerequisites
- [04-arrays](../04-arrays/README.md)
- [11-dangling-pointer](../11-dangling-pointer/README.md)

## Learning Outcomes
1. Understand the internal structure of `std::string_view` (Pointer + Length).
2. Learn how to use it for fast, allocation-free string parsing.
3. Understand the severe dangling pointer risks associated with non-owning views.
