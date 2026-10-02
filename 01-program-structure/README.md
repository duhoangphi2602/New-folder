# 01 — Program Structure

This chapter covers the fundamental anatomy of C/C++ programs — from how source files are organized to how the compiler transforms them into executables, and critically, how embedded systems differ at the startup level.

## Prerequisites
- A working compiler (see `00-getting-started/`)

## Topics

| # | Topic | Description |
|---|-------|-------------|
| 01 | [Source Files](./01-source-files/) | Header vs implementation, `.h` / `.hpp` / `.cpp` |
| 02 | [Declaration vs Definition](./02-declaration-vs-definition/) | ODR, forward declarations |
| 03 | [Translation Unit](./03-translation-unit/) | What the compiler actually sees |
| 04 | [Preprocessing](./04-preprocessing/) | `#include`, `#define`, `#ifdef`, include guards |
| 05 | [Compilation Pipeline](./05-compilation-pipeline/) | Preprocess → Compile → Assemble → Link |
| 06 | [Functions](./06-functions/) | Declaration, definition, pass-by-value/pointer/reference |
| 07 | [Function Pointer](./07-function-pointer/) | Callbacks, dispatch tables |
| 08 | [inline, static, extern](./08-inline-static-extern/) | Linkage, storage duration |
| 09 | [Namespace](./09-namespace/) | Scope management in C++ |
| 10 | [Class & Object Basics](./10-class-object-basics/) | Struct vs class, access specifiers |
| 11 | [Lambda](./11-lambda/) | Anonymous functions, captures |
| 12 | [main() and Program Entry](./12-main-and-program-entry/) | Desktop vs Embedded entry point |
| 13 | [Embedded Startup](./13-embedded-startup/) | Reset → Vector Table → Runtime Init → main() |
| 14 | [Constructor Init in Embedded](./14-constructor-init-embedded/) | Global constructors, `.init_array`, static init order |

## Learning Outcomes
After completing this chapter, you should be able to:
- Explain how C/C++ source code becomes an executable binary
- Distinguish between declaration and definition
- Understand what a translation unit is and why it matters for linking
- Write and use function pointers and callbacks
- Explain the difference between `main()` on a PC and firmware startup on an MCU
- Understand how global C++ objects are constructed before `main()` in embedded
