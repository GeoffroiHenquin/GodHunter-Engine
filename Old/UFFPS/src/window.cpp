/**
 * @file window.cpp
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
#include "window.h"

// C system headers

// C++ standard library headers

// Third party libraries headers
#include <SDL3/SDL.h>

// Project headers

// Exceptions

void uffps::initWindowSystem()
{
	SDL_Init(SDL_INIT_VIDEO);
}

void uffps::createWindow(Window& window_)
{
	window_.window = SDL_CreateWindow("UFFPS Window", 1280, 720, 0);
	window_.renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(window_.window), nullptr);
}

void uffps::createWindow(Window& window_, const char* title_, int32_t width_, int32_t height_, uint32_t flags_)
{
	uint32_t sdl_flags = 0;
	if (flags_ & borderless) sdl_flags |= SDL_WINDOW_BORDERLESS;
	if (flags_ & mouse_is_captured) sdl_flags |= SDL_WINDOW_MOUSE_CAPTURE;
	if (flags_ & has_mouse_focus) sdl_flags |= SDL_WINDOW_MOUSE_FOCUS;
	if (flags_ & has_input_focus) sdl_flags |= SDL_WINDOW_INPUT_FOCUS;
	if (flags_ & cant_be_focused) sdl_flags |= SDL_WINDOW_NOT_FOCUSABLE;
	if (flags_ & has_mouse_grabbed) sdl_flags |= SDL_WINDOW_MOUSE_GRABBED;
	if (flags_ & has_keyboard_grabbed) sdl_flags |= SDL_WINDOW_KEYBOARD_GRABBED;
	if (flags_ & mouse_relative_mode) sdl_flags |= SDL_WINDOW_MOUSE_RELATIVE_MODE;
	if (flags_ & always_on_top) sdl_flags |= SDL_WINDOW_ALWAYS_ON_TOP;
	if (flags_ & occluded) sdl_flags |= SDL_WINDOW_OCCLUDED;
	if (flags_ & high_pixel_density) sdl_flags |= SDL_WINDOW_HIGH_PIXEL_DENSITY;
	if (flags_ & resizable) sdl_flags |= SDL_WINDOW_RESIZABLE;
	if (flags_ & minimized) sdl_flags |= SDL_WINDOW_MINIMIZED;
	if (flags_ & maximized) sdl_flags |= SDL_WINDOW_MAXIMIZED;
	if (flags_ & fullscreen) sdl_flags |= SDL_WINDOW_FULLSCREEN;
	if (flags_ & opengl) sdl_flags |= SDL_WINDOW_OPENGL;
	if (flags_ & vulkan) sdl_flags |= SDL_WINDOW_VULKAN;
	if (flags_ & metal) sdl_flags |= SDL_WINDOW_METAL;
	if (flags_ & external) sdl_flags |= SDL_WINDOW_EXTERNAL;
	if (flags_ & modal) sdl_flags |= SDL_WINDOW_MODAL;
	if (flags_ & utility) sdl_flags |= SDL_WINDOW_UTILITY;
	if (flags_ & tooltip) sdl_flags |= SDL_WINDOW_TOOLTIP;
	if (flags_ & pop_up_menu) sdl_flags |= SDL_WINDOW_POPUP_MENU;
	if (flags_ & transparent) sdl_flags |= SDL_WINDOW_TRANSPARENT;
	if (flags_ & hidden) sdl_flags |= SDL_WINDOW_HIDDEN;
	if (flags_ & fill_document) sdl_flags |= SDL_WINDOW_FILL_DOCUMENT;

	window_.window = SDL_CreateWindow(title_, width_, height_, sdl_flags);
	window_.renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(window_.window), nullptr);
}

void uffps::destroyWindow(Window& window_)
{
	SDL_DestroyRenderer(static_cast<SDL_Renderer*>(window_.renderer));
	SDL_DestroyWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::setWindowTitle(Window& window_, const char* title_)
{
	SDL_SetWindowTitle(static_cast<SDL_Window*>(window_.window), title_);
}

void uffps::setWindowSize(Window& window_, int32_t width_, int32_t height_)
{
	SDL_SetWindowSize(static_cast<SDL_Window*>(window_.window), width_, height_);
}

void uffps::setWindowPosition(Window& window_, int32_t x_, int32_t y_)
{
	SDL_SetWindowPosition(static_cast<SDL_Window*>(window_.window), x_, y_);
}

void uffps::setWindowFullscreen(Window& window_, bool fullscreen_)
{
	SDL_SetWindowFullscreen(static_cast<SDL_Window*>(window_.window), fullscreen_);
}

void uffps::setWindowBorderless(Window& window_, bool borderless_)
{
	SDL_SetWindowBordered(static_cast<SDL_Window*>(window_.window), !borderless_);
}

void uffps::setWindowResizable(Window& window_, bool resizable_)
{
	SDL_SetWindowResizable(static_cast<SDL_Window*>(window_.window), resizable_);
}

void uffps::setWindowMinimumSize(Window& window_, int32_t min_width_, int32_t min_height_)
{
	SDL_SetWindowMinimumSize(static_cast<SDL_Window*>(window_.window), min_width_, min_height_);
}

void uffps::setWindowMaximumSize(Window& window_, int32_t max_width_, int32_t max_height_)
{
	SDL_SetWindowMaximumSize(static_cast<SDL_Window*>(window_.window), max_width_, max_height_);
}

void uffps::showWindow(Window& window_)
{
	SDL_ShowWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::hideWindow(Window& window_)
{
	SDL_HideWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::raiseWindow(Window& window_)
{
	SDL_RaiseWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::maximizeWindow(Window& window_)
{
	SDL_MaximizeWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::minimizeWindow(Window& window_)
{
	SDL_MinimizeWindow(static_cast<SDL_Window*>(window_.window));
}

void uffps::restoreWindow(Window& window_)
{
	SDL_RestoreWindow(static_cast<SDL_Window*>(window_.window));
}

bool uffps::isWindowShown(Window& window_)
{
	return !(SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_HIDDEN);
}

bool uffps::isWindowHidden(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_HIDDEN);
}

bool uffps::isWindowMinimized(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_MINIMIZED);
}

bool uffps::isWindowMaximized(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_MAXIMIZED);
}

bool uffps::isWindowFullscreen(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_FULLSCREEN);
}

bool uffps::windowHasMouseFocus(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_MOUSE_FOCUS);
}

bool uffps::windowHasKeyboardFocus(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_INPUT_FOCUS);
}

bool uffps::isWindowBorderless(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_BORDERLESS);
}

bool uffps::isWindowResizable(Window& window_)
{
	return (SDL_GetWindowFlags(static_cast<SDL_Window*>(window_.window)) & SDL_WINDOW_RESIZABLE);
}

void uffps::getWindowSize(Window& window_, int32_t& width_, int32_t& height_)
{
	SDL_GetWindowSize(static_cast<SDL_Window*>(window_.window), &width_, &height_);
}

void uffps::getWindowPosition(Window& window_, int32_t& x_, int32_t& y_)
{
	SDL_GetWindowPosition(static_cast<SDL_Window*>(window_.window), &x_, &y_);
}
