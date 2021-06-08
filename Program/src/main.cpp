// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "namedef.hpp"
#include "algorithms.hpp"
#include "chrono.hpp"
#include "matrixInit.hpp"

int main() {
	
	// Selecting size of arrays base on the first number introduced.
	size_t size[6]{};
	std::cin >> size[0];
	for (size_t i = 1; i < 6; i++) {
		size[i] = size[0] * (i + 1);
	}

	{
		std::cin.get();

		fullDataStructure DataMatrix = std::make_unique<algorithms[]>(8);
		dataInit(DataMatrix, size);


		for (size_t i = bubble; i <= BinarySearch; i++) {
			std::cout << "|||||||||||" << i+1 << "|||||||||||\n";
			for (size_t j = 0; j < 3; j++) {
				std::cout << "-----------" << j+1 << "-----------\n";
				for (size_t k = 0; k < 6; k++) {
					if (i >= linearSearch && j == 0) {  // Search Algorithms ( With only ordered arrays)
						Timer timer;
						switch (i) {
						case linearSearch:
							//linearSearch(DataMatrix[i][j][k], size[k]);
							timer.stop();
							break;
						case BinarySearch:
							//binarySearch(DataMatrix[i][j][k], size[k]);
							timer.stop();
							break;
						}
					}
					else {
						Timer timer;
						switch (i) {
						case bubble:
							BubbleSort(DataMatrix[i][j][k], size[k]);
							timer.stop();
							break;
						case selection:
							SelectionSort(DataMatrix[i][j][k], size[k]);
							timer.stop();
							break;
						case insertion:
							InsertionSort(DataMatrix[i][j][k], size[k]);
							timer.stop();
							break;
						case quick:
							QuickSort(DataMatrix[i][j][k], 0, (int)size[k] - 1);
							timer.stop();
							break;
						case mergeTopDown:
							mergeSortTpDwn(DataMatrix[i][j][k], 0, (int)size[k] - 1);
							timer.stop();
							break;
						case mergeBottomUp:
							mergeSortBtmUp(DataMatrix[i][j][k], (int)size[k]);
							timer.stop();
							break;
						}
					}
					std::cout << " ";
				}
				std::cout << "\n\n";
			}
			std::cout << "\n\n";
		}
		PrintArray(DataMatrix[linearSearch][ordered][n1],size[n1]);
		std::cin.get();
	}
	std::cin.get();
	return 0;
}

/*
	TODO:
		- Define a log function to send time results to a .csv file. 
		- Implement the rest of algorithms required
		- Think of a  way to test the search algorithms
		- Create a loop of the whole program to see how memory behaves(maybe find a memory leak?)
*/

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