#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace GodHunter {

	namespace OsSpecific {

		void Delay(int _milliseconds) {
			SDL_Delay(_milliseconds);
		}

	}

}