cmake_minimum_required(VERSION 3.28.0)

project(task3)

add_compile_options(-Wall -Wextra)

#add_executable(sortFunction src/main/sortFunction.cpp)
add_executable(positionTest src/main/position.cpp src/tests/positionTest.cpp)
add_executable(compareTest src/main/position.cpp src/tests/compareTest.cpp)
add_executable(sortTests src/main/sortFunction.cpp src/main/position.cpp src/tests/sortTests.cpp)
