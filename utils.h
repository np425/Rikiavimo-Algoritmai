#ifndef UTILS_H
#define UTILS_H

#include <iostream>

template <class T>
std::ostream& printArray(T* const arr, size_t first, size_t last) {
	for (size_t i = first; i <= last; ++i) {
		std::cout << arr[i] << " ";
	}
	return std::cout;
}

template <class T>
size_t binarySearch(const T val, T * const arr, size_t first, size_t last) {
	size_t mid = (first+last) / 2;

	if (first == last) {
		return first + (arr[first] < val);
	} else if (arr[mid] > val) {
		return binarySearch(val, arr, first, mid);
	} else if (arr[mid] < val) {
		return binarySearch(val, arr, mid+1, last);
	} else return mid;
}



#endif
