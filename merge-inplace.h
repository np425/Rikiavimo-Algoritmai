#ifndef MERGEINPLACE_H
#define MERGEINPLACE_H

#include "utils.h"
#include <iostream>
#include <algorithm>

// 100000 elementų = 0m7,134s


template <class T>
static void mergeInPlace(T * const arr, size_t first, size_t mid, size_t last) {
	for (size_t j = first; j <= mid; ++j) {
		if (arr[mid+1] < arr[j]) {
			std::swap(arr[mid+1], arr[j]);

			if (mid+1 == last) continue;

			T val = arr[mid+1];

			size_t p = binarySearch(val, arr, mid+2, last);
			
			std::cout << "p: " << p-mid-2 << std::endl;		
			printArray(arr, first, mid) << "| ";
			printArray(arr, mid+1, last) << std::endl;
		
			for (size_t k = mid+1; k < p-1; ++k) {
				arr[k] = arr[k+1];
				printArray(arr, first, mid) << "| ";
				printArray(arr, mid+1, last) << std::endl;
			}
			
			arr[p-1] = val;
			printArray(arr, first, mid) << "| ";
			printArray(arr, mid+1, last) << std::endl;
		}
	}
}

template <class T>
static void _mergeSortInPlace(T * const arr, size_t first, size_t last) {
	if (first < last) {	
		size_t mid = (first+last)/2;
		_mergeSortInPlace(arr, first, mid);
		_mergeSortInPlace(arr, mid+1, last);
	
		std::cout << "Sujungiami masyvai: " << std::endl;
		printArray(arr, first, mid) << "| ";
		printArray(arr, mid+1, last) << std::endl;
		mergeInPlace(arr, first, mid, last);

	}
}

template <class T>
void mergeSortInPlace(T* const arr, size_t first, size_t last) {
	std::cout << "Merge sort in place" << std::endl;
	std::cout << "--------------------" << std::endl;
	_mergeSortInPlace(arr, first, last);
	std::cout << "--------------------" << std::endl << std::endl;
}


#endif
