### Fetch SDL
### This file is made to fetch and include SDL into the project.
### SDL is a cross-platform library for creating games and other interactive applications.

# Include FetchContent
include(FetchContent)

# Set options
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

# Fetch SDL from GitHub
FetchContent_Declare(
    SDL3
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG main
)
FetchContent_MakeAvailable(SDL3)

# Add SDL include directory
include_directories(${SDL3_SOURCE_DIR}/include)
target_link_libraries(${ProjectId} SDL3-static)
