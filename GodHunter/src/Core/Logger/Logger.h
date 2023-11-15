// https://gist.github.com/RabaDabaDoba/145049536f815903c79944599c6f952a

#ifndef GODHUNTER_SRC_CORE_LOGGER_LOGGER
#define GODHUNTER_SRC_CORE_LOGGER_LOGGER

#include <stdio.h>
#include <Windows.h>

#include <iostream>
#include <source_location>
#include <string>

#pragma once
namespace Logger {

	enum class LogPriority
	{
		TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
	};

	class Logger
	{
	public:
		Logger();
		~Logger();

		Logger(const Logger&) = delete;
		Logger& operator= (const Logger&) = delete;

	private:
		LogPriority priority = LogPriority::TracePriority;
		short color_code[6] = { 8,2,1,14,4,12 };

		std::string message_display = "%d [%p] %m at line %l in %f";

		const char* filepath = 0;
		FILE* file = 0;

	public:
		template<typename... Args>
		void Trace(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Trace", LogPriority::TracePriority, message, args...);
		}

		template<typename... Args>
		void Debug(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Debug", LogPriority::DebugPriority, message, args...);
		}

		template<typename... Args>
		void Info(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Info", LogPriority::InfoPriority, message, args...);
		}

		template<typename... Args>
		void Warning(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Warning", LogPriority::WarnPriority, message, args...);
		}

		template<typename... Args>
		void Error(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Error", LogPriority::ErrorPriority, message, args...);
		}

		template<typename... Args>
		void Critical(const char* message, std::source_location location = std::source_location::current(), Args... args)
		{
			Log(location, "Critical", LogPriority::CriticalPriority, message, args...);
		}

	private:
		template<typename... Args>
		void Log(std::source_location location, const char* message_priority_str, LogPriority message_priority, const char* message, Args... args)
		{
			if (priority <= message_priority)
			{
				// Change the color of the text on the window
				HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hcon, color_code[(int)message_priority]);

				// Go trough the full string of the message display and print it on the display
				for (unsigned i = 0; i < message_display.size(); i++)
				{
					if ((const char)message_display[i] != (const char)'%')
					{
						std::cout << message_display[i];
					}
					else
					{
						switch ((char)message_display[i + 1])
						{
						case 't':
							std::cout << std::time(0);
							break;
						case 'd':
							std::cout << currentDateTime();
							break;
						case 'p':
							std::cout << message_priority_str;
							break;
						case 'm':
							printf_s(message, args...);
							break;
						case 'l':
							std::cout << location.line();
							break;
						case 'f':
							std::cout << location.file_name();
							break;
						default:
							printf_s("");
						}

						i++;
					}
				}
				printf_s("\n");
				// Print the message on the display

				// Print everything on a file
				if (file)
				{
					for (unsigned i = 0; i < message_display.size(); i++)
					{
						if ((const char)message_display[i] != (const char)'%')
						{
							fprintf(file, (const char* const)message_display[i]);
						}
						else
						{
							switch ((char)message_display[i + 1])
							{
							case 't':
								fprintf(file, (const char* const)std::time(0));
								break;
							case 'd':
								fprintf(file, currentDateTime().c_str());
								break;
							case 'p':
								fprintf(file, message_priority_str);
								break;
							case 'm':
								fprintf(file, message, args...);
								break;
							case 'l':
								fprintf(file, (const char* const)location.line());
								break;
							case 'f':
								fprintf(file, location.file_name());
								break;
							default:
								fprintf(file, "");
							}
							i++;
						}
					}
					fprintf(file, "\n");
				}
			}
		}

		const std::string currentDateTime();

	public:
		void EnableFileOutput();
		void free_file();
		void SetFilePath(const char* new_filepath);

		void SetLogDisplay(const char* display);
		void SetTraceColor(short color);
		void SetDebugColor(short color);
		void SetInfoColor(short color);
		void SetWarningColor(short color);
		void SetErrorColor(short color);
		void SetCriticalColor(short color);
	};

}

#endif