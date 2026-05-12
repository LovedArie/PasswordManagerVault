cmake_minimum_required(VERSION 3.20)
project(qt-dialog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(qt-dialog main.cpp)
target_link_libraries(qt-dialog PRIVATE Qt6::Widgets)