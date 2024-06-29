/**
 * @file debugging_tools.h
 * This file is part of the GodHunter Engine
 *
 * This file contains various features to debug and profile the engine and the games made with it.
 * All of these features should only exist in DEBUG mode.
 *
 * MIT License
 *
 * Copyright (c) 2023 GeoffroiHenquin
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

#ifndef GODHUNTER_SRC_DEBUGGING_TOOLS_H_
#define GODHUNTER_SRC_DEBUGGING_TOOLS_H_

// TODO: Implement assert().
/**
 * This is used to check if the values we use in the code make sens.
 * As an example: Lets imagine a function that should only take for input a value between 0 and 1.
 * We would add the line ASSERT(input>=0 && input<=1)
 * If it's true, the execution should continue with no issue.
 * If it's false, the program should stop and give an error message.
 */


// TODO: Implement a way to time the execution of code.
/**
 * This is used to check how much time a function takes to execute.
 * We would use it by writing COUNT_TIME( myFunction(x, y); ).
 * When not in debug mode, it should just execute myFunction(x, y);
 * When in debug mode, it should count the time it takes and print it in a message or in a file.
 */


// TODO: Implement a logger.
/**
 * This logger should have to print, in console and in file, various messages with differents types that can be silenced if needed.
 * Various file should have their own logger.
 * It should be a cleaner version of std::cout or std::println()
 */


// TODO: Implement a way to show stats of a game and dump them in a file.
// ???


// TODO: Implement a way to check how much memory each system takes.
/**
 * This seems to be difficult to implement and might not be very useful.
 */


// TODO: If possible, implement a way to record the screen.
/**
 * Recording the screen is a platform dependant feature and should therefore be handled by SDL.
 * SDL does not have this feature and therefore we cannot do this one.
 */

#endif // GODHUNTER_SRC_DEBUGGING_TOOLS_H_