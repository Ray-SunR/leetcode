cmake_minimum_required(VERSION 3.1)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    twoSum.cpp)

add_executable(leetcode ${SOURCE_FILES})