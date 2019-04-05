#include "Search.h"

void main() {
	int arr[10];
	int answer;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		arr[i] = rand() % 10 + 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] == arr[j]) {
				i--;
				break;
			}
		}
	}
	std::cout << "문자열 입력 : ";
	std::cin >> answer;
	for (int i = 0; i < 10; i++) std::cout << arr[i] << " ";
	std::cout << std::endl;

	sequentialSearch(arr, answer);
	std::cout << std::endl;
	binarySearch(arr, answer, 0, 9);

	getchar();
	getchar();
}