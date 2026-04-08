### CMakeLists.txt (UFFPS)
### This file is made to build a prototype for FNAF Tycoon Game.


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


# Application
# --------------------------------
add_executable (${ProjectId}
"src/main.cpp")


# Vendor Libraries
# --------------------------------
add_subdirectory(vendors)

# Vendor : SDL
target_link_libraries(${ProjectId} SDL3-static)

# Vendor : imgui
target_link_libraries(${ProjectId} imgui)


