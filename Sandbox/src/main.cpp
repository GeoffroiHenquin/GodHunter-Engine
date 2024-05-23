#include <GodHunter.h>

int main(int argc, char* argv[]) {
	GodHunter::loadWindowInformation({ (char*)"MyGame", 800, 600, false, true, true });
	GodHunter::runEngine();
	return 0;
}