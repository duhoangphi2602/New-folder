# Linking (The Linker)

## What is this topic?
This topic explores **Stage 4** of the toolchain: The Linker. It explains how all the isolated, incomplete `.o` Object files are finally stitched together into a single, functional executable program.

## Why is it important?
When developers encounter an "Undefined Reference" or "Multiple Definition" error, they often blame their code logic. But this is a structural error. Understanding how the Linker matches 'U' (Undefined) symbols with 'T' (Defined) symbols across dozens of files allows you to fix complex build architecture problems instantly.

## Prerequisites
- [04-object-files](../04-object-files/README.md)
- [09-linker-script](../09-linker-script/README.md) (Conceptually)

## Learning Outcomes
1. Trace the Linker's symbol resolution process.
2. Differentiate between "Undefined Reference" and "Multiple Definition" errors.
3. Understand how the Linker Script guides the Linker to assign physical VMA/LMA addresses.
