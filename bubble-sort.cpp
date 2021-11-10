#include <iostream>
#include <algorithm> // std::swap

// 100000 elementų = 1m23,622s

template <class T>
void bubbleSort(T* const arr, size_t first, size_t last) {
	for (size_t s = first; s <= last; ++s) {
		for (size_t x = first; x < last-first; ++x) {
			if (arr[x] > arr[x+1]) std::swap(arr[x], arr[x+1]);
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

	bubbleSort(arr, 0, n-1);
	
	//for (size_t i = 0; i < n; ++i) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << std::endl;
	return 0;
}
