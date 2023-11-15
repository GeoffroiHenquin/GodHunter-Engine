#pragma once

#include "Application.h"

extern GodHunter::Application* GodHunter::CreateApplication();
int main(int argc, char** argv)
{
	auto app = GodHunter::CreateApplication();
	app->Run();
	delete app;
}