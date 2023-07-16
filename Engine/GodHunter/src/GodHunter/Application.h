#pragma once

#include "Core.h"
#include <string>

namespace GodHunter {

	class GODHUNTER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}


