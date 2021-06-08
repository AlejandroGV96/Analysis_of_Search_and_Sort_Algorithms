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
int min(const T& x, const T& y);

template<typename T>
void merge(T& arr, const int& l, const int& m, const int& r);

template<typename T>
void BubbleSort(T& arr, size_t length);

template <typename T>
void SelectionSort(T& arr,size_t length);

template <typename T>
void InsertionSort(T& arr, size_t length);

template <typename T>
void QuickSort(T& a, int s, int e);

template<typename T>
void mergeSortTpDwn(T& Arr, int left_start, int right_end);

template<typename T>
void mergeSortBtmUp(T& arr, const int& n);


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
int partition(T& arr, int l, int h) {

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

template<typename T>
int min(const T& x, const T& y) { return (x < y) ? x : y; };

template<typename T>
void merge(T& arr, const int& l, const int& m, const int& r) {

	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	int* L = new int[n1];
	int* R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
	delete[] L;
	delete[] R;
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
void QuickSort(T& arr, int l, int h) {

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

template<typename T>
void mergeSortTpDwn(T& Arr, int left_start, int right_end) {

	if (left_start < right_end) {
		int mid = (left_start + right_end) / 2;
		mergeSortTpDwn(Arr, left_start, mid);
		mergeSortTpDwn(Arr, mid + 1, right_end);
		merge(Arr, left_start, mid, right_end);
	}
}

template<typename T>
void mergeSortBtmUp(T& arr, const int& n) {

	int curr_size;  // For current size of subarrays to be merged
					// curr_size varies from 1 to n/2
	int left_start; // For picking starting index of left subarray
					// to be merged

	// Merge subarrays in bottom up manner.  First merge subarrays of
	// size 1 to create sorted subarrays of size 2, then merge subarrays
	// of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		// Pick starting point of different subarrays of current size
		for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
		{
			// Find ending point of left subarray. mid+1 is starting
			// point of right
			int mid = min<int>(left_start + curr_size - 1, n - 1);

			int right_end = min<int>(left_start + 2 * curr_size - 1, n - 1);

			// Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
			merge(arr, left_start, mid, right_end);
		}
	}
}
