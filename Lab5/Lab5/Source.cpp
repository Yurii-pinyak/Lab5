#include "Header.h"
void print(datatype* arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

};
void Merg(datatype* arr, int begin, int end, int size) {
	
	int i = begin;
	int mid = begin + (end - begin) / 2;
	int j = mid + 1;
	int helpindex = 0;
	datatype* helparr = new datatype[size];
	while (i <= mid && j <= end) {
		if (arr[i] <= arr[j]) {
			helparr[helpindex] = arr[i];
			i++;
		}
		else {
			helparr[helpindex] = arr[j];
			j++;
		}
		helpindex++;
	}
	while (i <= mid) {
		helparr[helpindex] = arr[i];
		helpindex++;
		i++;
	}
	while (j <= end) {
		helparr[helpindex] = arr[j];
		helpindex++;
		j++;
	}
	for (int i = 0; i < helpindex; i++) {
		arr[begin + i] = helparr[i];
	}
}
void Mergesort(datatype* arr, int left, int right, int size) {
	datatype help = 0;
	if (left < right) {
		if (right - left == 1) {
			if (arr[left] > arr[right]) {
				help = arr[left];
				arr[left] = arr[right];
				arr[right] = help;
				help = 0;
			}
		}
		else {
			Mergesort(arr, left, left + (right - left) / 2, size);
			Mergesort(arr, left + (right - left) / 2 + 1, right, size);
			Merg(arr, left, right, size);
		}
	}
}