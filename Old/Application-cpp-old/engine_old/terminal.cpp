/**
 * @file terminal.cpp
 * This file is part of the GodHunter Engine
 *
 * This file provide various features to control the terminal.
 *
 * MIT License
 *
 * Copyright (c) 2024 GeoffroiHenquin
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
#include "terminal.h"

// C system headers

// C++ standard library headers
#include <cstdint>
#include <iostream>

// Third party libraries headers

// Project headers

// Exceptions
// Include Windows headers only if compiled on Windows with MSVC
#ifdef _WIN32
#include <Windows.h>
#endif


void godhunter::terminal::enableVirtualTerminalProcessing()
{
#ifdef _WIN32
	HANDLE terminal_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(terminal_handle, &mode);
	mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
	SetConsoleMode(terminal_handle, mode);
#endif
}

void godhunter::terminal::setTerminalSize(unsigned int width_, unsigned int height_)
{
	std::cout << "\x1b[8;" << height_ << ";" << width_ << "t";
}

void godhunter::terminal::openAlternativeBuffer()
{
	std::cout << "\x1b[?1049h";
}

void godhunter::terminal::closeAlternativeBuffer()
{
	std::cout << "\x1b[?1049l";
}

void godhunter::terminal::resetStyle()
{
	std::cout << "\x1b[0m";
}

void godhunter::terminal::setStyleBold()
{
	std::cout << "\x1b[1m";
}

void godhunter::terminal::setStyleUnderlined()
{
	std::cout << "\x1b[4m";
}

void godhunter::terminal::setStyleReversed()
{
	std::cout << "\x1b[7m";
}

void godhunter::terminal::setForegroundColor(godhunter::terminal::Color color_)
{
	std::cout << "\x1b[3" << color_ << "m";
}

void godhunter::terminal::setBackgroundColor(godhunter::terminal::Color color_)
{
	std::cout << "\x1b[4" << color_ << "m";
}

void godhunter::terminal::setForegroundBrightColor(godhunter::terminal::Color color_)
{
	std::cout << "\x1b[9" << color_ << "m";
}

void godhunter::terminal::setBackgroundBrightColor(godhunter::terminal::Color color_)
{
	std::cout << "\x1b[10" << color_ << "m";
}

void godhunter::terminal::setForegroundColorID(std::uint8_t color_id_)
{
	std::cout << "\x1b[38;5;" << color_id_ << "m";
}

void godhunter::terminal::setBackgroundColorID(std::uint8_t color_id_)
{
	std::cout << "\x1b[48;5;" << color_id_ << "m";
}

void godhunter::terminal::setForegroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_)
{
	std::cout << "\x1b[38;2;" << r_ << ";" << g_ << ";" << b_ << "m";
}

void godhunter::terminal::setBackgroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_)
{
	std::cout << "\x1b[48;2;" << r_ << ";" << g_ << ";" << b_ << "m";
}