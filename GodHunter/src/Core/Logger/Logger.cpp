#include "Logger.h"

namespace Logger {

	Logger::Logger()
	{
	}

	Logger::~Logger()
	{
		free_file();
	}

	const std::string Logger::currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		localtime_s(&tstruct, &now);
		strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

		return buf;
	}

	void Logger::EnableFileOutput()
	{
		filepath = "log.txt";

		if (file != 0)
		{
			fclose(file);
		}

		fopen(filepath, "a");

		if (file == 0)
		{
			printf("Logger: Failed to open file at %s", filepath);
		}
	}

	void Logger::free_file()
	{
		fclose(file);
		file = 0;
	}

	void Logger::SetFilePath(const char* new_filepath)
	{
		filepath = new_filepath;
	}

	void Logger::SetLogDisplay(const char* display)
	{
		message_display = (std::string)display;
	}

	void Logger::SetTraceColor(short color)
	{
		if (color == NULL) {
			color = 8;
		}
		color_code[0] = color;
	}

	void Logger::SetDebugColor(short color)
	{
		if (color == NULL) {
			color = 2;
		}
		color_code[1] = color;
	}

	void Logger::SetInfoColor(short color)
	{
		if (color == NULL) {
			color = 1;
		}
		color_code[2] = color;
	}

	void Logger::SetWarningColor(short color)
	{
		if (color == NULL) {
			color = 14;
		}
		color_code[3] = color;
	}

	void Logger::SetErrorColor(short color)
	{
		if (color == NULL) {
			color = 4;
		}
		color_code[4] = color;
	}

	void Logger::SetCriticalColor(short color)
	{
		if (color == NULL) {
			color = 12;
		}
		color_code[5] = color;
	}

}