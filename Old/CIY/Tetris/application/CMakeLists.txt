### CMakeLists.txt (Application-cpp/application)
### This file is made to build a Godhunter application.

# Test application
# --------------------------------
add_executable (${ProjectId}
"src/main.cpp")


# Engine
# --------------------------------
target_include_directories(${ProjectId} PRIVATE "../engine")


# Fetch contents
# --------------------------------
include(FetchContent)


# Fetch SDL
# --------------------------------
# Set options
set(SDL_SHARED OFF)
set(SDL_STATIC ON)
# Check if SDL3 is already available
if (NOT TARGET SDL3)
	message(STATUS "Fetching SDL3...")
	# Fetch SDL from GitHub
	FetchContent_Declare(
		SDL3
		GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
		GIT_TAG main
	)
	FetchContent_MakeAvailable(SDL3)
endif()
# Add SDL include directory
include_directories(${SDL3_SOURCE_DIR}/include)
target_link_libraries(${ProjectId} SDL3-static)
