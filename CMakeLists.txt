# Minimum CMake version required. Most modern Linux distros and macOS ship 3.20+.
cmake_minimum_required(VERSION 3.20)

# The project's name and the languages it uses.
# CHANGE "MyProject" to your project's actual name when you copy this template.
project(PasswordManager
    VERSION 0.1.0
    DESCRIPTION "A cloud password manager with Qt GUI"
    LANGUAGES CXX
)

# Use the C++17 standard. Change to 20 or 23 if your compiler supports them.
# Stroustrup's book covers C++11 by default; C++17 is a safe modern minimum.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)  # use -std=c++17, not -std=gnu++17

# Tell the compiler to treat 'include/' as a folder where headers live, so you
# can write `#include "myheader.h"` instead of `#include "../include/myheader.h"`.
include_directories(include)

# Build domain-logic source files into a static library so both the main
# app and the test executable can link against the same code.
add_library(domain
    src/Vault.cpp
    src/Entry.cpp
)

# The main application executable.
add_executable(${PROJECT_NAME}
    src/main.cpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE domain)

# --- Tests (optional, comment in when you add a test framework) ---
enable_testing()
add_subdirectory(tests)

# --- Notes ---
# To build:
#     mkdir build && cd build
#     cmake ..
#     cmake --build .
# To run:
#     ./PasswordManager        (Linux/macOS)
#     PasswordManager.exe      (Windows)
