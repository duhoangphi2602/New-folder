#!/bin/bash
# A simple script demonstrating the pipeline
# Run in a Linux environment or WSL

echo "1. Creating source file..."
cat << 'EOF' > hello.cpp
#include <iostream>
int main() {
    std::cout << "Hello Pipeline\n";
    return 0;
}
EOF

echo "2. Preprocessing (-E) -> hello.i"
g++ -E hello.cpp -o hello.i

echo "3. Compiling to Assembly (-S) -> hello.s"
g++ -S hello.cpp -o hello.s

echo "4. Assembling to Object (-c) -> hello.o"
g++ -c hello.cpp -o hello.o

echo "5. Linking -> hello.exe"
g++ hello.o -o hello.exe

echo "Pipeline complete. You can now inspect hello.i, hello.s, and hello.o"
