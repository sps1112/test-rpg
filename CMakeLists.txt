cmake_minimum_required(VERSION "3.16.3")

set(CMAKE_BUILD_TYPE Debug)

project(test-rpg)

include_directories(test-rpg/includes)

add_executable(
    test-rpg 
    test-rpg/src/Application.cpp
    test-rpg/src/Standard.cpp
    test-rpg/src/ASCArt.cpp
    test-rpg/src/Printer.cpp
    test-rpg/src/MathEngine.cpp
    test-rpg/src/FileManager.cpp
    test-rpg/src/Character.cpp
    test-rpg/src/Battle.cpp)
