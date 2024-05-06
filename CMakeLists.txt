# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GodHunter")

# Include sub-projects.

# SDL3 (Set as a Static Lib)
set(SDL_SHARED OFF)
set(SDL_STATIC ON)
add_subdirectory(vendor/sdl/SDL)

# GodHunter Engine (Set as a Static Lib)
add_subdirectory ("GodHunter")

# Game Project (Executable)
add_subdirectory ("Sandbox")
