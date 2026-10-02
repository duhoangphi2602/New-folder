cmake_minimum_required(VERSION 3.10)

add_library(common STATIC
    src/log.cpp
)

target_include_directories(common PUBLIC include)
target_compile_features(common PUBLIC cxx_std_17)
