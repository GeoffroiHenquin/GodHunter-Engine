/**
 * @file terminal.h
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

// C system headers

// C++ standard library headers
#include <cstdint>

// Third party libraries headers

// Project headers

// Exceptions


#ifndef GODHUNTER_SRC_GODHUNTER_TERMINAL_H_
#define GODHUNTER_SRC_GODHUNTER_TERMINAL_H_

namespace godhunter
{
	namespace terminal
	{
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

		void enableVirtualTerminalProcessing();
		void setTerminalSize(unsigned int width_, unsigned int height_);
		void openAlternativeBuffer();
		void closeAlternativeBuffer();
		void resetStyle();
		void setStyleBold();
		void setStyleUnderlined();
		void setStyleReversed();
		void setForegroundColor(godhunter::terminal::Color color_);
		void setBackgroundColor(godhunter::terminal::Color color_);
		void setForegroundBrightColor(godhunter::terminal::Color color_);
		void setBackgroundBrightColor(godhunter::terminal::Color color_);
		void setForegroundColorID(std::uint8_t color_id_);
		void setBackgroundColorID(std::uint8_t color_id_);
		void setForegroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_);
		void setBackgroundColorRGB(std::uint8_t r_, std::uint8_t g_, std::uint8_t b_);
	} // namespace terminal

} // namespace godhunter

#endif // GODHUNTER_SRC_GODHUNTER_TERMINAL_H_