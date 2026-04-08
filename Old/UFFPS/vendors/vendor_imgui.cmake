# vendor_imgui.cmake
# Fetch and compile imgui library
# --------------------------------

# FetchContent module
include(FetchContent)

# Check if imgui is already available
if (NOT TARGET imgui)
	message(STATUS "Fetching ImGui...")
	# Fetch ImGui from GitHub
	FetchContent_Declare(
		imgui
		GIT_REPOSITORY https://github.com/ocornut/imgui.git
		GIT_TAG        docking
	)
	FetchContent_MakeAvailable(imgui)

	add_library(imgui)

	target_include_directories(imgui
		PUBLIC
		${imgui_SOURCE_DIR}
		${imgui_SOURCE_DIR}/backends
	)

	target_sources(
		imgui
		PUBLIC
		${imgui_SOURCE_DIR}/imgui.cpp
		${imgui_SOURCE_DIR}/imgui_demo.cpp
		${imgui_SOURCE_DIR}/imgui_draw.cpp
		${imgui_SOURCE_DIR}/imgui_tables.cpp
		${imgui_SOURCE_DIR}/imgui_widgets.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_sdl3.cpp
		${imgui_SOURCE_DIR}/backends/imgui_impl_sdlrenderer3.cpp
	)
endif()

# Add imgui include directory
target_link_libraries(imgui PUBLIC SDL3::SDL3)
