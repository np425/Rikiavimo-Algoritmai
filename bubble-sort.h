#ifndef BUBBLESORT_H
#define BUBBLESORT_H

// 100000 elementų = 1m23,622s

#include "utils.h"
#include <iostream>
#include <algorithm> // std::swap

template <class T>
void bubbleSort(T* const arr, size_t first, size_t last) {
	std::cout << "Bubble sort" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (size_t s = first; s <= last; ++s) {
		for (size_t x = first; x < last-s; ++x) {
			if (arr[x] > arr[x+1]) {
				std::swap(arr[x], arr[x+1]);
				printArray(arr, first, last-s) << "| ";
				printArray(arr, last-s+1, last) << std::endl;
			}
		}
	}

	std::cout << "--------------------" << std::endl << std::endl;
}

#endif
