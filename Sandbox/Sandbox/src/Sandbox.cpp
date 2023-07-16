#include <GodHunter.h>

class Sandbox : public GodHunter::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{
		
	}
};

GodHunter::Application* GodHunter::CreateApplication() 
{
	return new Sandbox();
}
