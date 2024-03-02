#pragma once

#include "Core.h"

// Required to Handle various task such as Display,input,sound,etc
#include "Core/OsSpecific/OsSpecificSystem.h"

namespace GodHunter {

	class GODHUNTER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	public:
		// Game is running
		bool isRunning;

		// Game Window Data
		WindowInformation gameDisplayInfo;
	};

	Application* CreateApplication();
}


