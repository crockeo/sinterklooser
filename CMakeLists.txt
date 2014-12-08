# Setting up the project.
cmake_minimum_required(VERSION 2.6)
project(sinterklooser)

include(FindPkgConfig)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/bin")
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/build/lib")

# Setting up the target executable.
add_executable(sinterklooser src/main.cpp)

# Setting the C++11 flag.
set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

# Setting up my own libraries.
add_library(sinterklooser-library "src/graph.cpp"
                                  "src/node.cpp")

target_link_libraries(sinterklooser sinterklooser-library)
