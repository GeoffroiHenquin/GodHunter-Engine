/**
 * @file human_interface_devices.h
 * This file is part of the GodHunter Engine
 *
 * This file contains classes and structs representing a gui window.
 *
 * MIT License
 *
 * Copyright (c) 2023 GeoffroiHenquin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

// Related header

// C system headers

// C++ standard library headers

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_HUMAN_INTERFACE_DEVICES_H_
#define GODHUNTER_SRC_HUMAN_INTERFACE_DEVICES_H_

namespace godhunter
{

	/**
	 * This function should be called at the start of the program to init SDL
	 * 
	 * @return void
	 */
	void initHumanInterfaceDevices();

	/**
	 * This function should be called at the end of the program to close SDL
	 * 
	 * @return void
	 */
	void closeHumanInterfaceDevices();

	/**
	 * Struct - GUIWindowDataContainer
	 *
	 * This struct will contain a graphic window provided by a third party library.
	 * WARNING: this struct should only be defined and used in "human_interface_devices.cpp". This is done in order to avoid dependencies.
	 */
	struct GUIWindowDataContainer;

	/**
	 * Enum - WindowBorderFlag
	 *
	 * This enum decide if there's a border on the window and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowBorderFlag
	{
		window_border_default = 0,
		window_border_borderless = 1
	};

	/**
	 * Enum - WindowCaptureFlag
	 *
	 * This enum decide if the mouse is captured by the window and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowCaptureFlag
	{
		window_capture_default = 0,
		window_capture_mouse = 1 // will detect mouse movement even outside of window
	};

	/**
	 * Enum - WindowFocusFlag
	 *
	 * This enum decide if the window has the focus of the mouse and inputs and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowFocusFlag
	{
		window_focus_default = 0,
		window_focus_mouse = 1,
		window_focus_input = 2,
		window_focus_mouse_and_input = 3,
		window_focus_not_focusable = 4 // cant be focused
	};

	/**
	 * Enum - WindowGrabFlag
	 *
	 * This enum decide if the window has grabbed the mouse and inputs and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowGrabFlag
	{
		window_grab_default = 0,
		window_grab_mouse = 1, // mouse cant exit window
		window_grab_keyboard = 2, // keyboard inputs cant exit window
		window_grab_mouse_and_keyboard = 3
	};

	/**
	 * Enum - WindowPositionFlag
	 *
	 * This enum decide if the window is on top of the others and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowPositionFlag
	{
		window_position_default = 0,
		window_position_always_on_top = 1, // always on top of other windows
		window_position_occluded = 2 // window is treated as if it was in the background (dont update/dont render)
	};

	/**
	 * Enum - WindowQualityFlag
	 *
	 * This enum decide if there's high pixel density on the window and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowQualityFlag
	{
		window_quality_default = 0,
		window_quality_high_pixel_density = 1
	};

	/**
	 * Enum - WindowResizeFlag
	 *
	 * This enum decide if the window can be resized and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowResizeFlag
	{
		window_resize_default = 0,
		window_resize_resizable = 1
	};

	/**
	 * Enum - WindowSizeFlag
	 *
	 * This enum decide if the window is fullscreen or minimized and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowSizeFlag
	{
		window_size_default = 0,
		window_size_minimized = 1, // window is minimized
		window_size_maximized = 2, // window is maximized
		window_size_fullscreen = 3 // window is fullscreen
		
	};

	/**
	 * Enum - WindowSystemFlag
	 *
	 * This enum decide if the window uses another system and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowSystemFlag
	{
		window_system_default = 0,
		window_system_opengl = 1, // mix sdl and opengl
		window_system_vulkan = 2, // mix sdl and vulkan
		window_system_metal = 3, // mix sdl and metal
		window_system_external = 4 // uses an external window
	};

	/**
	 * Enum - WindowTypeFlag
	 *
	 * This enum decide if the window is normal or a popup and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowTypeFlag
	{
		window_type_default = 0,
		window_type_utility = 1,
		window_type_tooltip = 2,
		window_type_popup_menu = 3
	};

	/**
	 * Enum - WindowVisibilityFlag
	 *
	 * This enum decide if the window is visible or not and is based on the various SDL window flag (https://wiki.libsdl.org/SDL3/SDL_WindowFlags).
	 */
	enum WindowVisibilityFlag
	{
		window_visibility_default = 0,
		window_visibility_transparent = 1, // window is transparent
		window_visibility_hidden = 2 // window cant be seen / is invisible
	};

	/**
	 * Struct - GUIWindowInformation
	 *
	 * Contains information for a window such as name, size, etc.
	 */
	struct GUIWindowInformation
	{
		// Window name
		char* name;
		// Window size
		int width;
		int height;
		// Window flags
		WindowBorderFlag window_border_flag = window_border_default;
		WindowCaptureFlag window_capture_flag = window_capture_default;
		WindowFocusFlag window_focus_flag = window_focus_default;
		WindowGrabFlag window_grab_flag = window_grab_default;
		WindowPositionFlag window_position_flag = window_position_default;
		WindowQualityFlag window_quality_flag = window_quality_default;
		WindowResizeFlag window_resize_flag = window_resize_default;
		WindowSizeFlag window_size_flag = window_size_default;
		WindowSystemFlag window_system_flag = window_system_default;
		WindowTypeFlag window_type_flag = window_type_default;
		WindowVisibilityFlag window_visibility_flag = window_visibility_default;
	};

	/**
	 * Class - GUIWindow
	 *
	 * This class is used as a graphic window.
	 */
	class GUIWindow
	{
	private:
		// Contains a gui window provided by a third party library. It should only be used in the class GUIWindow.
		GUIWindowDataContainer* m_gui_data_container;

	public:
		GUIWindow();
		~GUIWindow();

		/**
		 * This create a default window
		 *
		 * @return void
		 */
		void createWindow();

		/**
		 * This create a window from information
		 *
		 * @param window_information_ Contains information for a window such as name, size, etc.
		 * @return void
		 */
		void createWindow(GUIWindowInformation window_information_);

		/**
		 * This destroy a window
		 *
		 * @return void
		 */
		void destroyWindow();
	}; // class GUIWindow

} // namespace godhunter

#endif // GODHUNTER_SRC_HUMAN_INTERFACE_DEVICES_H_
