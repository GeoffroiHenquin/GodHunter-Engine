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
#include <map>

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

	//--------------------------------------------------------------------------------------------------------------------------------------

	class EventSystem_OS
	{
	private:
		bool m_quit = false;
	public:
		void refresh();

		void setEventQuit(bool quit_);
		bool getEventQuit();
	};

	/*enum EventSystem_KeyCode
	{
        key_return = '\r',
        key_escape = '\x1B',
        key_BACKSPACE = '\b',
        key_TAB = '\t',
        key_SPACE = ' ',
        key_EXCLAIM = '!',
        key_QUOTEDBL = '"',
        key_HASH = '#',
        key_PERCENT = '%',
        key_DOLLAR = '$',
        key_AMPERSAND = '&',
        key_QUOTE = '\'',
        key_LEFTPAREN = '(',
        key_RIGHTPAREN = ')',
        key_ASTERISK = '*',
        key_PLUS = '+',
        key_COMMA = ',',
        key_MINUS = '-',
        key_PERIOD = '.',
        key_SLASH = '/',
        SDLK_0 = '0',
        SDLK_1 = '1',
        SDLK_2 = '2',
        SDLK_3 = '3',
        SDLK_4 = '4',
        SDLK_5 = '5',
        SDLK_6 = '6',
        SDLK_7 = '7',
        SDLK_8 = '8',
        SDLK_9 = '9',
        SDLK_COLON = ':',
        SDLK_SEMICOLON = ';',
        SDLK_LESS = '<',
        SDLK_EQUALS = '=',
        SDLK_GREATER = '>',
        SDLK_QUESTION = '?',
        SDLK_AT = '@',

        SDLK_LEFTBRACKET = '[',
        SDLK_BACKSLASH = '\\',
        SDLK_RIGHTBRACKET = ']',
        SDLK_CARET = '^',
        SDLK_UNDERSCORE = '_',
        SDLK_BACKQUOTE = '`',
        SDLK_a = 'a',
        SDLK_b = 'b',
        SDLK_c = 'c',
        SDLK_d = 'd',
        SDLK_e = 'e',
        SDLK_f = 'f',
        SDLK_g = 'g',
        SDLK_h = 'h',
        SDLK_i = 'i',
        SDLK_j = 'j',
        SDLK_k = 'k',
        SDLK_l = 'l',
        SDLK_m = 'm',
        SDLK_n = 'n',
        SDLK_o = 'o',
        SDLK_p = 'p',
        SDLK_q = 'q',
        SDLK_r = 'r',
        SDLK_s = 's',
        SDLK_t = 't',
        SDLK_u = 'u',
        SDLK_v = 'v',
        SDLK_w = 'w',
        SDLK_x = 'x',
        SDLK_y = 'y',
        SDLK_z = 'z',

        SDLK_CAPSLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK),

        SDLK_F1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1),
        SDLK_F2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2),
        SDLK_F3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3),
        SDLK_F4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4),
        SDLK_F5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5),
        SDLK_F6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6),
        SDLK_F7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7),
        SDLK_F8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8),
        SDLK_F9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9),
        SDLK_F10 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10),
        SDLK_F11 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11),
        SDLK_F12 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12),

        SDLK_PRINTSCREEN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN),
        SDLK_SCROLLLOCK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK),
        SDLK_PAUSE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE),
        SDLK_INSERT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT),
        SDLK_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME),
        SDLK_PAGEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP),
        SDLK_DELETE = '\x7F',
        SDLK_END = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END),
        SDLK_PAGEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN),
        SDLK_RIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT),
        SDLK_LEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT),
        SDLK_DOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN),
        SDLK_UP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP),

        SDLK_NUMLOCKCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR),
        SDLK_KP_DIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE),
        SDLK_KP_MULTIPLY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY),
        SDLK_KP_MINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS),
        SDLK_KP_PLUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS),
        SDLK_KP_ENTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER),
        SDLK_KP_1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1),
        SDLK_KP_2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2),
        SDLK_KP_3 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3),
        SDLK_KP_4 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4),
        SDLK_KP_5 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5),
        SDLK_KP_6 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6),
        SDLK_KP_7 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7),
        SDLK_KP_8 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8),
        SDLK_KP_9 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9),
        SDLK_KP_0 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0),
        SDLK_KP_PERIOD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD),

        SDLK_APPLICATION = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION),
        SDLK_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER),
        SDLK_KP_EQUALS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS),
        SDLK_F13 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13),
        SDLK_F14 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14),
        SDLK_F15 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15),
        SDLK_F16 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16),
        SDLK_F17 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17),
        SDLK_F18 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18),
        SDLK_F19 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19),
        SDLK_F20 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20),
        SDLK_F21 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21),
        SDLK_F22 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22),
        SDLK_F23 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23),
        SDLK_F24 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24),
        SDLK_EXECUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE),
        SDLK_HELP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP),
        SDLK_MENU = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU),
        SDLK_SELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT),
        SDLK_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP),
        SDLK_AGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN),
        SDLK_UNDO = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO),
        SDLK_CUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT),
        SDLK_COPY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY),
        SDLK_PASTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE),
        SDLK_FIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND),
        SDLK_MUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE),
        SDLK_VOLUMEUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP),
        SDLK_VOLUMEDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN),
        SDLK_KP_COMMA = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA),
        SDLK_KP_EQUALSAS400 =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400),

        SDLK_ALTERASE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE),
        SDLK_SYSREQ = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ),
        SDLK_CANCEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL),
        SDLK_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR),
        SDLK_PRIOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR),
        SDLK_RETURN2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2),
        SDLK_SEPARATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR),
        SDLK_OUT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT),
        SDLK_OPER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER),
        SDLK_CLEARAGAIN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN),
        SDLK_CRSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL),
        SDLK_EXSEL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL),

        SDLK_KP_00 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00),
        SDLK_KP_000 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000),
        SDLK_THOUSANDSSEPARATOR =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR),
        SDLK_DECIMALSEPARATOR =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR),
        SDLK_CURRENCYUNIT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT),
        SDLK_CURRENCYSUBUNIT =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT),
        SDLK_KP_LEFTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN),
        SDLK_KP_RIGHTPAREN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN),
        SDLK_KP_LEFTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE),
        SDLK_KP_RIGHTBRACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE),
        SDLK_KP_TAB = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB),
        SDLK_KP_BACKSPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE),
        SDLK_KP_A = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A),
        SDLK_KP_B = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B),
        SDLK_KP_C = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C),
        SDLK_KP_D = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D),
        SDLK_KP_E = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E),
        SDLK_KP_F = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F),
        SDLK_KP_XOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR),
        SDLK_KP_POWER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER),
        SDLK_KP_PERCENT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT),
        SDLK_KP_LESS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS),
        SDLK_KP_GREATER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER),
        SDLK_KP_AMPERSAND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND),
        SDLK_KP_DBLAMPERSAND =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND),
        SDLK_KP_VERTICALBAR =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR),
        SDLK_KP_DBLVERTICALBAR =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR),
        SDLK_KP_COLON = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON),
        SDLK_KP_HASH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH),
        SDLK_KP_SPACE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE),
        SDLK_KP_AT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT),
        SDLK_KP_EXCLAM = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM),
        SDLK_KP_MEMSTORE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE),
        SDLK_KP_MEMRECALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL),
        SDLK_KP_MEMCLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR),
        SDLK_KP_MEMADD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD),
        SDLK_KP_MEMSUBTRACT =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT),
        SDLK_KP_MEMMULTIPLY =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY),
        SDLK_KP_MEMDIVIDE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE),
        SDLK_KP_PLUSMINUS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS),
        SDLK_KP_CLEAR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR),
        SDLK_KP_CLEARENTRY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY),
        SDLK_KP_BINARY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY),
        SDLK_KP_OCTAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL),
        SDLK_KP_DECIMAL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL),
        SDLK_KP_HEXADECIMAL =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL),

        SDLK_LCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL),
        SDLK_LSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT),
        SDLK_LALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT),
        SDLK_LGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI),
        SDLK_RCTRL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL),
        SDLK_RSHIFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT),
        SDLK_RALT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT),
        SDLK_RGUI = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI),

        SDLK_MODE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE),

        SDLK_AUDIONEXT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT),
        SDLK_AUDIOPREV = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV),
        SDLK_AUDIOSTOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP),
        SDLK_AUDIOPLAY = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY),
        SDLK_AUDIOMUTE = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE),
        SDLK_MEDIASELECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT),
        SDLK_WWW = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW),
        SDLK_MAIL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL),
        SDLK_CALCULATOR = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR),
        SDLK_COMPUTER = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER),
        SDLK_AC_SEARCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH),
        SDLK_AC_HOME = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME),
        SDLK_AC_BACK = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK),
        SDLK_AC_FORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD),
        SDLK_AC_STOP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP),
        SDLK_AC_REFRESH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH),
        SDLK_AC_BOOKMARKS = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS),

        SDLK_BRIGHTNESSDOWN =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN),
        SDLK_BRIGHTNESSUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP),
        SDLK_DISPLAYSWITCH = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH),
        SDLK_KBDILLUMTOGGLE =
        SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE),
        SDLK_KBDILLUMDOWN = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN),
        SDLK_KBDILLUMUP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP),
        SDLK_EJECT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT),
        SDLK_SLEEP = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP),
        SDLK_APP1 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1),
        SDLK_APP2 = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2),

        SDLK_AUDIOREWIND = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND),
        SDLK_AUDIOFASTFORWARD = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD),

        SDLK_SOFTLEFT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT),
        SDLK_SOFTRIGHT = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT),
        SDLK_CALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL),
        SDLK_ENDCALL = SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL)
	};*/

	class EventSystem_Keyboard
	{
    private:
        std::map<char, bool> m_key_down;
        std::map<char, bool> m_key_pressed;
        std::map<char, bool> m_key_up;
	public:
		void refresh();

		void setEventKeyDown(char key_);
		void setEventKeyUp(char key_);

		bool getEventKeyDown(char key_);
		bool getEventKeyPressed(char key_);
		bool getEventKeyUp(char key_);
	};

	class EventSystem
	{
	public:
		EventSystem_OS m_operating_system;
		EventSystem_Keyboard m_keyboard;
	public:
		void handleEvents();
	};

} // namespace godhunter

#endif // GODHUNTER_SRC_HUMAN_INTERFACE_DEVICES_H_
