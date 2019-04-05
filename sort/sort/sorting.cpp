#include <cstdio>
using namespace std;

int a[10] = { 6, 4, 5, 7, 8, 0, 2, 9, 3, 1 };

void selectionSort(int a[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void bubbleSort(int a[], int n) {
	int temp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void insertionSort(int a[], int n) {
	int i, j;
	int temp;
	for (i = 1; i < n; i++) {
		temp = a[i];
		for (j = i - 1; j >= 0; j--) {
			if (a[j] > temp) {
				a[j + 1] = a[j];
			}
			else break;
		}
		a[j + 1] = temp;
	}
}

void merge(int low, int mid, int high) {

	int i = low, j = mid + 1, k = low;
	int b[10];
	while (i <= mid && j <= high) {
		if (a[i] <= a[j]) {
			b[k++] = a[i++];
		}
		else {
			b[k++] = a[j++];
		}
	}

	int temp = i > mid ? j : i;
	while (k <= high) b[k++] = a[temp++];

	for (int i = low; i <= high; i++) a[i] = b[i];
}

void mergeSort(int low, int high) {
	int mid;
	if (low < high) {
		mid = (low + high) / 2;
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

void partition(int low, int high, int& pivo) {
	int i, j, temp;
	int pivoitem = a[low];
	j = low;
	for (i = low + 1; i <= high; i++) {
		if (a[i] < pivoitem) {
			j++;
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[low];
	a[low] = a[j];
	a[j] = temp;
	pivo = j;
}
void quickSort(int low, int high) {
	int pivo;
	if (high > low) {
		partition(low, high, pivo);
		quickSort(low, pivo - 1);
		quickSort(pivo + 1, high);
	}
}

void main() {	
	quickSort(0, 9);

	for (int i = 0; i < 10; i++) printf("%d ", a[i]);

	getchar();
	getchar();
}

