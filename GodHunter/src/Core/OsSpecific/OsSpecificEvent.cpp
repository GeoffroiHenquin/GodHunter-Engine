#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>

#include "../Events/EngineEvents.h"

namespace GodHunter {

	namespace OsSpecific {

		void HandleEvents() {
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				//case SDL_EVENT_FIRST:
					//break;

					// Application events
					/* Application events */
				case SDL_EVENT_QUIT: /**< User-requested quit */
					GodHunter::EngineEvents::_GodHunter_Quit();
					break;

					// Android, iOS and WinRT events
					/* These application events have special meaning on iOS */
				//case SDL_EVENT_TERMINATING: /*The application is being terminated by the OS*/
					//break;
				//case SDL_EVENT_LOW_MEMORY: /*The application is low on memory, free memory if possible.*/
					//break;
				//case SDL_EVENT_WILL_ENTER_BACKGROUND: /*The application is about to enter the background*/
					//break;
				//case SDL_EVENT_DID_ENTER_BACKGROUND: /*The application did enter the background and may not get CPU for some time*/
					//break;
				//case SDL_EVENT_WILL_ENTER_FOREGROUND: /*The application is about to enter the foreground*/
					//break;
				//case SDL_EVENT_DID_ENTER_FOREGROUND: /*The application is now interactive*/
					//break;
				//case SDL_EVENT_LOCALE_CHANGED: /*The user's locale preferences have changed.*/
					//break;
				//case SDL_EVENT_SYSTEM_THEME_CHANGED: /*The system theme changed*/
					//break;

					// Display events
					/* Display events */
				//case SDL_EVENT_DISPLAY_ORIENTATION: /*Display orientation has changed to data1*/
					//break;
				//case SDL_EVENT_DISPLAY_ADDED: /*Display has been added to the system*/
					//break;
				//case SDL_EVENT_DISPLAY_REMOVED: /*Display has been removed from the system*/
					//break;
				//case SDL_EVENT_DISPLAY_MOVED: /*Display has changed position*/
					//break;
				//case SDL_EVENT_DISPLAY_CONTENT_SCALE_CHANGED: /*Display has changed content scale*/
					//break;
				//case SDL_EVENT_DISPLAY_HDR_STATE_CHANGED: /*Display HDR properties have changed*/
					//break;

					// Window events
				//case SDL_EVENT_WINDOW_SHOWN: /* Window was shown */
					//break;
				//case SDL_EVENT_WINDOW_HIDDEN: /* Window was hidden */
					//break;
				//case SDL_EVENT_WINDOW_EXPOSED: /* Window has been exposed and should be redrawn */
					//break;
				//case SDL_EVENT_WINDOW_MOVED: /* Window has been moved to position x, y */
					//break;
				//case SDL_EVENT_WINDOW_RESIZED: /* Window has been resized to width x height */
					//break;
				//case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED: /* pixel size of the window has changed to width x height */
					//break;
				//case SDL_EVENT_WINDOW_MINIMIZED: /* Window has been minimized */
					//break;
				//case SDL_EVENT_WINDOW_MAXIMIZED: /* Window has been maximized */
					//break;
				//case SDL_EVENT_WINDOW_RESTORED:
					//break;
				//case SDL_EVENT_WINDOW_MOUSE_ENTER: /* Window has gained mouse focus */
					//break;
				//case SDL_EVENT_WINDOW_MOUSE_LEAVE: /* Window has lost mouse focus */
					//break;
				//case SDL_EVENT_WINDOW_FOCUS_GAINED: /* Window has gained keyboard focus */
					//break;
				//case SDL_EVENT_WINDOW_FOCUS_LOST: /* Window has lost keyboard focus */
					//break;
				//case SDL_EVENT_WINDOW_CLOSE_REQUESTED: 
					//break;
				//case SDL_EVENT_WINDOW_TAKE_FOCUS: 
					//break;
				//case SDL_EVENT_WINDOW_HIT_TEST: 
					//break;
				//case SDL_EVENT_WINDOW_ICCPROF_CHANGED:
					//break;
				//case SDL_EVENT_WINDOW_DISPLAY_CHANGED: 
					//break;
				//case SDL_EVENT_WINDOW_DISPLAY_SCALE_CHANGED: 
					//break;
				//case SDL_EVENT_WINDOW_OCCLUDED: 
					//break;
				//case SDL_EVENT_WINDOW_ENTER_FULLSCREEN: /* Started Fullscreen */
					//break;
				//case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN: /* Ended Fullscreen */
					//break;
				//case SDL_EVENT_WINDOW_DESTROYED: /* Window was destroyed */
					//break;
				//case SDL_EVENT_WINDOW_PEN_ENTER: /* Window has gained pen focus */
					//break;
				//case SDL_EVENT_WINDOW_PEN_LEAVE: /* Window has lost pen focus */
					//break;

					// Keyboard events
				//case SDL_EVENT_KEY_DOWN:
					//break;
				//case SDL_EVENT_KEY_UP:
					//break;
				//case SDL_EVENT_TEXT_EDITING:
					//break;
				//case SDL_EVENT_TEXT_INPUT:
					//break;
				//case SDL_EVENT_KEYMAP_CHANGED:
					//break;

					// Mouse events
				//case SDL_EVENT_MOUSE_MOTION:
					//break;
				//case SDL_EVENT_MOUSE_BUTTON_DOWN:
					//break;
				//case SDL_EVENT_MOUSE_BUTTON_UP:
					//break;
				//case SDL_EVENT_MOUSE_WHEEL:
					//break;

					// Joystick events
				//case SDL_EVENT_JOYSTICK_AXIS_MOTION:
					//break;
				//case SDL_EVENT_JOYSTICK_BALL_MOTION:
					//break;
				//case SDL_EVENT_JOYSTICK_HAT_MOTION:
					//break;
				//case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
					//break;
				//case SDL_EVENT_JOYSTICK_BUTTON_UP:
					//break;
				//case SDL_EVENT_JOYSTICK_ADDED:
					//break;
				//case SDL_EVENT_JOYSTICK_REMOVED:
					//break;
				//case SDL_EVENT_JOYSTICK_BATTERY_UPDATED:
					//break;
				//case SDL_EVENT_JOYSTICK_UPDATE_COMPLETE:
					//break;

					// Controller/Gamepad events
				//case SDL_EVENT_GAMEPAD_AXIS_MOTION:
					//break;
				//case SDL_EVENT_GAMEPAD_BUTTON_DOWN:
					//break;
				//case SDL_EVENT_GAMEPAD_BUTTON_UP:
					//break;
				//case SDL_EVENT_GAMEPAD_ADDED:
					//break;
				//case SDL_EVENT_GAMEPAD_REMOVED:
					//break;
				//case SDL_EVENT_GAMEPAD_REMAPPED:
					//break;
				//case SDL_EVENT_GAMEPAD_TOUCHPAD_DOWN: 
					//break;
				//case SDL_EVENT_GAMEPAD_TOUCHPAD_MOTION: 
					//break;
				//case SDL_EVENT_GAMEPAD_TOUCHPAD_UP: 
					//break;
				//case SDL_EVENT_GAMEPAD_SENSOR_UPDATE: 
					//break;
				//case SDL_EVENT_GAMEPAD_UPDATE_COMPLETE: 
					//break;
				//case SDL_EVENT_GAMEPAD_STEAM_HANDLE_UPDATED: 
					//break;

					// Touch events
				//case SDL_EVENT_FINGER_DOWN:
					//break;
				//case SDL_EVENT_FINGER_UP:
					//break;
				//case SDL_EVENT_FINGER_MOTION:
					//break;

					// Clipboard events
				//case SDL_EVENT_CLIPBOARD_UPDATE:
					//break;

					// Drag and drop events
				//case SDL_EVENT_DROP_FILE:
					//break;
				//case SDL_EVENT_DROP_TEXT:
					//break;
				//case SDL_EVENT_DROP_BEGIN:
					//break;
				//case SDL_EVENT_DROP_COMPLETE:
					//break;
				//case SDL_EVENT_DROP_POSITION:
					//break;

					// Audio hotplug events
				//case SDL_EVENT_AUDIO_DEVICE_ADDED: 
					//break;
				//case SDL_EVENT_AUDIO_DEVICE_REMOVED: 
					//break;
				//case SDL_EVENT_AUDIO_DEVICE_FORMAT_CHANGED: 
					//break;

					/* Sensor events */
				//case SDL_EVENT_SENSOR_UPDATE: /**< A sensor was updated */
					//break;

					/* Pressure-sensitive pen events */
				//case SDL_EVENT_PEN_DOWN: /**< Pressure-sensitive pen touched drawing surface */
					//break;
				//case SDL_EVENT_PEN_UP: /**< Pressure-sensitive pen stopped touching drawing surface */
					//break;
				//case SDL_EVENT_PEN_MOTION: /**< Pressure-sensitive pen moved, or angle/pressure changed */
					//break;
				//case SDL_EVENT_PEN_BUTTON_DOWN: /**< Pressure-sensitive pen button pressed */
					//break;
				//case SDL_EVENT_PEN_BUTTON_UP: /**< Pressure-sensitive pen button released */
					//break;

					/* Camera hotplug events */
				//case SDL_EVENT_CAMERA_DEVICE_ADDED: /**< A new camera device is available */
					//break;
				//case SDL_EVENT_CAMERA_DEVICE_REMOVED: /**< A camera device has been removed. */
					//break;
				//case SDL_EVENT_CAMERA_DEVICE_APPROVED: /**< A camera device has been approved for use by the user. */
					//break;
				//case SDL_EVENT_CAMERA_DEVICE_DENIED: /**< A camera device has been denied for use by the user. */
					//break;

					// Render events
				//case SDL_EVENT_RENDER_TARGETS_RESET:
					//break;
				//case SDL_EVENT_RENDER_DEVICE_RESET:
					//break;

					/* Internal events */
				//case SDL_EVENT_POLL_SENTINEL:
					//break;

					// These are for your use, and should be allocated with SDL_RegisterEvents()
				//case SDL_EVENT_USER:
					//break;
				//case SDL_EVENT_LAST:
					//break;

				default:
					break;
				}
			}
		}

	}

}