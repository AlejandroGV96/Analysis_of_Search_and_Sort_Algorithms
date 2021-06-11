// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include<iostream>
#include<fstream>

class MyPrinter {
	char algorithms[6][35] = { "Bubble Sort\0", "Insertion Sort\0", "Selection Sort\0", "Quick Sort\0", "Top-Down Merge Sort\0", "Bottom-Up Merge Sort\0" };
	char dataType[3][20] = { "Ordered\0", "Reversed\0", "Random\0" };
	std::ofstream datafile;
public:
	MyPrinter(){
		datafile.open("results.csv");
	}
	void initText(const size_t* sizesArr) {
		if (datafile.is_open())
		{
			datafile << "Num of Integers,";
			std::cout << "Num of Integers,";
			for (size_t i = 0; i < 6; i++)
			{
				std::cout << "N" << int(i) + 1 << " = " << sizesArr[i] << ", ";
				datafile << "N" << int(i) + 1 << " = " << sizesArr[i] << ", ";
			}
			std::cout << "\n\n";
			datafile << "\n\n";
		}
	}
	void title(const int& algName) {
		if (datafile.is_open())
		{
			datafile << algorithms[algName] << ",N1,N2,N3,N4,N5,N6\n";
		}
		std::cout << algorithms[algName] << ": \n";
	}
	void data(const int& data) {

		if (datafile.is_open())
		{
			datafile << dataType[data] << ",";
		}
		std::cout << "	"<< dataType[data] << ": ";
	}
	void timeSpent(const std::string& timeInMs) {

		if (datafile.is_open())
		{
			datafile << timeInMs << ",";
		}
		std::cout << timeInMs << "ms ";
	}
	void fileNewLine(const size_t& n = 1) {
		if (datafile.is_open())
		{
			for (size_t i = 0; i < n; i++) {
				datafile << "\n";
				std::cout << "\n";
			}
		}
	}
};