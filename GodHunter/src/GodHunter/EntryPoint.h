#pragma once

#include "Application.h"

extern GodHunter::Application* GodHunter::CreateApplication();
int main(int argc, char** argv)
{
	auto app = GodHunter::CreateApplication();
	
	app->run();
	
	delete app;

	return 0;
}