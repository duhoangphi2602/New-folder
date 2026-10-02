# Exercises: inline, static, extern

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Storage Location
Look at the following variables:
```cpp
int a = 1;
static int b = 2;

void foo() {
    int c = 3;
    static int d = 4;
}
```
**Task:** For variables `a`, `b`, `c`, and `d`, state whether they are stored in the Stack, the Heap, or Static Memory (`.data`/`.bss`). 

## Exercise 2: C++17 Constants
You are reviewing old C++98 code. A header file `config.h` has this:
```cpp
const int BAUD_RATE = 115200;
```
If this header is included in 10 different `.cpp` files, what happens? 
**Task:** Rewrite this using C++17 features to ensure it is optimal and guarantees exactly one instance in memory.

## Exercise 3: State Machine Bug
A junior developer writes this code for an RTOS (Real-Time Operating System) where multiple threads might call `get_next_id()`.
```cpp
int get_next_id() {
    static int id = 0;
    id++;
    return id;
}
```
**Task:** Identify the fatal flaw in this code when used in a multi-threaded (RTOS) environment. How can it be fixed without removing the `static` keyword?
