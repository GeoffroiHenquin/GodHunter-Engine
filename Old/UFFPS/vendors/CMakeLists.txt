### CMakeLists.txt (UFFPS/vendors)
### This file is made to fetch and build the vendors.


# Settings
# --------------------------------
# CMake version
cmake_minimum_required (VERSION 3.8)
# C++ version
set(CMAKE_CXX_STANDARD 20)
# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
	cmake_policy(SET CMP0141 NEW)
	set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT
	"$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# Project ID
# --------------------------------
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})


# Project
# --------------------------------
project(${ProjectId})


# SDL3
# --------------------------------
include(vendor_sdl3.cmake)


# imgui
# --------------------------------
include(vendor_imgui.cmake)
