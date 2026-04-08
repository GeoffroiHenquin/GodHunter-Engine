/**
 * @file main.cpp
 * This file is part of the UFFPS project
 *
 * This file is a prototype for a FNAF Tycoon Game.
 *
 * MIT License
 *
 * Copyright (c) 2025 GeoffroiHenquin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

// Related header

// C system headers

// C++ standard library headers
#include <cstdint> // For fixed-width integer types like std::uint8_t
#include <iostream> // For std::cout
#include <string> // For std::string

// Third party libraries headers

// Project headers

// Exceptions
// Include Windows headers only if compiled on Windows with MSVC or MinGW
#ifdef _WIN32
#include <Windows.h> // For Windows API functions
#endif


// Terminal control class
// -------------------------------
class Terminal
{
public:
	enum Color
	{
		black = 0,
		red = 1,
		green = 2,
		yellow = 3,
		blue = 4,
		purple = 5,
		cyan = 6,
		white = 7
	};
public:
	void enableVirtualTerminalProcessing()
	{
#ifdef _WIN32
		HANDLE terminal_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		DWORD mode = 0;
		GetConsoleMode(terminal_handle, &mode);
		mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
		SetConsoleMode(terminal_handle, mode);
#endif
	}

	void setTerminalSize(unsigned int width_, unsigned int height_)
	{
		std::cout << "\x1b[8;" << height_ << ";" << width_ << "t";
	}

	void openAlternativeBuffer()
	{
		std::cout << "\x1b[?1049h";
	}

	void closeAlternativeBuffer()
	{
		std::cout << "\x1b[?1049l";
	}

	void resetStyle()
	{
		std::cout << "\x1b[0m";
	}

	void setStyleBold()
	{
		std::cout << "\x1b[1m";
	}

	void setStyleUnderlined()
	{
		std::cout << "\x1b[4m";
	}

	void setStyleReversed()
	{
		std::cout << "\x1b[7m";
	}

	void setForegroundColor(Terminal::Color color_)
	{
		std::cout << "\x1b[3" << color_ << "m";
	}

	void setBackgroundColor(Terminal::Color color_)
	{
		std::cout << "\x1b[4" << color_ << "m";
	}

	void setForegroundBrightColor(Terminal::Color color_)
	{
		std::cout << "\x1b[9" << color_ << "m";
	}

	void setBackgroundBrightColor(Terminal::Color color_)
	{
		std::cout << "\x1b[10" << color_ << "m";
	}

	void setForegroundColorID(std::uint8_t color_id_)
	{
		std::cout << "\x1b[38;5;" << color_id_ << "m";
	}

	void setBackgroundColorID(std::uint8_t color_id_)
	{
		std::cout << "\x1b[48;5;" << color_id_ << "m";
	}

	void setForegroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_)
	{
		std::cout << "\x1b[38;2;" << r_ << ";" << g_ << ";" << b_ << "m";
	}

	void setBackgroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_)
	{
		std::cout << "\x1b[48;2;" << r_ << ";" << g_ << ";" << b_ << "m";
	}
};
// -------------------------------

// Command system
// -------------------------------
class CommandSystem
{
public:
	void readCommand()
	{
	}
};
// -------------------------------

// Context
// -------------------------------
class Context
{
public:

};
// -------------------------------

// Main entry point
int main()
{
	// Setup terminal
	Terminal terminal;
	terminal.enableVirtualTerminalProcessing();
	terminal.setTerminalSize(100, 30);

	bool running = true;
	while (running)
	{
		terminal.resetStyle();

		// Print context on the terminal
		std::cout << "This is the context.\n";
		terminal.resetStyle();

		// Wait for a command input
		std::cout << "> ";
		terminal.setForegroundBrightColor(Terminal::black);
		std::string command;
		std::cin >> command;
		terminal.resetStyle();

		// Process the command and print the result
		terminal.setForegroundBrightColor(Terminal::green);
		std::cout << "This is the result\n";
		terminal.resetStyle();

		running = false; // For now, just exit immediately
	}
	return 0;
}