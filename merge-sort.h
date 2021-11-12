#ifndef MERGESORT_H
#define MERGESORT_H

// 100000 elementų = 0m0,039s

#include <iostream>
#include "utils.h"

template <class T>
static void merge(T * const arr, size_t first, size_t mid, size_t last) {
	T temp[last-first+1];

	size_t j = first;
	size_t k = mid+1;
	size_t i = 0;

	while (j <= mid && k <= last) {
		if (arr[k] < arr[j]) {
			temp[i++] = arr[k++];
			std::cout << "{D} ";
		} else {
			temp[i++] = arr[j++];
			std::cout << "{K} ";
		}
		printArray(temp, 0, i-1) << std::endl;
	}

	while (j <= mid) {
		temp[i++] = arr[j++];
		std::cout << "{K} ";
		printArray(temp, 0, i-1) << std::endl;
	}

	while (k <= last) {
		temp[i++] = arr[k++];
		std::cout << "{D} ";
		printArray(temp, 0, i-1) << std::endl;
	}

	for (size_t y = 0; y < i; ++y) 
		arr[first+y] = temp[y];
}

template <class T>
static void _mergeSort(T * const arr, size_t first, size_t last) {
	if (first < last) {	
		size_t mid = (first+last)/2;
		_mergeSort(arr, first, mid);
		_mergeSort(arr, mid+1, last);
	
		std::cout << "Sujungiami masyvai: " << std::endl;
		printArray(arr, first, mid) << "| ";
		printArray(arr, mid+1, last) << std::endl;
		//printArray(arr, mid+1, last);
		merge(arr, first, mid, last);
	}
}

template <class T>
void mergeSort(T* const arr, size_t first, size_t last) {
	std::cout << "Merge sort" << std::endl;
	std::cout << "--------------------" << std::endl;
	_mergeSort(arr, first, last);
	std::cout << "--------------------" << std::endl << std::endl;
}

#endif
