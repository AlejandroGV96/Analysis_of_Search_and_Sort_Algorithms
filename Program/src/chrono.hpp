#pragma once
#include <chrono>
#include <string>

class Timer {
	std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
public:
	Timer();
	std::string stop();
};