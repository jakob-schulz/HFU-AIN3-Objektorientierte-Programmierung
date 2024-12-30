cmake_minimum_required(VERSION 3.28.0)

project(task11)

add_compile_options(-Wall -Wextra)

add_executable(testFantasyGame src/tests/FantasyGameTest.cpp src/main/Dwarf.cpp src/main/Elf.cpp src/main/Orc.cpp src/main/Character.cpp)