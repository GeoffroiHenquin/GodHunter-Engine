/**
 * @file engine.h
 * This file is part of the GodHunter Engine
 *
 * This file contains a class that represent the engine itself.
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

// C system headers

// C++ standard library headers

// Third party libraries headers

// Project headers
#include "human_interface_devices.h"

// Exceptions

#ifndef GODHUNTER_SRC_ENGINE_H_
#define GODHUNTER_SRC_ENGINE_H_

namespace godhunter
{

	/**
	 * Class - GodHunterEngine
	 *
	 * Represent the engine and handle the main loop. It's a standard implementation. 
	 * For more customisation, users can create their own engine class.
	 *
	 * GodHunterEngine gh_engine;
	 * gh_engine.run();
	 */
	class GodHunterEngine
	{
	private:
		// m_running is used in the function GodHunterEngine::run(). While it's true, the engine will render frames.
		bool m_running = true;

		// m_game_window is the window of the game.
		GUIWindow m_game_window;

	public:
		GodHunterEngine();
		~GodHunterEngine();

		/**
		 * Execute the main loop and should only be called once.
		 * 
		 * @return void
		 */
		void run();
	}; // class GodHunterEngine

} // namespace godhunter

#endif // GODHUNTER_SRC_ENGINE_H_