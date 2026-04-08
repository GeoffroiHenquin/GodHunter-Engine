/**
 * @file window.h
 * This file is part of the UFFPS project
 *
 * This file implements features to create and manage a window.
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
#include <cstdint>

// Third party libraries headers

// Project headers

// Exceptions


#ifndef UFFPS_SRC_WINDOW_H_
#define UFFPS_SRC_WINDOW_H_

namespace uffps
{

	enum WindowFlags
	{
		borderless = 1 << 0,					// Has no border.
		mouse_is_captured = 1 << 1,		// Will detect mouse movement even outside of window.
		has_mouse_focus = 1 << 2,			// Has mouse focus.
		has_input_focus = 1 << 3,			// Has keyboard focus.
		cant_be_focused = 1 << 4,			// Can't be focused.
		has_mouse_grabbed = 1 << 5,		// Mouse cant exit window.
		has_keyboard_grabbed = 1 << 6,	// Keyboard inputs cant exit window.
		mouse_relative_mode = 1 << 7, // Has relative mouse mode enabled.
		always_on_top = 1 << 8,			// Always on top of other windows.
		occluded = 1 << 9,						// Window is treated as if it was in the background (dont update/dont render).
		high_pixel_density = 1 << 10,	// Has high pixel density.
		resizable = 1 << 11,					// Window can be resized.
		minimized = 1 << 12,					// Window is minimized.
		maximized = 1 << 13,					// Window is maximized.
		fullscreen = 1 << 14,					// Window is fullscreen.
		opengl = 1 << 15,							// Has an openGL context.
		vulkan = 1 << 16,							// Has a vulkan context.
		metal = 1 << 17,							// Has a metal context.
		external = 1 << 18,						// Is an external window.
		utility = 1 << 19,						// Is an utility window.
		tooltip = 1 << 20,						// Is a tooltip window.
		pop_up_menu = 1 << 21,				// Is a popup menu window.
		modal = 1 << 22,							// Is a modal window.
		transparent = 1 << 23,				// Is a transparent window.
		hidden = 1 << 24,							// Is invisible.
		fill_document = 1 << 25			// Is in fill-document mode (Emscripten only).
	};

	struct Window
	{
		void* window = nullptr;
		void* renderer = nullptr;
	};

	void initWindowSystem();
	void createWindow(Window& window_);
	void createWindow(Window& window_, const char* title_, int32_t width_, int32_t height_, uint32_t flags_);
	void destroyWindow(Window& window_);
	void setWindowTitle(Window& window_, const char* title_);
	void setWindowSize(Window& window_, int32_t width_, int32_t height_);
	void setWindowPosition(Window& window_, int32_t x_, int32_t y_);
	void setWindowFullscreen(Window& window_, bool fullscreen_);
	void setWindowBorderless(Window& window_, bool borderless_);
	void setWindowResizable(Window& window_, bool resizable_);
	void setWindowMinimumSize(Window& window_, int32_t min_width_, int32_t min_height_);
	void setWindowMaximumSize(Window& window_, int32_t max_width_, int32_t max_height_);
	void showWindow(Window& window_);
	void hideWindow(Window& window_);
	void raiseWindow(Window& window_);
	void maximizeWindow(Window& window_);
	void minimizeWindow(Window& window_);
	void restoreWindow(Window& window_);
	bool isWindowShown(Window& window_);
	bool isWindowHidden(Window& window_);
	bool isWindowMinimized(Window& window_);
	bool isWindowMaximized(Window& window_);
	bool isWindowFullscreen(Window& window_);
	bool windowHasMouseFocus(Window& window_);
	bool windowHasKeyboardFocus(Window& window_);
	bool isWindowBorderless(Window& window_);
	bool isWindowResizable(Window& window_);
	void getWindowSize(Window& window_, int32_t& width_, int32_t& height_);
	void getWindowPosition(Window& window_, int32_t& x_, int32_t& y_);

}

#endif // UFFPS_SRC_WINDOW_H_