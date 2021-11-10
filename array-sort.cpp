#include <iostream>
#include <algorithm> // std::swap

// 100000 elementų = 0m40,459s

template <class T>
void arraySort(T* const arr, size_t first, size_t last) {
	size_t index[last-first+1];
	T sorted[last-first+1];

	for (size_t i = first; i <= last; ++i) {
		size_t small = 0;
		for (size_t x = first; x <= last; ++x) {
			if (arr[x] < arr[i]) ++small;
		}
		index[i] = small+1;
	}

	for (size_t i = first; i <= last; ++i) {
		sorted[index[i]-1] = arr[i];
	}
	
	for (size_t i = first; i <= last; ++i) {
		arr[i] = sorted[i];
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

	arraySort(arr, 0, n-1);
	//for (size_t i = 0; i < n; ++i) {
	//	std::cout << arr[i] << " ";
	//}
	//std::cout << std::endl;
	return 0;
}
