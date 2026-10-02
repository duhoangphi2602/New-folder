# Lambda

## What is this topic?
This topic covers **Lambdas**, introduced in C++11, which are a way to write anonymous, inline functions directly at the point where they are needed.

## Why is it important?
Lambdas make code significantly more readable by keeping the logic of a callback right next to where the callback is registered, instead of forcing you to jump to a different function at the top of the file. However, in embedded C++, you must understand how lambdas capture state, because a capturing lambda cannot be passed to a C-style hardware driver.

## Prerequisites
- [06-functions](../06-functions/README.md)
- [07-function-pointer](../07-function-pointer/README.md)

## Learning Outcomes
1. Learn the syntax of writing a basic lambda function.
2. Understand the Capture List (`[]`) and the difference between capturing by value and by reference.
3. Know exactly when a lambda can and cannot decay into a C function pointer.
