cmake_minimum_required(VERSION 3.28)

project(EmployeeManagement)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(main
    main.cpp
    Employee.cpp
    Manager.cpp
    Worker.cpp
)
