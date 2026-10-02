# Struct Basics

## What is this topic?
This topic introduces the `struct` (structure) keyword. A struct is a user-defined composite data type that allows you to group different types of variables together under a single name.

## Why is it important?
In embedded systems, you rarely deal with single isolated variables. A sensor produces a temperature, a humidity value, and a timestamp. A UART peripheral has a control register, a status register, and a data register. Structs allow you to mathematically group these related pieces of data together in memory, making your code readable, scalable, and physically mapped to hardware.

## Prerequisites
- [01-variables-and-addresses](../../02-pointers-arrays/01-variables-and-addresses/README.md)
- [04-arrays](../../02-pointers-arrays/04-arrays/README.md)

## Learning Outcomes
1. Declare and define a basic `struct` in C/C++.
2. Instantiate struct objects and access their members using the dot (`.`) operator.
3. Understand how C++11 aggregate initialization simplifies struct creation.
