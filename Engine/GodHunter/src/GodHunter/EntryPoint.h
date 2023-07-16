#pragma once

#ifdef GH_PLATFORM_WINDOWS

extern GodHunter::Application* GodHunter::CreateApplication();
int main(int argc, char** argv)
{
	auto app = GodHunter::CreateApplication();
	app->Run();
	delete app;
}

#endif