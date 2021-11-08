#include <iostream>
#include <algorithm>

// 100000 elementų = 0m7,134s

template <class T>
size_t binarySearch(const T value, T * const arr, size_t first, size_t last) {
	size_t mid = (first+last) / 2;

	if (first == last || (arr[mid] <= value && value <= arr[mid+1]))
		return mid;
	else if (arr[mid] > value)
		return binarySearch(value, arr, first, mid);
	else
		return binarySearch(value, arr, mid+1, last);
}

template <class T>
void merge(T * const arr, size_t first, size_t mid, size_t last) {
	for (size_t j = first; j <= mid; ++j) {
		if (arr[mid+1] < arr[j]) {
			std::swap(arr[mid+1], arr[j]);
			T val = arr[mid+1];
			size_t place = binarySearch(val, arr, mid+1, last);
			for (size_t k = mid+1; k < place; ++k) {
				arr[k] = arr[k+1];
			}
			arr[place] = val;
		}
	}
}

template <class T>
void mergeSort(T * const arr, size_t first, size_t last) {
	if (first < last) {	
		size_t mid = (first+last)/2;
		mergeSort(arr, first, mid);
		mergeSort(arr, mid+1, last);
		merge(arr, first, mid, last);
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

	mergeSort(arr, 0, n-1);
	//for (size_t i = 0; i < n; ++i) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << std::endl;
	return 0;
}
