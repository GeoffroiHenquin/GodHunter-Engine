#pragma once

namespace GodHunter {

	namespace Debug {

		void _Log(int _priority, const char* _fileName, int _lineNumber, const char* _message);

	}

}

#define DEBUG
#ifdef DEBUG

#define LOG_TRACE(_message) _Log(0, __FILE__, __LINE__, _message);
#define LOG_DEBUG(_message) _Log(1, __FILE__, __LINE__, _message);
#define LOG_INFO(_message) _Log(2, __FILE__, __LINE__, _message);
#define LOG_WARN(_message) _Log(3, __FILE__, __LINE__, _message);
#define LOG_ERROR(_message) _Log(4, __FILE__, __LINE__, _message);

#else

#define LOG_TRACE(_message)
#define LOG_DEBUG(_message)
#define LOG_INFO(_message)
#define LOG_WARN(_message)
#define LOG_ERROR(_message)

#endif // DEBUG