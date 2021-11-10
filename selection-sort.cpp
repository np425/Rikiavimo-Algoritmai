#include <iostream>
#include <algorithm>

// 100000 elementų = 0m15,070s 

template <class T>
size_t findMax(T* const arr, size_t first, size_t last) {
	size_t max = arr[first];
	for (size_t i = first+1; i <= last; ++i) {
		if (arr[i] > arr[max]) max = i;
	}
	return max;
}

template <class T>
void selectionSort(T * const arr, size_t first, size_t last) {
	for (size_t i = first; i <= last; ++i) {
		std::swap(arr[last-i], arr[findMax(arr, first, last-i)]);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	size_t n;
	std::cin >> n;

	int arr[n];
	for (size_t i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	selectionSort(arr, 0, n-1);
	//for (size_t i = 0; i < n; ++i) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << std::endl;
	return 0;
}
