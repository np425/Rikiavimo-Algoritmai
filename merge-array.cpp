#include <iostream>
#include <algorithm>

// 100000 elementų = 0m0,039s

template <class T>
void merge(T * const arr, size_t first, size_t mid, size_t last) {
	T temp[last-first+1];

	size_t j = first;
	size_t k = mid+1;
	size_t i = 0;

	while (j <= mid && k <= last) {
		if (arr[k] < arr[j])
			temp[i++] = arr[k++];
		else 
			temp[i++] = arr[j++];
	}

	while (j <= mid) 
		temp[i++] = arr[j++];
	
	while (k <= last) 
		temp[i++] = arr[k++];
	
	for (size_t y = 0; y < i; ++y) 
		arr[first+y] = temp[y];
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
