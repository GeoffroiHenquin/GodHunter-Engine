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


/**
Logger
- Log to the console
- Log to a file
- Use multiple levels of logging:
	- Fatal: 
		- tells that the application encountered an event or entered a state in which one of the crucial business functionality is no longer working
	- Error: 
		- used when the application hits an issue preventing one or more functionalities from properly functioning
		- can be used when one of the payment systems is not available, but there is still the option to check out
	- Warn: 
		- indicates that something unexpected happened in the application
		- used in situations that are unexpected, but the code can continue the work
		- For example, a parsing error occurred that resulted in a certain document not being processed
	- Info: 
		- standard log level indicating that something happened
		- For example, a controller of your authorization API may include an INFO log level with information on which user requested authorization if the authorization was successful
	- Debug: 
		- Used for information that may be needed for diagnosing issues
		- For the purpose of making sure everything is running correctly
	- Trace: 
		- Very verbose
		- Used in rare cases where you need the full visibility of what is happening in your application
		- Used for example to annotate each step in the algorithm

Assert
- Error: If condition is false, 
	- Print an error to the console
	- Print the assert informations to a file
	- Crash the program
- Warning: If condition is false, 
	- Print an warning to the console

Framerate Counter
- Count the time to render each frame.
- Print the framerate informations to a file at the end.
- Print a warning to the console if a frame takes to long to render
*/




namespace debuggingtools
{
	// TODO: Create a logger
	enum LoggerLevel
	{
		logger_level_trace = 0,
		logger_level_debug = 1,
		logger_level_info = 2,
		logger_level_warning = 3,
		logger_level_error = 4,
		logger_level_fatal = 5
	};

	void printToConsole(const char* message_);
	void printToFile(const char* message_, const char* output_file_);

	void log(const char* message_, const char* file_, int line_, LoggerLevel log_level_);

	void initLogger();

	// TODO: Create Assert

	// TODO: Create Framerate Counter
} // namespace debuggingtools










// ---------------------------------------------------------------------------------

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
	void assert(const char* expression_, const char* file_, int line_, const char* message_);
} // namespace debuggingtools

#ifdef DEBUG
#define DEBUGGING_TOOLS_ASSERT(expression_, message_) (void)((!!(expression_)) || debuggingtools::assert(#expression_, __FILE__, __LINE__, message_))
#else
#define DEBUGGING_TOOLS_ASSERT(expression_, message_)
#endif


// TODO: Add comments for the logger.
namespace debuggingtools
{
	const char* g_logging_color_table[5] = {
		"\x1b[90m", // TEXT_COLOR_GREY
		"\x1b[92m", // TEXT_COLOR_BRIGHT_GREEN
		"\x1b[97m", // TEXT_COLOR_BRIGHT_WHITE
		"\x1b[93m", // TEXT_COLOR_BRIGHT_YELLOW
		"\x1b[91m"  // TEXT_COLOR_BRIGHT_RED
	};

	const char* g_logging_prefix_table[5] = {
		"TRACE",
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	class Logger
	{
	private:
		const char* m_logger_name;
		LoggerLevel m_level = logger_level_trace;
		bool m_active = false;
	public:
		Logger();
		Logger(const char* logger_name_);
		~Logger();

		void setActive(bool active_);
		void setLevel(LoggerLevel level_);

		void log(const char* message_, const char* file_, int line_, LoggerLevel level_);
	private:
		bool logPrint(const char* message_, const char* file_, int line_, LoggerLevel level_);
	};
} // namespace debuggingtools

// TODO: Create the various macros.
#ifdef DEBUG

#else
#define DEBUGGING_TOOLS_LOGGER_INIT(variable_, logger_name_)
#define DEBUGGING_TOOLS_LOGGER_SET_ACTIVE(variable_, active_)
#define DEBUGGING_TOOLS_LOGGER_SET_LEVEL(variable_, level_)
#define DEBUGGING_TOOLS_LOG_TRACE(variable_, message_)
#define DEBUGGING_TOOLS_LOG_DEBUG(variable_, message_)
#define DEBUGGING_TOOLS_LOG_INFO(variable_, message_)
#define DEBUGGING_TOOLS_LOG_WARN(variable_, message_)
#define DEBUGGING_TOOLS_LOG_ERROR(variable_, message_)
#endif


namespace debuggingtools
{
	/**
	 * Struct - FrameRateCounterData
	 *
	 * Used to contain various time points and time informations in order to calculate the framerate.
	 * WARNING: this struct should only be defined and used in "debbugging_tools.cpp". This is done in order to avoid dependencies.
	 */
	struct FrameRateCounterData;

	/**
	 * Class - FrameRateCounter
	 *
	 * This class is used to calculate the framerate of a game loop.
	 *
	 * FrameRateCounter my_framerate_counter("main loop");
	 * for (true) {
	 * my_framerate_counter.calculateFrameRate();
	 * }
	 * my_framerate_counter.printFrameRateToFile();
	 */
	class FrameRateCounter
	{
	private:
		// Used to contain various time points and time informations.
		FrameRateCounterData* m_framerate_counter_data;
		// Name of the loop its used on.
		const char* m_loop_name;
	public:
		FrameRateCounter();
		FrameRateCounter(const char* loop_name_);
		~FrameRateCounter();

		/**
		 * Check how much time it took to render a frame.
		 * 
		 * @return void
		 */
		void calculateFrameRate();

		/**
		 * Print the framerate in a file. 
		 * 
		 * @return void
		 */
		void printFrameRateToFile();
	};
} // namespace debuggingtools

#ifdef DEBUG
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_INIT(variable_, loop_name_) FrameRateCounter variable_(loop_name_)
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_CALCULATE(variable_) variable_.calculateFrameRate()
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_PRINT(variable_) variable_.printFrameRateToFile()
#else
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_INIT(variable_, loop_name_)
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_CALCULATE(variable_)
#define DEBUGGING_TOOLS_FRAMERATE_COUNTER_PRINT(variable_)
#endif // DEBUG

// TODO: Create a conditionnal assert.

#endif // GODHUNTER_SRC_DEBUGGING_TOOLS_H_