// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "namedef.hpp"
#include "algorithms.hpp"
#include "chrono.hpp"
#include "dataOutput.cpp"
#include "matrixInit.hpp"

void algorithmSelection(fullDataStructure& DataMatrix, size_t i, size_t j, size_t k, size_t* size, MyPrinter& print);

int main() {

	std::cout << "Empirical Analysis of Sort Algorithms.\n\n	Author: Alejandro Garcia Vera.\n	ID: w63666.\n	Subject: Algorithms and Data Structures.\n	Year of study: First year, second semester.\n\n\The program will measure the time taken to sort sets of arrays.\nEach set contains three subsets of six arrays (with increasing number of elements).\nThe subsets represent different arrangements of data contained (ordered, reversed and random).\nThe used algorithms for each set are the followings:\n -Bubble Sort.\n -Insertion Sort.\n -Selection Sort.\n -Quick Sort.\n -Top-Down Merge Sort.\n -Bottom-Up Merge Sort.\nThe results will be displayed in the console.\nA file called 'results.csv' will be generated storing the results.\n\nThe size of the arrays will be based on the size of the first one.\nPlease provide the size of the first array: ";
	size_t size[6]{};
	std::cin >> size[0];
	
	for (size_t i = 1; i < 6; i++) size[i] = size[0] * (i+1);

	MyPrinter print;
	print.initText(size);

	std::cin.get();

	fullDataStructure DataMatrix = std::make_unique<algorithms[]>(6);
	dataInit(DataMatrix, size);

	for (size_t i = bubble; i <= mergeBottomUp; i++) {
		print.title(i);
		for (size_t j = ordered; j <= random; j++) {
			print.data(j);
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