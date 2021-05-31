// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "chrono.hpp"

Timer::Timer() : m_StartTimePoint{ std::chrono::high_resolution_clock::now() } {}


void Timer::stop() {
	auto endTimePoint = std::chrono::high_resolution_clock::now();
	
	auto Start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
	auto End = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();;
	
	auto duration = End - Start;
	auto ms = duration * 0.001;
	
	std::cout << ms << "ms";// << std::endl;
}