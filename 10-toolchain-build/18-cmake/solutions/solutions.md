# Solutions: CMake

## Solution 1: Out-of-Source Build
**Answer:** An "Out-of-Source Build" keeps your source code folder pristine and untouched. CMake generates a massive amount of internal cache and tracking files. If these are mixed with your `.cpp` files, it becomes very difficult to tell what you wrote versus what the computer generated, and you risk accidentally committing build artifacts to Git.
If you use an out-of-source build (`mkdir build`), the absolute easiest way to completely clean the project and start fresh is to simply delete the folder: `rm -rf build/`. Everything is gone, and your source code is perfectly safe. 

## Solution 2: `target_...` Commands
**Answer:** In modern CMake, everything is based on "Targets" (an executable or a library). 
The `PRIVATE` keyword means that the `libs/` folder is only required to compile the `app` target, and it should not be shared with anyone else.
If you use the old global `include_directories(libs/)` command, *every single target* you define later in the project will automatically inherit that include path. This causes "Namespace Pollution". If you have a `UnitTests` target that shouldn't have access to hardware libraries, it gets them anyway. By using `target_include_directories()`, you strictly encapsulate dependencies, preventing nasty header-file collisions in large projects.
