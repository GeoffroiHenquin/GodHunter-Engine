#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace GodHunter {

	namespace OsSpecific {

		void InitOsSpecificSystems() {
			SDL_Init(SDL_INIT_EVERYTHING);
		}

		void CloseOsSpecificSystems() {
			SDL_Quit();
		}

	}

}