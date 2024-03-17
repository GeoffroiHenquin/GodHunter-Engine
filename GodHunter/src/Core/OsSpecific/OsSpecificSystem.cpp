#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>

namespace GodHunter {

	namespace OsSpecific {

		void InitOsSpecificSystems() {
			SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER | SDL_INIT_EVENTS | SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_HAPTIC | SDL_INIT_SENSOR);
		}

		void CloseOsSpecificSystems() {
			SDL_Quit();
		}

	}

}