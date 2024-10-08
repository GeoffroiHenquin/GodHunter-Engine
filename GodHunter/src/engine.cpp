/**
 * @file engine.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implement the various engine functions.
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
#include "engine.h"

// C system headers

// C++ standard library headers
#include <iostream>

// Third party libraries headers

// Project headers

// Exceptions


namespace godhunter
{

	GodHunterEngine::GodHunterEngine()
	{
	}

	GodHunterEngine::~GodHunterEngine()
	{
	}

	/**
	 * Execute the main loop and should only be called once.
	 *
	 * @return void
	 */
	void GodHunterEngine::run()
	{
		
		// Init device interface
		initHumanInterfaceDevices();

		// Create the Game Window
		GUIWindowInformation window_information = { (char*)"My Game", 
			1600, 900, 
			window_border_default,
			window_capture_default,
			window_focus_default,
			window_grab_default,
			window_position_default,
			window_quality_default,
			window_resize_default,
			window_size_default,
			window_system_default,
			window_type_default
		};
		this->m_game_window.createWindow(window_information);

		// TODO: add stuff to load a scene
		m_entity_system.loadScene(0);

		while (this->m_running)
		{
			// Handle events and inputs.
			m_event_system.handleEvents();
			this->m_running = !m_event_system.m_operating_system.getEventQuit();
			
			// Handle game logic.
			m_entity_system.handleGameLogic(m_event_system);

			// TODO: Handle rendering.
			m_game_window.startRender();
			m_entity_system.renderFrame(m_game_window);
			m_game_window.renderFrame();

			// TODO: Handle timing for next frame.
			delayMilliseconds(20);
		}

		// TODO: End the engine and clean memory before ending the program.
		this->m_game_window.destroyWindow();
		closeHumanInterfaceDevices();

	}

} // namespace godhunter