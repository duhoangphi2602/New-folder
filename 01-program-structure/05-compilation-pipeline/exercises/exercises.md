# Exercises: Compilation Pipeline

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Identify the Stage
A junior developer is trying to build their project. They encounter the following error message in their terminal:
```text
/usr/bin/ld: main.o: in function `main':
main.cpp:(.text+0x15): undefined reference to `uart_init'
collect2: error: ld returned 1 exit status
```
**Task:** Which stage of the compilation pipeline failed? How do you know? What is the likely cause of this error?

## Exercise 2: Object Files
You have a project with 3 files: `main.cpp`, `sensor.cpp`, and `display.cpp`.
You modify a single line of logic inside `sensor.cpp` and click "Build".
**Task:** Assuming a modern build system (like Make or CMake) is used, describe exactly what stages of the pipeline run for which files. Do `main.cpp` and `display.cpp` get recompiled?

## Exercise 3: Embedded Specifics
You successfully build an embedded C++ project for an STM32 microcontroller. The output is `firmware.elf`. 
You try to drag and drop `firmware.elf` into your STM32 flashing tool, but the tool rejects it, saying "Invalid file format. Expected .bin or .hex".
**Task:** Explain what an ELF file is, why the MCU cannot run it directly, and what specific command-line tool (and stage) you need to use to fix this.
