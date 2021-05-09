#include<iostream>

enum MatrixInfo
{
	bubble = 0,
	selection,
	insertion,
	quick,
	mergeTopDown,
	mergeBottomUp,
	linearSearch,
	BinarySearch,

	ordered = 0,
	reversed,
	random,

	n1 = 0,
	n2,
	n3,
	n4,
	n5,
	n6,

	size_n1 = 100,
	size_n2 = 1000,
	size_n3 = 10000,
	size_n4 = 100000,
	size_n5 = 1000000,
	size_n6 = 10000000,

};

void matrixValFiller(int ****Matrix,int &usedAlg, int &type,int nArr ,int size ) {
	for (int k = 0; k < size; k++) {
		switch (type) {
		case ordered:
			Matrix[usedAlg][type][nArr][k] = k + 1;
			break;
		case reversed:
			Matrix[usedAlg][type][nArr][k] = size - k;
			break;
		case random:
			Matrix[usedAlg][type][nArr][k] = rand() % size;
		}
	}
}

int main() {

	// Data Structure for the arrays to be sorted by the algorithms
	//	DataMatrix[0 - 7] : Set of arrays that will be sorted with the named algorithm (Bubble Sort, Selection Sort, Insertion Sort, Quick Sort, Merge Sort Top-Down, Merge Sort Bottom-Up, Linear Search, Binary Search)
	//	DataMatrix[][0 - 2] : Set of arrays with different types of data (ordered, reversed, random)
	//	DataMatrix[][][0-5] : Set of arrays with different sizes of data (n1, n2, n3, n4, n5, n6)
	int**** DataMatrix = new int***[8]; // First Dimension: 8 Algorithms to use 
	for (int i = 0; i < 8; i++) {

		std::cout << "Initializing " << i + 1 << "# set of arrays" << std::endl;
		DataMatrix[i] = new int**[3]; // Second Dimension: 3 types of data for each algorithm
		
		// Reseting random seed to ensure that every algorithm will sort the same random array
		std::srand(1);

		for (int j = 0; j < 3; j++) {
			DataMatrix[i][j] = new int*[6]; // Third Dimension: 6 sizes of data for each type

			// Fourth Dimension : Fill the arrays with data depending on required size and data type
			DataMatrix[i][j][n1] = new int[size_n1];
				matrixValFiller(DataMatrix, i, j, n1, size_n1);
			DataMatrix[i][j][n2] = new int[size_n2]{};
				matrixValFiller(DataMatrix, i, j, n2, size_n2);
			DataMatrix[i][j][n3] = new int[size_n3]{};
				matrixValFiller(DataMatrix, i, j, n3, size_n3);
			DataMatrix[i][j][n4] = new int[size_n4]{};
				matrixValFiller(DataMatrix, i, j, n4, size_n4);
			DataMatrix[i][j][n5] = new int[size_n5]{};
				matrixValFiller(DataMatrix, i, j, n5, size_n5);
			DataMatrix[i][j][n6] = new int[size_n6]{};
				matrixValFiller(DataMatrix, i, j, n6, size_n6);
		}
	}

}