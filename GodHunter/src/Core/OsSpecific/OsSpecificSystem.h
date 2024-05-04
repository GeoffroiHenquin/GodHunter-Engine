#pragma once

#include "../Structures/WindowInformation.h"
#include "../Structures/Color.h"

namespace GodHunter {

	namespace OsSpecific {

		// Os Specific System
		void InitOsSpecificSystems();
		void CloseOsSpecificSystems();

		// Os Specific Display
		void CreateDisplay();
		void CreateDisplay(WindowInformation& _information);
		void DestroyDisplay();

		void SetDisplayName(const char* _name);

		void SetDisplaySize(int _width, int _height);
		void SetDisplayWidth(int _width);
		void SetDisplayHeight(int _height);

		int GetDisplayWidth();
		int GetDisplayHeight();

		void SetFullScreen(bool _fullscreen);
		void AllowResize(bool _canResize);
		void SetBorders(bool _hasBorders);

		void FillDisplay(RGBAColor& _color);

		// Os Specific Audio

		// Os Specific Events
		void HandleEvents();

		// Os Specific Clock
		void Delay(int _milliseconds);

	}

}
