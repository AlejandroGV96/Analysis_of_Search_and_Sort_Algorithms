#include<iostream>
#include<chrono>

class Timer {
	public:
		Timer() {
			m_StartTimePoint = std::chrono::high_resolution_clock::now();
		}

		~Timer() {
			stop();
		}

		void stop() {
			auto endTimePoint = std::chrono::high_resolution_clock::now();
			
			auto Start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimePoint).time_since_epoch().count();
			auto End = std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();;
			
			auto duration = End - Start;
			auto ms = duration * 0.001;
			
			std::cout << ms << "ms" << std::endl;
		}
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimePoint;
};