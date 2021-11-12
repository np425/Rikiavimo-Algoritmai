#ifndef ARRAYSORT_H
#define ARRAYSORT_H

// NEVEIKIA SU REIKŠMĖMIS KURIOS KARTOJASI

#include <iostream>

// 100000 elementų = 0m40,459s

#include "utils.h"
#include <iostream>
#include <algorithm> // std::swap

template <class T>
void arraySort(T* const arr, size_t first, size_t last) {
	size_t index[last-first+1];
	T sorted[last-first+1];

	std::cout << "Papildomų masyvų rikiavimas" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "Indeksavimas" << std::endl;
	for (size_t i = first; i <= last; ++i) {
		size_t small = 0;
		for (size_t x = first; x <= last; ++x) {
			if (arr[x] < arr[i]) ++small;
		}
		index[i] = small;
		printArray(index, 0, i) << std::endl;
	}

	for (size_t i = first; i <= last; ++i) {
		sorted[index[i]] = arr[i];
	}
	
	std::cout << "Sudejimas į vietą" << std::endl;
	for (size_t i = first; i <= last; ++i) {
		arr[i] = sorted[i];
		printArray(arr, first, last) << std::endl;
	}

	std::cout << "--------------------" << std::endl << std::endl;
}

#endif
