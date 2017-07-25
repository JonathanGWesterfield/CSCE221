cmake_minimum_required(VERSION 3.7)
project(TemplateDoublyLinkedList)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        TemplateMain.cpp TemplateDoublyLinkedList.h)

add_executable(TemplateDoublyLinkedList ${SOURCE_FILES})