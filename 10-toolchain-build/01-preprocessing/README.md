# Preprocessing

## What is this topic?
This topic covers the **Preprocessor**, the very first step in the C/C++ compilation pipeline. It runs before the compiler even looks at your code.

## Why is it important?
The Preprocessor is just a dumb text-replacement engine. It does not understand C++ syntax, types, or scopes. However, it is the mechanism behind `#include`, `#define`, and conditional compilation (`#ifdef`). Understanding that the preprocessor merely copy-pastes text is crucial for debugging weird macro errors and avoiding circular includes.

## Prerequisites
- [01-source-files](../../01-program-structure/01-source-files/README.md)

## Learning Outcomes
1. Understand how `#include` physically copy-pastes file contents.
2. Recognize the dangers of `#define` macros (lack of type safety).
3. Use Include Guards (`#ifndef`) to prevent infinite copy-paste loops.
