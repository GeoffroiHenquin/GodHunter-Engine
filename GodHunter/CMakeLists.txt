# CMakeList.txt : CMake project for GodHunter, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(GodHunter STATIC "src/godhunter.h" "src/engine.h" "src/engine.cpp" "src/human_interface_devices.h" "src/human_interface_devices.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GodHunter PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

target_compile_definitions(GodHunter
    PRIVATE
        # If the debug configuration pass the DEBUG define to the compiler 
        $<$<CONFIG:Debug>:DEBUG>
)

# Linking with SDL
include_directories(${PROJECT_SOURCE_DIR}/vendor/sdl/SDL/include ${COMMON_INCLUDES})
target_link_libraries(GodHunter SDL3-static)
