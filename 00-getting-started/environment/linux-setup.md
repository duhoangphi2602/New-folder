# Linux Environment Setup

Linux (specifically Ubuntu/Debian based) is the standard environment for most embedded Linux and cross-compilation workflows.

## Installing the Native Toolchain

Open your terminal and run the following commands to install the GNU C/C++ compiler, Make, and CMake.

```bash
sudo apt update
sudo apt install build-essential cmake
```

`build-essential` includes `gcc`, `g++`, and `make`.

## Verify Installation

```bash
gcc --version
g++ --version
cmake --version
```

## IDE Recommendation
- **Visual Studio Code (VS Code)**
  - Extensions: C/C++ Extension Pack, CMake Tools.
- **Vim/Neovim** (for terminal enthusiasts)
