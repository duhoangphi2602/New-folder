# Exercises: CMake

Do not look at the `solutions/` folder until you have attempted these exercises.

## Exercise 1: Out-of-Source Build
You have a project with 50 source files. You accidentally run `cmake .` directly inside your source folder instead of creating a `build/` directory.
Instantly, CMake generates `CMakeCache.txt`, a `CMakeFiles/` directory with hundreds of internal tracking files, and a `Makefile`, polluting your repository.
**Task:** Why is an "Out-of-Source Build" (creating a `build/` folder and running `cmake ..`) considered a strict industry standard? What is the easiest way to undo your mistake and clean up the repository if you use an out-of-source build?

## Exercise 2: `target_...` Commands
In CMake, there are old commands like `include_directories()` and modern commands like `target_include_directories()`.
Look at this modern CMake snippet:
```cmake
add_executable(app main.cpp)
target_include_directories(app PRIVATE libs/)
```
**Task:** What does the `PRIVATE` keyword mean here? Why is it better to attach include directories directly to the target (`app`) rather than setting them globally for the entire project?
