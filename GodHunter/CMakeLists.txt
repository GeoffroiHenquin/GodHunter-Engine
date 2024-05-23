# CMakeList.txt : CMake project for GodHunter, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_library(GodHunter STATIC 
"src/GodHunter.h"
"src/Core/Core.h"
"src/Debug/Debug.h"

"src/Core/OsSpecific/OsSpecificSystem.h"
"src/Core/OsSpecific/OsSpecificClock.cpp"
"src/Core/OsSpecific/OsSpecificDisplay.cpp"
"src/Core/OsSpecific/OsSpecificEvent.cpp"
"src/Core/OsSpecific/OsSpecificAudio.cpp"
"src/Core/OsSpecific/OsSpecificSystem.cpp"

"src/Core/Structures/WindowInformation.h"
"src/Core/Structures/Color.h"
"src/Core/Structures/Event.h"

"src/Debug/Logger/Logger.h"
"src/Debug/Logger/Logger.cpp"
"src/Debug/FrameRate/FrameRate.h"
"src/Debug/FrameRate/FrameRate.cpp"

"src/GodHunter/Engine.h" 
"src/GodHunter/Engine.cpp" "src/Core/Events/UserEvents.h" "src/Core/Events/UserEvents.cpp" "src/Core/Events/EngineEvents.h" "src/GodHunter/EngineState.h" "src/GodHunter/EngineState.cpp")

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
