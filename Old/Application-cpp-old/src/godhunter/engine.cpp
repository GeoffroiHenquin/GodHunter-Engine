/**
 * @file engine.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implements the engine's runtime including the main loop.
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
#include "engine.h"

// C system headers

// C++ standard library headers

// Third party libraries headers
#include <SDL3/SDL.h>

// Project headers
#include "debug.h"
#include "ecs.h"
#include "events.h"
#include "timer.h"
#include "window.h"

// Exceptions

void godhunter::runApplication()
{
	// TEMPORARY ----------------------------------------------------------------

	godhunter::duration_ms_t temp_target_frame_duration = 30;
	const char* temp_window_title = "GodHunter Engine";

	// SETUP ----------------------------------------------------------------

	// Debug
	INIT_DEBUG();

	// SDL
	SDL_Init(
		SDL_INIT_AUDIO |
		SDL_INIT_VIDEO |
		SDL_INIT_JOYSTICK |
		SDL_INIT_HAPTIC |
		SDL_INIT_GAMEPAD |
		SDL_INIT_EVENTS |
		SDL_INIT_SENSOR |
		SDL_INIT_CAMERA
	);

	// ECS
	godhunter::EntityComponentSystem& ecs = godhunter::world();

	// Timing
	godhunter::time_point_t frame_duration_start = godhunter::getCurrentTimePoint();
	float elapsed_time = 0.0f;
	ecs.data_manager.registerData("elapsed_time", elapsed_time);

	// Events
	godhunter::Events events;
	ecs.data_manager.registerData("events", events);

	// Rendering
	godhunter::Window window;
	ecs.data_manager.registerData("window", window);
	window.createWindow(temp_window_title, 800, 600, 0);

	// MAIN LOOP
	bool main_loop_running = true;
	while (main_loop_running)
	{
		// HANDLE TIMING ----------------------------------------------------------------

		// Get the time since the last frame
		godhunter::duration_ms_t frame_duration = godhunter::calculateElapsedTime(
			frame_duration_start,
			godhunter::getCurrentTimePoint()
		);
		// Delay to match the target frame duration
		godhunter::duration_ms_t delay = (
			(temp_target_frame_duration > frame_duration) *
			(temp_target_frame_duration - frame_duration));
		godhunter::delay(delay);
		// Start counting the time it will takes to calculate the next frame
		elapsed_time = godhunter::millisecondsToSeconds(frame_duration + delay);
		frame_duration_start = godhunter::getCurrentTimePoint();
		// Display the FPS if in debug mode
#ifdef DEBUG
		window.setWindowTitle(
			("(" + std::to_string(1000 / (frame_duration + delay + 1)) + " FPS) - " + temp_window_title).c_str()
		);
#endif

		// HANDLE INPUT ----------------------------------------------------------------

		// Remove previously fetched events and fetch new ones
		events.clearEvents();
		events.fetchEvents();

		// TODO: Add input from other devices

		// TODO: Add a way to link inputs to keys

		// HANDLE LOGIC ----------------------------------------------------------------

		// TODO: Edit the ECS for our needs
		ecs.system_manager.runUpdateSystems(ecs.component_manager);

		// HANDLE RENDERING ----------------------------------------------------------------
		ecs.system_manager.runRenderSystems(ecs.component_manager);

		// TODO: Create a renderer

		// TODO: Create an audio system
	}

	// CLEANUP ----------------------------------------------------------------

	// Events
	events.clearEvents();

	// Window
	window.destroyWindow();

	// SDL
	SDL_Quit();
}
