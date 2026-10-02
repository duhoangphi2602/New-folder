# Interview Questions: CMake

## 1. What is the fundamental difference between CMake and Make?
**Answer:** Make is a Build Automation tool. It directly executes terminal commands (like invoking GCC) based on a dependency graph written in a Makefile. 
CMake is a Meta-Build System. It does not invoke GCC or compile code. It reads a high-level configuration file (`CMakeLists.txt`) and automatically generates the low-level build files (like a Makefile, a Ninja build file, or a Visual Studio Solution) tailored specifically to the host operating system. You use CMake to generate the instructions, and then you use Make to execute them.

## 2. When cross-compiling an embedded project with CMake, how do you stop CMake from finding and using the host PC's default compiler (e.g., Apple Clang or MSVC)?
**Answer:** You must provide CMake with a **Toolchain File**. By passing `-DCMAKE_TOOLCHAIN_FILE=toolchain.cmake` during the generation step, you force CMake to read that file before it searches the system. The toolchain file explicitly hardcodes the paths to the cross-compiler (`arm-none-eabi-gcc`), sets the target architecture to Bare-Metal, and disables the OS-specific checks (like checking for POSIX threads). Without this file, CMake will attempt to compile STM32 code using your desktop's Intel compiler, causing immediate failure.

## 3. What is the difference between `PRIVATE`, `PUBLIC`, and `INTERFACE` when using `target_link_libraries()`?
**Answer:** These keywords dictate how dependencies propagate between CMake targets.
- **PRIVATE:** The library is strictly used internally by the target. If Target A links Library B `PRIVATE`, Target A can use B's code. If Target C later links against Target A, Target C will *not* know about Library B.
- **PUBLIC:** The library is used internally AND is exposed in the API. If Target A links B `PUBLIC`, and Target C links A, Target C will automatically inherit access to Library B.
- **INTERFACE:** The target doesn't actually use the library's code itself, but it forces anyone who links against it to use it (commonly used for Header-Only libraries).
