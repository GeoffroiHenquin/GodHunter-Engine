#include "Application.h"

// To Be Removed when the other systems are done
#include <SDL.h>

// Used to evaluate performances
#include <chrono>
#include <iostream>

namespace GodHunter {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::run()
	{
		// Init Engine
		OsSpecific::InitOsSpecificSystems();

		// Create a Window
		OsSpecific::CreateDisplay((char*)"main", gameDisplayInfo);
		OsSpecific::SelectDisplay((char*)"main");

		// Main Loop
		isRunning = true;
		while (isRunning) {


			// Begin test for performance
			// To remove later
			// ------------------------------------------------------------------------------------------------
			auto beg = std::chrono::high_resolution_clock::now();
			// ------------------------------------------------------------------------------------------------


			// Handle scene change
			
			// Handle user input
			//OsSpecific::HandleEvents();
			SDL_Event event;
			SDL_PollEvent(&event);
			switch (event.type) {
			case SDL_QUIT:
				isRunning = false;
				break;
			default:
				break;
			}

			// Update game logic and objects

			// Render changes to the display

			// Delay before next frame
			OsSpecific::Delay(50);


			// End test for performance
			// To remove later
			// ------------------------------------------------------------------------------------------------
			auto end = std::chrono::high_resolution_clock::now();
			auto duration = duration_cast<std::chrono::microseconds>(end - beg);
			//std::cout << "FPS: " << 1000000 / duration.count() << "\n";
			// ------------------------------------------------------------------------------------------------
		}

		// End Main
		OsSpecific::CloseOsSpecificSystems();
	}

}

