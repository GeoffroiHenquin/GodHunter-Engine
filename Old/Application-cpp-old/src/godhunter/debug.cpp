/**
 * @file debug.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implements the various means of logging and debugging.
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
#include "debug.h"

// C system headers

// C++ standard library headers
#include <fstream>
#include <iostream>

// Third party libraries headers

// Project headers
#include "terminal.h"

// Exceptions

#ifdef DEBUG

// Assertions
namespace godhunter
{
    void initDebug()
    {
        godhunter::terminal::enableVirtualTerminalProcessing();
    }

    void assertWithMessage(const char* expression_string_, bool expression_, const char* file_, int line_, const char* message_)
    {
        if (!expression_)
        {
            // Print error to console
            godhunter::terminal::setForegroundColor(godhunter::terminal::red);
            std::cerr << "Assert failed:\t" << message_ << "\n"
                << "Expected:\t" << expression_string_ << "\n"
                << "Source:\t\t" << file_ << ", line " << line_ << "\n";
            godhunter::terminal::resetStyle();

            // Print error to log file
            std::ofstream assert_file("assert.txt");
			assert_file << "Assert failed:\t" << message_ << "\n"
				<< "Expected:\t" << expression_string_ << "\n"
				<< "Source:\t\t" << file_ << ", line " << line_ << "\n";
			assert_file.close();
            abort();
        }
    }

}

#endif