/**
 * @file events.h
 * This file is part of the GodHunter Engine
 *
 * This file declare various functionalities to handle events and inputs.
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
#include <unordered_map>

// Third party libraries headers
#include <SDL3/SDL.h>

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_GODHUNTER_EVENTS_H_
#define GODHUNTER_SRC_GODHUNTER_EVENTS_H_

namespace godhunter
{

	struct SystemEvents
	{
		bool quit = false;
	};


	struct WindowEvents
	{
		bool window_was_resized = false;
		bool window_was_minimized = false;
		bool window_was_maximized = false;
		bool window_was_restored = false;
		bool window_has_entered_fullscreen = false;
		bool window_has_left_fullscreen = false;
	};


	struct KeyboardEvents
	{
		struct KeyEvent
		{
			enum KeyState
			{
				released = 0,
				down = 1,
				pressed = 2,
				up = 3
			} state = godhunter::KeyboardEvents::KeyEvent::KeyState::released;
			enum KeyMode
			{
				none = SDL_KMOD_NONE,
				l_shift = SDL_KMOD_LSHIFT,
				r_shift = SDL_KMOD_RSHIFT,
				level5_shift = SDL_KMOD_LEVEL5,
				l_ctrl = SDL_KMOD_LCTRL,
				r_ctrl = SDL_KMOD_RCTRL,
				l_alt = SDL_KMOD_LALT,
				r_alt = SDL_KMOD_RALT,
				l_gui = SDL_KMOD_LGUI,
				r_gui = SDL_KMOD_RGUI,
				numlock = SDL_KMOD_NUM,
				capslock = SDL_KMOD_CAPS,
				altgr = SDL_KMOD_MODE,
				scroll = SDL_KMOD_SCROLL,
				ctrl = SDL_KMOD_CTRL,
				shift = SDL_KMOD_SHIFT,
				alt = SDL_KMOD_ALT,
				gui = SDL_KMOD_GUI
			};
			std::uint16_t mode = godhunter::KeyboardEvents::KeyEvent::KeyMode::none;
		};
		std::unordered_map<const char*, KeyEvent> keys;
	};


	struct MouseEvents
	{
		struct MouseVector
		{
			float x = 0;
			float y = 0;
		} position, motion;
		struct MouseButton
		{
			bool is_down = false;
			std::uint8_t clicks = 0;
		} button_left, button_right, button_middle, button_extra_1, button_extra_2;
		float wheel = 0;
	};

	class Events
	{
	private:
		godhunter::SystemEvents system_events;
		godhunter::WindowEvents window_events;
		godhunter::KeyboardEvents keyboard_events;
		godhunter::MouseEvents mouse_events;

	private:
		void fetchQuitEvents(const SDL_Event& event_);

		void fetchWindowResizingEvents(const SDL_Event& event_);
		void fetchWindowMinimizeEvents(const SDL_Event& event_);
		void fetchWindowMaximizeEvents(const SDL_Event& event_);
		void fetchWindowRestoreEvents(const SDL_Event& event_);
		void fetchWindowEnterFullscreenEvents(const SDL_Event& event_);
		void fetchWindowLeaveFullscreenEvents(const SDL_Event& event_);

		void fetchKeyboardKeyUpEvents(const SDL_Event& event_);
		void fetchKeyboardKeyDownEvents(const SDL_Event& event_);

		void fetchMouseMotionEvents(const SDL_Event& event_);
		void fetchMouseButtonDownEvents(const SDL_Event& event_);
		void fetchMouseButtonUpEvents(const SDL_Event& event_);
		void fetchMouseScrollEvents(const SDL_Event& event_);

	public:
		Events();
		~Events();
		void clearEvents();
		void fetchEvents();
	};

} // namespace godhunter

#endif // GODHUNTER_SRC_GODHUNTER_EVENTS_H_