#include "Logger.h"

#include <iostream>
#include <fstream>

namespace GodHunter {

	namespace Debug {

		const char* TextColorTable[5] = {
			"\x1b[90m", // TEXT_COLOR_GREY
			"\x1b[92m", // TEXT_COLOR_BRIGHT_GREEN
			"\x1b[97m", // TEXT_COLOR_BRIGHT_WHITE
			"\x1b[93m", // TEXT_COLOR_BRIGHT_YELLOW
			"\x1b[91m"  // TEXT_COLOR_BRIGHT_RED
		};

		const char* TextPrefixTable[5] = {
			"TRACE", 
			"DEBUG", 
			"INFO", 
			"WARNING", 
			"ERROR"
		};

		void _Log(int _priority, const char* _fileName, int _lineNumber, const char* _message) {
			std::cout << TextColorTable[_priority] << "[" << TextPrefixTable[_priority] << "] " << _message << " at line " << _lineNumber << " in file " << _fileName << "\033[0m\n";

			std::ofstream MyFile("log.txt", std::ios::app);
			MyFile << "[" << TextPrefixTable[_priority] << "] " << _message << " at line " << _lineNumber << " in file " << _fileName << "\n";
			MyFile.close();
		}

	}

}

