# CMakeList.txt : CMake project for GodHunter, include source and define
# project specific logic here.
#

find_package(SDL2 REQUIRED)

# Add source to this project's executable.
add_library(GodHunter SHARED 
"src/GodHunter.h"
"src/GodHunter/Application.h"
"src/GodHunter/Application.cpp"
"src/GodHunter/Core.h"
"src/GodHunter/EntryPoint.h" 
"src/Core/OsSpecific/OsSpecificSystem.h"
"src/Core/EntitySystem/EntitySystem.h"
"src/Core/EntitySystem/EntitySystem.cpp"
"src/Core/OsSpecific/OsSpecificClock.cpp"
"src/Core/OsSpecific/OsSpecificDisplay.cpp"
"src/Core/OsSpecific/OsSpecificEvent.cpp"
"src/Core/OsSpecific/OsSpecificAudio.cpp"
"src/Core/OsSpecific/OsSpecificSystem.cpp"
"src/Core/Structures/WindowInformation.h"
"src/Core/Structures/Color.h"
"src/Core/Structures/Event.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GodHunter PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
target_link_libraries(GodHunter SDL2::SDL2 SDL2::SDL2main)
add_compile_definitions(BUILD_SHAREDLIB)