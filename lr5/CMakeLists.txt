cmake_minimum_required(VERSION 2.8.12.2)

project(lab5KMP)

add_library(kmpFunc ./src/kmpFunc.cpp)

target_include_directories(kmpFunc PUBLIC ./hdr)
set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable (kmp ./src/kmp.cpp)
add_executable (shift ./src/shift.cpp)
add_executable (NaiveVsKmp ./src/NaiveVsKmp.cpp)
add_executable (test ./tests/test.cpp)
add_executable (clean ./src/clean.cpp)
add_executable (all ./src/all.cpp)

target_link_libraries(kmp kmpFunc)
target_link_libraries(test kmpFunc)
target_link_libraries(NaiveVsKmp kmpFunc)
target_link_libraries(shift kmpFunc)
