#pragma once
#include "namedef.hpp"
#include "chrono.hpp"

template<typename T>
void PrintArray(T& arr, size_t length);

template<typename T>
void SwapValues(T& x, T& y);

template<typename T>
void BubbleSort(T& arr, size_t length);

template <typename T>
void SelectionSort(T& arr,size_t length);

template <typename T>
void InsertionSort(T& arr, size_t length);

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

// Bubble Sort Algorithm
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

// Selection Sort Algorithm
template <typename T>
void SelectionSort(T& arr, size_t length) {
	Timer timer;
	int minimal{};
	for (size_t i = 0; i < length; i++) {
		minimal = i;
		for (size_t j = i + 1; j < length; j++) {
			if (arr[minimal] > arr[j]) minimal = j;
		}
		if (minimal != i) SwapValues(arr[i], arr[minimal]);
	}
}

// Insertion Sort Algorithm
template <typename T>
void InsertionSort(T& arr, size_t length) {
	Timer timer;

	int j{};
	int k{};

	for (size_t i = 1; i < length; i++) {
		k = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > k) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = k;
	}
}