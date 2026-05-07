cmake_minimum_required(VERSION 3.16)
project(qt-hello LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt needs these on for any non-trivial widget code.
# Hello World doesn't strictly need AUTOMOC, but turning it on now
# means we don't have to remember to flip it later.
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(qt-hello main.cpp)

target_link_libraries(qt-hello PRIVATE Qt6::Widgets)