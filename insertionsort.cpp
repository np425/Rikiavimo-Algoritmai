#include <iostream>
#include <algorithm> // std::swap

// 100000 elementų = 0m40,459s

template <class T>
void insertionSort(T* const arr, size_t first, size_t last) {
	for (size_t s = first; s < last; ++s) {
		for (size_t x = s+1; x > first && arr[x-1] > arr[x]; --x) {
			std::swap(arr[x], arr[x-1]);
		}
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

	insertionSort(arr, 0, n-1);
	//for (size_t i = 0; i < n; ++i) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << std::endl;
	return 0;
}
