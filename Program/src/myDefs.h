#pragma once
#include<iostream>
#include"chrono.cpp"

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
};

typedef std::unique_ptr<int[]> sixSizesArrays; // n1 - n6 data sizes
typedef std::unique_ptr<sixSizesArrays[]> typeOfData; // ordered, reverse and 'random'
typedef std::unique_ptr<typeOfData[]> algorithms; // algorithms that will sort stored data
typedef std::unique_ptr<algorithms[]> fullDataStructure; // Data Matrix containing all data

template<typename T>
void PrintArray(T& arr, int length);

template<typename T>
void SwapValues(T& x, T& y);

template<typename T>
void BubbleSort(T& arr, int length);

// IMPLEMENTATIONS
#include"algorithms.hpp"