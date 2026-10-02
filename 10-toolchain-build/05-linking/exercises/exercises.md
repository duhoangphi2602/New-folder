# Exercises: Linking

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: The Library Paradox
You are compiling a project with `main.cpp` and a static math library `libmath.a`.
Command A: `gcc libmath.a main.cpp -o app`
Command B: `gcc main.cpp libmath.a -o app`
**Task:** Command B successfully links the application. Command A fails with an "Undefined Reference to `add()`" error. Why does the order of files matter to the Linker? How does the Linker process `.a` static libraries?

## Exercise 2: Extern Variable
In `sensor.cpp`, you write: `int sensor_id = 5;`
In `main.cpp`, you write: `extern int sensor_id;`
**Task:** 
1. What does `extern` do in Stage 2 (Compiler)? 
2. What does `extern` do in Stage 4 (Linker)?
