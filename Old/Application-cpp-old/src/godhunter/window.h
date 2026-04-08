/**
 * @file window.h
 * This file is part of the GodHunter Engine
 *
 * This file declare features to create and manage a window.
 *
 * MIT License
 *
 * Copyright (c) 2024 GeoffroiHenquin
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
#include <SDL3/SDL.h>

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_GODHUNTER_WINDOW_H_
#define GODHUNTER_SRC_GODHUNTER_WINDOW_H_

namespace godhunter
{

	enum WindowFlags
	{
		borderless = SDL_WINDOW_BORDERLESS,					// Has no border.
		mouse_is_captured = SDL_WINDOW_MOUSE_CAPTURE,		// Will detect mouse movement even outside of window.
		has_mouse_focus = SDL_WINDOW_MOUSE_FOCUS,			// Has mouse focus.
		has_input_focus = SDL_WINDOW_INPUT_FOCUS,			// Has keyboard focus.
		cant_be_focused = SDL_WINDOW_NOT_FOCUSABLE,			// Can't be focused.
		has_mouse_grabbed = SDL_WINDOW_MOUSE_GRABBED,		// Mouse cant exit window.
		has_keyboard_grabbed = SDL_WINDOW_KEYBOARD_GRABBED,	// Keyboard inputs cant exit window.
		always_on_top = SDL_WINDOW_ALWAYS_ON_TOP,			// Always on top of other windows.
		occluded = SDL_WINDOW_OCCLUDED,						// Window is treated as if it was in the background (dont update/dont render).
		high_pixel_density = SDL_WINDOW_HIGH_PIXEL_DENSITY,	// Has high pixel density.
		resizable = SDL_WINDOW_RESIZABLE,					// Window can be resized.
		minimized = SDL_WINDOW_MINIMIZED,					// Window is minimized.
		maximized = SDL_WINDOW_MAXIMIZED,					// Window is maximized.
		fullscreen = SDL_WINDOW_FULLSCREEN,					// Window is fullscreen.
		opengl = SDL_WINDOW_OPENGL,							// Has an openGL context.
		vulkan = SDL_WINDOW_VULKAN,							// Has a vulkan context.
		metal = SDL_WINDOW_METAL,							// Has a metal context.
		external = SDL_WINDOW_EXTERNAL,						// Is an external window.
		utility = SDL_WINDOW_UTILITY,						// Is an utility window.
		tooltip = SDL_WINDOW_TOOLTIP,						// Is a tooltip window.
		pop_up_menu = SDL_WINDOW_POPUP_MENU,				// Is a popup menu window.
		transparent = SDL_WINDOW_TRANSPARENT,				// Is a transparent window.
		hidden = SDL_WINDOW_HIDDEN							// Is invisible.
	};

	class Window
	{
	private:
		SDL_Window* window = nullptr;
		SDL_Renderer* renderer = nullptr;
	public:
		Window();
		~Window();
		void createWindow(const char* title_, int width_, int height_, std::uint32_t flags_);
		void destroyWindow();
		void setWindowTitle(const char* title_);
	};

} // namespace godhunter

#endif // GODHUNTER_SRC_GODHUNTER_WINDOW_H_