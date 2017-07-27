cmake_minimum_required(VERSION 3.7)
project(MinQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MinQueue.cpp MinQueue.h TemplateDoublyLinkedList.h)
add_executable(MinQueue ${SOURCE_FILES})