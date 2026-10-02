# Exercises: typedef and using

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Translate to `using`
You are migrating a legacy C library to modern C++. You find the following lines of code:
```c
typedef unsigned short int uint16_t;
typedef struct { float x; float y; } Point;
typedef int* IntPtr;
```
**Task:** Rewrite all three lines using the modern C++11 `using` syntax.

## Exercise 2: The `typedef struct` Hack
In standard C, you will almost always see structs defined like this:
```c
typedef struct {
    int id;
} Device;
```
Instead of just:
```c
struct Device {
    int id;
};
```
**Task:** Why was this `typedef` hack considered mandatory in standard C? Why is it completely unnecessary (and slightly frowned upon) in modern C++?
