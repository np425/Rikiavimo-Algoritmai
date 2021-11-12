#include <iostream>

#include "bubble-sort.h"
#include "shaker-sort.h"
#include "array-sort.h"
#include "merge-sort.h"
#include "merge-inplace.h"
#include "insertion-sort.h"
#include "selection-sort.h"

#include "utils.h"

typedef void (*sortAlgo)(int* const, size_t, size_t);

constexpr sortAlgo sortAlgos[] = {
	bubbleSort, 
	shakerSort,
	arraySort, 
	mergeSort,
	mergeSortInPlace,
	insertionSort, 
	selectionSort
};

constexpr size_t algoKiek = sizeof(sortAlgos)/sizeof(sortAlgo);

int main() {
	size_t n;
	std::cout << "Iveskite kiek skaičių surikiuoti: " << std::endl;
	std::cin >> n;

	int sk[algoKiek][n];
	
	std::cout << "Iveskite skaičius kuriuos norite surikiuoti: " << std::endl;
	for (size_t i = 0; i < n; ++i) {
		std::cin >> sk[0][i];
		for (size_t a = 1; a < algoKiek; ++a) {
			sk[a][i] = sk[0][i];
		}
	}

	std::cout << "Pradinis masyvas: " << std::endl;
	printArray(sk[0], 0, n-1) << std::endl;

	for (size_t a = 0; a < algoKiek; ++a) {
		sortAlgos[a](sk[a], 0, n-1);
	}
		
	return 0;
}
