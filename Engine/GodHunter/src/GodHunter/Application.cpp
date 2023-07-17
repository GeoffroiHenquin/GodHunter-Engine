#include "Application.h"
#include <thread>

namespace GodHunter {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		// Get Data from Sandbox
		
		// Setup all components of the engine
		
		// Game Loop
		while (true) {
			// GAME TIMING =============================================
			std::this_thread::sleep_for(std::chrono::milliseconds(50));
			
			// PLAYER INPUT ============================================
			
			// GAME LOGIC ==============================================
			
			// RENDER OUTPUT ===========================================

		}
	}

}

