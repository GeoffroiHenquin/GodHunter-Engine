### Fetch Sol
### This file is made to fetch and include Sol into the project.
### Sol is a C++ wrapper for the Lua programming language.

# Include FetchContent
include(FetchContent)

# Fetch Sol from GitHub
FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG main
)
FetchContent_MakeAvailable(sol2)

# Add Sol include directory
include_directories(${sol2_SOURCE_DIR}/single/include)
