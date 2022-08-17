/*
	selection sort :
	1. get min of the arr
	2. place at the beginning
	3. do the same for the remaining arr
*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// One by one move boundary of unsorted subarray
	for (i = 0; i < n-1; i++)
	{
		// Find the minimum element in unsorted array
		min_idx = i;
		for (j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element
		swap(arr[min_idx], arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	selectionSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}

// inplace
// this implementation is not stable but can be made by swapping, just transfer it through the arr