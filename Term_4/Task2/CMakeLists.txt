cmake_minimum_required(VERSION 4.2)
project(Task2)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-DPROJECT_DIR="${CMAKE_SOURCE_DIR}")

add_executable(Task2 main.cpp)
