cmake_minimum_required(VERSION 3.28)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        cyclebreaker.cpp
        cyclebreaker.h
        main.cpp
        Graph.cpp
        Graph.h
)
