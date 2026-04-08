/**
 * @file timer.h
 * This file is part of the GodHunter Engine
 *
 * This file declare various timing functions.
 * This include a way to delay the execution of code and a way to calculate
 * the time it takes for code to be executed.
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
#include <chrono>
#include <cstdint>

// Third party libraries headers

// Project headers

// Exceptions

#ifndef GODHUNTER_SRC_GODHUNTER_TIMER_H_
#define GODHUNTER_SRC_GODHUNTER_TIMER_H_

namespace godhunter
{

    typedef std::chrono::system_clock::time_point time_point_t;
    typedef std::uint32_t duration_ms_t;

    godhunter::time_point_t getCurrentTimePoint();

    godhunter::duration_ms_t calculateElapsedTime(godhunter::time_point_t start_time_, godhunter::time_point_t end_time_);

    void delay(godhunter::duration_ms_t delay_ms_);

    float millisecondsToSeconds(godhunter::duration_ms_t time_ms_);

} // namespace godhunter

#endif // GODHUNTER_SRC_GODHUNTER_TIMER_H_