#include "../Core/Events/EngineEvents.h"
#include "EngineState.h"

namespace GodHunter {

	namespace EngineState {

		bool Running = true;

		bool& getRunning() {
			return Running;
		}

	}

}

void GodHunter::EngineEvents::_GodHunter_Quit() {
	GodHunter::EngineState::Running = false;
}