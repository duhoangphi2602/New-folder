# Ownership & Lifetime

## What is this topic?
This topic introduces the concepts of **Ownership** and **Lifetime**, which are the philosophical foundation of modern C++ resource management. It explains how C++ tracks who is responsible for cleaning up a resource and exactly how long that resource is guaranteed to exist.

## Why is it important?
Many C programmers transition to C++ and write code that crashes randomly. The most common cause is "Lifetime" bugs: passing a pointer to an object that has already been destroyed (Dangling Pointer). Understanding Ownership prevents these architectural mistakes by forcing you to explicitly define whether a function is merely "looking" at a resource, "sharing" it, or taking absolute "control" of it.

## Prerequisites
- [02-stack](../../05-memory/02-stack/README.md)
- [03-raii](../03-raii/README.md)

## Learning Outcomes
1. Define the concepts of Object Lifetime and Scope.
2. Differentiate between Exclusive Ownership, Shared Ownership, and Non-Owning views.
3. Identify how passing variables by Value, Pointer, or Reference communicates ownership intent.
