# Interview Questions: Makefiles

## 1. Briefly explain how the `make` utility decides whether or not to execute a compiler command.
**Answer:** The `make` utility relies on timestamp comparison. For any given rule, it compares the "Last Modified" timestamp of the Target file against the timestamps of all its listed Prerequisite files. If the Target file does not exist, or if *any* Prerequisite file has a newer timestamp than the Target (indicating the source code was modified after the last build), `make` executes the command recipe. If the Target is newer than all Prerequisites, `make` skips the command, declaring the target "up to date."

## 2. In a Makefile, what happens if you accidentally use 4 spaces instead of a 'TAB' character to indent a recipe command?
**Answer:** The `make` utility will instantly fail and throw a syntax error, usually stating `Makefile: missing separator`. This is an infamous historical quirk of the `make` parser. It strictly mandates that all command recipes must be indented with a literal physical `\t` TAB character. Spaces are not allowed, no matter how the IDE visually renders them.

## 3. Why is manually maintaining a `Makefile` for a massive C++ project considered dangerous or inefficient?
**Answer:** Manual Makefiles are highly prone to "Missing Dependency" bugs (specifically missing header files). If a developer adds a new `#include "math.h"` to a `.cpp` file, but forgets to manually add `math.h` to the prerequisite list in the Makefile, `make` will not know that modifying `math.h` should trigger a rebuild of that `.cpp` file. This leads to code being flashed that doesn't include the latest changes. Furthermore, maintaining paths and flags for multiple OS environments (Windows vs Linux) is incredibly complex in raw Make syntax. This is why modern development has shifted to Meta-Build systems like CMake, which auto-generate the Makefiles for you.
