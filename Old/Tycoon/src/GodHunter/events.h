/**
 * @file events.h
 * This file is part of the GodHunter Engine
 *
 * This file declare methods to handle events.
 *
 * MIT License
 *
 * Copyright (c) 2025 GeoffroiHenquin
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
#include <SDL3/SDL.h>

// Project headers

// Exceptions


#ifndef GODHUNTER_EVENTS_H_
#define GODHUNTER_EVENTS_H_

namespace godhunter
{

	// Raw Event Types --------------------------------
	// https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_events.h
	enum class Event
	{
		QUIT = 0,
		TERMINATING,
		LOW_MEMORY,

		WILL_ENTER_BACKGROUND,
		DID_ENTER_BACKGROUND,
		WILL_ENTER_FOREGROUND,
		DID_ENTER_FOREGROUND,

		LOCALE_CHANGED,
		SYSTEM_THEME_CHANGED,

		DISPLAY_ORIENTATION,
		DISPLAY_ADDED,
		DISPLAY_REMOVED,
		DISPLAY_MOVED,
		DISPLAY_DESKTOP_MODE_CHANGED,
		DISPLAY_CURRENT_MODE_CHANGED,
		DISPLAY_CONTENT_SCALE_CHANGED,
		DISPLAY_USABLE_BOUNDS_CHANGED,

		WINDOW_SHOWN,
		WINDOW_HIDDEN,
		WINDOW_EXPOSED,
		WINDOW_MOVED,
		WINDOW_RESIZED,
		WINDOW_PIXEL_SIZE_CHANGED,
		WINDOW_METAL_VIEW_RESIZED,
		WINDOW_MINIMIZED,
		WINDOW_MAXIMIZED,
		WINDOW_RESTORED,
		WINDOW_MOUSE_ENTER,
		WINDOW_MOUSE_LEAVE,
		WINDOW_FOCUS_GAINED,
		WINDOW_FOCUS_LOST,
		WINDOW_CLOSE_REQUESTED,
		WINDOW_HIT_TEST,
		WINDOW_ICCPROF_CHANGED,
		WINDOW_DISPLAY_CHANGED,
		WINDOW_DISPLAY_SCALE_CHANGED,
		WINDOW_SAFE_AREA_CHANGED,
		WINDOW_OCCLUDED,
		WINDOW_ENTER_FULLSCREEN,
		WINDOW_LEAVE_FULLSCREEN,
		WINDOW_DESTROYED,
		WINDOW_HDR_STATE_CHANGED,

		KEY_DOWN, // Precision
		KEY_STAY, // Precision
		KEY_UP, // Precision
		TEXT_EDITING,
		TEXT_INPUT,
		KEYMAP_CHANGED,
		KEYBOARD_ADDED,
		KEYBOARD_REMOVED,
		TEXT_EDITING_CANDIDATES,

		MOUSE_MOTION, // complex output
		MOUSE_BUTTON_DOWN, // Precision
		MOUSE_BUTTON_STAY, // Precision
		MOUSE_BUTTON_UP, // Precision
		MOUSE_WHEEL, // complex output
		MOUSE_ADDED,
		MOUSE_REMOVED,

		JOYSTICK_AXIS_MOTION,
		JOYSTICK_BALL_MOTION,
		JOYSTICK_HAT_MOTION,
		JOYSTICK_BUTTON_DOWN,
		JOYSTICK_BUTTON_UP,
		JOYSTICK_ADDED,
		JOYSTICK_REMOVED,
		JOYSTICK_BATTERY_UPDATED,
		JOYSTICK_UPDATE_COMPLETE,

		GAMEPAD_AXIS_MOTION,
		GAMEPAD_BUTTON_DOWN,
		GAMEPAD_BUTTON_UP,
		GAMEPAD_ADDED,
		GAMEPAD_REMOVED,
		GAMEPAD_REMAPPED,
		GAMEPAD_TOUCHPAD_DOWN,
		GAMEPAD_TOUCHPAD_MOTION,
		GAMEPAD_TOUCHPAD_UP,
		GAMEPAD_SENSOR_UPDATE,
		GAMEPAD_UPDATE_COMPLETE,
		GAMEPAD_STEAM_HANDLE_UPDATED,

		FINGER_DOWN,
		FINGER_UP,
		FINGER_MOTION,
		FINGER_CANCELED,

		CLIPBOARD_UPDATE,

		DROP_FILE,
		DROP_TEXT,
		DROP_BEGIN,
		DROP_COMPLETE,
		DROP_POSITION,

		AUDIO_DEVICE_ADDED,
		AUDIO_DEVICE_REMOVED,
		AUDIO_DEVICE_FORMAT_CHANGED,

		SENSOR_UPDATE,

		PEN_PROXIMITY_IN,
		PEN_PROXIMITY_OUT,
		PEN_DOWN,
		PEN_UP,
		PEN_BUTTON_DOWN,
		PEN_BUTTON_UP,
		PEN_MOTION,
		PEN_AXIS,

		CAMERA_DEVICE_ADDED,
		CAMERA_DEVICE_REMOVED,
		CAMERA_DEVICE_APPROVED,
		CAMERA_DEVICE_DENIED,

		RENDER_TARGETS_RESET,
		RENDER_DEVICE_RESET,
		RENDER_DEVICE_LOST,

		UNKNOWN,

		EVENT_COUNT // Used to get the size of the enum
	};

	// Key Event Data --------------------------------
	// https://wiki.libsdl.org/SDL3/SDL_Keycode
	enum class Keycode
	{
		RETURN = SDLK_RETURN, // \n
		ESCAPE = SDLK_ESCAPE, // esc
		BACKSPACE = SDLK_BACKSPACE, // \b
		TAB = SDLK_TAB, // tab
		SPACE = SDLK_SPACE, // space
		EXCLAIM = SDLK_EXCLAIM, // !
		DBLAPOSTROPHE = SDLK_DBLAPOSTROPHE, // "
		HASH = SDLK_HASH, // #
		DOLLAR = SDLK_DOLLAR, // $
		PERCENT = SDLK_PERCENT, // %
		AMPERSAND = SDLK_AMPERSAND, // &
		APOSTROPHE = SDLK_APOSTROPHE, // '
		LEFTPAREN = SDLK_LEFTPAREN, // (
		RIGHTPAREN = SDLK_RIGHTPAREN, // )
		ASTERISK = SDLK_ASTERISK, // *
		PLUS = SDLK_PLUS, // +
		COMMA = SDLK_COMMA, // ,
		MINUS = SDLK_MINUS, // -
		PERIOD = SDLK_PERIOD, // .
		SLASH = SDLK_SLASH, // /
		ZERO = SDLK_0, // 0
		ONE = SDLK_1, // 1
		TWO = SDLK_2, // 2
		THREE = SDLK_3, // 3
		FOUR = SDLK_4, // 4
		FIVE = SDLK_5, // 5
		SIX = SDLK_6, // 6
		SEVEN = SDLK_7, // 7
		EIGHT = SDLK_8, // 8
		NINE = SDLK_9, // 9
		COLON = SDLK_COLON, // :
		SEMICOLON = SDLK_SEMICOLON, // ;
		LESS = SDLK_LESS, // <
		EQUALS = SDLK_EQUALS, // =
		GREATER = SDLK_GREATER, // >
		QUESTION = SDLK_QUESTION, // ?
		AT = SDLK_AT, // @
		LEFTBRACKET = SDLK_LEFTBRACKET, // [
		BACKSLASH = SDLK_BACKSLASH, /* \ */
		RIGHTBRACKET = SDLK_RIGHTBRACKET, // ]
		CARET = SDLK_CARET, // ^
		UNDERSCORE = SDLK_UNDERSCORE, // _
		GRAVE = SDLK_GRAVE, // `
		A = SDLK_A, // a
		B = SDLK_B, // b
		C = SDLK_C, // c
		D = SDLK_D, // d
		E = SDLK_E, // e
		F = SDLK_F, // f
		G = SDLK_G, // g
		H = SDLK_H, // h
		I = SDLK_I, // i
		J = SDLK_J, // j
		K = SDLK_K, // k
		L = SDLK_L, // l
		M = SDLK_M, // m
		N = SDLK_N, // n
		O = SDLK_O, // o
		P = SDLK_P, // p
		Q = SDLK_Q, // q
		R = SDLK_R, // r
		S = SDLK_S, // s
		T = SDLK_T, // t
		U = SDLK_U, // u
		V = SDLK_V, // v
		W = SDLK_W, // w
		X = SDLK_X, // x
		Y = SDLK_Y, // y
		Z = SDLK_Z, // z
		LEFTBRACE = SDLK_LEFTBRACE, // {
		PIPE = SDLK_PIPE, // |
		RIGHTBRACE = SDLK_RIGHTBRACE, // }
		TILDE = SDLK_TILDE, // ~
		DELETE = SDLK_DELETE, // Delete
		PLUSMINUS = SDLK_PLUSMINUS, // ±
		CAPSLOCK = SDLK_CAPSLOCK, // Caps Lock
		F1 = SDLK_F1, // F1
		F2 = SDLK_F2, // F2
		F3 = SDLK_F3, // F3
		F4 = SDLK_F4, // F4
		F5 = SDLK_F5, // F5
		F6 = SDLK_F6, // F6
		F7 = SDLK_F7, // F7
		F8 = SDLK_F8, // F8
		F9 = SDLK_F9, // F9
		F10 = SDLK_F10, // F10
		F11 = SDLK_F11, // F11
		F12 = SDLK_F12, // F12
		PRINTSCREEN = SDLK_PRINTSCREEN, // Print Screen
		SCROLLLOCK = SDLK_SCROLLLOCK, // Scroll Lock
		PAUSE = SDLK_PAUSE, // Pause
		INSERT = SDLK_INSERT, // Insert
		HOME = SDLK_HOME, // Home
		PAGEUP = SDLK_PAGEUP, // Page Up
		END = SDLK_END, // End
		PAGEDOWN = SDLK_PAGEDOWN, // Page Down
		RIGHT = SDLK_RIGHT, // Right Arrow
		LEFT = SDLK_LEFT, // Left Arrow
		DOWN = SDLK_DOWN, // Down Arrow
		UP = SDLK_UP, // Up Arrow
		NUMLOCKCLEAR = SDLK_NUMLOCKCLEAR, // Num Lock
		KP_DIVIDE = SDLK_KP_DIVIDE, // Keypad /
		KP_MULTIPLY = SDLK_KP_MULTIPLY, // Keypad *
		KP_MINUS = SDLK_KP_MINUS, // Keypad -
		KP_PLUS = SDLK_KP_PLUS, // Keypad +
		KP_ENTER = SDLK_KP_ENTER, // Keypad Enter
		KP_1 = SDLK_KP_1, // Keypad 1
		KP_2 = SDLK_KP_2, // Keypad 2
		KP_3 = SDLK_KP_3, // Keypad 3
		KP_4 = SDLK_KP_4, // Keypad 4
		KP_5 = SDLK_KP_5, // Keypad 5
		KP_6 = SDLK_KP_6, // Keypad 6
		KP_7 = SDLK_KP_7, // Keypad 7
		KP_8 = SDLK_KP_8, // Keypad 8
		KP_9 = SDLK_KP_9, // Keypad 9
		KP_0 = SDLK_KP_0, // Keypad 0
		KP_PERIOD = SDLK_KP_PERIOD, // Keypad .
		APPLICATION = SDLK_APPLICATION, // Application
		POWER = SDLK_POWER, // Power
		KP_EQUALS = SDLK_KP_EQUALS, // Keypad =
		F13 = SDLK_F13, // F13
		F14 = SDLK_F14, // F14
		F15 = SDLK_F15, // F15
		F16 = SDLK_F16, // F16
		F17 = SDLK_F17, // F17
		F18 = SDLK_F18, // F18
		F19 = SDLK_F19, // F19
		F20 = SDLK_F20, // F20
		F21 = SDLK_F21, // F21
		F22 = SDLK_F22, // F22
		F23 = SDLK_F23, // F23
		F24 = SDLK_F24, // F24
		EXECUTE = SDLK_EXECUTE, // Execute
		HELP = SDLK_HELP, // Help
		MENU = SDLK_MENU, // Menu
		SELECT = SDLK_SELECT, // Select
		STOP = SDLK_STOP, // Stop
		AGAIN = SDLK_AGAIN, // Again
		UNDO = SDLK_UNDO, // Undo
		CUT = SDLK_CUT, // Cut
		COPY = SDLK_COPY, // Copy
		PASTE = SDLK_PASTE, // Paste
		FIND = SDLK_FIND, // Find
		MUTE = SDLK_MUTE, // Mute
		VOLUMEUP = SDLK_VOLUMEUP, // Volume Up
		VOLUMEDOWN = SDLK_VOLUMEDOWN, // Volume Down
		KP_COMMA = SDLK_KP_COMMA, // Keypad ,
		KP_EQUALSAS400 = SDLK_KP_EQUALSAS400, // Keypad = (AS400)
		ALTERASE = SDLK_ALTERASE, // Alternate Erase
		SYSREQ = SDLK_SYSREQ, // Sys Req
		CANCEL = SDLK_CANCEL, // Cancel
		CLEAR = SDLK_CLEAR, // Clear
		PRIOR = SDLK_PRIOR, // Prior
		RETURN2 = SDLK_RETURN2, // Return2
		SEPARATOR = SDLK_SEPARATOR, // Separator
		OUT = SDLK_OUT, // Out
		OPER = SDLK_OPER, // Oper
		CLEARAGAIN = SDLK_CLEARAGAIN, // Clear Again
		CRSEL = SDLK_CRSEL, // Cr Sel
		EXSEL = SDLK_EXSEL, // Ex Sel
		KP_00 = SDLK_KP_00, // Keypad 00
		KP_000 = SDLK_KP_000, // Keypad 000
		THOUSANDSSEPARATOR = SDLK_THOUSANDSSEPARATOR, // Thousands Separator
		DECIMALSEPARATOR = SDLK_DECIMALSEPARATOR, // Decimal Separator
		CURRENCYUNIT = SDLK_CURRENCYUNIT, // Currency Unit
		CURRENCYSUBUNIT = SDLK_CURRENCYSUBUNIT, // Currency Subunit
		KP_LEFTPAREN = SDLK_KP_LEFTPAREN, // Keypad (
		KP_RIGHTPAREN = SDLK_KP_RIGHTPAREN, // Keypad )
		KP_LEFTBRACE = SDLK_KP_LEFTBRACE, // Keypad {
		KP_RIGHTBRACE = SDLK_KP_RIGHTBRACE, // Keypad }
		KP_TAB = SDLK_KP_TAB, // Keypad Tab
		KP_BACKSPACE = SDLK_KP_BACKSPACE, // Keypad Backspace
		KP_A = SDLK_KP_A, // Keypad A
		KP_B = SDLK_KP_B, // Keypad B
		KP_C = SDLK_KP_C, // Keypad C
		KP_D = SDLK_KP_D, // Keypad D
		KP_E = SDLK_KP_E, // Keypad E
		KP_F = SDLK_KP_F, // Keypad F
		KP_XOR = SDLK_KP_XOR, // Keypad XOR
		KP_POWER = SDLK_KP_POWER, // Keypad Power
		KP_PERCENT = SDLK_KP_PERCENT, // Keypad %
		KP_LESS = SDLK_KP_LESS, // Keypad <
		KP_GREATER = SDLK_KP_GREATER, // Keypad >
		KP_AMPERSAND = SDLK_KP_AMPERSAND, // Keypad &
		KP_DBLAMPERSAND = SDLK_KP_DBLAMPERSAND, // Keypad &&
		KP_VERTICALBAR = SDLK_KP_VERTICALBAR, // Keypad |
		KP_DBLVERTICALBAR = SDLK_KP_DBLVERTICALBAR, // Keypad ||
		KP_COLON = SDLK_KP_COLON, // Keypad :
		KP_HASH = SDLK_KP_HASH, // Keypad #
		KP_SPACE = SDLK_KP_SPACE, // Keypad Space
		KP_AT = SDLK_KP_AT, // Keypad @
		KP_EXCLAM = SDLK_KP_EXCLAM, // Keypad !
		KP_MEMSTORE = SDLK_KP_MEMSTORE, // Keypad Memory Store
		KP_MEMRECALL = SDLK_KP_MEMRECALL, // Keypad Memory Recall
		KP_MEMCLEAR = SDLK_KP_MEMCLEAR, // Keypad Memory Clear
		KP_MEMADD = SDLK_KP_MEMADD, // Keypad Memory Add
		KP_MEMSUBTRACT = SDLK_KP_MEMSUBTRACT, // Keypad Memory Subtract
		KP_MEMMULTIPLY = SDLK_KP_MEMMULTIPLY, // Keypad Memory Multiply
		KP_MEMDIVIDE = SDLK_KP_MEMDIVIDE, // Keypad Memory Divide
		KP_PLUSMINUS = SDLK_KP_PLUSMINUS, // Keypad Plus/Minus
		KP_CLEAR = SDLK_KP_CLEAR, // Keypad Clear
		KP_CLEARENTRY = SDLK_KP_CLEARENTRY, // Keypad Clear Entry
		KP_BINARY = SDLK_KP_BINARY, // Keypad Binary
		KP_OCTAL = SDLK_KP_OCTAL, // Keypad Octal
		KP_DECIMAL = SDLK_KP_DECIMAL, // Keypad Decimal
		KP_HEXADECIMAL = SDLK_KP_HEXADECIMAL, // Keypad Hexadecimal
		LCTRL = SDLK_LCTRL, // Left Control
		LSHIFT = SDLK_LSHIFT, // Left Shift
		LALT = SDLK_LALT, // Left Alt
		LGUI = SDLK_LGUI, // Left GUI
		RCTRL = SDLK_RCTRL, // Right Control
		RSHIFT = SDLK_RSHIFT, // Right Shift
		RALT = SDLK_RALT, // Right Alt
		RGUI = SDLK_RGUI, // Right GUI
		MODE = SDLK_MODE, // Mode Shift
		SLEEP = SDLK_SLEEP, // Sleep
		WAKE = SDLK_WAKE, // Wake
		CHANNEL_INCREMENT = SDLK_CHANNEL_INCREMENT, // Channel Increment
		CHANNEL_DECREMENT = SDLK_CHANNEL_DECREMENT, // Channel Decrement
		MEDIA_PLAY = SDLK_MEDIA_PLAY, // Media Play
		MEDIA_PAUSE = SDLK_MEDIA_PAUSE, // Media Pause
		MEDIA_RECORD = SDLK_MEDIA_RECORD, // Media Record
		MEDIA_FAST_FORWARD = SDLK_MEDIA_FAST_FORWARD, // Media Fast Forward
		MEDIA_REWIND = SDLK_MEDIA_REWIND, // Media Rewind
		MEDIA_NEXT_TRACK = SDLK_MEDIA_NEXT_TRACK, // Media Next Track
		MEDIA_PREVIOUS_TRACK = SDLK_MEDIA_PREVIOUS_TRACK, // Media Previous Track
		MEDIA_STOP = SDLK_MEDIA_STOP, // Media Stop
		MEDIA_EJECT = SDLK_MEDIA_EJECT, // Media Eject
		MEDIA_PLAY_PAUSE = SDLK_MEDIA_PLAY_PAUSE, // Media Play/Pause
		MEDIA_SELECT = SDLK_MEDIA_SELECT, // Media Select
		AC_NEW = SDLK_AC_NEW, // AC New
		AC_OPEN = SDLK_AC_OPEN, // AC Open
		AC_CLOSE = SDLK_AC_CLOSE, // AC Close
		AC_EXIT = SDLK_AC_EXIT, // AC Exit
		AC_SAVE = SDLK_AC_SAVE, // AC Save
		AC_PRINT = SDLK_AC_PRINT, // AC Print
		AC_PROPERTIES = SDLK_AC_PROPERTIES, // AC Properties
		AC_SEARCH = SDLK_AC_SEARCH, // AC Search
		AC_HOME = SDLK_AC_HOME, // AC Home
		AC_BACK = SDLK_AC_BACK, // AC Back
		AC_FORWARD = SDLK_AC_FORWARD, // AC Forward
		AC_STOP = SDLK_AC_STOP, // AC Stop
		AC_REFRESH = SDLK_AC_REFRESH, // AC Refresh
		AC_BOOKMARKS = SDLK_AC_BOOKMARKS, // AC Bookmarks
		SOFTLEFT = SDLK_SOFTLEFT, // Soft Left
		SOFTRIGHT = SDLK_SOFTRIGHT, // Soft Right
		CALL = SDLK_CALL, // Call
		ENDCALL = SDLK_ENDCALL, // End Call
		LEFT_TAB = SDLK_LEFT_TAB, // Left Tab
		LEVEL5_SHIFT = SDLK_LEVEL5_SHIFT, // Level 5 Shift
		MULTI_KEY_COMPOSE = SDLK_MULTI_KEY_COMPOSE, // Multi Key Compose
		LMETA = SDLK_LMETA, // Left Meta
		RMETA = SDLK_RMETA, // Right Meta
		LHYPER = SDLK_LHYPER, // Left Hyper
		RHYPER = SDLK_RHYPER, // Right Hyper

		KEY_CODE_COUNT // Used to get the size of the enum
	};

	enum class KeyModifier
	{
		NONE = SDL_KMOD_NONE,
		LSHIFT = SDL_KMOD_LSHIFT,
		RSHIFT = SDL_KMOD_RSHIFT,
		LEVEL5 = SDL_KMOD_LEVEL5,
		LCTRL = SDL_KMOD_LCTRL,
		RCTRL = SDL_KMOD_RCTRL,
		LALT = SDL_KMOD_LALT,
		RALT = SDL_KMOD_RALT,
		LGUI = SDL_KMOD_LGUI,
		RGUI = SDL_KMOD_RGUI,
		NUM = SDL_KMOD_NUM,
		CAPS = SDL_KMOD_CAPS,
		MODE = SDL_KMOD_MODE,
		SCROLL = SDL_KMOD_SCROLL,
		CTRL = SDL_KMOD_CTRL,
		SHIFT = SDL_KMOD_SHIFT,
		ALT = SDL_KMOD_ALT,
		GUI = SDL_KMOD_GUI,

		KEY_MODIFIER_COUNT // Used to get the size of the enum
	};


	// Event Manager -------------------------------
	class Events
	{
	private:
		// List of all possible raw events (key_press_A, mouse_move, etc.)
		bool m_events[static_cast<int>(Event::EVENT_COUNT)] = { false };
		// List of all possible key events (A, B, C, etc.)
		struct {
			bool has_happened = false;
		} m_keyDownEvents[static_cast<int>(Keycode::KEY_CODE_COUNT)];
	public:
		Events()
		{
		}
		~Events()
		{
		}
		void pollEvents()
		{
			// Reset all events to false
			for (int i = 0; i < static_cast<int>(Event::EVENT_COUNT); ++i)
			{
				m_events[i] = false;
			}
			// Poll events
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				switch (event.type)
				{
					/* QUIT EVENTS */
				case SDL_EVENT_QUIT:
					m_events[static_cast<int>(Event::QUIT)] = true;
					break;
				case SDL_EVENT_TERMINATING:
					m_events[static_cast<int>(Event::TERMINATING)] = true;
					break;
				case SDL_EVENT_LOW_MEMORY:
					m_events[static_cast<int>(Event::LOW_MEMORY)] = true;
					break;
					/* ENTERING / EXITING BACKGROUND */
				case SDL_EVENT_WILL_ENTER_BACKGROUND:
					m_events[static_cast<int>(Event::WILL_ENTER_BACKGROUND)] = true;
					break;
				case SDL_EVENT_DID_ENTER_BACKGROUND:
					m_events[static_cast<int>(Event::DID_ENTER_BACKGROUND)] = true;
					break;
				case SDL_EVENT_WILL_ENTER_FOREGROUND:
					m_events[static_cast<int>(Event::WILL_ENTER_FOREGROUND)] = true;
					break;
				case SDL_EVENT_DID_ENTER_FOREGROUND:
					m_events[static_cast<int>(Event::DID_ENTER_FOREGROUND)] = true;
					break;
					/* SYSTEM EVENTS */
				case SDL_EVENT_LOCALE_CHANGED:
					m_events[static_cast<int>(Event::LOCALE_CHANGED)] = true;
					break;
				case SDL_EVENT_SYSTEM_THEME_CHANGED:
					m_events[static_cast<int>(Event::SYSTEM_THEME_CHANGED)] = true;
					break;
					/* DISPLAY EVENTS */
				case SDL_EVENT_DISPLAY_ORIENTATION:
					m_events[static_cast<int>(Event::DISPLAY_ORIENTATION)] = true;
					break;
				case SDL_EVENT_DISPLAY_ADDED:
					m_events[static_cast<int>(Event::DISPLAY_ADDED)] = true;
					break;
				case SDL_EVENT_DISPLAY_REMOVED:
					m_events[static_cast<int>(Event::DISPLAY_REMOVED)] = true;
					break;
				case SDL_EVENT_DISPLAY_MOVED:
					m_events[static_cast<int>(Event::DISPLAY_MOVED)] = true;
					break;
				case SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED:
					m_events[static_cast<int>(Event::DISPLAY_DESKTOP_MODE_CHANGED)] = true;
					break;
				case SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED:
					m_events[static_cast<int>(Event::DISPLAY_CURRENT_MODE_CHANGED)] = true;
					break;
				case SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED:
					m_events[static_cast<int>(Event::DISPLAY_CONTENT_SCALE_CHANGED)] = true;
					break;
					/* WINDOW EVENTS */
				case SDL_EVENT_WINDOW_SHOWN:
					m_events[static_cast<int>(Event::WINDOW_SHOWN)] = true;
					break;
				case SDL_EVENT_WINDOW_HIDDEN:
					m_events[static_cast<int>(Event::WINDOW_HIDDEN)] = true;
					break;
				case SDL_EVENT_WINDOW_EXPOSED:
					m_events[static_cast<int>(Event::WINDOW_EXPOSED)] = true;
					break;
				case SDL_EVENT_WINDOW_MOVED:
					m_events[static_cast<int>(Event::WINDOW_MOVED)] = true;
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					m_events[static_cast<int>(Event::WINDOW_RESIZED)] = true;
					break;
				case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_PIXEL_SIZE_CHANGED)] = true;
					break;
				case SDL_EVENT_WINDOW_METAL_VIEW_RESIZED:
					m_events[static_cast<int>(Event::WINDOW_METAL_VIEW_RESIZED)] = true;
					break;
				case SDL_EVENT_WINDOW_MINIMIZED:
					m_events[static_cast<int>(Event::WINDOW_MINIMIZED)] = true;
					break;
				case SDL_EVENT_WINDOW_MAXIMIZED:
					m_events[static_cast<int>(Event::WINDOW_MAXIMIZED)] = true;
					break;
				case SDL_EVENT_WINDOW_RESTORED:
					m_events[static_cast<int>(Event::WINDOW_RESTORED)] = true;
					break;
				case SDL_EVENT_WINDOW_MOUSE_ENTER:
					m_events[static_cast<int>(Event::WINDOW_MOUSE_ENTER)] = true;
					break;
				case SDL_EVENT_WINDOW_MOUSE_LEAVE:
					m_events[static_cast<int>(Event::WINDOW_MOUSE_LEAVE)] = true;
					break;
				case SDL_EVENT_WINDOW_FOCUS_GAINED:
					m_events[static_cast<int>(Event::WINDOW_FOCUS_GAINED)] = true;
					break;
				case SDL_EVENT_WINDOW_FOCUS_LOST:
					m_events[static_cast<int>(Event::WINDOW_FOCUS_LOST)] = true;
					break;
				case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
					m_events[static_cast<int>(Event::WINDOW_CLOSE_REQUESTED)] = true;
					break;
				case SDL_EVENT_WINDOW_HIT_TEST:
					m_events[static_cast<int>(Event::WINDOW_HIT_TEST)] = true;
					break;
				case SDL_EVENT_WINDOW_ICCPROF_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_ICCPROF_CHANGED)] = true;
					break;
				case SDL_EVENT_WINDOW_DISPLAY_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_DISPLAY_CHANGED)] = true;
					break;
				case SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_DISPLAY_SCALE_CHANGED)] = true;
					break;
				case SDL_EVENT_WINDOW_SAFE_AREA_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_SAFE_AREA_CHANGED)] = true;
					break;
				case SDL_EVENT_WINDOW_OCCLUDED:
					m_events[static_cast<int>(Event::WINDOW_OCCLUDED)] = true;
					break;
				case SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
					m_events[static_cast<int>(Event::WINDOW_ENTER_FULLSCREEN)] = true;
					break;
				case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
					m_events[static_cast<int>(Event::WINDOW_LEAVE_FULLSCREEN)] = true;
					break;
				case SDL_EVENT_WINDOW_DESTROYED:
					m_events[static_cast<int>(Event::WINDOW_DESTROYED)] = true;
					break;
				case SDL_EVENT_WINDOW_HDR_STATE_CHANGED:
					m_events[static_cast<int>(Event::WINDOW_HDR_STATE_CHANGED)] = true;
					break;
					/* KEYBOARD EVENTS */
				case SDL_EVENT_KEY_DOWN:
					if (event.key.repeat == 0)
					{
						m_events[static_cast<int>(Event::KEY_DOWN)] = true;
					}
					else
					{
						m_events[static_cast<int>(Event::KEY_STAY)] = true;
					}
					break;
				case SDL_EVENT_KEY_UP:
					m_events[static_cast<int>(Event::KEY_UP)] = true;
					break;
				case SDL_EVENT_TEXT_EDITING:
					m_events[static_cast<int>(Event::TEXT_EDITING)] = true;
					break;
				case SDL_EVENT_TEXT_INPUT:
					m_events[static_cast<int>(Event::TEXT_EDITING_CANDIDATES)] = true;
					break;
				case SDL_EVENT_KEYMAP_CHANGED:
					m_events[static_cast<int>(Event::KEYMAP_CHANGED)] = true;
					break;
				case SDL_EVENT_KEYBOARD_ADDED:
					m_events[static_cast<int>(Event::KEYBOARD_ADDED)] = true;
					break;
				case SDL_EVENT_KEYBOARD_REMOVED:
					m_events[static_cast<int>(Event::KEYBOARD_REMOVED)] = true;
					break;
				case SDL_EVENT_TEXT_EDITING_CANDIDATES:
					m_events[static_cast<int>(Event::TEXT_EDITING_CANDIDATES)] = true;
					break;
					/* MOUSE EVENTS */
				case SDL_EVENT_MOUSE_MOTION:
					m_events[static_cast<int>(Event::MOUSE_MOTION)] = true;
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					m_events[static_cast<int>(Event::MOUSE_BUTTON_DOWN)] = true;
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					m_events[static_cast<int>(Event::MOUSE_BUTTON_UP)] = true;
					break;
				case SDL_EVENT_MOUSE_WHEEL:
					m_events[static_cast<int>(Event::MOUSE_WHEEL)] = true;
					break;
				case SDL_EVENT_MOUSE_ADDED:
					m_events[static_cast<int>(Event::MOUSE_ADDED)] = true;
					break;
				case SDL_EVENT_MOUSE_REMOVED:
					m_events[static_cast<int>(Event::MOUSE_REMOVED)] = true;
					break;
					/* JOYSTICK EVENTS */
				case SDL_EVENT_JOYSTICK_AXIS_MOTION:
					m_events[static_cast<int>(Event::JOYSTICK_AXIS_MOTION)] = true;
					break;
				case SDL_EVENT_JOYSTICK_BALL_MOTION:
					m_events[static_cast<int>(Event::JOYSTICK_BALL_MOTION)] = true;
					break;
				case SDL_EVENT_JOYSTICK_HAT_MOTION:
					m_events[static_cast<int>(Event::JOYSTICK_HAT_MOTION)] = true;
					break;
				case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
					m_events[static_cast<int>(Event::JOYSTICK_BUTTON_DOWN)] = true;
					break;
				case SDL_EVENT_JOYSTICK_BUTTON_UP:
					m_events[static_cast<int>(Event::JOYSTICK_BUTTON_UP)] = true;
					break;
				case SDL_EVENT_JOYSTICK_ADDED:
					m_events[static_cast<int>(Event::JOYSTICK_ADDED)] = true;
					break;
				case SDL_EVENT_JOYSTICK_REMOVED:
					m_events[static_cast<int>(Event::JOYSTICK_REMOVED)] = true;
					break;
				case SDL_EVENT_JOYSTICK_BATTERY_UPDATED:
					m_events[static_cast<int>(Event::JOYSTICK_BATTERY_UPDATED)] = true;
					break;
				case SDL_EVENT_JOYSTICK_UPDATE_COMPLETE:
					m_events[static_cast<int>(Event::JOYSTICK_UPDATE_COMPLETE)] = true;
					break;
					/* GAMEPAD EVENTS */
				case SDL_EVENT_GAMEPAD_AXIS_MOTION:
					m_events[static_cast<int>(Event::GAMEPAD_AXIS_MOTION)] = true;
					break;
				case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
					m_events[static_cast<int>(Event::GAMEPAD_BUTTON_DOWN)] = true;
					break;
				case SDL_EVENT_GAMEPAD_BUTTON_UP:
					m_events[static_cast<int>(Event::GAMEPAD_BUTTON_UP)] = true;
					break;
				case SDL_EVENT_GAMEPAD_ADDED:
					m_events[static_cast<int>(Event::GAMEPAD_ADDED)] = true;
					break;
				case SDL_EVENT_GAMEPAD_REMOVED:
					m_events[static_cast<int>(Event::GAMEPAD_REMOVED)] = true;
					break;
				case SDL_EVENT_GAMEPAD_REMAPPED:
					m_events[static_cast<int>(Event::GAMEPAD_REMAPPED)] = true;
					break;
				case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN:
					m_events[static_cast<int>(Event::GAMEPAD_TOUCHPAD_DOWN)] = true;
					break;
				case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION:
					m_events[static_cast<int>(Event::GAMEPAD_TOUCHPAD_MOTION)] = true;
					break;
				case SDL_EVENT_GAMEPAD_TOUCHPAD_UP:
					m_events[static_cast<int>(Event::GAMEPAD_TOUCHPAD_UP)] = true;
					break;
				case SDL_EVENT_GAMEPAD_SENSOR_UPDATE:
					m_events[static_cast<int>(Event::GAMEPAD_SENSOR_UPDATE)] = true;
					break;
				case SDL_EVENT_GAMEPAD_UPDATE_COMPLETE:
					m_events[static_cast<int>(Event::GAMEPAD_UPDATE_COMPLETE)] = true;
					break;
				case SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED:
					m_events[static_cast<int>(Event::GAMEPAD_STEAM_HANDLE_UPDATED)] = true;
					break;
					/* TOUCH EVENTS */
				case SDL_EVENT_FINGER_DOWN:
					m_events[static_cast<int>(Event::FINGER_DOWN)] = true;
					break;
				case SDL_EVENT_FINGER_UP:
					m_events[static_cast<int>(Event::FINGER_UP)] = true;
					break;
				case SDL_EVENT_FINGER_MOTION:
					m_events[static_cast<int>(Event::FINGER_MOTION)] = true;
					break;
				case SDL_EVENT_FINGER_CANCELED:
					m_events[static_cast<int>(Event::FINGER_CANCELED)] = true;
					break;
					/* CLIPBOARD EVENTS */
				case SDL_EVENT_CLIPBOARD_UPDATE:
					m_events[static_cast<int>(Event::CLIPBOARD_UPDATE)] = true;
					break;
					/* DROP EVENTS */
				case SDL_EVENT_DROP_FILE:
					m_events[static_cast<int>(Event::DROP_FILE)] = true;
					break;
				case SDL_EVENT_DROP_TEXT:
					m_events[static_cast<int>(Event::DROP_TEXT)] = true;
					break;
				case SDL_EVENT_DROP_BEGIN:
					m_events[static_cast<int>(Event::DROP_BEGIN)] = true;
					break;
				case SDL_EVENT_DROP_COMPLETE:
					m_events[static_cast<int>(Event::DROP_COMPLETE)] = true;
					break;
				case SDL_EVENT_DROP_POSITION:
					m_events[static_cast<int>(Event::DROP_POSITION)] = true;
					break;
					/* AUDIO DEVICE EVENTS */
				case SDL_EVENT_AUDIO_DEVICE_ADDED:
					m_events[static_cast<int>(Event::AUDIO_DEVICE_ADDED)] = true;
					break;
				case SDL_EVENT_AUDIO_DEVICE_REMOVED:
					m_events[static_cast<int>(Event::AUDIO_DEVICE_REMOVED)] = true;
					break;
				case SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED:
					m_events[static_cast<int>(Event::AUDIO_DEVICE_FORMAT_CHANGED)] = true;
					break;
					/* SENSOR EVENTS */
				case SDL_EVENT_SENSOR_UPDATE:
					m_events[static_cast<int>(Event::SENSOR_UPDATE)] = true;
					break;
					/* PEN EVENTS */
				case SDL_EVENT_PEN_PROXIMITY_IN:
					m_events[static_cast<int>(Event::PEN_PROXIMITY_IN)] = true;
					break;
				case SDL_EVENT_PEN_PROXIMITY_OUT:
					m_events[static_cast<int>(Event::PEN_PROXIMITY_OUT)] = true;
					break;
				case SDL_EVENT_PEN_DOWN:
					m_events[static_cast<int>(Event::PEN_DOWN)] = true;
					break;
				case SDL_EVENT_PEN_UP:
					m_events[static_cast<int>(Event::PEN_UP)] = true;
					break;
				case SDL_EVENT_PEN_BUTTON_DOWN:
					m_events[static_cast<int>(Event::PEN_BUTTON_DOWN)] = true;
					break;
				case SDL_EVENT_PEN_BUTTON_UP:
					m_events[static_cast<int>(Event::PEN_BUTTON_UP)] = true;
					break;
				case SDL_EVENT_PEN_MOTION:
					m_events[static_cast<int>(Event::PEN_MOTION)] = true;
					break;
				case SDL_EVENT_PEN_AXIS:
					m_events[static_cast<int>(Event::PEN_AXIS)] = true;
					break;
					/* CAMERA EVENTS */
				case SDL_EVENT_CAMERA_DEVICE_ADDED:
					m_events[static_cast<int>(Event::CAMERA_DEVICE_ADDED)] = true;
					break;
				case SDL_EVENT_CAMERA_DEVICE_REMOVED:
					m_events[static_cast<int>(Event::CAMERA_DEVICE_REMOVED)] = true;
					break;
				case SDL_EVENT_CAMERA_DEVICE_APPROVED:
					m_events[static_cast<int>(Event::CAMERA_DEVICE_APPROVED)] = true;
					break;
				case SDL_EVENT_CAMERA_DEVICE_DENIED:
					m_events[static_cast<int>(Event::CAMERA_DEVICE_DENIED)] = true;
					break;
					/* RENDER EVENTS */
				case SDL_EVENT_RENDER_TARGETS_RESET:
					m_events[static_cast<int>(Event::RENDER_TARGETS_RESET)] = true;
					break;
				case SDL_EVENT_RENDER_DEVICE_RESET:
					m_events[static_cast<int>(Event::RENDER_DEVICE_RESET)] = true;
					break;
				case SDL_EVENT_RENDER_DEVICE_LOST:
					m_events[static_cast<int>(Event::RENDER_DEVICE_LOST)] = true;
					break;
				default:
					break;
				}
			}
		}

		// Raw events ---------------------------------

		// Any event
		bool onEvent(godhunter::Event event_)
		{
			return m_events[static_cast<int>(event_)];
		}

		// Keyboard event
		bool onEvent(godhunter::Event event_, godhunter::Keycode keycode_)
		{
			return false; // TODO: Implement keycode retrieval
		}

		// Keyboard event with modifier
		bool onEvent(godhunter::Event event_, godhunter::Keycode keycode_, godhunter::KeyModifier keymodifier_)
		{
			return false; // TODO: Implement keycode and keymodifier retrieval
		}
		
		// Check if Raw_Event is triggered
		// Return true if the event is triggered, false otherwise
		template <typename T>
		bool onEvent(T event_)
		{
			return false;
		}

		// Check if Raw_Event is triggered and get mouse position
		template <typename T>
		bool onEvent(T event_, int x_, int y_)
		{
			return false;
		}

		// void registerEvent(Raw_Event event, callback_function)
	};


	



	// Events
	// https://github.com/libsdl-org/SDL/blob/main/include/SDL3/SDL_events.h


	// Functions:

	// bool onEvent(Raw_Event)

	// void createKeyEvent("key_event", Raw_Event)
	// bool onEvent("key_event")

	// void registerEvent(Raw_Event, callback_function)
	// void registerEvent("key_event", callback_function)


} // namespace godhunter

#endif // GODHUNTER_EVENTS_H_