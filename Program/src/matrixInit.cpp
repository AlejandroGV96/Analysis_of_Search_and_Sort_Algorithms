#include "matrixInit.hpp"
#include "namedef.hpp"

void matrixValFiller(fullDataStructure& Matrix, size_t& alg, size_t& type, size_t& nArr, size_t& size) {
	for (size_t k = 0; k < size; k++) {
		switch (type) {
		case ordered:
			Matrix[alg][type][nArr][k] = k + 1;
			break;
		case reversed:
			Matrix[alg][type][nArr][k] = size - k;
			break;
		case random:
			Matrix[alg][type][nArr][k] = rand() % size;
			break;
		}
	}
}
void dataInit(fullDataStructure& DataMatrix,size_t size[]) {
	for (size_t i = 0; i < 8; ++i) {
		DataMatrix[i] = std::make_unique<typeOfData[]>(3);
	
		std::srand(1); // reseting randomizer
	
		for (size_t j = 0; j < 3; ++j) {
			DataMatrix[i][j] = std::make_unique<sixSizesArrays[]>(6);
	
			for (size_t n = 0; n < 6; ++n) {
				DataMatrix[i][j][n] = std::make_unique<int[]>(size[n]);
				matrixValFiller(DataMatrix, i, j, n, size[n]);
			}
		}
	}
}