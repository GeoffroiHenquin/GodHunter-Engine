﻿# CMakeList.txt : CMake project for Sandbox, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (Sandbox "src/main.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sandbox PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

# Linking with GodHunter
include_directories(${PROJECT_SOURCE_DIR}/GodHunter/src ${COMMON_INCLUDES})
target_link_libraries(Sandbox GodHunter)
