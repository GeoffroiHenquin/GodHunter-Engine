/**
 * @file main.cpp
 * This file is part of the UFFPS project
 *
 * This file is a prototype for a FNAF Tycoon Game.
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
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"
#include <SDL3/SDL.h>
#include <stdio.h>

// Project headers

// Exceptions

int main(int argc, char* argv[])
{
    // SETUP ----------------------------------------------------------------

	// Initialize SDL
    if (!SDL_Init(
			SDL_INIT_AUDIO |
			SDL_INIT_VIDEO |
			SDL_INIT_JOYSTICK |
			SDL_INIT_HAPTIC |
			SDL_INIT_GAMEPAD |
			SDL_INIT_EVENTS |
			SDL_INIT_SENSOR |
			SDL_INIT_CAMERA
		))
	{
        return -1;
    }

	// Create SDL window and renderer
    SDL_Window* window = SDL_CreateWindow("Dear ImGui + SDL3 Example", 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
    if (!window) {
        return -1;
    }
	SDL_ShowWindow(window);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
    if (!renderer) {
        return -1;
    }
	SDL_SetRenderVSync(renderer, 1);

	// Setup Dear ImGui context
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;

	// Setup Dear ImGui SDL3 and SDLRenderer3 backends
    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    // MAIN LOOP ------------------------------------------------------------
    bool running = true;
    while (running) {
        // HANDLE TIMING ----------------------------------------------------------------

        // HANDLE INPUT ----------------------------------------------------------------
        SDL_Event event;
        while (SDL_PollEvent(&event))
		{
			// Pass event to ImGui
            ImGui_ImplSDL3_ProcessEvent(&event);
			// Handle event
			switch (event.type)
			{
				/* QUIT EVENTS */
			case SDL_EVENT_QUIT:
				running = false;
				break;
			case SDL_EVENT_TERMINATING:
				break;
			case SDL_EVENT_LOW_MEMORY:
				break;
				/* ENTERING / EXITING BACKGROUND */
			case SDL_EVENT_WILL_ENTER_BACKGROUND:
				break;
			case SDL_EVENT_DID_ENTER_BACKGROUND:
				break;
			case SDL_EVENT_WILL_ENTER_FOREGROUND:
				break;
			case SDL_EVENT_DID_ENTER_FOREGROUND:
				break;
				/* SYSTEM EVENTS */
			case SDL_EVENT_LOCALE_CHANGED:
				break;
			case SDL_EVENT_SYSTEM_THEME_CHANGED:
				break;
				/* DISPLAY EVENTS */
			case SDL_EVENT_DISPLAY_ORIENTATION:
				break;
			case SDL_EVENT_DISPLAY_ADDED:
				break;
			case SDL_EVENT_DISPLAY_REMOVED:
				break;
			case SDL_EVENT_DISPLAY_MOVED:
				break;
			case SDL_EVENT_DISPLAY_DESKTOP_MODE_CHANGED:
				break;
			case SDL_EVENT_DISPLAY_CURRENT_MODE_CHANGED:
				break;
			case SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED:
				break;
				/* WINDOW EVENTS */
			case SDL_EVENT_WINDOW_SHOWN:
				break;
			case SDL_EVENT_WINDOW_HIDDEN:
				break;
			case SDL_EVENT_WINDOW_EXPOSED:
				break;
			case SDL_EVENT_WINDOW_MOVED:
				break;
			case SDL_EVENT_WINDOW_RESIZED:
				break;
			case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
				break;
			case SDL_EVENT_WINDOW_METAL_VIEW_RESIZED:
				break;
			case SDL_EVENT_WINDOW_MINIMIZED:
				break;
			case SDL_EVENT_WINDOW_MAXIMIZED:
				break;
			case SDL_EVENT_WINDOW_RESTORED:
				break;
			case SDL_EVENT_WINDOW_MOUSE_ENTER:
				break;
			case SDL_EVENT_WINDOW_MOUSE_LEAVE:
				break;
			case SDL_EVENT_WINDOW_FOCUS_GAINED:
				break;
			case SDL_EVENT_WINDOW_FOCUS_LOST:
				break;
			case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
				break;
			case SDL_EVENT_WINDOW_HIT_TEST:
				break;
			case SDL_EVENT_WINDOW_ICCPROF_CHANGED:
				break;
			case SDL_EVENT_WINDOW_DISPLAY_CHANGED:
				break;
			case SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED:
				break;
			case SDL_EVENT_WINDOW_SAFE_AREA_CHANGED:
				break;
			case SDL_EVENT_WINDOW_OCCLUDED:
				break;
			case SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
				break;
			case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
				break;
			case SDL_EVENT_WINDOW_DESTROYED:
				break;
			case SDL_EVENT_WINDOW_HDR_STATE_CHANGED:
				break;
				/* KEYBOARD EVENTS */
			case SDL_EVENT_KEY_DOWN:
				if (event.key.repeat == 0)
				{
				}
				else
				{
				}
				break;
			case SDL_EVENT_KEY_UP:
				break;
			case SDL_EVENT_TEXT_EDITING:
				break;
			case SDL_EVENT_TEXT_INPUT:
				break;
			case SDL_EVENT_KEYMAP_CHANGED:
				break;
			case SDL_EVENT_KEYBOARD_ADDED:
				break;
			case SDL_EVENT_KEYBOARD_REMOVED:
				break;
			case SDL_EVENT_TEXT_EDITING_CANDIDATES:
				break;
				/* MOUSE EVENTS */
			case SDL_EVENT_MOUSE_MOTION:
				break;
			case SDL_EVENT_MOUSE_BUTTON_DOWN:
				break;
			case SDL_EVENT_MOUSE_BUTTON_UP:
				break;
			case SDL_EVENT_MOUSE_WHEEL:
				break;
			case SDL_EVENT_MOUSE_ADDED:
				break;
			case SDL_EVENT_MOUSE_REMOVED:
				break;
				/* JOYSTICK EVENTS */
			case SDL_EVENT_JOYSTICK_AXIS_MOTION:
				break;
			case SDL_EVENT_JOYSTICK_BALL_MOTION:
				break;
			case SDL_EVENT_JOYSTICK_HAT_MOTION:
				break;
			case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
				break;
			case SDL_EVENT_JOYSTICK_BUTTON_UP:
				break;
			case SDL_EVENT_JOYSTICK_ADDED:
				break;
			case SDL_EVENT_JOYSTICK_REMOVED:
				break;
			case SDL_EVENT_JOYSTICK_BATTERY_UPDATED:
				break;
			case SDL_EVENT_JOYSTICK_UPDATE_COMPLETE:
				break;
				/* GAMEPAD EVENTS */
			case SDL_EVENT_GAMEPAD_AXIS_MOTION:
				break;
			case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
				break;
			case SDL_EVENT_GAMEPAD_BUTTON_UP:
				break;
			case SDL_EVENT_GAMEPAD_ADDED:
				break;
			case SDL_EVENT_GAMEPAD_REMOVED:
				break;
			case SDL_EVENT_GAMEPAD_REMAPPED:
				break;
			case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN:
				break;
			case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION:
				break;
			case SDL_EVENT_GAMEPAD_TOUCHPAD_UP:
				break;
			case SDL_EVENT_GAMEPAD_SENSOR_UPDATE:
				break;
			case SDL_EVENT_GAMEPAD_UPDATE_COMPLETE:
				break;
			case SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED:
				break;
				/* TOUCH EVENTS */
			case SDL_EVENT_FINGER_DOWN:
				break;
			case SDL_EVENT_FINGER_UP:
				break;
			case SDL_EVENT_FINGER_MOTION:
				break;
			case SDL_EVENT_FINGER_CANCELED:
				break;
				/* CLIPBOARD EVENTS */
			case SDL_EVENT_CLIPBOARD_UPDATE:
				break;
				/* DROP EVENTS */
			case SDL_EVENT_DROP_FILE:
				break;
			case SDL_EVENT_DROP_TEXT:
				break;
			case SDL_EVENT_DROP_BEGIN:
				break;
			case SDL_EVENT_DROP_COMPLETE:
				break;
			case SDL_EVENT_DROP_POSITION:
				break;
				/* AUDIO DEVICE EVENTS */
			case SDL_EVENT_AUDIO_DEVICE_ADDED:
				break;
			case SDL_EVENT_AUDIO_DEVICE_REMOVED:
				break;
			case SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED:
				break;
				/* SENSOR EVENTS */
			case SDL_EVENT_SENSOR_UPDATE:
				break;
				/* PEN EVENTS */
			case SDL_EVENT_PEN_PROXIMITY_IN:
				break;
			case SDL_EVENT_PEN_PROXIMITY_OUT:
				break;
			case SDL_EVENT_PEN_DOWN:
				break;
			case SDL_EVENT_PEN_UP:
				break;
			case SDL_EVENT_PEN_BUTTON_DOWN:
				break;
			case SDL_EVENT_PEN_BUTTON_UP:
				break;
			case SDL_EVENT_PEN_MOTION:
				break;
			case SDL_EVENT_PEN_AXIS:
				break;
				/* CAMERA EVENTS */
			case SDL_EVENT_CAMERA_DEVICE_ADDED:
				break;
			case SDL_EVENT_CAMERA_DEVICE_REMOVED:
				break;
			case SDL_EVENT_CAMERA_DEVICE_APPROVED:
				break;
			case SDL_EVENT_CAMERA_DEVICE_DENIED:
				break;
				/* RENDER EVENTS */
			case SDL_EVENT_RENDER_TARGETS_RESET:
				break;
			case SDL_EVENT_RENDER_DEVICE_RESET:
				break;
			case SDL_EVENT_RENDER_DEVICE_LOST:
				break;
			default:
				break;
			}
        }

        // HANDLE GAME LOGIC ----------------------------------------------------------------

        // HANDLE RENDERING ----------------------------------------------------------------

        
		// Start the Dear ImGui frame
        ImGui_ImplSDLRenderer3_NewFrame();
        ImGui_ImplSDL3_NewFrame();

		// Draw the GUI
        ImGui::NewFrame();

        ImGui::Begin("Hello, world!");
        ImGui::Text("Welcome to Dear ImGui with SDL3!");
        ImGui::End();

        ImGui::Render();

		// Draw on the SDL renderer
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

		// Put ImGui draw data on the SDL renderer
        ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

		// Show the rendered frame on screen
        SDL_RenderPresent(renderer);
    }

    // CLEANUP --------------------------------------------------------------

	// Shutdown imgui
    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

	// Destroy SDL renderer and window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

	// Quit SDL
    SDL_Quit();
	return 0;
}