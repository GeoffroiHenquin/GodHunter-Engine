/**
 * @file events.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implements various functionalities to handle events and inputs.
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
#include "events.h"

// C system headers

// C++ standard library headers

// Third party libraries headers
#include <SDL3/SDL.h>

// Project headers

// Exceptions


void godhunter::Events::fetchQuitEvents(const SDL_Event& event_)
{
	this->system_events.quit = true;
}

void godhunter::Events::fetchWindowResizingEvents(const SDL_Event& event_)
{
	this->window_events.window_was_resized = true;
}

void godhunter::Events::fetchWindowMinimizeEvents(const SDL_Event& event_)
{
	this->window_events.window_was_minimized = true;
}

void godhunter::Events::fetchWindowMaximizeEvents(const SDL_Event& event_)
{
	this->window_events.window_was_maximized = true;
}

void godhunter::Events::fetchWindowRestoreEvents(const SDL_Event& event_)
{
	this->window_events.window_was_restored = true;
}

void godhunter::Events::fetchWindowEnterFullscreenEvents(const SDL_Event& event_)
{
	this->window_events.window_has_entered_fullscreen = true;
}

void godhunter::Events::fetchWindowLeaveFullscreenEvents(const SDL_Event& event_)
{
	this->window_events.window_has_left_fullscreen = true;
}

void godhunter::Events::fetchKeyboardKeyUpEvents(const SDL_Event& event_)
{
	this->keyboard_events.keys[SDL_GetKeyName(event_.key.key)] = {
		(event_.key.repeat == 0) ?
		godhunter::KeyboardEvents::KeyEvent::KeyState::up :
		godhunter::KeyboardEvents::KeyEvent::KeyState::released,
		event_.key.mod
	};
}

void godhunter::Events::fetchKeyboardKeyDownEvents(const SDL_Event& event_)
{
	this->keyboard_events.keys[SDL_GetKeyName(event_.key.key)] = {
		(event_.key.repeat == 0) ?
		godhunter::KeyboardEvents::KeyEvent::KeyState::down :
		godhunter::KeyboardEvents::KeyEvent::KeyState::pressed,
		event_.key.mod
	};
}

void godhunter::Events::fetchMouseMotionEvents(const SDL_Event& event_)
{
	this->mouse_events.position.x = event_.motion.x;
	this->mouse_events.position.y = event_.motion.y;
	this->mouse_events.motion.x = event_.motion.xrel;
	this->mouse_events.motion.y = event_.motion.yrel;
}

void godhunter::Events::fetchMouseButtonDownEvents(const SDL_Event& event_)
{
	switch (event_.button.button)
	{
	case SDL_BUTTON_LEFT:
		this->mouse_events.button_left.is_down = true;
		this->mouse_events.button_left.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_RIGHT:
		this->mouse_events.button_right.is_down = true;
		this->mouse_events.button_right.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_MIDDLE:
		this->mouse_events.button_middle.is_down = true;
		this->mouse_events.button_middle.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_X1:
		this->mouse_events.button_extra_1.is_down = true;
		this->mouse_events.button_extra_1.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_X2:
		this->mouse_events.button_extra_2.is_down = true;
		this->mouse_events.button_extra_2.clicks = event_.button.clicks;
		break;
	default:
		break;
	}
}

void godhunter::Events::fetchMouseButtonUpEvents(const SDL_Event& event_)
{
	switch (event_.button.button)
	{
	case SDL_BUTTON_LEFT:
		this->mouse_events.button_left.is_down = false;
		this->mouse_events.button_left.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_RIGHT:
		this->mouse_events.button_right.is_down = false;
		this->mouse_events.button_right.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_MIDDLE:
		this->mouse_events.button_middle.is_down = false;
		this->mouse_events.button_middle.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_X1:
		this->mouse_events.button_extra_1.is_down = false;
		this->mouse_events.button_extra_1.clicks = event_.button.clicks;
		break;
	case SDL_BUTTON_X2:
		this->mouse_events.button_extra_2.is_down = false;
		this->mouse_events.button_extra_2.clicks = event_.button.clicks;
		break;
	default:
		break;
	}
}

void godhunter::Events::fetchMouseScrollEvents(const SDL_Event& event_)
{
	this->mouse_events.wheel = event_.wheel.y;
}

void godhunter::Events::fetchEvents()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			// System events
		case SDL_EVENT_QUIT:
			this->fetchQuitEvents(event);
			break;
			// Window events
		case SDL_EVENT_WINDOW_RESIZED:
			this->fetchWindowResizingEvents(event);
			break;
		case SDL_EVENT_WINDOW_MINIMIZED:
			this->fetchWindowMinimizeEvents(event);
			break;
		case SDL_EVENT_WINDOW_MAXIMIZED:
			this->fetchWindowMaximizeEvents(event);
			break;
		case SDL_EVENT_WINDOW_RESTORED:
			this->fetchWindowRestoreEvents(event);
			break;
		case SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
			this->fetchWindowEnterFullscreenEvents(event);
			break;
		case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
			this->fetchWindowLeaveFullscreenEvents(event);
			break;
			// Keyboard events
		case SDL_EVENT_KEY_DOWN:
			this->fetchKeyboardKeyDownEvents(event);
			break;
		case SDL_EVENT_KEY_UP:
			this->fetchKeyboardKeyUpEvents(event);
			break;
			// Mouse events
		case SDL_EVENT_MOUSE_MOTION:
			this->fetchMouseMotionEvents(event);
			break;
		case SDL_EVENT_MOUSE_BUTTON_DOWN:
			this->fetchMouseButtonDownEvents(event);
			break;
		case SDL_EVENT_MOUSE_BUTTON_UP:
			this->fetchMouseButtonUpEvents(event);
			break;
		case SDL_EVENT_MOUSE_WHEEL:
			this->fetchMouseScrollEvents(event);
			break;
		default:
			break;
		}
	}
}

void godhunter::Events::clearEvents()
{
	// System events
	this->system_events.quit = false;
	// Window events
	this->window_events.window_was_resized = false;
	this->window_events.window_was_minimized = false;
	this->window_events.window_was_maximized = false;
	this->window_events.window_was_restored = false;
	this->window_events.window_has_entered_fullscreen = false;
	this->window_events.window_has_left_fullscreen = false;
	// Keyboard events
	this->keyboard_events.keys.clear();
	// Mouse events
	this->mouse_events.position.x = 0;
	this->mouse_events.position.y = 0;
	this->mouse_events.motion.x = 0;
	this->mouse_events.motion.y = 0;
	this->mouse_events.wheel = 0;
	this->mouse_events.button_left.is_down = false;
	this->mouse_events.button_right.is_down = false;
	this->mouse_events.button_middle.is_down = false;
	this->mouse_events.button_extra_1.is_down = false;
	this->mouse_events.button_extra_2.is_down = false;
}

godhunter::Events::Events()
{

}

godhunter::Events::~Events()
{

}