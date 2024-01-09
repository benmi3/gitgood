cmake_minimum_required(VERSION 3.27)
project(first_test)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(first_test
        main.cpp)
