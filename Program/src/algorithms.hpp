#pragma once
#include "myDefs.h"
#include "chrono.hpp"

template<typename T>
void PrintArray(T& arr, size_t length);

template<typename T>
void SwapValues(T& x, T& y);

template<typename T>
void BubbleSort(T& arr, size_t length);




// ---------------------IMPLEMENTATIONS--------------------------

template<typename T>
void PrintArray(T& arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << std::endl;
	}
}

template<typename T>
void SwapValues(T& x, T& y) {
	T temp{};
	temp = x;
	x = y;
	y = temp;
}

template<typename T>
void BubbleSort(T& arr, size_t length) {
	Timer timer;
	bool swapped{};
	for (size_t i = 0; i < length - 1; i++) {
		swapped = false;
		for (size_t j = 0; j < length - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				SwapValues(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}
