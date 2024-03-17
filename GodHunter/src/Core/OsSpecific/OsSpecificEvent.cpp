#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>

namespace GodHunter {

	namespace OsSpecific {

		void HandleEvents() {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
					// Application events
				case SDL_EVENT_QUIT:
					break;
					// Android, iOS and WinRT events
				case SDL_EVENT_TERMINATING:
					break;
				case SDL_EVENT_LOW_MEMORY:
					break;
				case SDL_EVENT_WILL_ENTER_BACKGROUND:
					break;
				case SDL_EVENT_DID_ENTER_BACKGROUND:
					break;
				case SDL_EVENT_WILL_ENTER_FOREGROUND:
					break;
				case SDL_EVENT_DID_ENTER_FOREGROUND:
					break;
				case SDL_EVENT_LOCALE_CHANGED:
					break;
					// Keyboard events
				case SDL_EVENT_KEY_DOWN:
					break;
				case SDL_EVENT_KEY_UP:
					break;
				case SDL_EVENT_TEXT_EDITING:
					break;
				case SDL_EVENT_TEXT_INPUT:
					break;
				case SDL_EVENT_KEYMAP_CHANGED:
					break;
					// Mouse events
				case SDL_EVENT_MOUSE_MOTION:
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					break;
				case SDL_EVENT_MOUSE_WHEEL:
					break;
					// Joystick events
				case SDL_EVENT_JOYSTICK_AXIS_MOTION:
					break;
				case SDL_EVENT_JOYSTICK_BALL_MOTION:
					break;
				case SDL_EVENT_JOYSTICK_HAT_MOTION:
					break;
				case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
					break;
				case SDL_EVENT_JOYSTICK_BUTTON_UP:
					break;
				case SDL_EVENT_JOYSTICK_ADDED:
					break;
				case SDL_EVENT_JOYSTICK_REMOVED:
					break;
					// Controller events
				case SDL_EVENT_GAMEPAD_AXIS_MOTION:
					break;
				case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
					break;
				case SDL_EVENT_GAMEPAD_BUTTON_UP:
					break;
				case SDL_EVENT_GAMEPAD_ADDED:
					break;
				case SDL_EVENT_GAMEPAD_REMOVED:
					break;
				case SDL_EVENT_GAMEPAD_REMAPPED:
					break;
					// Touch events
				case SDL_EVENT_FINGER_DOWN:
					break;
				case SDL_EVENT_FINGER_UP:
					break;
				case SDL_EVENT_FINGER_MOTION:
					break;
					// Clipboard events
				case SDL_EVENT_CLIPBOARD_UPDATE:
					break;
					// Drag and drop events
				case SDL_EVENT_DROP_FILE:
					break;
				case SDL_EVENT_DROP_TEXT:
					break;
				case SDL_EVENT_DROP_BEGIN:
					break;
				case SDL_EVENT_DROP_COMPLETE:
					break;
					// Audio hotplug events
				case SDL_EVENT_AUDIO_DEVICE_ADDED:
					break;
				case SDL_EVENT_AUDIO_DEVICE_REMOVED:
					break;
					// Render events
				case SDL_EVENT_RENDER_TARGETS_RESET:
					break;
				case SDL_EVENT_RENDER_DEVICE_RESET:
					break;
					// These are for your use, and should be allocated with SDL_RegisterEvents()
				case SDL_EVENT_USER:
					break;
				case SDL_EVENT_LAST:
					break;
				default:
					break;
				}
			}
		}

	}

}