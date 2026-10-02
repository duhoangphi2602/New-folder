# Windows Environment Setup

To develop Embedded C/C++ on Windows, you have several options. We recommend using MSYS2/MinGW or Windows Subsystem for Linux (WSL).

## Option 1: MSYS2 (Recommended for Native Windows)

1. Download MSYS2 from [msys2.org](https://www.msys2.org/).
2. Install it and open the "MSYS2 UCRT64" terminal.
3. Install the GCC toolchain and CMake:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc
   pacman -S mingw-w64-ucrt-x86_64-cmake
   pacman -S mingw-w64-ucrt-x86_64-ninja
   ```
4. Add `C:\msys64\ucrt64\bin` to your Windows System `PATH`.

## Option 2: WSL (Windows Subsystem for Linux)

If you prefer a Linux environment on Windows:
1. Open PowerShell as Administrator and run:
   ```powershell
   wsl --install
   ```
2. Restart your computer.
3. Open the "Ubuntu" app that was installed.
4. Follow the [Linux Setup](./linux-setup.md) instructions inside WSL.

## IDE Recommendation
- **Visual Studio Code (VS Code)**
  - Extensions: C/C++ Extension Pack, CMake Tools.
