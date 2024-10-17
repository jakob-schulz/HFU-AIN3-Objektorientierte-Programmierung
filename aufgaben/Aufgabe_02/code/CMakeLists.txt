cmake_minimum_required(VERSION 3.28.0)

project(FunctionsAndPosition)

add_compile_options(-Wall -Wextra)

add_executable(usefulFunctionsTests src/tests/usefulFunctionsTests.cpp src/main/usefulFunctions.cpp)
add_executable(positionTests src/tests/positionTests.cpp src/main/position.cpp)