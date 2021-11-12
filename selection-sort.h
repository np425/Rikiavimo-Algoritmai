#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

// 100000 elementų = 0m15,070s 
#include "selection-sort.h"
#include "utils.h"
#include <iostream>
#include <algorithm>

template <class T>
static size_t findMax(T* const arr, size_t first, size_t last) {
	size_t maxI = first;
	for (size_t i = first+1; i <= last; ++i) {
		if (arr[i] > arr[maxI]) maxI = i;
	}
	return maxI;
}

template <class T>
void selectionSort(T * const arr, size_t first, size_t last) {
	std::cout << "Selection sort" << std::endl;
	std::cout << "--------------------" << std::endl;
	for (size_t i = first; i <= last; ++i) {
		size_t maxI = findMax(arr, first, last-i);
		std::cout << "Max: " << arr[maxI] << std::endl;
		std::swap(arr[last-i], arr[maxI]);
		printArray(arr, first, last) << std::endl;
	}
	std::cout << "--------------------" << std::endl;
}

#endif
