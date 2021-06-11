// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#pragma once
#include "namedef.hpp"
#include "chrono.hpp"

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

template<typename T>
int linearSrch(T& arr, const int& n, int& x);

template <typename T>
int binarySrch(T& arr, int l, int r, int x);


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
	int* L = new int[(size_t)n1];
	int* R = new int[(size_t)n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[(size_t)i] = arr[(size_t)l + (size_t)i];
	for (j = 0; j < n2; j++)
		R[(size_t)j] = arr[(size_t)m + 1 + (size_t)j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[(size_t)i] <= R[(size_t)j])
		{
			arr[(size_t)k] = L[(size_t)i];
			i++;
		}
		else
		{
			arr[(size_t)k] = R[(size_t)j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there are any */
	while (i < n1)
	{
		arr[(size_t)k] = L[(size_t)i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there are any */
	while (j < n2)
	{
		arr[(size_t)k] = R[(size_t)j];
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

	int *stack = new int[(size_t)h - (size_t)l + 1];
	int top = -1;

	stack[++top] = l;
	stack[++top] = h;

	while (top >= 0) {
		// Pop h and l
		h = stack[(size_t)top--];
		l = stack[(size_t)top--];

		int p = partition(arr, l, h);

		if (p - 1 > l) {
			stack[(size_t)++top] = l;
			stack[(size_t)++top] = p - 1;
		}

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

	int curr_size;
	int left_start;

	for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
	{
		for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size)
		{
			int mid = min<int>(left_start + curr_size - 1, n - 1);
			int right_end = min<int>(left_start + 2 * curr_size - 1, n - 1);
			merge(arr, left_start, mid, right_end);
		}
	}
}

template<typename T>
int linearSrch(T& arr, const int& n, int& x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[(size_t)i] == x)
			return i;
	return -1;
}

template <typename T>
int binarySrch(T& arr, int l, int r, int x)
{
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}
	return -1;
}