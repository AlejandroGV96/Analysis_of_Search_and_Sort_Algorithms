// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include "namedef.hpp"
#include "chrono.hpp"
#include <algorithm>

template<typename T>
void PrintArray(T& arr, size_t length);

template<typename T>
void SwapValues(T& x, T& y);

template<typename T>
int partition(T& a, int s, int e);

template<typename T>
void BubbleSort(T& arr, size_t length);

template <typename T>
void SelectionSort(T& arr,size_t length);

template <typename T>
void InsertionSort(T& arr, size_t length);

template <typename T>
void QuickSort(T& a, int s, int e);


// ---------------------IMPLEMENTATIONS--------------------------

template<typename T>
void PrintArray(T& arr, size_t length) {
	for (size_t i = 0; i < length; i++) {
		std::cout << arr[i] << std::endl;
	}
}

template<typename T>
void SwapValues(T& x, T& y) {
	T temp{x};
	x = y;
	y = temp;
}

template<typename T>
int partition(T& arr, int l, int h)
{
	int x = arr[(size_t)h];
	int i = (l - 1);

	for (int j = l; j <= h - 1; j++) {
		if (arr[(size_t)j] <= x) {
			i++;
			SwapValues(arr[(size_t)i], arr[(size_t)j]);
		}
	}
	SwapValues(arr[(size_t)i + 1], arr[(size_t)h]);
	return (i + 1);
}

// Bubble Sort Algorithm
template<typename T>
void BubbleSort(T& arr, size_t length) {
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
	size_t minimal{};
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

	size_t j{};
	int k{};

	for (size_t i = 1; i < length; i++) {
		k = arr[i];
		j = i - 1;
		while ( arr[j] > k) {
			arr[j + 1] = arr[j];
			if (!j) {
				break;
			}
			j--;
		}
		arr[j + 1] = k;
	}
}

template<typename T>
void QuickSort(T& arr, int l, int h)
{
	// Create an auxiliary stack
	int *stack = new int[(size_t)h - (size_t)l + 1];

	// initialize top of stack
	int top = -1;

	// push initial values of l and h to stack
	stack[++top] = l;
	stack[++top] = h;

	// Keep popping from stack while is not empty
	while (top >= 0) {
		// Pop h and l
		h = stack[(size_t)top--];
		l = stack[(size_t)top--];

		// Set pivot element at its correct position
		// in sorted array
		int p = partition(arr, l, h);

		// If there are elements on left side of pivot,
		// then push left side to stack
		if (p - 1 > l) {
			stack[(size_t)++top] = l;
			stack[(size_t)++top] = p - 1;
		}

		// If there are elements on right side of pivot,
		// then push right side to stack
		if (p + 1 < h) {
			stack[(size_t)++top] = p + 1;
			stack[(size_t)++top] = h;
		}
	}
	delete[] stack;
}