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


		for (size_t i = 0; i < 3; i++) {
			std::cout << "|||||||||||" << i+1 << "|||||||||||\n";
			for (size_t j = 0; j < 3; j++) {
				std::cout << "-----------" << j+1 << "-----------\n";
				for (size_t k = 0; k < 6; k++) {
					switch (i)
					{
					case 0:
						BubbleSort(DataMatrix[i][j][k], size[k]);
						break;
					case 1:
						SelectionSort(DataMatrix[i][j][k], size[k]);
						break;
					case 2:
						InsertionSort(DataMatrix[i][j][k], size[k]);
						break;
					default:
						break;
					}
					std::cout << ", ";
				}
				std::cout << "\n\n";
			}
			std::cout << "\n\n";
		}

		std::cin.get();
	}
	std::cin.get();
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

*/