/**
 * @file debugging_tools.cpp
 * This file is part of the GodHunter Engine
 *
 * This file implements the various debbuging features declared in debbugging_tools.h.
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
#include "debugging_tools.h"

// C system headers

// C++ standard library headers
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <iostream>


// Third party libraries headers

// Project headers

// Exceptions
// The file windows.h can only be used on Windows. In this case it will be used to control the terminal.
#ifdef _WIN32
#include <Windows.h>
#endif


namespace debuggingtools
{
	void printToConsole(const char* message_)
	{
		std::cout << message_;
	}

	void printToFile(const char* message_, const char* output_file_)
	{
		std::ofstream output_file(output_file_);
		output_file << message_;
		output_file.close();
	}
} // namespace debuggingtools






// -----------------------------------------------------------------------------------------------------------------------------------

namespace debuggingtools
{
	/**
	 * Write an assertion message in a file and end the execution of the program.
	 *
	 * @param expression_ The expression that was asserted.
	 * @param file_ The file in which the assertion was called.
	 * @param line_ The line where the assertion was called.
	 * @param message_ The message that indicate what failed.
	 * @return void
	 */
	void assert(const char* expression_, const char* file_, int line_, const char* message_)
	{
		// Write failure to file
		std::ofstream output_file("assert.txt");
		output_file << "[ASSERT] ( " << expression_ << " )\n" << "[FILE] " << file_ << "\n" << "[LINE] " << line_ << "\n" << "[MESSAGE] " << message_;
		output_file.close();

		// End the program
		std::abort();
	}

	Logger::Logger() : m_logger_name("Logger")
	{
	}

	Logger::Logger(const char* logger_name_) : m_logger_name(logger_name_)
	{
	}

	Logger::~Logger()
	{
		delete[] m_logger_name;
	}

	void Logger::setActive(bool active_)
	{
		m_active = active_;
	}

	void Logger::setLevel(LoggerLevel level_)
	{
		m_level = level_;
	}

	bool Logger::logPrint(const char* message_, const char* file_, int line_, LoggerLevel level_)
	{
		// Print message to console
		std::cout << g_logging_color_table[level_] << "[" << g_logging_prefix_table[level_] << "] " << message_ << " at line " << line_ << " in file " << file_ << "\n" << "\033[0m\n";

		// Print the message to a file
		// TODO: add the ability to modify the output file.
		std::ofstream output_file("log.txt");
		output_file << "[" << g_logging_prefix_table[level_] << "] " << message_ << " at line " << line_ << " in file " << file_ << "\n";
		output_file.close();

		return true;
	}

	void Logger::log(const char* message_, const char* file_, int line_, LoggerLevel level_)
	{
		(void)((!(m_active && level_>=m_level)) || logPrint(message_, file_, line_, level_));
	}

#ifdef _WIN32
	bool enableTerminalColors()
	{
		DWORD console_mode;
		HANDLE output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (GetConsoleMode(output_handle, &console_mode))
		{
			SetConsoleMode(output_handle, console_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
		}
		return false;
	}

	bool g_console_color_enabled = enableTerminalColors();
#endif // _WIN32

	/**
	 * Struct - FrameRateCounterData
	 *
	 * Used to contain various time points and time informations in order to calculate the framerate.
	 * WARNING: this struct should only be defined and used in "debbugging_tools.cpp". This is done in order to avoid dependencies.
	 */
	struct FrameRateCounterData
	{
		// Last recorded time
		std::chrono::steady_clock::time_point last_recorded_time = std::chrono::high_resolution_clock::now();

		// Average time to render 1 frame
		std::chrono::microseconds frame_time_average = std::chrono::microseconds::zero();

		// Highest time to render 1 frame
		std::chrono::microseconds frame_time_highest = std::chrono::microseconds::zero();

		// Lowest time to render 1 frame
		std::chrono::microseconds frame_time_lowest = std::chrono::microseconds::zero();
	};

	FrameRateCounter::FrameRateCounter() : m_framerate_counter_data(new FrameRateCounterData), m_loop_name("main loop")
	{
	}

	FrameRateCounter::FrameRateCounter(const char* loop_name_) : m_framerate_counter_data(new FrameRateCounterData), m_loop_name(loop_name_)
	{
	}

	FrameRateCounter::~FrameRateCounter()
	{
		printFrameRateToFile();
		delete[] m_loop_name;
		delete m_framerate_counter_data;
	}

	/**
	 * Check how much time it took to render a frame.
	 *
	 * @return void
	 */
	void FrameRateCounter::calculateFrameRate()
	{
		// Get current time
		std::chrono::steady_clock::time_point current_time = std::chrono::high_resolution_clock::now();

		// Get the time since last frame
		std::chrono::microseconds duration = duration_cast<std::chrono::microseconds>(current_time - m_framerate_counter_data->last_recorded_time);

		// Replace the last recorded time
		m_framerate_counter_data->last_recorded_time = current_time;

		// Get the average time for a frame
		m_framerate_counter_data->frame_time_average = duration_cast<std::chrono::microseconds>((m_framerate_counter_data->frame_time_average + duration) * 0.5);

		// Check if the duration is the highest or lowest
		m_framerate_counter_data->frame_time_highest += (duration > m_framerate_counter_data->frame_time_highest) * (duration - m_framerate_counter_data->frame_time_highest);
		m_framerate_counter_data->frame_time_lowest -= (duration < m_framerate_counter_data->frame_time_lowest) * (m_framerate_counter_data->frame_time_lowest - duration);
	}

	/**
	 * Print the framerate in a file.
	 *
	 * @return void
	 */
	void FrameRateCounter::printFrameRateToFile()
	{
		std::ofstream output_file("framerate.txt", std::ios::app);
		output_file << m_loop_name << "\n"; 
		output_file << "[AVG] " << (int)(1000000 / m_framerate_counter_data->frame_time_average.count()) << "\n";
		output_file << "[LOW] " << (int)(1000000 / m_framerate_counter_data->frame_time_highest.count()) << "\n";
		output_file << "[HIG] " << (int)(1000000 / m_framerate_counter_data->frame_time_lowest.count()) << "\n";
		output_file.close();
	}

} // namespace debuggingtools