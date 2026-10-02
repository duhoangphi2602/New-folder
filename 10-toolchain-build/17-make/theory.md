# Make and Makefiles

## 1. The Build Automation Problem
If your project has 3 files (`main.cpp`, `sensor.cpp`, `display.cpp`), you must run 4 commands to build it:
1. Compile `main.cpp` into `main.o`
2. Compile `sensor.cpp` into `sensor.o`
3. Compile `display.cpp` into `display.o`
4. Link `main.o`, `sensor.o`, `display.o` into `firmware.elf`
If you edit `sensor.cpp`, it is extremely inefficient to manually re-run all 4 commands. You only need to re-run steps 2 and 4.

## 2. The `make` Utility
`make` is a command-line tool. When you type `make`, it looks for a text file named `Makefile` in the current directory. 
The `Makefile` contains the dependency graph of your project.

## 3. Makefile Syntax
A Makefile consists of **Rules**. Each rule has 3 parts:
```make
target: prerequisites
	recipe (command)
```
- **Target:** What file are you trying to build? (e.g., `firmware.elf`)
- **Prerequisites:** What files must exist *before* you can build the target? (e.g., `main.o`, `sensor.o`)
- **Recipe:** The exact terminal command to execute. ***Crucial: This line MUST begin with a physical TAB character, not spaces.***

## 4. Incremental Builds (Timestamps)
The true power of `make` is timestamp comparison.
When `make` evaluates a rule like `sensor.o: sensor.cpp`:
- It checks the "Last Modified" timestamp of `sensor.cpp`.
- It checks the "Last Modified" timestamp of `sensor.o`.
- If `sensor.cpp` is *newer* than `sensor.o` (meaning you edited the code), `make` executes the recipe to rebuild `sensor.o`.
- If `sensor.o` is newer, `make` says: *"sensor.o is up to date."* and does absolutely nothing, saving massive amounts of compile time.

## 5. Variables
Makefiles use variables to keep commands clean.
```make
CC = arm-none-eabi-g++
CFLAGS = -Wall -O2 -mcpu=cortex-m4

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o
```

## 6. Example
*(See `examples/` for a fully functional Makefile).*

## 7. Exercises
Please proceed to the `exercises/` folder.

## 8. Interview
Please proceed to `interview.md` for common interview questions regarding this topic.
