
#include <iostream> 
#include "Header.h"
void main()
{
	int n = 0;
	cout << "Enter array size" << endl;
	cin >> n;
	datatype *arr = new datatype [n];
	for (int i = 0; i < n; i++) {
		cout << "Enter element " << i + 1 << endl;
		cin >> arr[i];
	}
	print(arr, n);
	Mergesort(arr, 0,n-1,n);
	print(arr, n);
}