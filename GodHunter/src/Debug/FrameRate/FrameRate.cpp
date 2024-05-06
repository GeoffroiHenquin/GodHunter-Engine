#include "FrameRate.h"

#include <chrono>

namespace Debug {

	int fps = 0;

	std::chrono::steady_clock::time_point last_time = std::chrono::high_resolution_clock::now();

	float time_for_frame = 0;

	int getFPS() { return fps; }

	float getTimeForFrame() { return time_for_frame; }

	void countFPS() {
		auto time_now = std::chrono::high_resolution_clock::now();
		auto duration = duration_cast<std::chrono::microseconds>(time_now - last_time);
		last_time = time_now;
		fps = (int)(1000000 / duration.count());
		time_for_frame = (float)(1 / fps);
	}

}