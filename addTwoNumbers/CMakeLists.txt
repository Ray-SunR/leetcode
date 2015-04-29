cmake_minimum_required(VERSION 3.1)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    addTwoNumbers.cpp)

add_executable(addTwoNumbers ${SOURCE_FILES})