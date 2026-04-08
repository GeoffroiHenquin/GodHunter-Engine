/**
 * @file window.cpp
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
#include "window.h"

// C system headers

// C++ standard library headers
#include <cstdint>

// Third party libraries headers
#include <SDL3/SDL.h>

// Project headers

// Exceptions


void godhunter::Window::createWindow(const char* title_, int width_, int height_, std::uint32_t flags_)
{
	this->window = SDL_CreateWindow(title_, width_, height_, flags_);
	this->renderer = SDL_CreateRenderer(this->window, NULL);
}

void godhunter::Window::destroyWindow()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}

void godhunter::Window::setWindowTitle(const char* title_)
{
	SDL_SetWindowTitle(this->window, title_);
}

godhunter::Window::Window()
{
	this->window = nullptr;
	this->renderer = nullptr;
}

godhunter::Window::~Window()
{
	this->destroyWindow();
}