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
			const char* windowID;
		};

		std::vector<windowDisplay> displayList;

		int selectedDisplay = -1;

		void CreateDisplay(char* _displayID) {
			windowDisplay modelDisplay;
			modelDisplay.windowID = _displayID;

			SDL_CreateWindowAndRenderer(
				200, 150, 0,
				&modelDisplay.window, &modelDisplay.renderer);

			displayList.push_back(modelDisplay);
		}

		void CreateDisplay(char* _displayID, WindowInformation& _information) {
			windowDisplay modelDisplay;
			modelDisplay.windowID = _displayID;

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
			modelDisplay.window = SDL_CreateWindow(_information.title, _information.width, _information.height, flags);
			modelDisplay.renderer = SDL_CreateRenderer(modelDisplay.window, NULL, 0);

			displayList.push_back(modelDisplay);
		}

		void DestroyDisplay(char* _displayID) {
			int listSize = displayList.size();
			for (int i = 0; i < listSize; ++i) {
				if (displayList.at(i).windowID == _displayID) {
					SDL_DestroyRenderer(displayList[i].renderer);
					SDL_DestroyWindow(displayList[i].window);
					displayList.erase(displayList.begin() + i);
					return;
				}
			}
		}

		void SelectDisplay(char* _displayID) {
			int listSize = displayList.size();
			for (int i = 0; i < listSize; ++i) {
				if (displayList.at(i).windowID == _displayID) {
					selectedDisplay = i;
					return;
				}
			}
		}

		void SetDisplayName(const char* _name) {
			SDL_SetWindowTitle(displayList[selectedDisplay].window, _name);
		}

		void SetDisplaySize(int _width, int _height) {
			SDL_SetWindowSize(displayList[selectedDisplay].window, _width, _height);
		}

		void SetDisplayWidth(int _width) {
			SDL_SetWindowSize(displayList[selectedDisplay].window, _width, GetDisplayHeight());
		}

		void SetDisplayHeight(int _height) {
			SDL_SetWindowSize(displayList[selectedDisplay].window, GetDisplayWidth(), _height);
		}

		int GetDisplayWidth() {
			int* w;
			int* h;
			SDL_GetWindowSize(displayList[selectedDisplay].window, w, h);
			return *w;
		}

		int GetDisplayHeight() {
			int* w;
			int* h;
			SDL_GetWindowSize(displayList[selectedDisplay].window, w, h);
			return *h;
		}

		void SetFullScreen(bool _fullscreen) {
			Uint32 flag = 0;
			if (_fullscreen) flag = SDL_WINDOW_FULLSCREEN;
			SDL_SetWindowFullscreen(displayList[selectedDisplay].window, flag);
		}

		void AllowResize(bool _canResize) {
			SDL_bool flag = SDL_FALSE;
			if (_canResize) flag = SDL_TRUE;
			SDL_SetWindowResizable(displayList[selectedDisplay].window, flag);
		}

		void SetBorders(bool _hasBorders) {
			SDL_bool flag = SDL_FALSE;
			if (_hasBorders) flag = SDL_TRUE;
			SDL_SetWindowBordered(displayList[selectedDisplay].window, flag);
		}

	}

}