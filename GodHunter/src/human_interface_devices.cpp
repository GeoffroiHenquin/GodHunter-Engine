/**
 * @file human_interface_devices.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implement the various gui window functions.
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
#include "human_interface_devices.h"

// C system headers

// C++ standard library headers
#include <cassert>

// Third party libraries headers
#define SDL_MAIN_HANDLED // This is used to avoid using sdl_main
#include <SDL3/SDL.h>

// Project headers

// Exceptions


namespace godhunter
{

	/**
	 * This function should be called at the start of the program to init SDL
	 *
	 * @return void
	 */
	void initHumanInterfaceDevices() {
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_SENSOR);
	}

	/**
	 * This function should be called at the end of the program to close SDL
	 *
	 * @return void
	 */
	void closeHumanInterfaceDevices() {
		SDL_Quit();
	}

	/**
	 * Struct - GUIWindowDataContainer
	 *
	 * This struct will contain a graphic window provided by a third party library.
	 * WARNING: this struct should only be defined and used in "human_interface_devices.cpp". This is done in order to avoid dependencies.
	 */
	struct GUIWindowDataContainer
	{
		SDL_Window* window;
		SDL_Renderer* renderer;
	};

	GUIWindow::GUIWindow() : m_gui_data_container(new GUIWindowDataContainer)
	{
	}

	GUIWindow::~GUIWindow()
	{
		SDL_DestroyRenderer(this->m_gui_data_container->renderer);
		SDL_DestroyWindow(this->m_gui_data_container->window);
		delete this->m_gui_data_container;
	}

	/**
	 * This create a default window
	 *
	 * @return void
	 */
	void GUIWindow::createWindow()
	{
		this->m_gui_data_container->window = SDL_CreateWindow("GodHunter Application", 800, 600, 0);
		this->m_gui_data_container->renderer = SDL_CreateRenderer(this->m_gui_data_container->window, NULL, 0);
	}

	/**
	 * This create a window from information
	 *
	 * @param window_information_ Contains information for a window such as name, size, etc.
	 * @return void
	 */
	void GUIWindow::createWindow(GUIWindowInformation window_information_)
	{
		assert(window_information_.window_border_flag >= 0 && window_information_.window_border_flag <= 1);
		SDL_WindowFlags sdl_border_flags[] = 
		{
			0,
			SDL_WINDOW_BORDERLESS
		};

		assert(window_information_.window_capture_flag >= 0 && window_information_.window_capture_flag <= 1);
		SDL_WindowFlags sdl_capture_flags[] = 
		{
			0,
			SDL_WINDOW_MOUSE_CAPTURE
		};

		assert(window_information_.window_focus_flag >= 0 && window_information_.window_focus_flag <= 4);
		SDL_WindowFlags sdl_focus_flags[] = 
		{
			0,
			SDL_WINDOW_MOUSE_FOCUS,
			SDL_WINDOW_INPUT_FOCUS,
			SDL_WINDOW_MOUSE_FOCUS | SDL_WINDOW_INPUT_FOCUS,
			SDL_WINDOW_NOT_FOCUSABLE
		};

		assert(window_information_.window_grab_flag >= 0 && window_information_.window_grab_flag <= 3);
		SDL_WindowFlags sdl_grab_flags[] = 
		{
			0,
			SDL_WINDOW_MOUSE_GRABBED,
			SDL_WINDOW_KEYBOARD_GRABBED,
			SDL_WINDOW_MOUSE_GRABBED | SDL_WINDOW_KEYBOARD_GRABBED
		};

		assert(window_information_.window_position_flag >= 0 && window_information_.window_position_flag <= 2);
		SDL_WindowFlags sdl_position_flags[] = 
		{
			0,
			SDL_WINDOW_ALWAYS_ON_TOP,
			SDL_WINDOW_OCCLUDED
		};

		assert(window_information_.window_quality_flag >= 0 && window_information_.window_quality_flag <= 1);
		SDL_WindowFlags sdl_quality_flags[] = 
		{
			0,
			SDL_WINDOW_HIGH_PIXEL_DENSITY
		};

		assert(window_information_.window_resize_flag >= 0 && window_information_.window_resize_flag <= 1);
		SDL_WindowFlags sdl_resize_flags[] = 
		{
			0,
			SDL_WINDOW_RESIZABLE
		};

		assert(window_information_.window_size_flag >= 0 && window_information_.window_size_flag <= 3);
		SDL_WindowFlags sdl_size_flags[] = 
		{
			0,
			SDL_WINDOW_MINIMIZED,
			SDL_WINDOW_MAXIMIZED,
			SDL_WINDOW_FULLSCREEN
		};

		assert(window_information_.window_system_flag >= 0 && window_information_.window_system_flag <= 4);
		SDL_WindowFlags sdl_system_flags[] = 
		{
			0,
			SDL_WINDOW_OPENGL,
			SDL_WINDOW_VULKAN,
			SDL_WINDOW_METAL,
			SDL_WINDOW_EXTERNAL
		};

		assert(window_information_.window_type_flag >= 0 && window_information_.window_type_flag <= 3);
		SDL_WindowFlags sdl_type_flags[] = 
		{
			0,
			SDL_WINDOW_UTILITY,
			SDL_WINDOW_TOOLTIP,
			SDL_WINDOW_POPUP_MENU
		};

		assert(window_information_.window_visibility_flag >= 0 && window_information_.window_visibility_flag <= 2);
		SDL_WindowFlags sdl_visibility_flags[] = 
		{
			0,
			SDL_WINDOW_TRANSPARENT,
			SDL_WINDOW_HIDDEN
		};

		SDL_WindowFlags flags = 
			sdl_border_flags[window_information_.window_border_flag] |
			sdl_capture_flags[window_information_.window_capture_flag] |
			sdl_focus_flags[window_information_.window_focus_flag] |
			sdl_grab_flags[window_information_.window_grab_flag] |
			sdl_position_flags[window_information_.window_position_flag] |
			sdl_quality_flags[window_information_.window_quality_flag] |
			sdl_resize_flags[window_information_.window_resize_flag] |
			sdl_size_flags[window_information_.window_size_flag] |
			sdl_system_flags[window_information_.window_system_flag] |
			sdl_type_flags[window_information_.window_type_flag] |
			sdl_visibility_flags[window_information_.window_visibility_flag];

		this->m_gui_data_container->window = SDL_CreateWindow(window_information_.name, window_information_.width, window_information_.height, flags);
		this->m_gui_data_container->renderer = SDL_CreateRenderer(this->m_gui_data_container->window, NULL, 0);
	}

	/**
	 * This destroy a window
	 *
	 * @return void
	 */
	void GUIWindow::destroyWindow()
	{
		SDL_DestroyRenderer(this->m_gui_data_container->renderer);
		SDL_DestroyWindow(this->m_gui_data_container->window);
	}

	void GUIWindow::startRender()
	{
		SDL_SetRenderDrawColor(m_gui_data_container->renderer, 0, 0, 0, 255);
		SDL_RenderClear(m_gui_data_container->renderer);
	}

	void GUIWindow::drawRect(int position_x, int position_y, int size, unsigned char color[4])
	{
		SDL_FRect rect;
		rect.x = position_x;
		rect.y = position_y;
		rect.w = size;
		rect.h = size;

		SDL_SetRenderDrawColor(m_gui_data_container->renderer, color[0], color[1], color[2], color[3]);
		SDL_RenderFillRect(m_gui_data_container->renderer, &rect);
	}

	void GUIWindow::renderFrame()
	{
		SDL_RenderPresent(m_gui_data_container->renderer);
	}

	int GUIWindow::getWidth()
	{
		int w, h;
		SDL_GetWindowSize(m_gui_data_container->window, &w, &h);
		return w;
	}

	int GUIWindow::getHeight()
	{
		int w, h;
		SDL_GetWindowSize(m_gui_data_container->window, &w, &h);
		return h;
	}

	//--------------------------------------------------------------------------------------------------------------------------------------

	void EventSystem_OS::refresh()
	{
		this->m_quit = false;
	}

	void EventSystem_OS::setEventQuit(bool quit_)
	{
		this->m_quit = quit_;
	}

	bool EventSystem_OS::getEventQuit()
	{
		return this->m_quit;
	}

	//--------------------------------------------------------------------------------------------------------------------------------------

	void EventSystem_Keyboard::refresh()
	{
		for (auto& [_, v] : m_key_down) v = false;
		for (auto& [_, v] : m_key_up) v = false;
	}

	void EventSystem_Keyboard::setEventKeyDown(char key_)
	{
		this->m_key_down[key_] = true;
		this->m_key_pressed[key_] = true;
	}

	void EventSystem_Keyboard::setEventKeyUp(char key_)
	{
		this->m_key_pressed[key_] = false;
		this->m_key_up[key_] = true;
	}

	bool EventSystem_Keyboard::getEventKeyDown(char key_)
	{
		return m_key_down[key_];
	}

	bool EventSystem_Keyboard::getEventKeyPressed(char key_)
	{
		return m_key_pressed[key_];
	}

	bool EventSystem_Keyboard::getEventKeyUp(char key_)
	{
		return m_key_up[key_];
	}

	//--------------------------------------------------------------------------------------------------------------------------------------

	void EventSystem::handleEvents()
	{
		// Refresh the state of the various events.
		m_operating_system.refresh();
		m_keyboard.refresh();

		// Poll Events
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_QUIT: /**< User-requested quit */
				m_operating_system.setEventQuit(true);
				break;
				// Keyboard events
			case SDL_EVENT_KEY_DOWN:
				m_keyboard.setEventKeyDown(event.key.keysym.sym);
				break;
			case SDL_EVENT_KEY_UP:
				m_keyboard.setEventKeyUp(event.key.keysym.sym);
				break;
			default:
				break;
			}
		}
	}

	void delayMilliseconds(int milliseconds_)
	{
		SDL_Delay(milliseconds_);
	}
}