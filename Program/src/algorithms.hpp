#include"chrono.cpp"

// Function to Print an array
template<typename T>
void PrintArray(T& arr, int length) {
	for (int i = 0; i < length; i++) {
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
void BubbleSort(T& arr, int length) {
	Timer timer;
	bool swapped{};
	for (int i = 0; i < length - 1; i++) {
		swapped = false;
		for (int j = 0; j < length - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				SwapValues(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) break;
	}
}
