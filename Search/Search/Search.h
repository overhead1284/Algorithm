#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void sequentialSearch(int arr[], int answer) {
	int n = 10;
	for (int i = 0; i < n; i++) {
		if (arr[i] == answer) {
			std::cout << "���� Ž�� : Ž�� ��ġ(ȸ��) : " << i + 1;
			break;
		}
		else {
			if (i == n - 1) std::cout << "Ž�� ����";
		}
	}
}

void binarySearch(int arr[], int answer, int low, int high) {
	if (low > high) return;
	else {
		int mid = (low + high) / 2;
		if (arr[mid] == answer) {
			std::cout << "���� Ž�� : Ž�� ��ġ :" << mid + 1;
			return;
		}
		else if (arr[mid] > answer) binarySearch(arr, answer, low, mid - 1);
		else binarySearch(arr, answer, mid + 1, high);
	}
}