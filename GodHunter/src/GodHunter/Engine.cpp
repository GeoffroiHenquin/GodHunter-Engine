#include "Engine.h"

// To Be Removed when the other systems are done
#include <SDL3/SDL.h>

// Used to evaluate performances
#include <chrono>
#include <iostream>

#include "../Debug/Logger.h"
#include "../Debug/FrameRate.h"
#include "../Core/OsSpecific/OsSpecificSystem.h"

namespace GodHunter {

	int startEngine(WindowInformation gameDisplayInfo) {
		// Init Engine
		OsSpecific::InitOsSpecificSystems();

		// Create a Window
		OsSpecific::CreateDisplay(gameDisplayInfo);
		return 0;
	}

	int runEngine() {

		// Main Loop
		bool isRunning = true;
		while (isRunning) {

			// Handle user input
			//OsSpecific::HandleEvents();
			SDL_Event event;
			SDL_PollEvent(&event);
			switch (event.type) {
			case SDL_EVENT_QUIT:
				isRunning = false;
				break;
			default:
				break;
			}

			// Update game logic and objects

			// Render changes to the display

			// Delay before next frame
			OsSpecific::Delay(50);
			Debug::countFPS();
		}
		
		return 0;
	}

	int stopEngine() {
		// End Main
		OsSpecific::CloseOsSpecificSystems();
		return 0;
	}

}