cmake_minimum_required(VERSION 3.17)
project(Rubik)

set(CMAKE_CXX_STANDARD 14)

include_directories(ConsoleApplication4)

add_executable(Rubik
        ConsoleApplication4/Blue.cpp
        ConsoleApplication4/Green.cpp
        ConsoleApplication4/main.cpp
        ConsoleApplication4/Orange.cpp
        ConsoleApplication4/Red.cpp
        ConsoleApplication4/Cube.cpp ConsoleApplication4/Cube.h ConsoleApplication4/Colors.cpp ConsoleApplication4/Colors.h)
