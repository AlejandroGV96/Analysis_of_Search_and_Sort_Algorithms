// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include <string>
#include "chrono.hpp"

Timer::Timer() : m_StartTimePoint{ std::chrono::high_resolution_clock::now() } {}


std::string Timer::stop() {
	auto endTimePoint = std::chrono::high_resolution_clock::now();
	
	auto Start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
	auto End = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();;
	
	auto duration = End - Start;
	auto ms = std::to_string( duration * 0.001);
	ms.erase(ms.begin() + ms.find_last_not_of('0'), ms.end());
	return ms;
	
	//std::cout << ms << "ms";// << std::endl;
}