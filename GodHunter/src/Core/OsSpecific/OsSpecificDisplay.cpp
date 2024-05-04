#include "OsSpecificSystem.h"

#define SDL_MAIN_HANDLED
#include <SDL3/SDL.h>

#include <vector>

namespace GodHunter {

	namespace OsSpecific {

		// Struct for a window
		struct windowDisplay {
			SDL_Window* window;
			SDL_Renderer* renderer;
		};

		windowDisplay _display;

		void CreateDisplay() {
			SDL_CreateWindowAndRenderer(
				200, 150, 0,
				&_display.window, &_display.renderer);
		}

		void CreateDisplay(WindowInformation& _information) {
			// Setting the flags
			Uint32 flags = 0;
			if (_information.windowIsFullscreen) {
				flags = flags | SDL_WINDOW_FULLSCREEN;
			}
			if (!_information.windowHasBorder) {
				flags = flags | SDL_WINDOW_BORDERLESS;
			}
			if (_information.windowIsResizable) {
				flags = flags | SDL_WINDOW_RESIZABLE;
			}
			// Create Window
			_display.window = SDL_CreateWindow(_information.title, _information.width, _information.height, flags);
			_display.renderer = SDL_CreateRenderer(_display.window, NULL, 0);
		}

		void DestroyDisplay(char* _displayID) {
			SDL_DestroyRenderer(_display.renderer);
			SDL_DestroyWindow(_display.window);
		}

		void SetDisplayName(const char* _name) {
			SDL_SetWindowTitle(_display.window, _name);
		}

		void SetDisplaySize(int _width, int _height) {
			SDL_SetWindowSize(_display.window, _width, _height);
		}

		void SetDisplayWidth(int _width) {
			SDL_SetWindowSize(_display.window, _width, GetDisplayHeight());
		}

		void SetDisplayHeight(int _height) {
			SDL_SetWindowSize(_display.window, GetDisplayWidth(), _height);
		}

		int GetDisplayWidth() {
			int* w;
			int* h;
			SDL_GetWindowSize(_display.window, w, h);
			return *w;
		}

		int GetDisplayHeight() {
			int* w;
			int* h;
			SDL_GetWindowSize(_display.window, w, h);
			return *h;
		}

		void SetFullScreen(bool _fullscreen) {
			Uint32 flag = 0;
			if (_fullscreen) flag = SDL_WINDOW_FULLSCREEN;
			SDL_SetWindowFullscreen(_display.window, flag);
		}

		void AllowResize(bool _canResize) {
			SDL_bool flag = SDL_FALSE;
			if (_canResize) flag = SDL_TRUE;
			SDL_SetWindowResizable(_display.window, flag);
		}

		void SetBorders(bool _hasBorders) {
			SDL_bool flag = SDL_FALSE;
			if (_hasBorders) flag = SDL_TRUE;
			SDL_SetWindowBordered(_display.window, flag);
		}

	}

}