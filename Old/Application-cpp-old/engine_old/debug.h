/**
 * @file debug.h
 * This file is part of the GodHunter Engine
 *
 * This file provide various means of logging and debugging.
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

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_GODHUNTER_DEBUG_H_
#define GODHUNTER_SRC_GODHUNTER_DEBUG_H_

// Features needed
// 1 - Logging
// 2 - FPS Counter
// 3 - Timing

#ifdef DEBUG

namespace godhunter
{
    // Initialize the debug features
    void initDebug();

    // Assertions
    void assertWithMessage(const char* expression_string_, bool expression_, const char* file_, int line_, const char* message_);
}

// Initialize the debug features
#define INIT_DEBUG() godhunter::initDebug();

// Assertions
#define ASSERTM(expression_, message_) godhunter::assertWithMessage(#expression_, expression_, __FILE__, __LINE__, message_);

#else

// Initialize the debug features
#define INIT_DEBUG()

// Assertions
#define ASSERTM(expression_, message_)

#endif


#endif // GODHUNTER_SRC_GODHUNTER_DEBUG_H_