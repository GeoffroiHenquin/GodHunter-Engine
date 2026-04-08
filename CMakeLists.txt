### CMakeLists.txt
### This file is made to build the entire solution.


# Settings
# --------------------------------
# CMake version
cmake_minimum_required (VERSION 3.8)
# C version
set(CMAKE_C_STANDARD 20)
# C++ version
set(CMAKE_CXX_STANDARD 20)


# Project ID
# --------------------------------
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})


# Project
# --------------------------------
project(${ProjectId})


# Api
# --------------------------------
# add_subdirectory("api")
