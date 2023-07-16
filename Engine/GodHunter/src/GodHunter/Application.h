#pragma once

#include "Core.h"

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


