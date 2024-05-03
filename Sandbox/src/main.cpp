#include <GodHunter.h>

int main(int argc, char* argv[]) {
	GodHunter::startEngine({ (char*)"MyGame", 800, 600, false, true, true });
	GodHunter::runEngine();
	GodHunter::stopEngine;
	return 0;
}