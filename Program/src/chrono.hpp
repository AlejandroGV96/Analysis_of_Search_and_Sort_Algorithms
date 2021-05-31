#pragma once
#include <chrono>

class Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
	Timer();
	void stop();
};