// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "matrixInit.hpp"
#include "namedef.hpp"

void matrixValFiller(fullDataStructure& Matrix, size_t alg, size_t type, size_t nArr, size_t size) {
	for (size_t k = 0; k < size; k++) {
		switch (type) {
		case ordered:
			Matrix[alg][type][nArr][k] = int(k + 1);
			break;
		case reversed:
			Matrix[alg][type][nArr][k] = int(size - k);
			break;
		case random:
			Matrix[alg][type][nArr][k] = rand() % size;
			break;
		}
	}
}
void dataInit(fullDataStructure& DataMatrix,size_t size[]) {

	// For Sorting Algorithms
	for (size_t i = bubble; i <= mergeBottomUp; ++i) {
		DataMatrix[i] = std::make_unique<typeOfData[]>(3);
	
		std::srand(1); // reseting randomizer
	
		for (size_t j = 0; j < 3; ++j) {
			DataMatrix[i][j] = std::make_unique<sixSizesArrays[]>(6);
	
			for (size_t arrSize = 0; arrSize < 6; ++arrSize) {
				DataMatrix[i][j][arrSize] = std::make_unique<int[]>(size[arrSize]);
				matrixValFiller(DataMatrix, i, j, arrSize, size[arrSize]);
			}
		}
	}

	// For Searching Algorithms
	for (size_t i = linearSearch; i <= BinarySearch; ++i) {
		DataMatrix[i] = std::make_unique<typeOfData[]>(1);
		DataMatrix[i][ordered] = std::make_unique<sixSizesArrays[]>(6);
		for (size_t arrSize = 0; arrSize < 6; ++arrSize) {
			DataMatrix[i][0][arrSize] = std::make_unique<int[]>(size[arrSize]);
			matrixValFiller(DataMatrix, i, ordered, arrSize, size[arrSize]);
		}
	}
}