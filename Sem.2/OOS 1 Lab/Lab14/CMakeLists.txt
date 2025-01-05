cmake_minimum_required(VERSION 3.28.0)
project(Labor14 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(Labor14)
target_sources(Labor14
    PUBLIC
        FILE_SET CXX_MODULES FILES
            Employee.cpp Manager.cpp Worker.cpp
)

add_executable(Labor14module main.cpp)
target_link_libraries(Labor14module PRIVATE Labor14)