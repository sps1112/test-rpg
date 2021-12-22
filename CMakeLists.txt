cmake_minimum_required(VERSION "3.16.3")

set(CMAKE_CXX_STANDARD 17)

if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)

set(CMAKE_BUILD_TYPE Debug)

project(test-rpg)

include_directories(test-rpg/includes)
include_directories(test-rpg/configuration)


configure_file(test-rpg/configuration/root_directory.h.in configuration/root_directory.h)
include_directories(${CMAKE_BINARY_DIR}/configuration)

add_executable(
    test-rpg 
    test-rpg/src/Application.cpp
    test-rpg/src/Standard.cpp
    test-rpg/src/ASCArt.cpp
    test-rpg/src/Printer.cpp
    test-rpg/src/MathEngine.cpp
    test-rpg/src/FileManager.cpp
    test-rpg/src/Character.cpp
    test-rpg/src/Battle.cpp
    test-rpg/src/FileSystem.cpp
    test-rpg/src/Game.cpp)
