cmake_minimum_required(VERSION 3.7)
project(HelloWorld)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(HelloWorld ${SOURCE_FILES})