#include <GodHunter.h>

class Sandbox : public GodHunter::Application
{
public:
	Sandbox()
	{
		gameDisplayInfo = { (char*)"MyGame", 800, 600, false, true, true };
	}
	~Sandbox()
	{
		
	}
};

GodHunter::Application* GodHunter::CreateApplication() 
{
	return new Sandbox();
}
