cmake_minimum_required(VERSION 3.28.0)

project(task5)

add_compile_options(-Wall -Wextra)

add_executable(testPosition src/main/position.cpp src/tests/test_position.cpp)