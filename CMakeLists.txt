cmake_minimum_required(VERSION 3.10)
project(EmbeddedCppLearning CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable aggressive warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

# Add common utilities
add_subdirectory(common)

# We will add subdirectories here as they are populated with CMakeLists
add_subdirectory(00-getting-started/first-program)
# add_subdirectory(13-practical-projects)
# add_subdirectory(tests)
