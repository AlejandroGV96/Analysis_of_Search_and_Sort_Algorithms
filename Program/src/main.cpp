// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "namedef.hpp"
#include "algorithms.hpp"
#include "chrono.hpp"
#include "dataOutput.cpp"
#include "matrixInit.hpp"

void algorithmSelection(fullDataStructure& DataMatrix, size_t i, size_t j, size_t k, size_t* size, MyPrinter& print);

int main() {
	
	size_t size[6]{};
	std::cin >> size[0];
	
	for (size_t i = 1; i < 6; i++) size[i] = size[0] * (i+1);

	MyPrinter print;
	print.initText(size);

	std::cin.get();

	fullDataStructure DataMatrix = std::make_unique<algorithms[]>(6);
	dataInit(DataMatrix, size);

	for (size_t i = bubble; i <= mergeBottomUp; i++) {
		print.title((int)i);
		for (size_t j = ordered; j <= random; j++) {
			print.data((int)j);
			for (size_t k = 0; k < 6; k++) {
				algorithmSelection(DataMatrix, i, j, k, size, print);
			}
			print.fileNewLine();
		}
		print.fileNewLine();
	}

	std::cin.get();
	return 0;
}

void algorithmSelection(fullDataStructure& DataMatrix, size_t i, size_t j, size_t k, size_t* size, MyPrinter& print) {
	Timer timer;
	std::string ms;
	switch (i) {
	case bubble:
		BubbleSort(DataMatrix[i][j][k], size[k]);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	case selection:
		SelectionSort(DataMatrix[i][j][k], size[k]);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	case insertion:
		InsertionSort(DataMatrix[i][j][k], size[k]);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	case quick:
		QuickSort(DataMatrix[i][j][k], 0, (int)size[k] - 1);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	case mergeTopDown:
		mergeSortTpDwn(DataMatrix[i][j][k], 0, (int)size[k] - 1);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	case mergeBottomUp:
		mergeSortBtmUp(DataMatrix[i][j][k], (int)size[k]);
		ms = timer.stop();
		print.timeSpent(ms);
		break;
	}
}

/*
	REFERENCES:

		-Inspiration for using typedef, to create a smart pointers data structure
		 that allows automatic deallocation of memory used
		https://stackoverflow.com/questions/15488470/syntax-for-dynamically-allocating-a-2d-array-of-smart-pointers

		-Benchmarking with chrono
		https://www.youtube.com/watch?v=YG4jexlSAjc

		- Iterative quick sort
		https://www.geeksforgeeks.org/iterative-quick-sort/
*/