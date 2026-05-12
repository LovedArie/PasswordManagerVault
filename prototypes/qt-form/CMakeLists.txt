cmake_minimum_required(VERSION 3.20)
project(qt-form LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_AUTOMOC ON)
SET(CMAKE_AUTORCC ON)
SET(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()

qt_add_executable(qt-form main.cpp)

target_link_libraries(qt-form PRIVATE Qt6::Widgets)