cmake_minimum_required(VERSION 3.16)
project(qt-signals LANGUAGES CXX)

set(CMAKE_CXX_STANDAD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(qt-signals main.cpp)

target_link_libraries(qt-signals PRIVATE Qt6::Widgets)