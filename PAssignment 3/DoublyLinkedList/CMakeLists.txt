cmake_minimum_required(VERSION 3.7)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        DoublyLinkedList.cpp
        DoublyLinkedList.h
        Main.cpp)

add_executable(DoublyLinkedList ${SOURCE_FILES})