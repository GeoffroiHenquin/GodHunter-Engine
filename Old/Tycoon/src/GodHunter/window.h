/**
 * @file window.h
 * This file is part of the GodHunter Engine
 *
 * This file declare a window.
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


#ifndef GODHUNTER_WINDOW_H_
#define GODHUNTER_WINDOW_H_

namespace godhunter
{

	class Window
	{
	private:
		SDL_Window* m_window = nullptr;
		SDL_Renderer* m_renderer = nullptr;
	public:
		Window()
		{
			m_window = SDL_CreateWindow("Godhunter application", 1600, 900, 0);
			m_renderer = SDL_CreateRenderer(m_window, NULL);
		}
		Window(const char* title_, int32_t width_, int32_t height_, uint32_t flags_)
		{
			m_window = SDL_CreateWindow(title_, width_, height_, flags_);
			m_renderer = SDL_CreateRenderer(m_window, NULL);
		}
		~Window()
		{
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
		}
		SDL_Window* getSDLWindow() const
		{
			return m_window;
		}
		SDL_Renderer* getSDLRenderer() const
		{
			return m_renderer;
		}
		void setTitle(const char* title_)
		{
			SDL_SetWindowTitle(m_window, title_);
		}
		void setSize(int32_t width_, int32_t height_)
		{
			SDL_SetWindowSize(m_window, width_, height_);
		}
		void setPosition(int32_t x_, int32_t y_)
		{
			SDL_SetWindowPosition(m_window, x_, y_);
		}
		void setFullscreen(bool fullscreen_)
		{
			SDL_SetWindowFullscreen(m_window, fullscreen_);
		}
		void setBorderless(bool borderless_)
		{
			SDL_SetWindowBordered(m_window, !borderless_);
		}
		void setResizable(bool resizable_)
		{
			SDL_SetWindowResizable(m_window, resizable_);
		}
		void setMinimumSize(int32_t min_width_, int32_t min_height_)
		{
			SDL_SetWindowMinimumSize(m_window, min_width_, min_height_);
		}
		void setMaximumSize(int32_t max_width_, int32_t max_height_)
		{
			SDL_SetWindowMaximumSize(m_window, max_width_, max_height_);
		}
		void show()
		{
			SDL_ShowWindow(m_window);
		}
		void hide()
		{
			SDL_HideWindow(m_window);
		}
		void raise()
		{
			SDL_RaiseWindow(m_window);
		}
		void maximize()
		{
			SDL_MaximizeWindow(m_window);
		}
		void minimize()
		{
			SDL_MinimizeWindow(m_window);
		}
		void restore()
		{
			SDL_RestoreWindow(m_window);
		}
		bool isShown() const
		{
			return !(SDL_GetWindowFlags(m_window) & SDL_WINDOW_HIDDEN);
		}
		bool isHidden() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_HIDDEN);
		}
		bool isMinimized() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_MINIMIZED);
		}
		bool isMaximized() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_MAXIMIZED);
		}
		bool isFullscreen() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_FULLSCREEN);
		}
		bool hasMouseFocus() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_MOUSE_FOCUS);
		}
		bool hasKeyboardFocus() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_INPUT_FOCUS);
		}
		bool isBorderless() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_BORDERLESS);
		}
		bool isResizable() const
		{
			return (SDL_GetWindowFlags(m_window) & SDL_WINDOW_RESIZABLE);
		}
		void getSize(int32_t& width_, int32_t& height_) const
		{
			SDL_GetWindowSize(m_window, &width_, &height_);
		}
		void getPosition(int32_t& x_, int32_t& y_) const
		{
			SDL_GetWindowPosition(m_window, &x_, &y_);
		}
	}; // class Window

} // namespace godhunter

#endif // GODHUNTER_WINDOW_H_