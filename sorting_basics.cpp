#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++) {
		int mini = i;
		for(int j = i + 1; j < n; j++) {
			if (arr[j] < arr[mini]) {
				mini = j;
			}
		}
		swap(arr[i], arr[mini]);
	}
}

void bubbleSort(int arr[], int n) {
	for(int i = n - 1; i >= 1; i--) {
		for(int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
}

void bubbleSortOptimized(int arr[], int n) {
	for(int i = n - 1; i >= 1; i--) {
		int didswap = 0;  
		for(int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				didswap = 1; 
			}
		}
		if (didswap == 0)  
			break;
	}
}

void insertionSort(int arr[], int n) {
	for(int i = 1; i < n; i++) {
		int j = i;
		while(j > 0 && arr[j] < arr[j - 1]) {  
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

int main() {
	int arr[5] = {2, 4, 2, 6, 8};
	int n = 5;

	insertionSort(arr, n); 

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
