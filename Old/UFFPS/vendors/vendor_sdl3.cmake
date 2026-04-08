# vendor_sdl3.cmake
# Fetch and compile SDL3 library
# --------------------------------

# FetchContent module
include(FetchContent)

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
