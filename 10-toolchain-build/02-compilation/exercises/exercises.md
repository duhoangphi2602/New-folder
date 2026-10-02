# Exercises: Compilation

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Finding the Culprit
You attempt to compile your firmware. The terminal spits out this output:
```text
Compiling main.cpp... OK
Compiling sensor.cpp... OK
Compiling uart.cpp... OK
Linking firmware.elf...
Error: main.o: In function `main`: undefined reference to `init_hardware()`
```
**Task:** A junior developer says, "The C++ compiler failed to compile our code!" 
Is the developer correct? Did Stage 2 (The Compiler) fail? Explain exactly what happened.

## Exercise 2: Syntax vs Semantics
Consider these two lines of code:
Line A: `int x = "Hello"`
Line B: `int x = 5` (Notice the missing semicolon)
**Task:** Which line causes a Syntax Error, and which causes a Semantic Error? Why?
