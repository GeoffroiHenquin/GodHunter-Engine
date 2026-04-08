### CMakeLists.txt (Application-cpp/tests)
### This file is made to test a Godhunter application.

# Test application
# --------------------------------
add_executable (${ProjectId}-Tests
"src/main.cpp"
"src/tests/ecs.tests.cpp")


# Engine
# --------------------------------
target_include_directories(${ProjectId}-Tests PRIVATE "../engine")


# Tests
# --------------------------------
# Fetch Googletest
include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# No need for GMock
set( BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set( INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set( GTEST_FORCE_SHARED_CRT ON CACHE BOOL "" FORCE)
set( GTEST_DISABLE_PTHREADS ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Link with gtest
target_link_libraries(${ProjectId}-Tests gtest)