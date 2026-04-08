### CMakeLists.txt (Application-cpp/application)
### This file is made to build a Godhunter application.

# Test application
# --------------------------------
add_executable (${ProjectId}
"src/main.cpp")


# Engine
# --------------------------------
target_include_directories(${ProjectId} PRIVATE "../engine")