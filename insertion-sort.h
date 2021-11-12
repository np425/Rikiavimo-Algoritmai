#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

// 100000 elementų = 0m40,459s

#include "utils.h"
#include <iostream>
#include <algorithm> // std::swap

// 100000 elementų = 0m40,459s

template <class T>
void insertionSort(T* const arr, size_t first, size_t last) {
	std::cout << "Insertion sort" << std::endl;
	std::cout << "--------------------" << std::endl;

	for (size_t s = first+1; s <= last; ++s) {
		printArray(arr, first, s) << "| ";
		printArray(arr, s+1, last) << std::endl;

		T val = arr[s];
		size_t p = binarySearch(val, arr, first, s-1);
		std::cout << "p: " << p << std::endl;		


		for (size_t x = s; x > p; --x) {
			arr[x] = arr[x-1];
			//std::swap(arr[x], arr[x-1]);

			printArray(arr, first, s) << "| ";
			printArray(arr, s+1, last) << std::endl;
		}

		arr[p] = val;
		printArray(arr, first, s) << "| ";
		printArray(arr, s+1, last) << std::endl;
	}

	std::cout << "--------------------" << std::endl << std::endl;
}

#endif
