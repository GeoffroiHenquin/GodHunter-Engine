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
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// Third party libraries headers

// Project headers

// Exceptions
// Include Windows headers only if compiled on Windows with MSVC or MinGW
#ifdef _WIN32
#include <Windows.h> // For Windows API functions
#endif


// --- Debugging utilities ---

// Terminal control class
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


// --- Layer #00 : Inventory and money ---

// Camera struct
struct Camera
{
	float position_x;
	float position_y;
};

// --- Layer #01 : World grid (tiles, map, etc.) ---
// Should be resizable
// Should be easy to modify
// Should support different tile types (floor, wall, door, etc.)
// Should be super fast to access and modify
// Should support serialization and deserialization

// Tile ID type
using tileID_t = uint8_t;

// Map class
template<int _width, int _height>
class Map
{
private:
	tileID_t tiles[_width * _height] = { 0 };
public:
	Map()
	{
	}
	~Map()
	{
	}
	tileID_t operator()(int x_, int y_) const
	{
		return tiles[y_ * _width + x_];
	}
	tileID_t& operator()(int x_, int y_)
	{
		return tiles[y_ * _width + x_];
	}

	void setZeros()
	{
		for (int i = 0; i < _width * _height; ++i) {
			tiles[i] = 0;
		}
	}

	void setDefault()
	{
		setZeros();

		int x_start = 0;
		int y_start = 0;
		int x_end = _width;
		int y_end = _height;

		if (_width % 2 == 0 && _width > 16)
		{
			x_start = (_width / 2) - 8;
			x_end = (_width / 2) + 8;
		}
		if (_height % 2 == 0 && _height > 16)
		{
			y_start = (_height / 2) - 8;
			y_end = (_height / 2) + 8;
		}

		for (int y = y_start; y <= y_end; ++y) {
			for (int x = x_start; x <= x_end; ++x) {
				if (x == x_start || x == x_end || y == y_start || y == y_end) {
					tiles[y * _width + x] = 2; // Wall tile
				}
				else {
					tiles[y * _width + x] = 1; // Floor tile
				}
			}
		}
		// To be implemented
	}

	int getWidth() const { return _width; }
	int getHeight() const { return _height; }

	void loadFromFile(const std::string& filename_)
	{
		// To be implemented
	}
	void saveToFile(const std::string& filename_) const
	{
		// To be implemented
	}
};

// Map instance
Map<64, 64> game_map;


// --- Layer #02 : Attractions and Decorations ---

// --- Layer #03 : AI (Employees, Animatronics, Customers (adults and childrens), Story AI, etc.) ---

// --- Layer #04 : Trash and issues ---



int main(int argc, char* argv[])
{
	// SETUP ----------------------------------------------------------------

	Terminal terminal;
	terminal.enableVirtualTerminalProcessing();
	terminal.setTerminalSize(120, 40);

	game_map.setDefault();

	Camera camera = {
		game_map.getWidth() / 2.0f,
		game_map.getHeight() / 2.0f
	};

	// MAIN LOOP ------------------------------------------------------------
	bool running = true;
	while (running) {
		// HANDLE TIMING --------------------------------------------------------

		// HANDLE INPUT ---------------------------------------------------------

		// HANDLE GAME LOGIC ----------------------------------------------------

		// HANDLE RENDERING -----------------------------------------------------

		unsigned char tile_chars[] = { ' ', '.', '#', 'D' }; // D for Door

		unsigned char buffer[40 * 120] = { 0 };
	}

	// CLEANUP --------------------------------------------------------------
	return 0;
}