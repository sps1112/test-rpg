cmake_minimum_required(VERSION "3.16.3")

set(CMAKE_BUILD_TYPE Debug)

project(test-rpg)

add_executable(
    test-rpg 
    test-rpg/src/Application.cpp)
