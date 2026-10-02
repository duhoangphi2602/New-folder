cmake_minimum_required(VERSION 3.10)

# Build the C++ executable
add_executable(hello_cpp hello.cpp)
target_compile_features(hello_cpp PRIVATE cxx_std_17)

# Build the C executable
add_executable(hello_c hello_c.c)
