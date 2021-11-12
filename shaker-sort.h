#ifndef SHAKERSORT_H
#define SHAKERSORT_H

#include "utils.h"
#include <iostream>
#include <algorithm> // std::swap

template <class T>
void shakerSort(T* const arr, size_t first, size_t last) {
	std::cout << "Shaker sort" << std::endl;
	std::cout << "--------------------" << std::endl;
	
	int incr = +1;
	size_t x = first;
	size_t l = first;

	for (; l != last; incr = -incr, ++l) {
		bool sorted = false;

		size_t end = (incr == 1 ? last-l/2-1 : l/2);
		
		for (; x != end; x += incr) {
			if (arr[x] > arr[x+1]) {
				std::swap(arr[x], arr[x+1]);
				printArray(arr, first, end) << "| ";
				printArray(arr, end+1, last) << std::endl;
				sorted = false;
			} 
		}

		if (sorted) break;
	}

	std::cout << "--------------------" << std::endl << std::endl;
}

#endif
