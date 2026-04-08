### CMakeLists.txt
### This file is made to build a Godhunter application.


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
set(GODHUNTER_SOURCES
"src/godhunter/debug.cpp"
"src/godhunter/engine.cpp"
"src/godhunter/events.cpp"
"src/godhunter/rendering.cpp"
"src/godhunter/terminal.cpp"
"src/godhunter/timer.cpp"
"src/godhunter/window.cpp"
"src/godhunter/ecs.cpp")

set(GODHUNTER_HEADERS
"src/godhunter/debug.h"
"src/godhunter/engine.h"
"src/godhunter/events.h"
"src/godhunter/rendering.h"
"src/godhunter/terminal.h"
"src/godhunter/timer.h"
"src/godhunter/window.h"
"src/godhunter/ecs.h")

set(MAIN_SOURCES
"src/main.cpp")

add_executable (${ProjectId}
${GODHUNTER_SOURCES}
${GODHUNTER_HEADERS}
${MAIN_SOURCES} "src/godhunter/components/default_component.h")


# Declare preprocessor definitions for the application
# --------------------------------
# DEBUG
target_compile_definitions(${ProjectId} PRIVATE $<$<CONFIG:Debug>:DEBUG>)


# Include assets in the application
# --------------------------------
include("./tools/AssetEmbedder/embed-assets.cmake")


# Link libraries with the application
# --------------------------------
include("./cmake/fetch-sdl.cmake")

include("./cmake/fetch-lua.cmake")

include("./cmake/fetch-sol.cmake")


# Set application data
# --------------------------------
# Set application title
file (STRINGS "data/application_title.txt" APPLICATION_TITLE)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${APPLICATION_TITLE})
# Set application icon
include("./cmake/set-icon.cmake")